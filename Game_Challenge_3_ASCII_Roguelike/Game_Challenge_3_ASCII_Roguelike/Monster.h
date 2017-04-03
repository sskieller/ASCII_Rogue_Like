#pragma once
class Monster
{
public:
	Monster();
	void initPlayer(int y, int x);

	int getPlayerX() const { return x_; }
	int getPlayerY() const { return y_; }

	void setPlayerX(int X) { x_ = X; }
	void setPlayerY(int Y) { y_ = Y; }
private:
	int x_;
	int y_;
};


