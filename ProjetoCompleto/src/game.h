#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.h"
#include "TextureManager.cpp"
class CriarJanela
{
private:
    SDL_Window* janela;
    SDL_Renderer* renderizador;
    int m_currentFrame;
    TextureManager * m_textureManager;

public:
    CriarJanela();
    ~CriarJanela();
    void criar(const char * titulo, int tamW, int tamH);
    void claro();
    void limpar();
    void tela();
    void loopjanela();
   

};