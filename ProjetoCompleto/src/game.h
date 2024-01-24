#pragma once
#include <SDL2/SDL.h>
#include <iostream>

#include "background.h"
#include "background.cpp"

class CriarJanela
{
private:
    SDL_Window* janela;
    SDL_Renderer* renderizador;
    Background* fundo;
public:
    CriarJanela();
    ~CriarJanela();
    void criar(const char * titulo, int tamW, int tamH);
    void claro();
    void limpar();
    void tela();
    void loopjanela();
    void carregarTextura();
};