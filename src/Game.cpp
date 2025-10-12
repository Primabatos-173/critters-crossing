
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{
	
	
}

bool Game::init()
{
	if (!font.loadFromFile("../Data/Fonst/OpenSans-Bold.ttf"))
	{
		std::cout << "font did not load";
	}

	//initalising animal sprites
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			animals[i].initialiseSprite(character_texture, "../Data/Images/Critter Crossing Customs/gorilla.png");
			std::cout << "animal 1 loaded\n";
		}
		if (i == 1)
		{
			animals[i].initialiseSprite(character_texture, "../Data/Images/Critter Crossing Customs/giraffe.png");
			std::cout << "animal 2 loaded\n";
		}
		if (i == 2)
		{
			animals[i].initialiseSprite(character_texture, "../Data/Images/Critter Crossing Customs/elephant.png");
			std::cout << "animal 3 loaded\n";
		}
		
	}

	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			passports[i].initialiseSprite(passport_texture, "../Data/Images/Critter Crossing Customs/default passport.png");
			std::cout << "passport 1 loaded\n";
		}
		if (i == 1)
		{
			passports[i].initialiseSprite(passport_texture, "../Data/Images/Critter Crossing Customs/default passport.png");
			std::cout << "passport 2 loaded\n";
		}
		if (i == 2)
		{
			passports[i].initialiseSprite(passport_texture, "../Data/Images/Critter Crossing Customs/default passport.png");
			std::cout << "passport 3 loaded\n";
		}
	}


  return true;
}

void Game::update(float dt)
{
	
}

void Game::render()
{
	
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{

}


