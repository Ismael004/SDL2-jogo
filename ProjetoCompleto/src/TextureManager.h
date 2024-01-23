#pragma once

#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager
{
public:

       static TextureManager* Instance()
       {
              if (instance == 0)
              {
                     instance = new TextureManager();
              }

              return instance;
       }

       bool load(std::string fileName, std::string id, SDL_Renderer* renderer);

       void draw(std::string id, int x, int y, int w, int h, double scale, double r, SDL_Renderer* renderer, 
            SDL_RendererFlip flip = SDL_FLIP_NONE);

       void drawFrame(std::string id, int x, int y, int w, int h, double scale, int currentRow, int currentFrame, double r, 
            SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

       void clearFromTextureMap(std::string id);

       std::map<std::string, SDL_Texture*> textureMap;

private:

       static TextureManager* instance;

       TextureManager(){}
       ~TextureManager(){}

};

typedef TextureManager _TextureManager;