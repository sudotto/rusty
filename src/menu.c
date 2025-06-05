#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "screen.h"

#include "menu.h"

Menu new_menu(char* title, char** options, int option_count){
	Menu menu;
	menu.title = title;
	menu.options = options;
	menu.option_count = option_count;
	menu.option_selected = 0;
	return menu;
}

int update_menu(Menu* menu, char key){
	switch(key){
		case 'w':
		case 'W':
			menu->option_selected--;
			break;
		case 's':
		case 'S':
			menu->option_selected++;
			break;
		case ' ':
			return menu->option_selected;
			break;
	}
	if(menu->option_selected < 0){
		menu->option_selected = menu->option_count - 1;
	} else if(menu->option_selected > menu->option_count - 1){
		menu->option_selected = 0;
	}
	return -1;
}

void render_menu(Screen* screen, Menu* menu, int x, int y){
	write_screen(screen, center(screen->w, strlen(menu->title)), y, menu->title, FG_BLK, BG_WHT);
	y++;
	write_screen(screen, center(screen->w, strlen("-----")), y, "-----", FG_WHT, BG_BLK);
	y++;
	for(int i = 0; i < menu->option_count; i++){
		if(i == menu->option_selected){
			char* formatted = malloc(strlen(menu->options[i]) + strlen("> "));
			strcpy(formatted, "> ");
			strcat(formatted, menu->options[i]);
			write_screen(screen, center(screen->w, strlen(menu->options[i])), y + (i), formatted, FG_BLK, BG_WHT);
		} else {
			write_screen(screen, center(screen->w, strlen(menu->options[i])), y + (i), menu->options[i], FG_WHT, BG_BLK);
		}
	}
}
