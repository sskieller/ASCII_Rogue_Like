#include "player.h"



Player::Player() : attack_(10), defense_(10), health_(250), healthRegen_(2), experience_(0), level_(1)
{
}


Player::~Player()
{
}

void Player::update()
{
	if (experience_ < level_ * 50)
	{
		level_++;
		experience_ = 0;
	}
	if (health_ < maxHealth_)
	{
		health_ += healthRegen_;
	}
}