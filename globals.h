#ifndef GLOBALS_H
#define GLOBALS_H

#include "raylib.h"

#include <string>
#include <cstddef>
#include <cmath>

/* Game Elements */

const char WALL      = '#';
const char WALL_DARK = '=';
const char AIR       = ' ';
const char SPIKE     = '^';
const char PLAYER    = '@';
const char ENEMY     = '&';
const char COIN      = '*';
const char EXIT      = 'E';

/* Levels */

struct level {
    size_t rows = 0, columns = 0;
    char *data = nullptr;
};

char LEVEL_1_DATA[] = {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '^', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', '=', '=', ' ', ' ', ' ', '^', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '=', '=', '=', '=', ' ', ' ', ' ', ' ', ' ', ' ', '=', '=', '=', '=', '=', '#', ' ', ' ', ' ', '=', '=', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', '#', '=', '=', '=', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '=', '=', '=', '=', ' ', ' ', ' ', ' ', ' ', ' ', '=', '=', '=', '=', '=', '#', ' ', '^', '^', '=', '=', '^', '^', '^', '=', '=', '^', '^', ' ', '#', '=', '=', '=', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
        '#', ' ', '#', ' ', '#', ' ', '#', ' ','#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '=', '=', '=', '=', ' ', ' ', ' ', ' ', ' ', ' ', '=', '=', '=', '=', '=', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '=', '=', '=', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
        '#', '#', '#', '#', '#', '#', '#', '#','#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '=', '=', '=', '=', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '=', '=', '=', '=', '=', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '=', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '=', '=', '#', ' ', '#', '=', '=', '=', '=', '=', '=', '=', '=', '=', '#', ' ', '#', '=', '=', '=', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
        '#', '#', '#', '#', '=', '#', '#', '#','#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '=', '=', '=', '=', '#', '^', '#', ' ', ' ', ' ', ' ', ' ', ' ', '=', '#', '#', '#', '=', ' ', ' ', ' ', ' ', ' ', ' ', '=', '=', '=', '=', '=', '#', '=', ' ', ' ', ' ', ' ', ' ', ' ', '=', '#', '#', '=', '=', '#', '#', '#', '=', '=', '=', ' ', '*', ' ', '=', '=', '=', '#', '#', '#', '=', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
        '#', '#', '#', '=', '=', '=', '#', '#','#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '=', '=', '=', '=', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '=', '=', '=', '=', '=', '#', '=', ' ', ' ', ' ', ' ', ' ', ' ', '=', '#', '#', '=', '=', '=', '=', '=', '=', '=', '=', ' ', '#', ' ', '=', '=', '=', '=', '=', '=', '=', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
        '#', '#', '#', '=', '=', '=', '#', '#','#', ' ', '@', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '=', '=', '=', '=', '#', '#', '#', '^', '#', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '=', '=', '=', '=', '=', '#', '=', ' ', ' ', ' ', '&', ' ', ' ', '=', '#', '#', '=', '=', '=', '=', '=', '=', '=', '=', '&', '#', '&', '=', '=', '=', '=', '=', '=', '=', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', 'E', '#',
        '#', '#', '#', '#', '#', '#', '#', '#','#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '=', '=', '=', '=', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
};

level LEVEL_1 = {
        12, 88,
        LEVEL_1_DATA
};

int level_index = 0;
const int LEVEL_COUNT = 1;

level LEVELS[LEVEL_COUNT] = {
        LEVEL_1
};

/* Loaded Level Data */

level current_level;
char *current_level_data;

/* Player data */

const float GRAVITY_FORCE = 0.01f;
const float JUMP_STRENGTH = 0.3f;
const float PLAYER_MOVEMENT_SPEED = 0.1f;
const float ENEMY_MOVEMENT_SPEED = 0.07f;

Vector2 player_pos;
float player_y_velocity = 0;

bool is_player_on_ground;

int player_score = 0;

struct Enemy {
    Vector2 pos;
    bool is_looking_right;
};

size_t total_enemies;
Enemy enemies[10];

/* Graphic Metrics */

const float SCREEN_SCALE_DIVISOR = 700.0f; // The divisor was found through experimentation
                                           // to scale things accordingly to look pleasant.

Vector2 screen_size;
float screen_scale; // Used to scale str/UI components size and displacements based on the screen_size size
float cell_size;
float horizontal_shift;

/* Fonts */

Font menu_font;

/* Display Text Parameters */

// Going off of personal experience, a basic text class is THE building block of a raylib game
// I hope that by providing them with this basic thingy, they'll build more sophisticated stuff from it
struct Text {
    std::string str;
    Vector2 position = {0.50f, 0.50f};
    float size = 32.0f;
    Color color = WHITE;
    float spacing = 4.0f;
    Font* font = &menu_font;
};

Text game_title = {
    "Platformer",
    {0.50f, 0.50f},
    100.0f,
    RED
};

Text game_subtitle = {
    "Press Enter to Start",
    {0.50f, 0.65f}
};

Text game_paused = {
    "Press Escape to Resume"
};

Text death_title = {
        "Game Over!",
        {0.50f, 0.50f},
        100.0f,
        RED
};

Text death_subtitle = {
        "Press Enter to Restart",
        {0.50f, 0.65f}
};

Text victory_title = {
    "You Won!",
    {0.50f, 0.50f},
    100.0f,
    RED
};

Text victory_subtitle = {
    "Press Enter to go back to menu",
    {0.50f, 0.65f}
};

/* Images and Sprites */

Texture2D wall_image;
Texture2D wall_dark_image;
Texture2D spike_image;
Texture2D exit_image;

struct sprite {
    size_t frame_count    = 0;
    size_t frames_to_skip = 3;
    size_t frames_skipped = 0;
    size_t frame_index    = 0;
    bool loop = true;
    size_t prev_game_frame = 0;
    Texture2D *frames = nullptr;
};

sprite coin_sprite;

Texture2D player_stand_forward_image;
Texture2D player_stand_backwards_image;
Texture2D player_jump_forward_image;
Texture2D player_jump_backwards_image;
Texture2D player_dead_image;
sprite player_walk_forward_sprite;
sprite player_walk_backwards_sprite;

sprite enemy_walk;

Texture2D background;
Texture2D middleground;
Texture2D foreground;

bool is_looking_forward;
bool is_moving;

/* Sounds */

Sound coin_sound;
Sound exit_sound;

/* Victory Menu Background */

struct victory_ball {
    float x, y;
    float dx, dy;
    float radius;
};

const size_t VICTORY_BALL_COUNT     = 2000;
const float VICTORY_BALL_MAX_SPEED  = 2.0f;
const float VICTORY_BALL_MIN_RADIUS = 2.0f;
const float VICTORY_BALL_MAX_RADIUS = 3.0f;
const Color VICTORY_BALL_COLOR      = { 180, 180, 180, 255 };
const unsigned char VICTORY_BALL_TRAIL_TRANSPARENCY = 10;
victory_ball victory_balls[VICTORY_BALL_COUNT];

/* Frame Counter */

size_t game_frame = 0;

/* Game States */

enum game_state {
    MENU_STATE,
    GAME_STATE,
    PAUSED_STATE,
    DEATH_STATE,
    GAME_OVER_STATE,
    VICTORY_STATE
};
game_state game_state = MENU_STATE;

/* Forward Declarations */

// GRAPHICS_H

void draw_text(Text &text);
void derive_graphics_metrics_from_loaded_level();
void draw_menu();
void draw_game_overlay();
void draw_level();
void draw_player();
void draw_enemies();
void draw_pause_menu();
void create_victory_menu_background();
void animate_victory_menu_background();
void draw_victory_menu_background();
void draw_victory_menu();

// LEVEL_H

bool is_colliding(Vector2 pos, char look_for = '#', level &level = current_level);
char& get_collider(Vector2 pos, char look_for, level &level = current_level);

void load_level(int offset = 0);
void unload_level();

// PLAYER_H

void spawn_player();
void move_player_horizontally(float delta);
void update_player();
void update_player_gravity();

// ENEMY_H

bool is_colliding_with_enemies(Vector2 pos);
void spawn_enemies();
void update_enemies();

// ASSETS_H

void load_fonts();
void unload_fonts();

void load_images();
void unload_images();

void draw_image(Texture2D image, Vector2 pos, float width, float height);
void draw_image(Texture2D image, Vector2 pos, float size);

sprite load_sprite(
        const std::string &file_name_prefix,
        const std::string &file_name_suffix,
        size_t frame_count = 1,
        bool loop = true,
        size_t frames_to_skip = 3
);
void unload_sprite(sprite &sprite);
void draw_sprite(sprite &sprite, Vector2 pos, float width, float height);
void draw_sprite(sprite &sprite, Vector2 pos, float size);

void load_sounds();
void unload_sounds();

// UTILITIES_H

float rand_from_to(float from, float to);
float rand_up_to(float to);

#endif // GLOBALS_H