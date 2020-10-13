#include "command.h"
#include "Player.h"
#include "Enemy.h"
#include<iostream>
#include <vector>
#include<algorithm>




namespace {

	void cross_attack(Player player, Enemy enemy) 
	{
		// Max is there to avoid giving health point in case too high defence.
		player.SetHealthPoints(player.GetHealthPoints() - std::max(0, enemy.GetAttack() - player.GetDefence())); //A séparer pour l'attaque du joueur et l'une des action tick du mob
		enemy.SetHealthPoints(enemy.GetHealthPoints() - std::max(0, player.GetAttack() - enemy.GetDefence()));
		set_player(player);
		set_enemy(enemy, enemy.GetX(), enemy.GetY());
	}

}

void north()
{
	Player player = get_player();
	// Get the location at north of the current player.
	TileType tile_type = get_tile_at_position(player.GetX(), player.GetY() - 1);
	// If the location is not empty do NOTHING!
	if (tile_type != TileType::EMPTY)
		return;
	player.SetY(player.GetY() - 1);
	set_player(player);
}

void south()
{
	// TODO complete me!
	Player player = get_player();
	TileType tile_type = get_tile_at_position(player.GetX(), player.GetY() + 1);
	if (tile_type != TileType::EMPTY)
	{
		return;
	}
	player.SetX(player.GetX() + 1);
	set_player(player);
}

void east()
{
	// TODO complete me!
	Player player = get_player();
	TileType tile_type = get_tile_at_position(player.GetX() + 1, player.GetY());
	if (tile_type != TileType::EMPTY)
		return;
	player.SetY(player.GetY() + 1);
	set_player(player);
}

void west()
{
	// TODO complete me!
	Player player = get_player();
	TileType tile_type = get_tile_at_position(player.GetX() - 1, player.GetY());
	if (tile_type != TileType::EMPTY)
		return;
	player.SetX(player.GetX() - 1);
	set_player(player);
}

void attack()
{
	Player player = get_player();
	Enemy enemy = get_enemy(player.GetX(), player.GetY());
	std::vector<Enemy> enemy_vec;
	// for now only attack enemy that are in strait line +.
	if (TileType::ENEMY == get_tile_at_position(player.GetY(), player.GetY() - 1))
		enemy_vec.push_back(get_enemy(player.GetX(), player.GetY() - 1));
	{

	}
	if (TileType::ENEMY == get_tile_at_position(player.GetX(), player.GetY() + 1))
		enemy_vec.push_back(get_enemy(player.GetX(), player.GetY() + 1));
	{

	}
	if (TileType::ENEMY == get_tile_at_position(player.GetX() - 1, player.GetY()))
		enemy_vec.push_back(get_enemy(player.GetX() - 1, player.GetY()));
	{

	}
	if (TileType::ENEMY == get_tile_at_position(player.GetX() + 1, player.GetY()))
		enemy_vec.push_back(get_enemy(player.GetX() + 1, player.GetY()));
	{

	}
	for (const auto& enemy : enemy_vec)
		cross_attack(player, enemy);
	{

	}

}

void tick()
{
	// FIXME Suppose to have enemy moving soon(tm).
	// Life regen.
	Player player = get_player();
	player.SetHealthPoints(player.GetHealthPoints() + player.GetHealthRegen();
	player.SetHealthPoints(player.GetHealthPoints() =
		std::min(player.GetHealthPoints(), player.GetMaxHealthPoints());
}
