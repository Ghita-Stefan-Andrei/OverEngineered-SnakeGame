#include "Snake.hpp"
Snake::Snake(Gfx gfx)
{
	srand(time(0));
	this->gfx = gfx;
	int x = 50 + rand() % 25;
	int y = 50 + rand() % 25;
	this->snake.push_back(G::Point(x, y));
	for (int i = 1; i <= SnakeStartSize; i++)
	{
		this->snake.push_back(G::Point(x, y + i));
	}
	this->direction = "Up";
	this->alive = 1;
}
vector<G::Point> Snake::GetSnakePositions()
{
	return snake;
}
void Snake::MoveSnake()
{
	vector<G::Point> aux;
	if (this->direction == "Up")
	{
		aux.push_back(G::Point(this->snake[0].GetX(), this->snake[0].GetY() - 1));
	}
	else if (this->direction == "Down")
	{
		aux.push_back(G::Point(this->snake[0].GetX(), this->snake[0].GetY() + 1));
	}
	else if (this->direction == "Left")
	{
		aux.push_back(G::Point(this->snake[0].GetX() - 1, this->snake[0].GetY()));
	}
	else if (this->direction == "Right")
	{
		aux.push_back(G::Point(this->snake[0].GetX() + 1, this->snake[0].GetY()));
	}
	for (int i = 0; i < this->snake.size() - 1; i++)
	{
		aux.push_back(this->snake[i]);
	}
	gfx.PutPixel(this->snake.back(), Vec3b(255, 255, 255));
	this->snake = aux;
	gfx.PutPixel(this->head(), Vec3b(0, 255, 0));
}
void Snake::ChangeDir(string newDir)
{
	this->direction = newDir;
}
bool Snake::GetStatus() const
{
	return this->alive;
}
void Snake::SetStatus(bool arg)
{
	this->alive = arg;
}
G::Point Snake::head() const
{
	return this->snake[0];
}
string Snake::GetDir()
{
	return this->direction;
}
void Snake::Grow()
{
	this->snake.push_back(this->snake.back());
}
int Snake::size() const
{
	return snake.size();
}