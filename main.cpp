#include "tile.h"
#include "command.h"
#include <iostream>
#include<vector>
#include<cassert>



void show_help() 
{
	std::cout << "\t# = Wall\n\t. = Empty\n\tE = Enemy\n\tP = Player\n";
	std::cout << "Valid options:\n";
	std::cout << "\t[q]uit  -> quit the game.\n";
	std::cout << "\t[n]orth -> move north.\n";
	std::cout << "\t[s]outh -> move south.\n";
	std::cout << "\t[e]ast -> move east.\n";
	std::cout << "\t[w]est -> move west.\n";
	std::cout << "\t[a]ttack -> attack the target.\n";
	// TODO fill up the rest!
	// See the list of command in the tile.h.
}

void show_map()
{
	Player player = get_player();
	
	//provisoir map

	/*std::cout << "\t";
	for (int i = -3; i <= 3; i++)
	{
		std::cout << (char)get_tile_at_position(player.x + i, player.y - 3) << " ";
	}
	std::cout << "\n"; // line north + 1 box*/
	
	std::cout << "\t";
	for (int i = -3; i <= 3; i++)
	{
		std::cout << (char)get_tile_at_position(player.GetX() + i, player.GetY() - 2) << " ";
	}
	std::cout << "\n"; // line north + 1 box

	std::cout << "\t";
	for (int i = -3; i <= 3; i++)
	{
		std::cout << (char)get_tile_at_position(player.GetX() + i, player.GetY() - 1) << " ";
	}
	std::cout << "\n"; // line nord

	std::cout << "\t";
	for (int i = -3; i <= 3; i++)
	{
		std::cout << (char)get_tile_at_position(player.GetX() + i, player.GetY()) << " ";
	}
	std::cout << "\n"; // line player

	std::cout << "\t";
	for (int i = -3; i <= 3; i++)
	{
		std::cout << (char)get_tile_at_position(player.GetX() + i, player.GetY() + 1) << " ";
	}
	std::cout << "\n"; // line south

	std::cout << "\t";
	for (int i = -3; i <= 3; i++)
	{
		std::cout << (char)get_tile_at_position(player.GetX() + i, player.GetY() + 2) << " ";
	}
	std::cout << "\n"; // line south + 1 box

	std::cout << "\t";
	for (int i = -3; i <= 3; i++)
	{
		std::cout << (char)get_tile_at_position(player.GetX() + i, player.GetY() + 3) << " ";
	}
	std::cout << "\n"; // line south + 2 box

	/*std::cout << "\t";
	for (int i = -3; i <= 3; i++)
	{
		std::cout << (char)get_tile_at_position(player.x + i, player.y + 4) << " ";
	}
	std::cout << "\n"; // ligne sud +3 case*/
}

void show_state() 
{
	Player player = get_player();
	std::cout << "Maze :\n";
	// TODO complete me!
	// You can either show the whole maze or just a portion of it.
	show_map();
	std::cout << "\n ";
	std::cout << "Player(" << player.x << ", " << player.y << ")\n";
	std::cout << "\t[ Name : " << player.name << "\n";
	std::cout << "\t  Health points : " << player.health_points << " ]\n";

	Enemy enemy = get_enemy(player.x, player.y);
	std::vector<Enemy> enemy_vec;
	std::cout << "Enemies : \n";

	for (int i = - 2; i <= 2; i++) // position x
	{
		for (int j = - 2; j <= 2; j++) // position y
		{
			if (TileType::ENEMY == get_tile_at_position(player.x + i, player.y + j))
				enemy_vec.push_back(get_enemy(player.x + i, player.y + j));
		}
	}
	for (const auto& enemy : enemy_vec)
	{
		std::cout << "\t[" << enemy.name << "\n\thealth points : " << enemy.health_points << "\n";
		if (enemy.health_points <= 0)
		{
				//set_enemy();
			//local_world[xy_local(local_enemy.x, local_enemy.y)] = '.';
			std::cout << "\tdied\n";
		}
		std::cout << "\t\t]\n";
		std::cout << "<=============>\n";
	}


	if (player.health_points <= 0)
	{
		system("cls");
		std::cout << "You have loose !\n";
		system("pause");
		std::cout << "press q for exit.\n";
	}
	// TODO complete me!
	// Now check if there is an enemy within range.
	// for each enemy within range:
	// show enemy description.
}

CommandType get_command() 
{
	std::string command_str;
	std::getline(std::cin, command_str);
	switch (command_str[0])
	{
		case 'q':
			return CommandType::QUIT;
		case 'n':
			system("cls");
			return CommandType::NORTH;
		case 's':
			system("cls");
			return CommandType::SOUTH;
		case 'e':
			system("cls");
			return CommandType::EAST;
		case 'w':
			system("cls");
			return CommandType::WEST;
		case 'a':
			system("cls");
			return CommandType::ATTACK;
		case 'h':
			system("cls");
			show_help();
			return CommandType::HELP;
		default:
			std::cout << "Writh h for help valide option.\n";
			return CommandType::HELP; // h or other lettre donc used drop here -> shop help menu
	}
}

int main()
{
	std::cout << "Welcome in the Maze!\n";
	show_help();
	while (true)
	{
		show_state();
		CommandType command_type = get_command();
		switch (command_type) 
		{
			case CommandType::QUIT:
				std::cout << "bye!\n";
				return 0;
			case CommandType::NORTH:
				north();
				tick();
				break;
			case CommandType::SOUTH:
				south();
				tick();
				break;
			case CommandType::EAST:
				east();
				tick();
				break;
			case CommandType::WEST:
				west();
				tick();
				break;
			case CommandType::ATTACK:
				attack();
				tick();
				break;
			case CommandType::HELP:
			default:
				tick();
				break;
		}
	}
	return 0;
}
