#pragma once
namespace G
{
	class Point
	{
	private:
		int x;
		int y;
	public:
		Point();
		Point(int x, int y);
		int GetX() const;
		int GetY() const;
		void SetX(int x);
		void SetY(int y);
		bool operator == (const G::Point& arg);
	};
}