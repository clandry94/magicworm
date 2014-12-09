// Main Menu
#include "menu.h"

//constructor
Menu::Menu(SDL_Window *sentWindow){
  	window = sentWindow;

  	//creates the renderer to be used
  	ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  	if (ren == nullptr){
    	SDL_DestroyWindow(window);
	    std::cout << "SDL_CreateMenuRenderer Error: " << SDL_GetError() << std::endl;
	    SDL_Quit();
  	}

  	//creates the menu's textures
  	const string menuPath = getResourcePath("magicworm") + "menu.bmp";
  	SDL_Surface *bmp = SDL_LoadBMP(menuPath.c_str());
  	if (bmp == nullptr){
    	SDL_DestroyRenderer(ren);
    	SDL_DestroyWindow(window);
    	std::cout << "SDL_LoadMenuBMP Error: " << SDL_GetError() << std::endl;
    	SDL_Quit();
  	}

  	menTex = SDL_CreateTextureFromSurface(ren, bmp);
  	SDL_FreeSurface(bmp);
  	if (menTex == nullptr){
  	  	SDL_DestroyRenderer(ren);
  	  	SDL_DestroyWindow(window);
  	  	std::cout << "SDL_CreateMenuTextureFromSurface Error: " << SDL_GetError() << std::endl;
  	  	SDL_Quit();
  	}

  	mainMenu();
}

//prints the main menu
void Menu::printMenu(){
  	//SDL_Delay(2000); //I'm not sure this is necessary
  	SDL_RenderClear(ren);
  	SDL_RenderCopy(ren, menTex, NULL, NULL);
  	SDL_RenderPresent(ren);
}

//prints the High score screen and contains High Score functionality
void Menu::showHighScore(){
 	//reads the high score and stores it in a string
  	istring highScore;
  	fstream textfile;
  	string highscorepath = getResourcePath("menu") + "highscore.txt";
  	textfile.open(highscorepath);
  	textfile >> highScore;
  	textfile.close();
    std::cout << highScore << std::endl;
}

//main menu functionality
void Menu::mainMenu() {
  	//cin >> begin; //this was in the code already, I don't know what it's for
  	printMenu();
  	bool quit = false;

		SDL_Event e;
  	//checks for key inputs
  	while (!quit){
	  	while (SDL_PollEvent(&e)){
	  		switch(e.type){
	          	/* Look for a keypress */
		        case SDL_KEYDOWN:
		          	/* Check the SDLKey values */
		        	switch(e.key.keysym.sym){
			            case SDLK_ESCAPE:
                      SDL_DestroyRenderer(ren);
                      SDL_DestroyTexture(menTex);
                      SDL_DestroyWindow(window);
                      SDL_Quit();
                      std::exit(0);
			                break;
			            case SDLK_s:
			                quit = true;
			                break;
			            case SDLK_h:
			                showHighScore();
			                break;
			            default:
			                break;
		          	}
		        default:
		           	break;
	      	}
	     	break;
	    }
  	}
  	SDL_DestroyRenderer(ren);
  	SDL_DestroyTexture(menTex);
}
