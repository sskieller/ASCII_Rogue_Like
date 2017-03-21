#pragma once
class Player
{
public:
	Player(); // bruger bare standardværdier indtil videre
	~Player();
	void update();
	void playerMove(char input); //skal den være her, eller i level?
private:
	//attributes
	int health_;
	int maxHealth_;
	int experience_;
	int level_;
	int healthRegen_;
	int attack_; //items senere?
	int defense_;
};

