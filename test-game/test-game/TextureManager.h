#pragma once
#include "Headers.h"
#include "ResourceManager.h"

class TextureManager : public ResourceManager<TextureManager, Texture> {
public:
    TextureManager();
    ~TextureManager();
    Texture &getTexture(const std::string &path);
    bool load(const string &path);
private:
    std::map <string, Texture> textures;
};