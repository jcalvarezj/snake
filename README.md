# Snake Game

Small prototype of the snake game made in C++ with the SDL library (dev and ttf-dev, from SDL2)

Compile on Linux with **g++ \*.cpp \`sdl2-config --cflags --libs\` -lSDL_ttf**

Compile on Windows with **g++ \*.cpp -IC:\\SDL\\i686-w64-mingw32\\include\\SDL2 -LC:\\SDL\\i686-w64-mingw32\\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf**

_For the above Windows example, it is necessary to have a copy of all SDL2 contents in C:\\SDL\\ (which should include the contents of the SDL TTF extension on the corresponding architecture folder, in this case i686...). Header files are required on MinGW's include folder, inside an SDL2 folder, and DLLs (libfreetype-6, SDL2, and SDL2_ttf) inside MinGW's bin folder)_

Arrow keys move change the snake's direction. Press RETURN (ENTER) to pause the game