#include <iostream>

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "PBox.h"
#include "Joystick/SfmlController.h"

int	main(int ac, char** av)
{
  static_cast<void>(ac);
  static_cast<void>(av);

  Player	flap;

  flap.setPosition(Vect2f(100.0f, 0.0f));

  sf::RenderWindow window(sf::VideoMode(800, 600), "FlappyMario - Schuel_t roxxe du poney");
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);

  SfmlController	controller(window, Vect2i());

  sf::Texture	flapTex;
  sf::Texture	pipeDownTex;
  sf::Texture	pipeUpTex;

  if (!flapTex.loadFromFile("rc/flapflap.jpg"))
    return (1);
  if (!pipeDownTex.loadFromFile("rc/pipe2.png"))
    return (1);
  if (!pipeUpTex.loadFromFile("rc/pipe.png"))
    return (1);

  sf::Sprite	flapSp(flapTex);
  sf::Sprite	pipeUpSp(pipeUpTex);
  sf::Sprite	pipeDownSp(pipeDownTex);

  flapSp.setOrigin(32.0f, 32.0f);

  PBox		playerBox(Vect2f(flapTex.getSize().x, flapTex.getSize().y));
  PBox		pipeBox(Vect2f(pipeDownTex.getSize().x, pipeDownTex.getSize().y));

  while (window.isOpen())
  {
    sf::Event	event;

    //User input
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	window.close();
    }
    // Gamelogic

    controller.update();

    Vect2f accel;
    accel += Vect2f(0.0f, -50.0f); // La gravité c'est génial.
    if (controller.isPressed(SfmlController::UpArrow))
    {
      flap.setSpeed(Vect2f());
      accel += Vect2f(0.0f, 1000.0f); // Je FLAPFLAP donc je vole.
    }

    flap.setAccel(accel);
    flap.update(1.0f / 60.0f);

    float amount = flap.getSpeed()[1] * 4.0f;

    flapSp.setRotation(- amount);
    flapSp.setPosition(flap.getPosition()[0], 10 - flap.getPosition()[1]);
    // Render
    window.clear(sf::Color::Blue);
    window.draw(flapSp);
    window.display();
  }
  return (0);
}
