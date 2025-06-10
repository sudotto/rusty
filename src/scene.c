#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "screen.h"
#include "input.h"
#include "menu.h"
#include "player.h"

#include "scene.h"

Scene main_menu_scene(Screen* screen){
	Menu menu = new_menu("Rusty", (char*[]){"Start", "Config", "Quit"}, 3, 4, '-');
	char key;
	bool running = true;
	while(running){
		printf("\x1b[H");
		fill_screen(screen, 0, 0, screen->w, screen->h, ' ', FG_BLK, BG_BLU);
		render_menu(screen, &menu, center(screen->w, menu.w), center(screen->h, menu.h));
		render_screen(screen);
		key = get_key();
		if(key == 'Q' || key == 'q'){
			return -1;
		}
		switch(update_menu(&menu, key)){
			case -1: // no choice selected
				break;
			case 0:
				destroy_menu(&menu);
				return GAME;
				break;
			case 2:
				destroy_menu(&menu);
				return -1; // quit game
				break;
		}
	}
	//destroy_menu(&menu);
	return MAIN_MENU;
}

Scene game_scene(Screen* screen, Player* player){
	char key;
	bool running = true;
	while(running){
		printf("\x1b[H");
		fill_screen(screen, 0, 0, screen->w, screen->h, ' ', FG_BLK, BG_RED);
		update_player(player, key);
		render_player(screen, player);
		render_screen(screen);
		key = get_key();
		if(key == 'M' || key == 'm'){
			return MAIN_MENU;
		}
	}
	return GAME;
}
