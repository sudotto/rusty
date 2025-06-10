#ifndef SCENE
#define SCENE

typedef enum {
	MAIN_MENU,
	GAME
} Scene;

Scene main_menu_scene(Screen* screen);
Scene game_scene(Screen* screen);

#endif
