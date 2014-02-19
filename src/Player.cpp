#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::update(float t)
{
  _speed += _accel * t;
  _pos += _speed;
}

const Vect2f& Player::getPosition() const
{
  return (_pos);
}

void Player::setPosition(const Vect2f& position)
{
  _pos = position;
}

const Vect2f& Player::getSpeed() const
{
  return (_speed);
}

void Player::setSpeed(const Vect2f& speed)
{
  _speed = speed;
}

const Vect2f& Player::getAccel() const
{
  return (_accel);
}

void Player::setAccel(const Vect2f& accel)
{
  _accel = accel;
}
