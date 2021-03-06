#include "Gfx.hpp"
Gfx::Gfx()
{
	map = Mat(mapR, mapC, CV_8UC3, Vec3b(255, 255, 255));
	for (int i = 0; i < map.rows; i++)
	{
		for (int j = 0; j < map.cols; j++)
		{
			if ((i == 0) || (i == map.rows - 1) || (j == 0) || (j == map.cols - 1))
			{
				PutPixel(G::Point(i, j), Vec3b(0, 0, 0));
			}
		}
	}
}
void Gfx::PutPixel(G::Point p, Vec3b color)
{
	try
	{
		if (p.GetX() < 0 || p.GetX() >= map.cols || p.GetY() < 0 || p.GetY() >= map.rows)
		{
			throw ((string)" Pixel put outside of the map borders");
		}
		map.at<Vec3b>(p.GetY(), p.GetX()) = color;
	}
	catch (string Err)
	{
		cout << " Error:" << Err << endl;
	}
}
void Gfx::showMap()
{
	namedWindow("Game", WINDOW_FREERATIO);
	moveWindow("Game", 650, 250);
	imshow("Game", map);
	resizeWindow("Game", 5 * map.cols, 5 * map.rows);
}
Vec3b Gfx::GetPixel(G::Point arg)
{
	return map.at<Vec3b>(arg.GetY(), arg.GetX());
}
int Gfx::GetLength()
{
	return this->map.rows;
}
int Gfx::GetWidth()
{
	return this->map.cols;
}