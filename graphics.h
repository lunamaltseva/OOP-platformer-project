#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "globals.h"

void draw_text(Text &text) {
    Vector2 dimensions = MeasureTextEx(*text.font, text.str.c_str(), text.size * screen_scale, text.spacing);

    Vector2 pos = {
        (screen_size.x * text.position.x) - (0.5f * dimensions.x),
        (screen_size.y * text.position.y) - (0.5f * dimensions.y)
    };

    DrawTextEx(*text.font, text.str.c_str(), pos, dimensions.y, text.spacing, text.color);
}

void derive_graphics_metrics_from_loaded_level() {
    screen_size.x  = static_cast<float>(GetScreenWidth());
    screen_size.y = static_cast<float>(GetScreenHeight());

    cell_size = std::min(
        screen_size.x,
        screen_size.y
    ) / static_cast<float>(LEVELS[level_index].rows);
    screen_scale = std::min(
        screen_size.x,
        screen_size.y
    ) / SCREEN_SCALE_DIVISOR;

    float level_width  = static_cast<float>(current_level.columns) * cell_size;
    float level_height = static_cast<float>(current_level.rows)    * cell_size;
}

void draw_menu() {
    draw_text(game_title);
    draw_text(game_subtitle);
}

void draw_game_overlay() {
    Text score = {
        "Score " + std::to_string(player_score),
        {0.50f, 0.05f},
        48.0f
    };
    Text score_shadow = {
        "Score " + std::to_string(player_score),
        {0.503f, 0.055f},
        48.0f,
        GRAY
    };

    draw_text(score_shadow);
    draw_text(score);
}

void draw_level() {
    horizontal_shift = (screen_size.x - cell_size) / 2;

    for (size_t row = 0; row < current_level.rows; ++row) {
        for (size_t column = 0; column < current_level.columns; ++column) {

            Vector2 pos = {
                    (static_cast<float>(column) - player_pos.x) * cell_size + horizontal_shift,
                    static_cast<float>(row) * cell_size
            };

            char cell = current_level.data[row * current_level.columns + column];
            switch (cell) {
                case WALL:
                    draw_image(wall_image, pos, cell_size);
                    break;
                case COIN:
                    draw_sprite(coin_sprite, pos, cell_size);
                    break;
                case EXIT:
                    draw_image(exit_image, pos, cell_size);
                    break;
                default:
                    break;
            }
        }
    }

    draw_player();
}

void draw_player() {
    horizontal_shift = (screen_size.x - cell_size) / 2;

    Vector2 pos = {
            horizontal_shift,
            player_pos.y * cell_size
    };

    if (game_state == GAME_STATE) {
        if (!is_player_on_ground) {
            draw_image((is_looking_forward ? player_jump_forward_image : player_jump_backwards_image), pos, cell_size);
        }
        else if (is_moving) {
            draw_sprite((is_looking_forward ? player_walk_forward_sprite : player_walk_backwards_sprite), pos, cell_size);
            is_moving = false;
        }
        else {
            draw_image((is_looking_forward ? player_stand_forward_image : player_stand_backwards_image), pos, cell_size);
        }
    }
    else draw_image(player_dead_image, pos, cell_size);

}

void draw_pause_menu() {
    draw_text(game_paused);
}

void create_victory_menu_background() {
    for (auto &ball : victory_balls) {
        ball.x  = rand_up_to(screen_size.x);
        ball.y  = rand_up_to(screen_size.y);
        ball.dx = rand_from_to(-VICTORY_BALL_MAX_SPEED, VICTORY_BALL_MAX_SPEED);
        ball.dx *= screen_scale;
        if (abs(ball.dx) < 0E-1) ball.dx = 1.0f;
        ball.dy = rand_from_to(-VICTORY_BALL_MAX_SPEED, VICTORY_BALL_MAX_SPEED);
        ball.dy *= screen_scale;
        if (abs(ball.dy) < 0E-1) ball.dy = 1.0f;
        ball.radius = rand_from_to(VICTORY_BALL_MIN_RADIUS, VICTORY_BALL_MAX_RADIUS);
        ball.radius *= screen_scale;
    }

    /* Clear both the front buffer and the back buffer to avoid ghosting of the game graphics. */
    ClearBackground(BLACK);
    EndDrawing();
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
    BeginDrawing();
}

void animate_victory_menu_background() {
    for (auto &ball : victory_balls) {
        ball.x += ball.dx;
        if (ball.x - ball.radius < 0 ||
            ball.x + ball.radius >= screen_size.x) {
            ball.dx = -ball.dx;
        }
        ball.y += ball.dy;
        if (ball.y - ball.radius < 0 ||
            ball.y + ball.radius >= screen_size.y) {
            ball.dy = -ball.dy;
        }
    }
}

void draw_victory_menu_background() {
    for (auto &ball : victory_balls) {
        DrawCircleV({ ball.x, ball.y }, ball.radius, VICTORY_BALL_COLOR);
    }
}

void draw_victory_menu() {
    DrawRectangle(
        0, 0,
        static_cast<int>(screen_size.x), static_cast<int>(screen_size.y),
        { 0, 0, 0, VICTORY_BALL_TRAIL_TRANSPARENCY }
    );

    animate_victory_menu_background();
    draw_victory_menu_background();

    draw_text(victory_title);
    draw_text(victory_subtitle);
}

#endif //GRAPHICS_H
