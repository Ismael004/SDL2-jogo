#pragma once

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class GerenciadorTexture
{
public:
//Static são variáveis que não são duplicados nos objetos da classe
    static GerenciadorTexture* Instance()
    {
        if(s_pInstance == 0){
            s_pInstance = new GerenciadorTexture();
        }
        return s_pInstance;
    }
    bool carregarTextura(string fileName, string id, SDL_Renderer* pRenderizador);

    void desenhar(string in, int x, int y, int width, int height,
    int currentRow, int currentFramem, SDL_Renderer* pRenderizador, 
    SDL_RendererFlip flip = SDL_FLIP_NONE);

    void limparTexura(string id);

private: 
    map<string, SDL_Texture*> m_textureMap;
    GerenciadorTexture(){};
    ~GerenciadorTexture();

    static GerenciadorTexture* s_pInstance;

};

typedef GerenciadorTexture TheGerenciadorTexture();