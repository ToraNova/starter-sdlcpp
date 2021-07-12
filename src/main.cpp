/*
 * sample SDL program
 */

#include <iostream>
#include <SDL.h>

//Screen dimension constants
const int SX_MAX = 800;
const int SY_MAX = 600;

int main(int argc, char *args[]) {
	//The window we'll be rendering to
	SDL_Window* win = NULL;

	//The surface contained by the win
	SDL_Surface* screen = NULL;

	//Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "unable to initialize:" << SDL_GetError() std::endl;
	} else {
		// Create win
		win = SDL_CreateWindow(
				"starter-gamecpp win",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				SX_MAX, SY_MAX,
				SDL_WINDOW_SHOWN
				);
		if( win == NULL ) {
			std::cout << "unable to create window:" << SDL_GetError() std::endl;
		} else {
			// get win surface and fill color
			screen = SDL_GetWindowSurface(win);
			SDL_FillRect(
					screen, NULL,
					SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF )
				    );

			// update and wait
			SDL_UpdateWindowSurface(win);
			SDL_Delay(2000);
		}
	}

	// cleanup
	SDL_DestroyWindow( win );
	SDL_Quit();
	return 0;
}
