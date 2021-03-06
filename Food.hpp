#pragma once
#include"Point.hpp"
#include"Gfx.hpp"
#include<cstdlib>
#include<ctime>
class Food
{
private:
	G::Point p;
	Gfx gfx;
public:
	Food(Gfx gfx);
	void ChangePoz();
	G::Point GetCoords();
};