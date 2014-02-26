#ifndef PIPES_H
#define PIPES_H

#include <list>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Vector.hpp"

class Pipes
{
  static const float	VerticalPipeSpacing;
  static const float	HorizontalPipePositionLimit;
  static const float	HorizontalSpeed;

public:
  typedef struct {
    Vect2f	pos;
    bool	upwards;
  } Pipe;

public:
  Pipes();
  ~Pipes();

public:
  void				update(float dt);
  const std::list<Pipe>&	getPipes() const;

private:
  void	genPipe(float x);

private:
  sf::Texture		_pipeTex[2];
  sf::Sprite		_pipeSp[2];
  std::list<Pipe>	_pipes;
};

#endif // PIPES_H
