#pragma once
#include <SDL.h>

class Image
{
public:
	Image(const char*, SDL_Renderer*);
	~Image();
	void draw();

	// Setters
	void setWidth(int width) { m_rect->w = width; }
	void setHeight(int height) { m_rect->h = height; }
	void setX(int x) { m_rect->x = x; }
	void setY(int y) { m_rect->y = y; }

	// Getters
	int getWidth() const { return m_rect->w; }
	int getHeight() const { return m_rect->h; }
	int getX() const { return m_rect->x; }
	int getY() const { return m_rect->y; }

private:
	SDL_Texture * m_texture;
	SDL_Renderer * m_renderer;
	SDL_Rect * m_rect;
};

