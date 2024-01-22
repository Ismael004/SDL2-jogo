#include "game.h"
#include <iostream>
#include "gerenciador-de-Texture.h"
#include "gerenciador-de-Texture.cpp"




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
   
    TextureManager::Instance()->load("src/teste.png", "test", renderizador);
    TextureManager::Instance()->draw("test", 100, 100, 128, 128, 1, 0, renderizador);
    SDL_RenderPresent(renderizador);  // Chame SDL_RenderPresent depois de renderizar a textura
    SDL_RenderClear(renderizador);     // Limpe o renderizador antes de renderizar novamente


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
    
}

void CriarJanela::limpar()
{
    SDL_DestroyWindow(janela);
}