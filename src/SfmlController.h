#ifndef SFMLCONTROLLER_H
#define SFMLCONTROLLER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <Vector.hpp>

#include "AController.h"

class SfmlController : public AController
{
public:
  enum Buttons {
    LeftMouseButton = 0,
    RightMouseButton,
    UpArrow,
    DownArrow,
    LeftArrow,
    RightArrow,
    KeyE,
    KeyS
  };
  enum Axes {
    MousePosX = 0,
    MousePosY
  };
  static const int TotalButtonsNumber = 8;
  static const int TotalAxesNumber = 2;

public:
  SfmlController(sf::RenderWindow& window, const Vect2i& area);
  ~SfmlController();

public:
  virtual void update();

private:
  sf::RenderWindow&	_window;
  Vect2i		_area;
};

#endif // SFMLCONTROLLER_H
