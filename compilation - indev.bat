@echo off

@echo Compilation en cours...

gcc src/main.c -o bin/prog.exe -I include -L lib -lmingw32 -lSDL2main -lSDL2 src/my.res

PAUSE