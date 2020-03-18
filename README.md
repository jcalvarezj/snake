# Snake Game

Small prototype of the snake game made in C++ with the SDL 2 library (dev and ttf-dev, from SDL2).

The game implements lives system, pause, and Game Over screen. For the moment it only supports one speed.

## Compilation

Compile on Linux with **g++ \*.cpp \`sdl2-config --cflags --libs\` -lSDL2_ttf**

Compile on Windows with **g++ \*.cpp -IC:\\SDL\\i686-w64-mingw32\\include\\SDL2 -LC:\\SDL\\i686-w64-mingw32\\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf**

## Requirements

In order to successfully compile and run this project, you will need to have the SDL 2 libraries on your system.

### For Linux

Install the libsdl2-2.0-0, libsdl2-dev, libsdl2-ttf-2.0-0, and libsdl2-ttf-dev libraries.

### For Windows

MinGW with g++ compiler should be installed on your system.

Download the latest _SDL2-devel-2.x.x-mingw_ from [SDL's official page](https://www.libsdl.org/index.php) and uncompress the inner folder's contents on an easy access directory (such as C:\\SDL, for example). Download as well the latest _SDL2_ttf-devel-2.x.x-mingw_ from [SDL_ttf 2.0's page](https://www.libsdl.org/projects/SDL_ttf/), uncompress, and merge the inner folder's content with the previously created for base SDL (inside C:\\SDL)

From the new directory (C:\\SDL), there is a folder named with your desired architecture. Copy that folder's _bin_ content onto your MinGW's _bin_ folder, and the _include_ folder's contents onto MinGW's _include_

## Gameplay

Guide the snake to eat food while avoiding collisions with walls or the body of the snake. Arrow keys change the snake's direction and RETURN (ENTER) pauses the game. You have three lives to get the highest possible score.

## Preview

![Short gameplay demo](https://jcalvarezj.github.io/img/Snake.gif)
