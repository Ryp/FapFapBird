#ifndef PLAYER_H
#define PLAYER_H

#include "Vector.hpp"

class Player
{
public:
  Player();
  ~Player();

public:
  void		update(float t);
  const Vect2f&	getPosition() const;
  void		setPosition(const Vect2f& position);
  const Vect2f&	getSpeed() const;
  void		setSpeed(const Vect2f& speed);
  const Vect2f&	getAccel() const;
  void		setAccel(const Vect2f& accel);

private:
  Vect2f	_pos;
  Vect2f	_speed;
  Vect2f	_accel;
};

#endif // PLAYER_H
