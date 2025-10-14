
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

	if (!passports[1].loadFromFile("../Data/Images/Critter Crossing Customs/penguin passport.png"))
	{
		std::cout << "passport 2 did not load\n";
	}
	if (!passports[2].loadFromFile("../Data/Images/Critter Crossing Customs/elephant passport.png"))
	{
		std::cout << "passport 3 did not load\n";
	}
	
	background.initialiseSprite(background_texture, "../Data/WhackaMole Worksheet/background.png");

	acceptbutton.initialiseSprite(acceptbutton_texture, "../Data/Images/Critter Crossing Customs/accept button.png");
	acceptbutton.getSprite()->setScale(0.8, 0.8);
	acceptbutton.getSprite()->setPosition(window.getSize().x / 2, window.getSize().y / 4.8);

	rejectbutton.initialiseSprite(rejectbutton_texture, "../Data/Images/Critter Crossing Customs/reject button.png");
	rejectbutton.getSprite()->setScale(0.8, 0.8);
	rejectbutton.getSprite()->setPosition(window.getSize().x / 1.3, window.getSize().y / 4.8);


  return true;
}

void Game::update(float dt)
{
	if (change == true)
	{
		newAnimal();
	}
	if (dragged)
	{
		dragSprite(passport.getSprite());
	}

}

void Game::render()
{
	window.draw(*background.getSprite());
    window.draw(*character.getSprite());
	window.draw(*passport.getSprite());
	window.draw(*acceptbutton.getSprite());
	window.draw(*rejectbutton.getSprite());



}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
  sf::Vector2f clickf = static_cast<sf::Vector2f>(click);

  if (passport.getSprite()->getGlobalBounds().contains(clickf))
  {
	  dragged = passport.getSprite();
	  
	  std::cout << "clicked\n"; 
  }
}

void Game::mouseReleased(sf::Event event)
{
	dragged = nullptr;
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
	character.getSprite()->setScale(1, 1);
	character.getSprite()->setPosition(window.getSize().x /12, window.getSize().y / 12);
	
	passport.getSprite()->setTexture(passports[passport_index], true);
	passport.getSprite()->setScale(0.6, 0.6);
	passport.getSprite()->setPosition(window.getSize().x / 2, window.getSize().y / 3);
	change = false;

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

void Game::dragSprite(sf::Sprite* sprite)
{
	if (sprite != nullptr)
	{
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		sf::Vector2f mouse_positionf = static_cast<sf::Vector2f>(mouse_position);

		sf::Vector2f drag_position = mouse_positionf;
		sprite->setPosition(drag_position.x, drag_position.y);
	}
}

bool Game::mouseDetection(sf::Vector2i click, sf::Sprite sprite)
{
	if (
		//determines if the sprite has been clicked or not
		click.x > sprite.getPosition().x &&
		click.x < sprite.getPosition().x + sprite.getGlobalBounds().width &&
		click.y > sprite.getPosition().y &&
		click.y < sprite.getPosition().y + sprite.getGlobalBounds().height)
	{
		
		return true;
	}
	return false;
}