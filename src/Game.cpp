
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{
	delete[] animals;
	delete[] passports;
	
}

bool Game::init()
{
	if (!font.loadFromFile("../Data/Fonst/OpenSans-Bold.ttf"))
	{
		std::cout << "font did not load\n";
	}

	//initalising animal sprites
	if (!animals[0].loadFromFile("../Data/Images/Critter Crossing Customs/moose.png"))
	{
		std::cout << "animal 1 did not load\n";
	}
	
	if (!animals[1].loadFromFile("../Data/Images/Critter Crossing Customs/penguin.png"))
	{
		std::cout << "animal 2 did not load\n";
	}

	if (!animals[2].loadFromFile("../Data/Images/Critter Crossing Customs/elephant.png"))
	{
		std::cout << "animal 3 did not load\n";
	}
	
	//initalising passports
	if (!passports[0].loadFromFile("../Data/Images/Critter Crossing Customs/moose passport.png"))
	{
		std::cout << "passport 1 did not load\n";
	}

	if (!passports[0].loadFromFile("../Data/Images/Critter Crossing Customs/penguin passport.png"))
	{
		std::cout << "passport 2 did not load\n";
	}
	if (!passports[0].loadFromFile("../Data/Images/Critter Crossing Customs/elephant passport.png"))
	{
		std::cout << "passport 3 did not load\n";
	}
	
		
		
			
		
	

	
	background.initialiseSprite(background_texture, "../Data/WhackaMole Worksheet/background.png");


	


  return true;
}

void Game::update(float dt)
{
	if (change == false)
	{
		newAnimal();
	}
	
}

void Game::render()
{
	window.draw(*background.getSprite());
    window.draw(*character.getSprite());
	window.draw(*passport.getSprite());
	




}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{

}

void Game::newAnimal()
{
	bool passport_accept = false;
	bool passport_rejected = false;

	
	int animal_index = rand() % 3;
	int passport_index = rand() % 3;
	std::cout << animal_index;

	if (passport_index == animal_index)
	{
		should_accept = true;
	}
	else
	{
		should_accept = false;
	}
	character.getSprite()->setTexture(animals[animal_index], true);
	character.getSprite()->setScale(1.8, 1.8);
	character.getSprite()->setPosition(window.getSize().x /12, window.getSize().y / 12);
	
	passport.getSprite()->setTexture(passports[passport_index], true);
	passport.getSprite()->setScale(0.6, 0.6);
	passport.getSprite()->setPosition(window.getSize().x / 2, window.getSize().y / 3);


}


bool Game::ui(sf::Vector2i click, sf::Text icon)
{
	//detection for the mouse and the UI
	if (
		click.x > icon.getPosition().x &&
		click.x < icon.getPosition().x + icon.getGlobalBounds().width &&
		click.y > icon.getPosition().y &&
		click.y < icon.getPosition().y + icon.getGlobalBounds().height)
	{
		return true;
	}
	return false;
}

void Game::gamestate()
{

}