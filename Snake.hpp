#pragma once
#include"Point.hpp"
#include<vector>
#include<cstdlib>
#include<ctime>
#include"Gfx.hpp"
#include"Settings.hpp"
using namespace std;
class Snake
{
private:
	vector<G::Point> snake;
	string direction;
	Gfx gfx;
	bool alive;
public:
	Snake(Gfx gfx);
	vector<G::Point> GetSnakePositions();
	void MoveSnake();
	void ChangeDir(string newDir);
	string GetDir();
	bool GetStatus() const;
	void SetStatus(bool arg);
	G::Point head() const;
	void Grow();
	int size() const;
};

