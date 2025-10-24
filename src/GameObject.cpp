#include "GameObject.h"

GameObject::GameObject()
{
    sprite = std::make_unique<sf::Sprite>();
}

GameObject::~GameObject()
{

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

std::shared_ptr<sf::Sprite> GameObject::getSprite()
{
    return sprite;
}