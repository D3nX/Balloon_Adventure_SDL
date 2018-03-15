#include "stdafx.h"
#include "Image.h"
#include <SDL_image.h>

Image::Image(const char * path, SDL_Renderer * renderer)
{
	// Store the renderer
	m_renderer = renderer;

	// Load the image
	SDL_Surface * surface = IMG_Load(path);
	m_texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	
	// Set the x, y, width, height
	m_rect = new SDL_Rect;

	m_rect->x = 0;
	m_rect->y = 0;

	SDL_QueryTexture(m_texture, NULL, NULL, &m_rect->w, &m_rect->h);
}

Image::~Image() {}

void Image::draw()
{
	SDL_RenderCopy(m_renderer, m_texture, NULL, m_rect);
}
