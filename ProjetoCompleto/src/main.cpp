#include <SDL2/SDL.h>
#include <iostream>

#include "game.h"
#include "game.cpp"

CriarJanela janela;

int main(int argc, char* args[])
{
    //Criar janela
    janela.criar("Primeiro programa", SCREEN_WIDTH, SCREEN_WIDTH);
    //Coloca imagem e os efeitos
    janela.claro();
    janela.tela();
    //Parte final
    janela.loopjanela();
    janela.limpar();
    
    return 0;
}