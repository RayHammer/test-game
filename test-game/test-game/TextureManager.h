#pragma once

#include "ResourceManager.h"
#include <SFML/Graphics.hpp>
#include <map>

using namespace std;
using namespace sf;

class TextureManager : public ResourceManager<TextureManager, Texture>
{
public:
    Texture& getTexture(const std::string & path);
    bool load(const string & path);
private:
    TextureManager();
    ~TextureManager();
    std::map <string, Texture> textures;
};