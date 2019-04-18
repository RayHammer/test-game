#pragma once

#include "ResourceManager.h"
#include <SFML/Graphics.hpp>
#include <map>

using namespace std;
using namespace sf;

class TextureManager : public ResourceManager<Texture>
{
public:
    TextureManager();
    ~TextureManager();
    Texture& getTexture(const std::string & path);
    bool load(const string & path);
private:
    std::map <string, Texture> textures;
};