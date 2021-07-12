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
		std::cout << "unable to initialize:" << SDL_GetError() << std::endl;
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
			std::cout << "unable to create window:" << SDL_GetError() << std::endl;
		} else {
			// get win surface and fill color
			screen = SDL_GetWindowSurface(win);
			SDL_Event e;

			int color = 0xff;
			int flag = 0;

			Uint32 ltrig = 0;

			SDL_FillRect(screen, NULL,
				SDL_MapRGB(
					screen->format,
					color, color, color
				)
			);

			// update screen
			SDL_UpdateWindowSurface(win);

			while(1){
				SDL_PollEvent(&e);
				if( e.type == SDL_QUIT ) break;
				if( e.type == SDL_KEYDOWN ){
					switch(e.key.keysym.sym){
						case SDLK_ESCAPE:
							flag = 1;
							break;
						default:
							break;
					}
				}

				if(flag) break;

				if( SDL_GetTicks() - ltrig > 500) {
					// 1 second elapsed

					// draw
					SDL_FillRect(screen, NULL,
						SDL_MapRGB(
							screen->format,
							color, color, color
						)
					);

					// update screen
					SDL_UpdateWindowSurface(win);
					color = ~color;

					//reset trigger
					ltrig = SDL_GetTicks();
				}
			}
		}
	}

	// cleanup
	SDL_DestroyWindow( win );
	SDL_Quit();
	return 0;
}
