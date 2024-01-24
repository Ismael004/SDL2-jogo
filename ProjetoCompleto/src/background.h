#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Background
{
public:
    Background();
    ~Background();
    void carregarFundo(char caminho);
private:
    SDL_Renderer * renderizador;
    SDL_Surface * imagem;
    SDL_Texture * textura;
}