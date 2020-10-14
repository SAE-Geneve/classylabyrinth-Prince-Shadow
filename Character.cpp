#include "Character.h"

int Character::GetX()
{
	return x_;
}

void Character::SetX(int x)
{
	x_ = x;
}

int Character::GetY()
{
	return y_;
}

void Character::SetY(int y)
{
	y_ = y;
}

int Character::GetHealthPoints()
{
	return health_points_;
}

void Character::SetHealthPoints(int health_points)
{
	health_points_ = health_points;
}

int Character::GetAttack()
{
	return attack_;
}

void Character::SetAttack(int attack)
{
	attack_ = attack;
}

int Character::GetDefence()
{
	return defence_;
}

void Character::SetDefence(int defence)
{
	defence_ = defence;
}