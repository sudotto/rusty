#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "screen.h"

#include "menu.h"

Menu new_menu(char* title, char** options, int option_count, int padding, char bar_char){
	Menu menu;
	menu.title = malloc(strlen(title) + 2);
	strcpy(menu.title, " ");
	strcat(menu.title, title);
	strcat(menu.title, " ");
	menu.bar = malloc(strlen(title) + 2);
	for(int i = 0; i < strlen(title) + 2; i++){
		strcat(menu.bar, &bar_char);
	}
	menu.options = options;
	menu.option_count = option_count;
	menu.option_selected = 0;
	menu.w = strlen(menu.title);
	for(int i = 0; i < menu.option_count; i++){
		if(strlen(menu.options[i]) > menu.w){
			menu.w = strlen(menu.options[i]);
		}
	}
	menu.h = option_count + 2;
	menu.padding = padding;
	menu.w += padding; 
	menu.h += padding;
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
		case '\n':
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
	fill_screen(screen, x - (menu->padding / 2), y - (menu->padding / 2), menu->w, menu->h, ' ', FG_WHT, BG_BLK);
	write_screen(screen, x, y, menu->title, FG_BLK, BG_WHT);
	y++;
	write_screen(screen, x, y, menu->bar, FG_WHT, BG_BLK);
	y++;
	for(int i = 0; i < menu->option_count; i++){
		if(i == menu->option_selected){
			char* formatted = malloc(strlen(menu->options[i]) + strlen("> "));
			strcpy(formatted, "> ");
			strcat(formatted, menu->options[i]);
			write_screen(screen, x, y + (i), formatted, FG_BLK, BG_WHT);
		} else {
			write_screen(screen, x, y + (i), menu->options[i], FG_WHT, BG_BLK);
		}
	}
}

void destroy_menu(Menu* menu){
	free(menu->title);
	free(menu->bar);
}
