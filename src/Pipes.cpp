#include <iostream>
#include <ctime>

#include "Pipes.h"
#include "Vector.hpp"

const float Pipes::VerticalPipeSpacing = 250.0f;
const float Pipes::HorizontalSpeed = -400.0f;
const float Pipes::HorizontalPipePositionLimit = -64.0f;
const float Pipes::ProcTimeInterval = 0.8f;

Pipes::Pipes()
: _t(0.0f),
  _score(0)
{
  if (!_pipeTex[0].loadFromFile("rc/pipe2.png"))
    std::cerr << "Error: could not load texture" << std::endl;
  if (!_pipeTex[1].loadFromFile("rc/pipe.png"))
    std::cerr << "Error: could not load texture" << std::endl;

  for (int i = 0; i < 2; ++i)
    _pipeSp[i].setTexture(_pipeTex[i]);

  srand(time(0));
}

Pipes::~Pipes() {}

void Pipes::update(float dt)
{
  _t += dt;
  if (_t > ProcTimeInterval)
  {
    _t = 0;
    genPipe(rand() % VerticalPipeRange - 300);
  }

  for (std::list<Pipe>::iterator it = _pipes.begin(); it != _pipes.end();)
  {
    it->pos = it->pos + Vect2f(HorizontalSpeed, 0.0f) * dt;

    if (it->pos[0] < HorizontalPipePositionLimit)
    {
      it = _pipes.erase(it);
      if (it->upwards)
	++_score;
    }
    else
      ++it;
  }
}

void Pipes::reset()
{
  _score = 0;
  _t = 0.0f;
  _pipes.clear();
}

bool Pipes::isColliding(const PBox& player) const
{
  PBox	box(Vect2f(0.0f));

  for (std::list<Pipes::Pipe>::const_iterator it = _pipes.begin(); it != _pipes.end(); ++it)
  {
    sf::Vector2u s = _pipeTex[((it->upwards) ? (0) : (1))].getSize();
    box.setSize(Vect2f(s.x, s.y));
    box.setPosition(it->pos);
    if (box.isColliding(player))
      return (true);
  }
  return (false);
}

void Pipes::draw(sf::RenderWindow& window)
{
  for (std::list<Pipes::Pipe>::const_iterator it = _pipes.begin(); it != _pipes.end(); ++it)
  {
    sf::Sprite& sp = ((it->upwards) ? (_pipeSp[0]) : (_pipeSp[1]));

    sp.setPosition(it->pos[0], it->pos[1]);
    window.draw(sp);
  }
}

const std::list< Pipes::Pipe >& Pipes::getPipes() const
{
  return (_pipes);
}

void Pipes::genPipe(float x)
{
  Pipe	pipes[2];

  pipes[0].pos = Vect2f(1000.0f, x);
  pipes[0].upwards = true;
   pipes[1].pos = pipes[0].pos + Vect2f(10.0f, VerticalPipeSpacing + _pipeTex[0].getSize().y);
  pipes[1].upwards = false;

  _pipes.push_back(pipes[0]);
  _pipes.push_back(pipes[1]);
}

int Pipes::getScore() const
{
  return (_score);
}
