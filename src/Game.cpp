
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{
	animals.clear();
	passports.clear();

	
}

bool Game::init()
{
	title.setString("Critters Crossing");
	title.setFont(font);
	title.setCharacterSize(80);
	title.setFillColor(sf::Color::White);
	title.setPosition(220, 90);

	play_option.setString("Start");
	play_option.setFont(font);
	play_option.setCharacterSize(60);
	play_option.setFillColor(sf::Color::Green);
	play_option.setPosition(460, 300);

	exit_option.setString("Exit");
    exit_option.setFont(font);
	exit_option.setCharacterSize(60);
	exit_option.setFillColor(sf::Color::Red);
	exit_option.setPosition(460, 400);

	win_text.setString("        You got promoted!\n for being good at your job!");
	win_text.setFont(font);
	win_text.setCharacterSize(60);
	win_text.setFillColor(sf::Color::White);
	win_text.setPosition(150, 90);

	loose_text.setString("          You're fired!\n for sucking at your job!");
	loose_text.setFont(font);
	loose_text.setCharacterSize(60);
	loose_text.setFillColor(sf::Color::White);
	loose_text.setPosition(200, 90);


	if (!font.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cout << "font did not load\n";
	}

	animals.reserve(5);


	//initalising animal sprites
	animals.emplace_back();
	if (!animals[0].loadFromFile("../Data/Images/Critter Crossing Customs/moose.png"))
	{
		std::cout << "animal 1 did not load\n";
	}
	animals.emplace_back();
	if (!animals[1].loadFromFile("../Data/Images/Critter Crossing Customs/penguin.png"))
	{
		std::cout << "animal 2 did not load\n";
	}
	animals.emplace_back();
	if (!animals[2].loadFromFile("../Data/Images/Critter Crossing Customs/elephant.png"))
	{
		std::cout << "animal 3 did not load\n";
	}
	animals.emplace_back();
	if (!animals[3].loadFromFile("../Data/WhackaMole Worksheet/ball.png"))
	{
		std::cout << "animal 4 did not load\n";
	}
	animals.emplace_back();
	if (!animals[4].loadFromFile("../Data/WhackaMole Worksheet/bird.png"))
	{
		std::cout << "animal 5 did not load\n";
	}

	passports.reserve(5);
	
	//initalising passports
	passports.emplace_back();
	if (!passports[0].loadFromFile("../Data/Images/Critter Crossing Customs/moose passport.png"))
	{
		std::cout << "passport 1 did not load\n";
	}

	passports.emplace_back();
	if (!passports[1].loadFromFile("../Data/Images/Critter Crossing Customs/penguin passport.png"))
	{
		std::cout << "passport 2 did not load\n";
	}

	passports.emplace_back();
	if (!passports[2].loadFromFile("../Data/Images/Critter Crossing Customs/elephant passport.png"))
	{
		std::cout << "passport 3 did not load\n";
	}

	passports.emplace_back();
	if (!passports[3].loadFromFile("../Data/Images/Critter Crossing Customs/ball passport.png"))
	{
		std::cout << "passport 4 did not load\n";
	}

	passports.emplace_back();
	if (!passports[4].loadFromFile("../Data/Images/Critter Crossing Customs/red passport.png"))
	{
		std::cout << "passport 5 did not load\n";
	}
	
	background.initialiseSprite(background_texture, "../Data/Images/Critter Crossing Customs/background.png");

	acceptbutton.initialiseSprite(acceptbutton_texture, "../Data/Images/Critter Crossing Customs/accept button.png");
	acceptbutton.getSprite()->setScale(0.8, 0.8);
	acceptbutton.getSprite()->setPosition(window.getSize().x / 2, window.getSize().y / 4.8);

	rejectbutton.initialiseSprite(rejectbutton_texture, "../Data/Images/Critter Crossing Customs/reject button.png");
	rejectbutton.getSprite()->setScale(0.8, 0.8);
	rejectbutton.getSprite()->setPosition(window.getSize().x / 1.3, window.getSize().y / 4.8);

	accept.initialiseSprite(accept_texture, "../Data/Images/Critter Crossing Customs/accept.png");
	accept.getSprite()->setScale(0.8, 0.8);

	reject.initialiseSprite(reject_texture, "../Data/Images/Critter Crossing Customs/reject.png");
	reject.getSprite()->setScale(0.8, 0.8);

	//initalising drop box
	drop_box.setSize(sf::Vector2f(450, 450));
	drop_box.setFillColor(sf::Color (202, 202, 202));
	drop_box.setPosition(50, 300);

	correct.setString("correct:     /10");
	correct.setFont(font);
	correct.setCharacterSize(30);
	correct.setFillColor(sf::Color::Black);
	correct.setPosition(550, 40);

	correct_num.setString("0");
	correct_num.setFont(font);
	correct_num.setCharacterSize(30);
	correct_num.setFillColor(sf::Color::Black);
	correct_num.setPosition(680, 40);

	wrong.setString("wrong:     /5");
	wrong.setFont(font);
	wrong.setCharacterSize(30);
	wrong.setFillColor(sf::Color::Black);
	wrong.setPosition(800, 40);

	wrong_num.setString("0");
	wrong_num.setFont(font);
	wrong_num.setCharacterSize(30);
	wrong_num.setFillColor(sf::Color::Red);
	wrong_num.setPosition(920, 40);


  return true;
}

void Game::update(float dt)
{
	if (in_game) 
	{
		if (change == true)
		{
			newAnimal();
		}
		if (dragged)
		{
			dragSprite(passport.getSprite());
		}

		if (accept_stamped)
		{
			accept.getSprite()->setPosition(passport.getSprite()->getPosition().x, passport.getSprite()->getPosition().y);
		}

		if (reject_stamped)
		{
			reject.getSprite()->setPosition(passport.getSprite()->getPosition().x, passport.getSprite()->getPosition().y);
		}

		if (change == true)
		{
			newAnimal();
		}
		correct_num.setString(std::to_string(correct_score));
		wrong_num.setString(std::to_string(wrong_score));
		
		if (correct_score == 10)
		{
			in_game = false;
			win = true;
			respawn();
		}

		if (wrong_score == 5)
		{
			in_game = false;
			loose = true;
			respawn();
		}


	}

}

void Game::render()
{
	if (win == true)
	{
		window.draw(win_text);
	}
	else if (loose == true)
	{
		window.draw(loose_text);
	}
	else
	{
		window.draw(title);
	}
	window.draw(play_option);
	window.draw(exit_option);


	if (in_game) 
	{
		window.draw(*background.getSprite());
		window.draw(drop_box);
		window.draw(*passport.getSprite());
		
		if (accept_stamped)
		{
			window.draw(*accept.getSprite());
		}
		
		if (reject_stamped)
		{
			window.draw(*reject.getSprite());
		}
		
		window.draw(*character.getSprite());
		window.draw(*acceptbutton.getSprite());
		window.draw(*rejectbutton.getSprite());
		window.draw(correct);
		window.draw(correct_num);
		window.draw(wrong);
		window.draw(wrong_num);

	}

}

void Game::mouseClicked(sf::Event event)
{
	//get the click position
	sf::Vector2i click = sf::Mouse::getPosition(window);
	sf::Vector2f clickf = static_cast<sf::Vector2f>(click);

	if (!in_game) 
	{
		if (ui(click, exit_option))
		{
			window.close();
		}

		if (ui(click, play_option))
		{
			in_game = true;
			win = false;
			loose = false;
		}
	}
	

	


	if (passport.getSprite()->getGlobalBounds().contains(clickf))
	{
		dragged = passport.getSprite();

		
	}

	if (mouseDetection(click, *acceptbutton.getSprite()))
	{
		accept_stamped = true;
		reject_stamped = false;
	}

	if (mouseDetection(click, *rejectbutton.getSprite()))
	{
		reject_stamped = true;
		accept_stamped = false;
	}
	
	

}

void Game::mouseReleased(sf::Event event)
{
	dragged = nullptr;
	if (dropbox_collision() && (accept_stamped || reject_stamped))
	{
		
		change = true;
		

		if (should_accept && accept_stamped)
		{
			correct_score = correct_score + 1;
		}
		if (!should_accept && reject_stamped)
		{
			correct_score = correct_score + 1;
		}
		if (should_accept && reject_stamped)
		{
			wrong_score = wrong_score + 1;
		}
		if (!should_accept && accept_stamped)
		{
			wrong_score = wrong_score + 1;
		}
		accept_stamped = false;
		reject_stamped = false;
		//std::cout << correct_score << "\n";
	}
}

void Game::keyPressed(sf::Event event)
{

}

void Game::newAnimal()
{
	bool passport_accept = false;
	bool passport_rejected = false;


	int animal_index = rand() % 5;
	int passport_index = rand() % 5;
	

	if (passport_index == animal_index)
	{
		should_accept = true;
	}
	else
	{
		should_accept = false;
	}
	character.getSprite()->setTexture(animals[animal_index], true);
	character.getSprite()->setScale(0.8, 0.8);
	character.getSprite()->setPosition(window.getSize().x / 12, window.getSize().y / 12);

	passport.getSprite()->setTexture(passports[passport_index], true);
	passport.getSprite()->setScale(0.6, 0.6);
	passport.getSprite()->setPosition(window.getSize().x / 2, window.getSize().y / 2.5);
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

void Game::respawn()
{
	correct_score = 0;
	wrong_score = 0;
	correct_num.setString("0");
	wrong_num.setString("0");
	newAnimal();
}




bool Game::dropbox_collision()
{
	if (
		passport.getSprite()->getPosition().x >
		drop_box.getPosition().x &&
		passport.getSprite()->getPosition().x <
		drop_box.getPosition().x +
		drop_box.getGlobalBounds().width &&
		passport.getSprite()->getPosition().y >
		drop_box.getPosition().y &&
		passport.getSprite()->getPosition().y <
		drop_box.getPosition().y +
		drop_box.getGlobalBounds().height)
	{
		return true;
	}

	return false;

}

void Game::dragSprite(std::shared_ptr<sf::Sprite> sprite)
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