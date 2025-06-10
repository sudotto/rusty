#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "screen.h"

// UTILS

int center(int len1, int len2){
	return (len1 / 2) - (len2 / 2); 
}

// SCREEN STRUCTURE

Screen new_screen(int w, int h){
	Screen screen;
	screen.w = w;
	screen.h = h;
	fill_screen(&screen, 0, 0, w, h, '#', FG_WHT, BG_BLK);
	return screen;
}

void write_screen(Screen* screen, int x, int y, char* string, int fg, int bg){
	if(x > screen->w || y > screen->h || x < 0 || y < 0){
		printf("%i , %i\n", x, y);
		return;
	}
	int old_x = x;
	int old_y = y;
	for(int i = 0; i < strlen(string); i++){
		if(string[i] == '\n'){
			y++;
			x = old_x;
		} else {
			screen->fg[y][x] = fg;
			screen->bg[y][x] = bg;
			screen->chars[y][x] = string[i];
			x++;
		}
	}
}

void fill_screen(Screen* screen, int x, int y, int w, int h, char c, int fg, int bg){
	int old_x = x;
	int old_y = y;
	for(y = old_y; y <= h + old_y; y++){
		for(x = old_x; x <= w + old_x; x++){
			write_screen(screen, x, y, &c, fg, bg);
		}
	}
}

void render_screen(Screen* screen){
	for(int y = 0; y <= screen->h; y++){
		for(int x = 0; x <= screen->w; x++){
			printf("\e[%i;%im", screen->fg[y][x], screen->bg[y][x]);
			printf("%c", screen->chars[y][x]);
		}
		printf("%s", CLR_RESET);
		printf("\n");
	}
}
