#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include "globals.h"

void spawn_enemies() {
    total_enemies = 0;

    for (size_t row = 0; row < current_level.rows; ++row) {
        for (size_t column = 0; column < current_level.columns; ++column) {
            char cell = current_level.data[row * current_level.columns + column];

            if (cell == ENEMY) {
                enemies[total_enemies++] = {{static_cast<float>(column), static_cast<float>(row)}, true};
            }
        }
    }
}

void update_enemies() {
    for (int i = 0; i < total_enemies; i++) {
        float next_x = enemies[i].pos.x;
        next_x += (enemies[i].is_looking_right ? ENEMY_MOVEMENT_SPEED : -ENEMY_MOVEMENT_SPEED);
        if (is_colliding({next_x, enemies[i].pos.y}, WALL)) {
            enemies[i].is_looking_right = !enemies[i].is_looking_right;
        }
        else {
            enemies[i].pos.x = next_x;
        }
    }
}

bool is_colliding_with_enemies(Vector2 pos) {
    Rectangle entity_hitbox = {pos.x, pos.y, 1.0f, 1.0f};

    for (int i = 0; i < total_enemies; i++) {
        Rectangle enemy_hitbox = {(float) enemies[i].pos.x, (float) enemies[i].pos.y, 1.0f, 1.0f};
        if (CheckCollisionRecs(entity_hitbox, enemy_hitbox)) {
            return true;
        }
    }
    return false;
}

void remove_colliding_enemy(Vector2 pos) {
    Rectangle entity_hitbox = {pos.x, pos.y, 1.0f, 1.0f};

    for (int i = 0; i < total_enemies; i++) {
        Rectangle enemy_hitbox = {(float) enemies[i].pos.x, (float) enemies[i].pos.y, 1.0f, 1.0f};
        if (CheckCollisionRecs(entity_hitbox, enemy_hitbox)) {
            for (int j = i + 1; j < MAX_ENEMIES; j++) {
                enemies[j - 1] = enemies[j];
            }
            total_enemies--;
            return;
        }
    }
}

#endif //ENEMY_H
