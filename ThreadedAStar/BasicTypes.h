#pragma once

#include <SDL.h>


//Define some basic types needed for 2D graphics
static const float vpWidth = 39;

class Point2D {
public:
	float x, y;
	Point2D(float _x = 0, float _y = 0) :x(_x), y(_y) { };

	Point2D operator-(Point2D rhs)
	{
		return Point2D(x - rhs.x, y - rhs.y);
	}
};

class Vector2D {
public:
	float x, y;
	Vector2D(float _x = 0, float _y = 0) :x(_x), y(_y) { };
	Vector2D(Point2D _point) :x(_point.x), y(_point.y) { };
	float length() { return (float)sqrt(x*x + y*y); };
	
	Vector2D operator*(float rhs) 
	{
		return Vector2D(x * rhs, y * rhs);
	};
};

class Size2D {
public:
	float w, h;
	Size2D(float _w = 0, float  _h = 0) :w(_w), h(_h) {};
};

class Colour {
public:
	int r, g, b, a;
	Colour(int _r = 255, int  _g = 255, int _b = 255, int  _a = 255) :r(_r), g(_g), b(_b), a(_a) {};
};

class Rect {
public:
	Point2D pos;
	Size2D size;
	Rect(Point2D p, Size2D s) :pos(p), size(s) {};
	Rect(float x = 0, float y = 0, float w = 1, float h = 1) :pos(x, y), size(w, h) {};
	Point2D getCentre() const { return Point2D(pos.x + size.w / 2, pos.y + size.h / 2); };

	bool contains(int x, int y) 
	{
		return (x >= pos.x && x < pos.x + size.w) 
			&& (y >= pos.y && y < pos.y + size.h);
	};

	bool contains(float x)
	{
		return (x >= pos.x && x < pos.x + size.w);
	}
	
	SDL_Rect getSDLRect() const 
	{ 
		SDL_Rect r;
		r.x = pos.x;
		r.y = pos.y;
		r.w = size.w;
		r.h = size.h;

		return r;
	}
};