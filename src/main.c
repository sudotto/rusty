#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "screen.h"
#include "input.h"
#include "menu.h"
#include "scene.h"
#include "player.h"

int main(){
	printf("\e[?1049h");
	Screen screen = new_screen(150, 40);
	Scene scene = MAIN_MENU;
	Player player = new_player("rusty", 0, 0);
	bool running = true;
	while(running){
		switch(scene){
			case -1:
				running = false;
				break;
			case MAIN_MENU:
				scene = main_menu_scene(&screen);
				break;
			case GAME:
				scene = game_scene(&screen, &player);
				break;
		}
	}
	printf("\e[?1049l");
	return 0;
}
