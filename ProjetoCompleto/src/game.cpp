#include "game.h"
#include <iostream>



const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512;


CriarJanela::CriarJanela(){}
CriarJanela::~CriarJanela(){}
void CriarJanela::criar(const char *titulo, int tamW, int tamH)
{
    janela = SDL_CreateWindow(titulo, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, tamW, tamH, SDL_WINDOW_SHOWN);
    if(janela == NULL){
        std::cout << "Janela com erro, revise!" << SDL_GetError() << std::endl;
    }
    else{
        std::cout << "Janela funcinou!" << std::endl;
    }

    renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
}
void CriarJanela::claro()
{
    SDL_SetRenderDrawColor(renderizador, 72, 61, 139, 1);
    SDL_RenderClear(renderizador);
}



void CriarJanela::loopjanela()
{
    bool janelarodando = true;
    SDL_Event evento;
    while(janelarodando){
        while(SDL_PollEvent(&evento) != 0)
        {
            if(evento.type == SDL_QUIT){
                janelarodando = false;
            }
        }
    }
}

void CriarJanela::tela()
{
    SDL_RenderPresent(renderizador);
}

void CriarJanela::limpar()
{
    SDL_DestroyWindow(janela);
}