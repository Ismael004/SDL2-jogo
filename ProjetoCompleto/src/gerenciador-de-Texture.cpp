#include "gerenciador-de-Texture.h"

GerenciadorTexture::~GerenciadorTexture(){}
GerenciadorTexture *Gerenciador::s_pInstance = 0;

bool GerenciadorTexture::carregarTextura(string fileName, string id, SDL_Renderer* pRenderizador){
    SDL_Surface* pTempSurface = IMG_load(fileName.c_str());
    if(pTempSurface == 0)
    {
        std::cout << "erro ao carregar a pTempSurface" << fileName << endl;
        return false;
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderizador,pTempSurface);
    SDL_FreeSurface(pTempSurface);

    if(pTexture == 0){
        std::cout << "Erro ao criar a textura" << fileName << endl;
        return false;
    }

    m_textureMap[id] = pTexture;
    return true;
}

void GerenciadorTexture::desenhar(string id, int x, int y, int width, int height, SDL_Renderer* pRenderizador, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;

    srcRect.w = destRect.w = width;
    srcRect.w = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderizador, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void GerenciadorTexture::desenhoFrame(string id, int x, int y, int width, int height,
    int currentRow, int currentFrame, SDL_Renderer* pRenderizador, 
    SDL_RendererFlip flip = SDL_FLIP_NONE)
    {
        SDL_Rect srcRect;
        SDL_Rect destRect;

        srcRect.x = width * currentFrame;
        srcRect.y = height * (currentRow - 1);
        srcRect.w = destRect.w = width;
        src.h = destRect.h = height;
        destRect.x = x;
        destRect.y = y;

        SDL_RenderCopyEx(pRenderizador, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
    }
void GerenciadorTexture::limparTextura(string id)
{
    m_textureMap.erase(id);
}