#include "Food.hpp"
Food::Food(Gfx gfx)
{
	this->gfx = gfx;
	do
	{
		srand(time(0));
		this->p.SetX(rand() % 98 + 1);
		this->p.SetY(rand() % 98 + 1);
	} while (this->gfx.GetPixel(p) == Vec3b(0, 255, 0));
	gfx.PutPixel(p, Vec3b(0, 0, 0));
}
void Food::ChangePoz()
{
	do
	{
		srand(time(0));
		this->p.SetX(rand() % 98 + 1);
		this->p.SetY(rand() % 98 + 1);
	} while (gfx.GetPixel(p) == Vec3b(0, 255, 0));
	gfx.PutPixel(p, Vec3b(0, 0, 0));
}
G::Point Food::GetCoords()
{
	return p;
}