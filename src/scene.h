#ifndef SCENE
#define SCENE

#include "player.h"

typedef enum {
	MAIN_MENU,
	GAME
} Scene;

Scene main_menu_scene(Screen* screen);
Scene game_scene(Screen* screen, Player* player);

#endif
