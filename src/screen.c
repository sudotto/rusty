#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "screen.h"

// SCREEN STRUCTURE

Screen new_screen(int w, int h){
	Screen screen;
	screen.w = w;
	screen.h = h;
	fill_screen(&screen, ' ', FG_WHT, BG_BLK);
	return screen;
}

void write_screen(Screen* screen, int x, int y, char* string, int fg, int bg){
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

void fill_screen(Screen* screen, char c, int fg, int bg){
	for(int y = 0; y < screen->h; y++){
		for(int x = 0; x < screen->w; x++){
			write_screen(screen, x, y, &c, fg, bg);
		}
	}
}

void render_screen(Screen* screen){
	for(int y = 0; y < screen->h; y++){
		for(int x = 0; x < screen->w; x++){
			printf("\e[%i;%im", screen->fg[y][x], screen->bg[y][x]);
			printf("%c", screen->chars[y][x]);
		}
		printf("\n");
	}
	printf("%s", CLR_RESET);
}
