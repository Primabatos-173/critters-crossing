
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

 private:


  sf::RenderWindow& window;
  sf::Font font;

  sf::Sprite ball;
  sf::Texture ball_texture;
  sf::Text title;
  sf::Text play_option;
  sf::Text exit_option;

  GameObject character;
  GameObject animals[3];
  sf::Texture character_texture;

  GameObject passport;
  GameObject passports[3];
  sf::Texture passport_texture;
  

  
  
 
 

};

#endif // PLATFORMER_GAME_H
