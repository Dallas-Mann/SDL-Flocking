#ifndef TEXTURELOADER_H_
	#define TEXTURELOADER_H_
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

class TextureLoader {
private:
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;

public:
	TextureLoader();
	bool LoadFromFile(std::string path, SDL_Renderer* renderer);
	void Render(int x, int y, double angle, SDL_Renderer* renderer);
	int GetWidth();
	int GetHeight();
	SDL_Texture* GetTexture();
};
#endif