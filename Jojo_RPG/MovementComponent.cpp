#include "MovementComponent.h"



MovementComponent::MovementComponent(sf::Sprite& sprite,
	float maxVelocity, float acceleration, float deceleration)
	: sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{
	this->maxVelocity = maxVelocity;
	this->gravity = 500.f;
	this->maxVelocityY = 15.f;
	this->drag = 50.f;
}

MovementComponent::~MovementComponent()
{

}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

//Functions



const bool MovementComponent::getState(const short unsigned state) const
{
	switch (state) {

	case IDLE:
		if (this->velocity.x == 0.f && this->velocity.y == 0.f) { return true; }
		break;
	case MOVING:
		if (this->velocity.x != 0.f || this->velocity.y != 0.f) { return true; }
		break;
	case MOVING_LEFT:
		if (this->velocity.x < 0.f) { return true; }
		break;
	case MOVING_RIGHT:
		if (this->velocity.x > 0.f) { return true; }
		break;
	case MOVING_UP:
		if (this->velocity.y < 0.f) { return true; }
		break;
	case MOVING_DOWN:
		if (this->velocity.y > 0.f) { return true; }
		break;
	
	}
	return false;
}



void MovementComponent::move(const float dir_x, const float dir_y, const float& dt)
{
	/*Accelerating a sprite until reach maxVel*/

	this->velocity.x += this->acceleration * dir_x;


	//Limit Velocity


}

void MovementComponent::updatePhysics()
{
	this->velocity.y += this->gravity * 1.0;
	if (std::abs(this->velocity.y) > this->maxVelocityY)
	{
		this->velocity.y = this->maxVelocityY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}

	this->velocity.y *= drag;
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

	//Final Move
	updatePhysics();
	this->sprite.move(this->velocity * dt);//uses velocity
}


