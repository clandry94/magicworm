#ifndef RES_PATH_H
#define RES_PATH_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

std::string getResourcePath(const std::string &subDir = ""){
  //Seperator
	const char PATH_SEP = '/';

  //Base path
	static std::string base;
	if (base.empty()){
		//SDL_GetBasePath will return NULL if problem getting path
		char * baseP = SDL_GetBasePath();
		if (baseP){
			base = baseP;
			SDL_free(baseP);
		}
		else {
			std::cerr << "Error getting resource path: " << SDL_GetError() << std::endl;
			return "";
		}
		//replace the last bin/ with res/ to get the the resource path
		size_t pos = base.rfind("bin");
		base = base.substr(0, pos) + "res" + PATH_SEP;
	}

	return subDir.empty() ? base : base + subDir + PATH_SEP;
}

#endif
