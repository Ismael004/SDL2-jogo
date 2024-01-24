#include "background.h"

Background::Background(){}
Background::~Background(){}

void Background::carregarFundo(char caminho, SDL_Renderer * ren){
    imagem = IMG_Load(caminho);
    textura = SDL_CreateTextureFromSurface(ren, imagem);

    SDL_RenderCopy(ren, textura, NULL, NULL);
    
}