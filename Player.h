#pragma once
#include "Character.h"
#include <string>


class Player : public Character
{
	/*int x = 22;
	int y = 1;
	int health_points = 100;
	int attack = 20;
	int defence = 5;*/
public:
	Player(int max_health_points_,
		int experience_,
		int health_regen_
			);
	int GetMaxHealthPoints();
	int GetExpercience();
	int GetHealthRegen();

protected :
	int max_health_points_; //= 100;
	std::string name = "The Hero";
	int experience_; // = 0;
	int health_regen_; //= 5;

};

void set_player(Player player);
Player get_player();
