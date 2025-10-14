
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
  void mouseReleased(sf::Event event);
  void keyPressed(sf::Event event);
  void dragSprite(sf::Sprite* sprite);
  bool mouseDetection(sf::Vector2i click, sf::Sprite sprite);

 private:
  bool ui(sf::Vector2i click, sf::Text icon);
  void newAnimal();
  bool should_accept = false;
  bool change = true;
  sf::Sprite* dragged = nullptr;

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
  
  GameObject acceptbutton;
  sf::Texture acceptbutton_texture;

  GameObject rejectbutton;
  sf::Texture rejectbutton_texture;
 
 

};

#endif // PLATFORMER_GAME_H
