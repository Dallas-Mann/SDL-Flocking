#include "TextureLoader.h"
#include <iostream>

TextureLoader::TextureLoader(){
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

bool TextureLoader::LoadFromFile(std::string path, SDL_Renderer* renderer) {
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image to make Cyan transparent
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0x0FF, 0xFF, 0xFE));

		mTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		SDL_SetTextureBlendMode(mTexture, SDL_BLENDMODE_BLEND);
		if (renderer == NULL) {
			std::cout << "null renderer" << std::endl;
		}

		if (mTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	
	//Return success
	return mTexture != NULL;
}

void TextureLoader::Render(int x, int y, double angle, SDL_Renderer* renderer) {
	double degrees = -angle * 180 / M_PI + 90;

	if (mTexture != NULL && renderer != NULL) {
		SDL_Rect renderQuad = { x, y, mWidth, mHeight };
		SDL_RenderCopyEx(renderer, mTexture, NULL, &renderQuad, degrees, NULL, SDL_FLIP_NONE);
	}
	else {
		std::cout << "Cannot Render!" << std::endl;
	}
}

int TextureLoader::GetWidth() {
	return mWidth;
}

int TextureLoader::GetHeight() {
	return mHeight;
}
SDL_Texture* TextureLoader::GetTexture() {
	return mTexture;
}