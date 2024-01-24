#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


;class Background
{
public:
    Background();
    ~Background();
    void carregarFundo(char caminho, SDL_Renderer * ren);
private:
    SDL_Surface * imagem;
    SDL_Texture * textura;
};