#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "screen.h"

#include "player.h"

// PLAYER STRUCTURE

Player new_player(char* name, int x, int y){
	Player player;
	player.name = name;
	player.sprite = '@';
	player.x = x;
	player.y = y;
	player.w = 1;
	player.h = 1;
	return player;
}

void update_player(Player* player, char key){
	switch(key){
		case 'w':
		case 'W':
			player->y -= 1;
			break;
		case 'a':
		case 'A':
			player->x -= 1;
			break;
		case 's':
		case 'S':
			player->y += 1;
			break;
		case 'd':
		case 'D':
			player->x += 1;
			break;
	}
}

void render_player(Screen* screen, Player* player){
	write_screen(screen, player->x, player->y, &player->sprite, FG_YEL, BG_RED);
}
