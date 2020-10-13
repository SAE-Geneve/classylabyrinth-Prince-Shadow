#include "tile.h"
#include "Character.h"
#include <map>
#include <cassert>
#include<iostream>


// An anonymous namespace just here so you cannot access there from somewhere
// else.
namespace {

	// Map of the local space.
	std::string local_world = 
		"########################" // 24 * 8
		"#.....E......E.....#..P#" // P is at (22, 1)
		"#######..#####..####...#"
		"#........#.............#"
		"#.E......#...E...E.....#"
		"#..##################..#"
		"#.........E............#"
		"########################";

	// Local player stuff.
	Player local_player{};
	// Map that map space to enemies.
	std::map<std::pair<int, int>, Enemy> local_enemy;

	int xy_local(int x, int y)
	{
		// We want the local array to be bound to the borders.
		if (x < 0) x = 0;
		if (x > 23) x = 23;
		if (y < 0) y = 0;
		if (y > 7) y = 7;
		// Return the position within the local world of the cursor.
		// As the array is singular dimention we use the largest value to
		// split it.
		return x + y * 24;
	}

} // End of namespace.

TileType get_tile_at_position(int x, int y)
{
							// TODO Get the tile at the location x, y in the world.
	return (TileType)local_world[xy_local(x,y)];
}

void set_enemy(Enemy enemy, int x, int y)
{
	enemy.x = x;
	enemy.y = y;
	local_enemy[{x, y}] = enemy;
		//std::cout << "empty\n";
		//local_enemy[{x, y}] = '.';
		//local_enemy[{x, y}] = ;
		//local_world[xy_local(local_enemy.x, local_enemy.y)] = '.';
}

Enemy get_enemy( int x, int y)
{
	Enemy enemy = local_enemy[{x, y}];
	enemy.x = x;
	enemy.y = y;
	return enemy;
}

void set_player(Player player, Character hero)
{
	// Erase the local player.
	local_world[xy_local(local_player.x, local_player.y)] = '.';
	local_player = player;
	// Reinclude the new player.
	local_world[xy_local(player.x, player.y)] = 'P';
}

Player get_player()
{
	return local_player;
}
