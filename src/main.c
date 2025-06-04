#include <stdio.h>

#include "screen.h"

int main(){
	Screen screen = new_screen(150, 40);
	fill_screen(&screen, '#', FG_RED, BG_GRN);
	render_screen(&screen);
	return 0;
}
