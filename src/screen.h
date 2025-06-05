#ifndef SCREEN
#define SCREEN

#define SCREEN_MAX_W 500
#define SCREEN_MAX_H 500

#define CLR_RESET "\e[0;0m"

#define FG_BLK 30
#define FG_RED 31
#define FG_GRN 32
#define FG_YEL 33
#define FG_BLU 34
#define FG_PUR 35
#define FG_CYN 36
#define FG_WHT 37

#define FG_BRIGHT_BLK 90
#define FG_BRIGHT_RED 91
#define FG_BRIGHT_GRN 92
#define FG_BRIGHT_YEL 93
#define FG_BRIGHT_BLU 94
#define FG_BRIGHT_PUR 95
#define FG_BRIGHT_CYN 96
#define FG_BRIGHT_WHT 97

#define BG_BLK 40
#define BG_RED 41
#define BG_GRN 42
#define BG_YEL 43
#define BG_BLU 44
#define BG_PUR 45
#define BG_CYN 46
#define BG_WHT 47

#define BG_BRIGHT_BLK 100
#define BG_BRIGHT_RED 101
#define BG_BRIGHT_GRN 102
#define BG_BRIGHT_YEL 103
#define BG_BRIGHT_BLU 104
#define BG_BRIGHT_PUR 105
#define BG_BRIGHT_CYN 106
#define BG_BRIGHT_WHT 107

// UTILS

int center(int size1, int size2);

// SCREEN STRUCTURE

typedef struct {
	char chars[SCREEN_MAX_W][SCREEN_MAX_H];
	int fg[SCREEN_MAX_W][SCREEN_MAX_H];
	int bg[SCREEN_MAX_W][SCREEN_MAX_H];
	int w;
	int h;
} Screen;

Screen new_screen(int w, int h);
void write_screen(Screen* screen, int x, int y, char* string, int fg, int bg);
void fill_screen(Screen* screen, char c, int fg, int bg);
void render_screen(Screen* screen);

#endif
