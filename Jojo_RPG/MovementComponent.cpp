#include "MovementComponent.h"



MovementComponent::MovementComponent(sf::Sprite& sprite,
	float maxVelocity, float acceleration, float deceleration)
	: sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{
	this->maxVelocity = maxVelocity;
}

MovementComponent::~MovementComponent()
{

}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

//Functions

const bool MovementComponent::Idle() const
{
	if (this->velocity.x == 0.f && this->velocity.y == 0.f) { return true; }

	return false;
}

void MovementComponent::move(const float dir_x, const float dir_y, const float& dt)
{
	/*Accelerating a sprite until reach maxVel*/

	this->velocity.x += this->acceleration * dir_x;
	this->velocity.y += this->acceleration * dir_y;

	
}

void MovementComponent::update(const float& dt)
{
	/*Decelerates sprite and control to max velocity, also move the sprite*/

	//Deceleration X
	if (this->velocity.x > 0.f) // check for right
	{
		//Max Vel Check right
		if (this->velocity.x > this->maxVelocity) {
			this->velocity.x = this->maxVelocity;
		}

		//Deceleration X positive
		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f) 
		{
			this->velocity.x = 0.f;
		}

	}
	else if (this->velocity.x < 0.f) // check for right
	{
		//Max Vel check x positive
		if (this->velocity.x < -this->maxVelocity) {
			this->velocity.x = -this->maxVelocity;
		}
		
		//Deceleration X negative
		this->velocity.x += deceleration;
		if (this->velocity.x > 0.f)
		{
			this->velocity.x = 0.f;
		}

	}

	//Deceleration Y
	if (this->velocity.y > 0.f) // check for up
	{
		//Max Vel Check y positive
		if (this->velocity.y > this->maxVelocity) {
			this->velocity.y = this->maxVelocity;
		}

		//Deceleration y positive
		this->velocity.y -= deceleration;
		if (this->velocity.y < 0.f)
		{
			this->velocity.y = 0.f;
		}

	}
	else if (this->velocity.y < 0.f) //check for down
	{
		//Max Vel check y negative
		if (this->velocity.y < -this->maxVelocity) {
			this->velocity.y = -this->maxVelocity;
		}

		//Deceleration y negative
		this->velocity.y += deceleration;
		if (this->velocity.y > 0.f)
		{
			this->velocity.y = 0.f;
		}

	}


	//Final Move
	this->sprite.move(this->velocity * dt);//uses velocity
}
