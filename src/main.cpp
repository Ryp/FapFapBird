#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "PBox.h"
#include "Joystick/SfmlController.h"
#include "Pipes.h"

int	main(int ac, char** av)
{
  static_cast<void>(ac);
  static_cast<void>(av);

  Player	bird;
  Pipes		pipes;

  bird.setPosition(Vect2f(100.0f, 0.0f));

  sf::RenderWindow window(sf::VideoMode(800, 600), "FapFapBird");
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);

  SfmlController	controller(window, Vect2i());

  sf::Font font;
  if (!font.loadFromFile("rc/font.ttf"))
    return (1);

  sf::Text	scoreText("Text", font);
  scoreText.setCharacterSize(30);

  sf::Texture	flapTex;
  if (!flapTex.loadFromFile("rc/flapflap.jpg"))
    return (1);

  sf::Sprite	flapSp(flapTex);

  flapSp.setOrigin(32.0f, 32.0f);

  PBox		playerBox(Vect2f(32.0f, 32.0f));

  sf::Clock	clock;
  sf::Time	dt;

  clock.restart();
  while (window.isOpen())
  {
    sf::Event	event;

    //User input
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	window.close();
    }
    if (controller.isPressed(SfmlController::Esc))
      window.close();
    // Gamelogic

    controller.update();

    dt = clock.getElapsedTime();
    clock.restart();

    Vect2f accel;
    accel += Vect2f(0.0f, 55.0f); // La gravité c'est génial.
    if (controller.isPressed(SfmlController::UpArrow))
    {
      bird.setSpeed(Vect2f());
      accel += Vect2f(0.0f, -900.0f); // Je FLAPFLAP donc je vole.
    }

    pipes.update(dt.asSeconds());

    bird.setAccel(accel);
    bird.update(dt.asSeconds());
    playerBox.setPosition(bird.getPosition() - Vect2f(16.0f, 16.0f));

    if (pipes.isColliding(playerBox) || bird.getPosition()[1] < 0 || bird.getPosition()[1] > 600)
    {
      bird.setPosition(Vect2f(100.0f, 0.0f));
      bird.setSpeed(Vect2f());
      bird.setAccel(Vect2f());
      pipes.reset();
      continue;
    }

    float rotAmount = -bird.getSpeed()[1] * 4.0f;

    flapSp.setRotation(- rotAmount);
    flapSp.setPosition(bird.getPosition()[0], bird.getPosition()[1]);

    // Render
    window.clear(sf::Color::Blue);
    pipes.draw(window);
    window.draw(flapSp);

    std::ostringstream	oss;

    oss << "Score: ";
    oss << pipes.getScore();
    scoreText.setString(oss.str());

    window.draw(scoreText);
    window.display();
  }
  return (0);
}
