#include "background.h"
using namespace std;

Background::Background(){}
Background::~Background(){}

void Background::carregarFundo(const char * caminho, SDL_Renderer * ren){
    imagem = IMG_Load(caminho);
    textura = SDL_CreateTextureFromSurface(ren, imagem);

    if (!imagem) {
        std::cerr << "Erro ao carregar a imagem: " << IMG_GetError() << std::endl;
        return;
    }

    SDL_RenderCopy(ren, textura, NULL, NULL);
    
}