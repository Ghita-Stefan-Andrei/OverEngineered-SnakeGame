#include "Point.hpp"
using namespace G;
Point::Point()
{
	this->x = this->y = 0;
}
Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}
int Point::GetX() const
{
	return this->x;
}
int Point::GetY() const
{
	return this->y;
}
void Point::SetX(int x)
{
	this->x = x;
}
void Point::SetY(int y)
{
	this->y = y;
}
bool Point::operator == (const G::Point& arg)
{
	if (this->x == arg.x && this->y == arg.y)
	{
		return true;
	}
	return false;
}