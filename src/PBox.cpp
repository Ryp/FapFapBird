#include "PBox.h"

PBox::PBox(const Vect2f& size, const Vect2f& position)
: _size(size),
  _position(position)
{}

PBox::~PBox() {}

const Vect2f& PBox::getSize() const
{
  return (_size);
}

void PBox::setSize(const Vect2f& size)
{
  _size = size;
}

const Vect2f& PBox::getPosition() const
{
  return (_position);
}

void PBox::setPosition(const Vect2f& position)
{
  _position = position;
}

bool PBox::isColliding(const PBox& other)
{
  bool rslt;

  rslt = ((_position[0] + _size[0]) >= other._position[0] &&
	  _position[0] <= (other._position[0] + other._size[0]) &&
	  (_position[1] + _size[1]) >= other._position[1] &&
	  _position[1] <= (other._position[1] + other._size[1]));
  return (rslt);
}
