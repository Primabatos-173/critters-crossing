#include "GameObject.h"

GameObject::GameObject()
{
    sprite = new sf::Sprite();
}

GameObject::~GameObject()
{
    if (sprite != nullptr)
    {
        delete sprite;
        sprite = nullptr;
    }
}

bool GameObject::initialiseSprite(sf::Texture& texture, std::string filename)
{
    if (!texture.loadFromFile(filename))
    {
        std::cout << "file did not load\n";
        return false;
    }
    sprite->setTexture(texture);
    return true;
}

sf::Sprite* GameObject::getSprite()
{
    return sprite;
}