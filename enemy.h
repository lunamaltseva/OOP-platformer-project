#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include "globals.h"

void spawn_enemies() {
    // Create enemies, incrementing their amount every time a new one is created
    total_enemies_on_level = 0;

    for (size_t row = 0; row < current_level.rows; ++row) {
        for (size_t column = 0; column < current_level.columns; ++column) {
            char cell = get_level_cell(row, column);

            if (cell == ENEMY) {
                // Instantiate and add an enemy to the level
                enemies[total_enemies_on_level] = {
                        {static_cast<float>(column), static_cast<float>(row)},
                        true
                };
                total_enemies_on_level++;

                set_level_cell(row, column, AIR);
            }
        }
    }
}

void update_enemies() {
    for (int i = 0; i < total_enemies_on_level; i++) {
        // Get the enemy
        Enemy& enemy = enemies[i];

        // Find its next x
        float next_x = enemy.pos.x;
        next_x += ( enemy.is_looking_right ? ENEMY_MOVEMENT_SPEED : -ENEMY_MOVEMENT_SPEED);

        // If its next position collides with a wall, turn around
        if (is_colliding({next_x, enemy.pos.y}, WALL)) {
            enemy.is_looking_right = !enemy.is_looking_right;
        }
        // Otherwise, keep moving
        else {
            enemy.pos.x = next_x;
        }
    }
}

// Custom is_colliding function for enemies
bool is_colliding_with_enemies(Vector2 pos) {
    Rectangle entity_hitbox = {pos.x, pos.y, 1.0f, 1.0f};

    for (int i = 0; i < total_enemies_on_level; i++) {
        Rectangle enemy_hitbox = {(float) enemies[i].pos.x, (float) enemies[i].pos.y, 1.0f, 1.0f};
        if (CheckCollisionRecs(entity_hitbox, enemy_hitbox)) {
            return true;
        }
    }
    return false;
}

void remove_colliding_enemy(Vector2 pos) {
    Rectangle entity_hitbox = {pos.x, pos.y, 1.0f, 1.0f};

    for (int i = 0; i < total_enemies_on_level; i++) {
        Rectangle enemy_hitbox = {(float) enemies[i].pos.x, (float) enemies[i].pos.y, 1.0f, 1.0f};
        // Overwrite the enemy by shifting all following enemies to the left
        if (CheckCollisionRecs(entity_hitbox, enemy_hitbox)) {
            for (int j = i + 1; j < MAX_ENEMIES; j++) {
                enemies[j - 1] = enemies[j];
            }
            total_enemies_on_level--;
            return;
        }
    }
}

#endif //ENEMY_H
