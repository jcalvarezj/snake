# Snake Game

Small prototype of the snake game made in C++ with the SDL library (dev and ttf, from SDL2)

Compile on Linux with **g++ \*.cpp \`sdl2-config --cflags --libs\`**
Compile on Windows with **g++ \*.cpp -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2**
	(_Requires having SDL2.dll and SDL2\_ttf.dll on MinGW's bin, and headers MinGW's include, inside a SDL2 folder_)

Arrow keys move change the snake's direction. Press RETURN (ENTER) to pause the game