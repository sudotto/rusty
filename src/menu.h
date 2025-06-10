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
	int w;
	int h;
	int padding;
	char* bar;
} Menu;

Menu new_menu(char* title, char** options, int option_count, int padding, char bar_char);
int update_menu(Menu* menu, char key);
void render_menu(Screen* screen, Menu* menu, int x, int h);
void destroy_menu(Menu* menu);

#endif

