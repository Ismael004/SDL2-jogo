all:
	g++ ProjetoCompleto/src/main.cpp -o main.exe -Imingw\include\SDL2 -Lmingw\bin -lmingw32 -lSDL2main -lSDL2 -lSDL2_image