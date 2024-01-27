#include "background.h"
using namespace std;

Background::Background(){}
Background::~Background(){}

void Background::carregarFundo(const char * caminho, SDL_Renderer * ren){
    imagem = IMG_LoadTexture(ren, caminho);
    SDL_RenderCopy(ren, imagem, NULL, NULL);
    //return imagem;
}