#include "raylib.h"

#include "globals.h"
#include "level.h"
#include "player.h"
#include "enemy.h"
#include "graphics.h"
#include "assets.h"
#include "utilities.h"

void update_game() {
    game_frame++;

    switch (game_state) {
        case MENU_STATE:
            if (IsKeyPressed(KEY_ENTER)) {
                SetExitKey(0);
                game_state = GAME_STATE;
                load_level(0);
            }
            break;

        case GAME_STATE:
            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
                move_player_horizontally(PLAYER_MOVEMENT_SPEED);
            }

            if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
                move_player_horizontally(-PLAYER_MOVEMENT_SPEED);
            }

            // Calculating collisions to decide whether the player is allowed to jump: don't want them to suction cup to the ceiling or jump midair
            is_player_on_ground = is_colliding({player_pos.x, player_pos.y + 0.1f}, WALL);
            if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W) || IsKeyDown(KEY_SPACE)) && is_player_on_ground) {
                player_y_velocity = -JUMP_STRENGTH;
            }

            update_player();
            update_enemies();

            if (IsKeyPressed(KEY_ESCAPE)) {
                game_state = PAUSED_STATE;
            }
            break;

        case PAUSED_STATE:
            if (IsKeyPressed(KEY_ESCAPE)) {
                game_state = GAME_STATE;
            }
            break;

        case DEATH_STATE:
            update_player_gravity();
            if (IsKeyPressed(KEY_ENTER)) {
                load_level(0);
                game_state = GAME_STATE;
            }
            break;

        case VICTORY_STATE:
            if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_ESCAPE)) {
                SetExitKey(KEY_ESCAPE);
                game_state = MENU_STATE;
            }
            break;
    }
}

void draw_game() {
    switch(game_state) {
        case MENU_STATE:
            ClearBackground(BLACK);
            draw_menu();
            break;

        case GAME_STATE:
            ClearBackground(BLACK);
            draw_parallax_background();
            draw_level();
            draw_game_overlay();
            break;

        case DEATH_STATE:
            ClearBackground(BLACK);
            draw_parallax_background();
            draw_level();
            draw_game_overlay();
            DrawRectangle(0, 0, GetRenderWidth(), GetRenderHeight(), {0, 0, 0, 100});
            draw_text(death_title);
            draw_text(death_subtitle);
            break;

        case PAUSED_STATE:
            ClearBackground(BLACK);
            draw_pause_menu();
            break;

        case VICTORY_STATE:
            draw_victory_menu();
            break;
    }
}

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Platformer");
    SetTargetFPS(60);
    ToggleFullscreen();
    HideCursor();
    InitAudioDevice();

    load_fonts();
    load_images();
    load_sounds();
    load_level();

    while (!WindowShouldClose()) {
        BeginDrawing();

        update_game();
        draw_game();

        EndDrawing();
    }

    unload_level();
    unload_sounds();
    unload_images();
    unload_fonts();

    CloseAudioDevice();
    CloseWindow();

    return 0;
}
