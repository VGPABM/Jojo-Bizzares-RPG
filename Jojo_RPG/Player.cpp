#include "Player.h"

//Initializer Functions
void Player::initVariables()
{

}

void Player::initComponents()
{

}

//Constructor / Destructors
Player::Player(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setPosition(x, y);

	this->createMovementComponent(500.f, 15.f, 6.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_LEFT", 75.f, 0, 0, 5, 0, 146, 212);
	this->animationComponent->addAnimation("WALK_RIGHT", 75.f, 0, 1, 7, 1, 146, 212);
	this->animationComponent->addAnimation("WALK_LEFT", 75.f, 0, 2, 7, 2, 146, 212);
}

Player::~Player()
{

}

void Player::update(const float& dt)
{
	this->movementComponent->update(dt);
	
	if (this->movementComponent->getState(IDLE)) {
		this->animationComponent->play("IDLE_LEFT", dt);
	}
	else if(this->movementComponent->getState(MOVING_LEFT)) {
		this->animationComponent->play("WALK_LEFT", dt);
	}
	else if (this->movementComponent->getState(MOVING_RIGHT)) {
		this->animationComponent->play("WALK_RIGHT", dt);
	}
}
