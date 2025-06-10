#ifndef PLAYER
#define PLAYER

#include <stdbool.h>

#include "screen.h"

// PLAYER STRUCTURE

typedef struct {
	char* name;
	int x;
	int y;
	int w;
	int h;
} Player;

Player new_player(char* name, int x, int y);
void render_player(Screen* screen, Player* player);
