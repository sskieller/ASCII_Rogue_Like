#pragma once
class Player
{
public:
	Player(); // bruger bare standardv�rdier indtil videre
	~Player();
	void update();
	void playerMove(char input); //skal den v�re her, eller i level?
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

