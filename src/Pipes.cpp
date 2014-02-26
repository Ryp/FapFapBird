#include <iostream>

#include "Pipes.h"
#include "Vector.hpp"

const float Pipes::VerticalPipeSpacing = 400.0f;
const float Pipes::HorizontalSpeed = -20.0f;
const float Pipes::HorizontalPipePositionLimit = -64.0f;

Pipes::Pipes()
{
  if (!_pipeTex[0].loadFromFile("rc/pipe2.png"))
    std::cout << "Error: could not load texture" << std::endl;
  if (!_pipeTex[1].loadFromFile("rc/pipe.png"))
    std::cout << "Error: could not load texture" << std::endl;

  for (int i = 0; i < 2; ++i)
    _pipeSp[0].setTexture(_pipeTex[0]);
}

Pipes::~Pipes() {}

void Pipes::update(float dt)
{
  for (std::list<Pipe>::iterator it = _pipes.begin(); it != _pipes.end();)
  {
    it->pos += Vect2f(HorizontalSpeed, 0.0f) * dt;

    if (it->pos[0] < HorizontalPipePositionLimit)
      it = _pipes.erase(it);
    else
      ++it;
  }
}

const std::list< Pipes::Pipe >& Pipes::getPipes() const
{
  return (_pipes);
}

void Pipes::genPipe(float x)
{
  Pipe	newPipe[2];

  newPipe[0].pos = Vect2f(1000.0f, x);
  newPipe[0].upwards = true;
  newPipe[1].pos = newPipe[0].pos + Vect2f(0.0f, VerticalPipeSpacing);
  newPipe[1].upwards = false;

  _pipes.push_back(newPipe[0]);
  _pipes.push_back(newPipe[1]);
}
