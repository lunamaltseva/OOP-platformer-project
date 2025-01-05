<h1 align=center> COM-119 2025S Project 1: OOP-platformer-project </h1>

<h5 align=center>This is the starting point for Project 1 of the Object-Oriented Programming course at AUCA, which students are required to translate into OOP </h5>

![titlescreen](data/screenshots/readme-header.png)

**OOP-platformer-project** is a raylib-based game that challenges students to translate procedural code into Object-Oriented code.

<h2 align=center> Essence </h2>

This is a fork of **simple-platformer-project** which builds on top of the original single-screen platformer, to create a side-scrolling platformer with additional elements and logic.

### Level Elements
|                                                                           Static Elements                                                                            |                              UI Elements                              |                                      Dynamic Elements                                      |
|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------:|:---------------------------------------------------------------------:|:------------------------------------------------------------------------------------------:|
| ![wall](data/images/wall.png) ![wall](data/images/wall_dark.png) ![spikes](data/images/spikes.png) ![exit](data/images/exit.png) ![coin](data/images/coin/coin0.png) | ![coins](data/images/coin/coin0.png) ![hearts](data/images/heart.png) | ![player](data/images/player_jump_forward.png) ![enemy](data/images/enemy_walk/enemy0.png) |
|                                                                   Walls, spikes, flags, and coins                                                                    |                           Coins and hearts                            |                                     Player and bandits                                     |

The player's objective is to traverse every level, collecting coins and avoiding spikes, pits, and bandits in as little time as possible. To do so, the player is given three lives. Losing a life resets the level. Running out of lives means fully starting over.

<h2 align=center> Prerequisites </h2>

To successfully complete this project, students are encouraged to familiarize themselves with the following theoretical ground:

- Liang, Daniel Y. _Introduction to Programming with C++_. Pearson, 2014, Chapters 9, 10, 11, and 13 (pp. 361-542);
- [Singleton](https://refactoring.guru/design-patterns/singleton), [Factory](https://refactoring.guru/design-patterns/factory-method), and [Mediator](https://refactoring.guru/design-patterns/mediator)/[Observer](https://refactoring.guru/design-patterns/observer) design patterns.

Doing so will simplify and ease the process of redesigning procedural code into object-oriented code.

<h2 align=center> Run-Length Encoding </h2>

This project utilizes RLE to encode levels, making them compact and efficient.

| Puzzle Element | Character | ASCII code |
|:---------------|:----------|:-----------|
| Wall           | #         | 0x23       |
| Dark Wall      | =         | 0x3D       |
| Air            | -         | 0x2D       |
| Player         | @         | 0x40       |
| Coin           | *         | 0x2A       |
| Spike          | ^         | 0x5E       |
| Enemy          | &         | 0x26       |

In this format digits show how many elements of the same type are following;

`---- becomes 4-`

So the following level,
```
 -------
 ---*---
 -------
 -------
 -------
 @-^^^-E
 #######
```

looks like this with RLE:

`7-|3-*3-|7-|7-|7-|@-3^-e|7#`.

The rows of the level are separated by `|`s (vertical bars).

<h2 align=center> Implementation Tips </h2>

- You need to implement three classes: Level, Player, and Enemy. Level is the hardest, Enemy is the easiest. So, go with player first.
- In your `class.h` files, exclusively use forward declarations—do not implement functions. Furthermore, try to only include `"raylib.h"` in your `.h` files.
- In your `class.cpp` files, however, you may include anything and everything you desire.
- Use the `inline` keyword on variables that are included in more than one `.cpp` file—like `globals.h`—to avoid redefinitions.
- Do not forget to initialize static member variables.
- When using singletons, do not forget to initialize them before using them.
- Use compilation and linking errors to your advantage—_read_ them.
- Use the debug tool to resolve crashes.

---
<h5 align=center> by @lunamaltseva </h5>