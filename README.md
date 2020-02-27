# Snake Game

Small prototype of the snake game made in C++ with the SDL library

Compile on Linux with **g++ \*.cpp \`sdl2-config --cflags --libs\`**
Compile on Windows (using MinGW's g++ compiler and assuming SDL root is at C:\\) with **g++ \*.cpp -IC:\\SDL\\include -LC:\\SDL\\i686-w64-mingw32\\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2**

Arrow keys move change the snake's direction