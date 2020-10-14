#pragma once
#include <string>

class Character
{
public :
	Character(
		int x_,
		int y_,
		int health_points_,
		int attack_,
		int defence_
			);
	int GetX();
	void SetX(int x);
	int GetY();
	void SetY(int y);
	int GetHealthPoints();
	void SetHealthPoints(int health_points);
	int GetAttack();
	void SetAttack(int attack);
	int GetDefence();
	void SetDefence(int defence);

protected:
	int x_;	
	int y_;
	int health_points_;
	int attack_;
	int defence_;
};
