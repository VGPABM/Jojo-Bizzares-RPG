#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

#include<vector>
#include <iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include <vector>
#include <stack>
#include <map>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

enum movement_states { IDLE = 0, MOVING, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN };

class MovementComponent
{
private:
	sf::Sprite& sprite;

	float maxVelocity;
	float minVelocity;
	float acceleration;
	float deceleration;
	float drag;
	float gravity;
	float maxVelocityY;

	sf::Vector2f velocity;
	

	//Initializing Function


public:

	MovementComponent(sf::Sprite& sprite,float maxVelocity, float acceleration, float deceleration);
	virtual ~MovementComponent();

	//Accessors
	const sf::Vector2f& getVelocity() const;

	//Functions
	const bool getState(const short unsigned state) const;


	void move(const float x, const float y,const float& dt);
	void update(const float& dt);
	void updatePhysics();

};
#endif
