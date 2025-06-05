#ifndef MENU
#define MENU

// MENU ELEMENT

/*typedef struct {
	
} Element;

Element new_button();
Element new_text_input();
Element new_slider();
*/
// MENU STRUCT

typedef struct {
	char* title;
	char** options;
	int option_count;
	int option_selected;
} Menu;

Menu new_menu(char* title, char** options, int option_count);
int update_menu(Menu* menu, char key);
void render_menu(Screen* screen, Menu* menu, int x, int h);

#endif

