#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "SfmlController.h"

SfmlController::SfmlController(sf::RenderWindow& window, const Vect2i& area)
: AController(TotalButtonsNumber, TotalAxesNumber),
  _window(window),
  _area(area)
{
  update();
  AController::reset();
}

SfmlController::~SfmlController() {}

void SfmlController::update()
{
  sf::Vector2i mouse = sf::Mouse::getPosition(_window);

  _axes[MousePosX] = mouse.x;
  _axes[MousePosY] = mouse.y;
  _buttons[LeftMouseButton].new_held = false;
  _buttons[RightMouseButton].new_held = false;
  if (mouse.x >= 0 && mouse.x < _area[0] && mouse.y >= 0 && mouse.y < _area[1])
  {
    _buttons[LeftMouseButton].new_held = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    _buttons[RightMouseButton].new_held = sf::Mouse::isButtonPressed(sf::Mouse::Right);
  }
  _buttons[UpArrow].new_held = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
  _buttons[DownArrow].new_held = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
  _buttons[LeftArrow].new_held = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
  _buttons[RightArrow].new_held = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
  _buttons[KeyE].new_held = sf::Keyboard::isKeyPressed(sf::Keyboard::E);
  _buttons[KeyS].new_held = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
  AController::update();
}
