#ifndef PBOX_H
#define PBOX_H

#include "Vector.hpp"

class PBox
{
public:
  PBox(const Vect2f& size, const Vect2f& position = Vect2f());
  ~PBox();

public:
  const Vect2f&	getSize() const;
  void		setSize(const Vect2f& size);
  const Vect2f&	getPosition() const;
  void		setPosition(const Vect2f& position);
  bool		isColliding(const PBox& other);

private:
  Vect2f	_size;
  Vect2f	_position;
};

#endif // PBOX_H
