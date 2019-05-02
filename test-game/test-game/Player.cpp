#include "Player.h"

using namespace sf;

Player::Player() {
    sprite = Sprite(TextureManager::getInstance().getTexture("Assets/Textures/default.png"));
    sprite.setOrigin(Vector2f(16.f, 16.f));
    pos = Vector2f(48.f, 48.f);
}

Player::~Player() {

}

void Player::update(sf::Time dt) {
    int horInput = 0;
    int verInput = 0;
    if (Keyboard::isKeyPressed(key_left)) {
        horInput -= 1;
    }
    if (Keyboard::isKeyPressed(key_right)) {
        horInput += 1;
    }
    if (Keyboard::isKeyPressed(key_up)) {
        verInput -= 1;
    }
    if (Keyboard::isKeyPressed(key_down)) {
        verInput += 1;
    }

    pos.x += horInput * movSpeed * dt.asSeconds();
    pos.y += verInput * movSpeed * dt.asSeconds();

    sprite.setPosition(pos);
}

void Player::draw(RenderTarget& target, RenderStates states) const {
    target.draw(sprite, states);
}