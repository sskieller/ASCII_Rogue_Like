#pragma once
class Player
{
public:
	Player(); // bruger bare standardværdier indtil videre

	void initPlayer(int y, int x); 

	int getPlayerX() const { return x_; }
	int getPlayerY() const { return y_; }

	void setPlayerX(int X) { x_ = X; }
	void setPlayerY(int Y) { y_ = Y; }

	void update();
	void playerMove(char input); //skal den være her, eller i level?
private:
	//attributes
	int x_;
	int y_;
	int health_;
	int maxHealth_;
	int experience_;
	int level_;
	int healthRegen_;
	int attack_; //items senere?
	int defense_;
};

