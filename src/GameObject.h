#pragma once
#ifndef PLATFORMER_GAMEOBJECT_H
#define PLATFORMER_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class GameObject
{
public:
	GameObject();
	

	bool initialiseSprite(sf::Texture& texture, std::string filename);
	std::shared_ptr<sf::Sprite> getSprite();

	std::shared_ptr<sf::Sprite> sprite = nullptr;
	//sf::Sprite* sprite = nullptr;
};

#endif // GAMEOBJECT_H