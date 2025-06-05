#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "screen.h"
#include "input.h"
#include "menu.h"

int main(){
	Screen screen = new_screen(150, 40);
	Menu menu = new_menu("main menu", (char*[]){"play", "settings", "exit", NULL}, 3);
	char key;
	bool running = true;
	while(running){
		// RESET PHASE
		system("clear");
		fill_screen(&screen, ' ', FG_BLK, BG_BLU);
		// RENDER PHASE
		render_menu(&screen, &menu, 0, 0);
		render_screen(&screen);
		// UPDATE PHASE
		key = get_key();
		if(key == 'Q' || key == 'q'){
			running = false;
		}
		switch(update_menu(&menu, key)){
			case -1: // no choice selected
				break;
			case 2:
				running = false;
				break;
		}
	}
	return 0;
}
