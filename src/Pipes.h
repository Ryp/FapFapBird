#ifndef PIPES_H
#define PIPES_H

#include <list>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Vector.hpp"
#include "PBox.h"

class Pipes
{
  static const int	VerticalPipeRange = 300;
  static const float	VerticalPipeSpacing;
  static const float	HorizontalPipePositionLimit;
  static const float	HorizontalSpeed;
  static const float	ProcTimeInterval;

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
  void				reset();
  bool				isColliding(const PBox& player) const;
  void				draw(sf::RenderWindow& window);
  const std::list<Pipe>&	getPipes() const;
  int				getScore() const;

private:
  void	genPipe(float x);

private:
  sf::Texture		_pipeTex[2];
  sf::Sprite		_pipeSp[2];
  std::list<Pipe>	_pipes;
  float			_t;
  int			_score;
};

#endif // PIPES_H
