#include <stdio.h>

#include "screen.h"

int main(){
	Screen screen = new_screen(150, 40);
	fill_screen(&screen, '#', FG_RED, BG_GRN);
	write_screen(&screen, 3, 3, "testing if this shit works\nBLAH BLAH BLAH newline worked?", FG_BLK, BG_WHT);
	render_screen(&screen);
	return 0;
}
