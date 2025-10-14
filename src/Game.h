
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void gamestate();

 private:
  bool ui(sf::Vector2i click, sf::Text icon);
  void newAnimal();
  bool should_accept = false;
  bool change = true;
  

  sf::RenderWindow& window;
  sf::Font font;

  sf::Sprite ball;
  sf::Texture ball_texture;
  sf::Text title;
  sf::Text play_option;
  sf::Text exit_option;

  GameObject character;
  sf::Texture* animals = new sf::Texture[3];
  

  GameObject passport;
  sf::Texture* passports = new sf::Texture[3];
  sf::Texture passport_texture;
  
  GameObject background;
  sf::Texture background_texture;
  
  
 
 

};

#endif // PLATFORMER_GAME_H
