#include "Player.h"

//Initializer Functions
void Player::initVariables()
{

}

void Player::initComponents()
{
	
}

//Constructor / Destructors
Player::Player(float x, float y, sf::Texture* texture)
{
	this->initVariables();
	this->initComponents();

	this->createSprite(texture);
	this->setPosition(x, y);
}

Player::~Player()
{

}