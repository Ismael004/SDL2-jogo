#include "game.h"
#include <iostream>
#include <SDL2/SDL_image.h>
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
    
    m_textureManager->load("res/fundo.png", "teste", renderizador);
    //m_textureManager::Instance()->load("src/teste.png","teste", renderizador);
}
void CriarJanela::claro()
{
    SDL_RenderClear(renderizador);
    m_textureManager->draw("teste", 0,0, 128, 82, 1.0, 0.0, renderizador, SDL_FLIP_HORIZONTAL);

    m_currentFrame = 60;

    m_textureManager->drawFrame("teste",100,100,128,82, 1.0,0.0,
    1, m_currentFrame, renderizador);

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
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
    SDL_RenderPresent(renderizador);
}

void CriarJanela::limpar()
{
    SDL_DestroyWindow(janela);
}