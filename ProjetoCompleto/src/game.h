#pragma once
#include <SDL2/SDL.h>

#include "background.h"

class CriarJanela
{
private:
    SDL_Window* janela;
    SDL_Renderer* renderizador;
    

public:
    
    CriarJanela();
    ~CriarJanela();
    void criar(const char * titulo, int tamW, int tamH);
    void claro();
    void limpar();
    void tela();
    void loopjanela();
};