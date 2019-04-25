#include "Player.h"

using namespace sf;

Player::Player() {
    sprite = Sprite(TextureManager::getInstance().getTexture("Assets/Textures/default.png"));
    sprite.setPosition(Vector2f(32.f, 32.f));
}

Player::~Player() {

}

void Player::update(sf::Time dt) {

}

void Player::draw(RenderTarget& target, RenderStates states) const {
    target.draw(sprite, states);
}