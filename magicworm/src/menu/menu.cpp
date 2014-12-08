// Main Menu
#include "menu.h"
//#include <iostream>
//#include <fstream> these are unecessary I believe
//#include <string>



//constructor
Menu::Menu(SDL_Window *sentWindow){
  	window = sentWindow;

  	//creates the renderer to be used
  	ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  	if (ren == nullptr){
    	SDL_DestroyWindow(win);
	    std::cout << "SDL_CreateMenuRenderer Error: " << SDL_GetError() << std::endl;
	    SDL_Quit();
	    return 1;
  	}

  	//creates the menu's textures
  	const string menuPath = getResourcePath("magicworm") + "menu.bmp";
  	SDL_Surface *bmp = SDL_LoadBMP(menuPath.c_str());
  	if (bmp == nullptr){
    	SDL_DestroyRenderer(ren);
    	SDL_DestroyWindow(window);
    	std::cout << "SDL_LoadMenuBMP Error: " << SDL_GetError() << std::endl;
    	SDL_Quit();
    	return 1;
  	}

  	menTex = SDL_CreateTextureFromSurface(ren, bmp);
  	SDL_FreeSurface(bmp);
  	if (menTex == nullptr){
  	  	SDL_DestroyRenderer(ren);
  	  	SDL_DestroyWindow(window);
  	  	std::cout << "SDL_CreateMenuTextureFromSurface Error: " << SDL_GetError() << std::endl;
  	  	SDL_Quit();
    	return 1;
  	}

  	mainMenu();
}

//prints the main menu
void printMenu(){
  	//SDL_Delay(2000); //I'm not sure this is necessary

  	SDL_RenderClear(ren);
  	SDL_RenderCopy(ren, menTex, NULL, NULL);
  	SDL_RenderPresent(ren);
}

//prints the High score screen and contains High Score functionality
void showHighScores(){

 	//reads the high score and stores it in a string
  	string text;
  	fstream textfile;
  	string highscorepath = getResourcePath("menu") + "highscore.txt";
  	textfile.open(highscorepath);
  	textfile >> text;
  	textfile.close();

  	textColor = {255, 255, 255};

  	const string fontPath = getResourcePath("menu") + "dpcomic.tff";
  	const string backgroundPath = getResourcePath("magicworm") + "highscore.png"
  	
  	background = load_image(backgroundPath);
  	if(background == NULL){
  		SDL_DestroyTexture(menTex);
    	SDL_DestroyRenderer(ren);
    	SDL_DestroyWindow(window);
    	std::cout << "SDL_Background Error: " << SDL_GetError() << std::endl;
    	TFF_Quit();
    	SDL_Quit();   
  	}

  	font = TTF_OpenFont(fontPath, 32);
  	if(font == NULL){
    	SDL_FreeSurface(background);
    	SDL_DestroyTexture(menTex);
    	SDL_DestroyRenderer(ren);
    	SDL_DestroyWindow(window);
    	std::cout << "SDL_Font Error: " << SDL_GetError() << std::endl;
    	TFF_Quit();
    	SDL_Quit();
  	}

  	message = TTF_RenderText_Solid(font, text, textColor);
  	if(message == NULL){
    	TFF_CloseFont(font);
    	SDL_FreeSurface(background);
    	SDL_DestroyTexture(menTex);
    	SDL_DestroyRenderer(ren);
    	SDL_DestroyWindow(window);
    	std::cout << "SDL_Message Error: " << SDL_GetError() << std::endl;
    	TFF_Quit();
    	SDL_Quit();  
  	}

  	//creates the textures
  	/*messageTex = SDL_CreateTextureFromSurface(ren, message);
  	SDL_FreeSurface(message);
  	if (messageTex == nullptr){
  		TFF_CloseFont(font);
    	SDL_FreeSurface(background)
    	SDL_DestroyTexture(menTex);
    	SDL_DestroyRenderer(ren);
    	SDL_DestroyWindow(window);
    	std::cout << "SDL_CreateMessageTextureFromSurface Error: " << SDL_GetError() << std::endl;
    	TFF_Quit();
    	SDL_Quit();
    	return 1;
  	}*/

    SDL_Rect offset;
    offset.x = 90;
   	offset.y = 150;
    SDL_BlitSurface(message, NULL, background, &offset);

  	tex = SDL_CreateTextureFromSurface(ren, background);
  	SDL_FreeSurface(background);
  	SDL_FreeSurface(message);
  	if (tex == nullptr){
    	TFF_CloseFont(font);
    	SDL_DestroyTexture(messageTex);
    	SDL_DestroyTexture(menTex);
    	SDL_DestroyRenderer(ren);
    	SDL_DestroyWindow(window);
    	std::cout << "SDL_CreateBackgroundTextureFromSurface Error: " << SDL_GetError() << std::endl;
    	TFF_Quit();
    	SDL_Quit();
    	return 1;
  	}

  	//displays the textures
  	SDL_RenderClear(ren);
  	SDL_RenderCopy(ren, tex, NULL, NULL);
  	SDL_RenderPresent(ren);

  	//checks for key inputs
  	bool quit = false;
  	while (!quit){
    	while (SDL_PollEvent(&e)){
      		switch(e.type){
          		/* Look for a keypress */
        		case SDL_KEYDOWN:
          			/* Check the SDLKey values */
          			switch(e.key.keysym.sym){
            			case SDLK_ESCAPE:
              				quit = true;
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

  	//clean up
  	SDL_DestroyTexture(tex);
  	//SDL_DestroyTexture(messageTex);
  	TFF_CloseFont(font);
  	TFF_Quit();
}

//main menu functionality
bool mainMenu() {
  	//cin >> begin; //this was in the code already, I don't know what it's for

 	if(TTF_Init() == -1){
   		SDL_DestroyTexture(menTex);
    	SDL_DestroyRenderer(ren);
    	SDL_DestroyWindow(window);
    	std::cout << "TFF_Initialization Error: " << std::endl;
    	SDL_Quit();    
  	}

  	printMenu(){
  	bool quitProgram = false;
  	bool quit = false;

  	//checks for key inputs
  	while (!quit){
	  	while (SDL_PollEvent(&e)){
	  		switch(e.type){
	          	/* Look for a keypress */
		        case SDL_KEYDOWN:
		          	/* Check the SDLKey values */
		        	switch(e.key.keysym.sym){
			            case SDLK_ESCAPE:
			                quit = true;
			                quitProgram = true;
			                break;
			            case SDLK_s:
			                quit = true;
			                break;
			            case SDLK_h:
			                showHighScores();
			                printMenu();
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
  	return quitProgram;
}
