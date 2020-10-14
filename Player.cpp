#include "Player.h"

int Player::GetMaxHealthPoints()
{
	return max_health_points_;
}

int Player::GetExpercience()
{
	return experience_;
}

int Player::GetHealthRegen()
{
	return health_regen_;
}


int Character::GetHealthPoints()
{
	return health_points_;
}

void Character::SetHealthPoints(int health_points)
{
	health_points_ = health_points;
}