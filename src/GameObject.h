#pragma once
#ifndef PLATFORMER_GAMEOBJECT_H
#define PLATFORMER_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class GameObject
{
public:
	GameObject();
	~GameObject();

	bool initialiseSprite(sf::Texture& texture, std::string filename);

	sf::Sprite* sprite = nullptr;
};

#endif // GAMEOBJECT_H