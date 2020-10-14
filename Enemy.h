#pragma once
#include "Character.h"
#include <string>


class Enemy : public Character
{
	/*int x;
	int y;
	int health_points = 50;
	int attack = 10;
	int defence = 2;*/
public :

protected :
	std::string name = "Gob";
};

void set_enemy(Enemy enemy, int x, int y);
Enemy get_enemy(int x, int y);
