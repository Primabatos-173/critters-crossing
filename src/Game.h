
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <vector>

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
  void dragSprite(std::shared_ptr<sf::Sprite> sprite);
  bool mouseDetection(sf::Vector2i click, sf::Sprite sprite);
  


 private:
  bool ui(sf::Vector2i click, sf::Text icon);
  bool dropbox_collision();
  void newAnimal();
  void respawn();
  
  bool should_accept = false;
  bool change = true;
  bool accept_stamped = false;
  bool reject_stamped = false;
  bool in_game = false;
  bool win = false;
  bool loose = false;

  int correct_score = 0;
  int wrong_score = 0;

std::shared_ptr<sf::Sprite> dragged = nullptr;

  sf::RenderWindow& window;
  sf::Font font;

  sf::Text title;
  sf::Text play_option;
  sf::Text exit_option;

  sf::RectangleShape drop_box;
  sf::Sprite ball;
  sf::Texture ball_texture;

  sf::Text correct;
  sf::Text correct_num;
  sf::Text wrong;
  sf::Text wrong_num;
  sf::Text win_text;
  sf::Text loose_text;


  GameObject character;
  using animalvector = std::vector <sf::Texture>;
  animalvector animals;
  //sf::Texture* animals = new sf::Texture[5];
 

  GameObject passport;
  using passportvector = std::vector <sf::Texture>;
  passportvector passports;
  //sf::Texture* passports = new sf::Texture[5];
  
  
  GameObject background;
  sf::Texture background_texture;
  
  GameObject acceptbutton;
  sf::Texture acceptbutton_texture;

  GameObject rejectbutton;
  sf::Texture rejectbutton_texture;
 
  GameObject accept;
  sf::Texture accept_texture;

  GameObject reject;
  sf::Texture reject_texture;

};

#endif // PLATFORMER_GAME_H
