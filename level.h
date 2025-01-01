#ifndef LEVEL_H
#define LEVEL_H

#include "globals.h"

bool is_colliding(Vector2 pos, char look_for, level &level) {
    Rectangle entity_hitbox = {pos.x, pos.y, 1.0f, 1.0f};

    // Prevent the game from crashing on GNU/Linux
    if (pos.y > level.rows - 1 || pos.x > level.columns - 1) return false;

    for (size_t row = pos.y - 1; row < pos.y + 1; ++row) {
        for (size_t column = pos.x - 1; column < pos.x + 1; ++column) {
            if (level.data[row * level.columns + column] == look_for) {
                Rectangle block_hitbox = {(float) column, (float) row, 1.0f, 1.0f};
                if (CheckCollisionRecs(entity_hitbox, block_hitbox)) {
                    return true;
                }
            }
        }
    }
    return false;
}

char& get_collider(Vector2 pos, char look_for, level &level) {
    Rectangle player_hitbox = {pos.x, pos.y, 1.0f, 1.0f};

    for (size_t row = pos.y - 1; row < pos.y + 1; ++row) {
        for (size_t column = pos.x - 1; column < pos.x + 1; ++column) {
            if (level.data[row * level.columns + column] == look_for) {
                Rectangle block_hitbox = {(float) column, (float) row, 1.0f, 1.0f};
                if (CheckCollisionRecs(player_hitbox, block_hitbox)) {
                    return level.data[row * level.columns + column];
                }
            }
        }
    }

    return level.data[static_cast<int>(roundf(pos.y) * level.columns + roundf(pos.x))];
}

void load_level(int offset) {
    level_index += offset;

    if (level_index >= LEVEL_COUNT) {
        game_state = VICTORY_STATE;
        create_victory_menu_background();
        level_index = 0;
        return;
    }

    size_t rows = LEVELS[level_index].rows;
    size_t columns = LEVELS[level_index].columns;
    current_level_data = new char[rows*columns];

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            current_level_data[row*columns + column] = LEVELS[level_index].data[row*columns + column];
        }
    }

    current_level = {rows, columns, current_level_data};

    spawn_player();
    spawn_enemies();
    derive_graphics_metrics_from_loaded_level();
}

void unload_level() {
    delete[] current_level_data;
}

#endif //LEVEL_H
