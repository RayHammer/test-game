#include "TextureManager.h"

TextureManager::TextureManager() {

}

TextureManager::~TextureManager() {

}

bool TextureManager::load(const string &path) {
    auto &texture = this->textures[path];
    return texture.loadFromFile(path);
}

Texture &TextureManager::getTexture(const string &path) {
    auto &m = this->textures;
    auto entry = m.find(path);

    if (entry != m.end()) {
        return entry->second;
    } else {
        load(path);
        return m[path];
    }
}