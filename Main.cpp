#include<opencv2/opencv.hpp>
#include<conio.h>
#include<chrono>
#include<thread>
#include"Gfx.hpp"
#include"Snake.hpp"
#include"Food.hpp"
#include"Settings.hpp"
using namespace cv;
using namespace std;
void SetDirectie(Snake& snake)
{
	while (snake.GetStatus())
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
			{
				snake.ChangeDir("Up");
			}break;
			case 's':
			{
				snake.ChangeDir("Down");
			}break;
			case 'a':
			{
				snake.ChangeDir("Left");
			}break;
			case 'd':
			{
				snake.ChangeDir("Right");
			}break;
			default:break;
			}
		}
	}
	snake.SetStatus(0);
}
void MoveSnake(Snake& snake)
{
	while (snake.GetStatus())
	{
		snake.MoveSnake();
		std::this_thread::sleep_for(std::chrono::milliseconds(SnakeSpeed));
	}
}
void collision(Snake& snake, Gfx gfx)
{
	while (snake.GetStatus())
	{
		if (snake.head().GetX() == 0 || snake.head().GetX() == gfx.GetWidth() - 1 || snake.head().GetY() == 0 || snake.head().GetY() == gfx.GetLength() - 1)
		{
			snake.SetStatus(0);
			cout << endl;
			cout << " /----------\\" << endl;
			cout << " | You died |" << endl;
			cout << " \\----------/" << endl;
		}
		for (int i = 1; i < snake.size(); i++)
		{
			if (snake.head() == snake.GetSnakePositions()[i])
			{
				snake.SetStatus(0);
				cout << endl;
				cout << " /----------\\" << endl;
				cout << " | You died |" << endl;
				cout << " \\----------/" << endl;
			}
		}
	}
}
void Eat(Snake& snake, Food& food)
{
	while (snake.GetStatus())
	{
		if (snake.head() == food.GetCoords())
		{
			food.ChangePoz();
			snake.Grow();
		}
	}
}
void showMap(Snake& snake, Gfx& gfx)
{
	while (snake.GetStatus())
	{
		gfx.showMap();
		waitKey(1);
	}
}
int main()
{
	Gfx gfx;
	Snake snake(gfx);
	Food food(gfx);

	thread dirT(SetDirectie, ref(snake));
	thread moveingT(MoveSnake, ref(snake));
	thread collisionT(collision, ref(snake), gfx);
	thread eatingT(Eat, ref(snake), ref(food));
	thread gameT(showMap, ref(snake), ref(gfx));

	dirT.join();
	moveingT.join();
	collisionT.join();
	eatingT.join();
	gameT.join();
	return 0;
}
