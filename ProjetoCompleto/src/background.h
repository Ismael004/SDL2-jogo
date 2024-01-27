#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Background
{
public:
    Background();
    ~Background();
    void carregarFundo(const char* caminho, SDL_Renderer* ren);
private:
    //SDL_Surface* imagem;
    SDL_Texture* imagem;
};