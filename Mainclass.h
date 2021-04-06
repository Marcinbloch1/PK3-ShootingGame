#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Mainclass
{
public:
	Mainclass();
	~Mainclass();

	float left();
	float right();
	float top();
	float bottom();

	Vector2f getPosition();

	bool isGained();
	void gain();
	
protected:
	RectangleShape shape;
	bool gained{ false };
};

