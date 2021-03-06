#pragma once
#include<opencv2/opencv.hpp>
#include<string>
#include"Point.hpp"
#include"Settings.hpp"
using namespace cv;
using namespace std;
class Gfx
{
private:
	Mat map;
public:
	Gfx();
	void PutPixel(G::Point p, Vec3b color);
	void showMap();
	Vec3b GetPixel(G::Point arg);
	int GetWidth();
	int GetLength();
};