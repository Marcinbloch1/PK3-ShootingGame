#include "pch.h"
#include "Mainclass.h"


Mainclass::Mainclass()
{
	;
}


Mainclass::~Mainclass()
{
	;
}



float Mainclass::left()
{
	return this->shape.getPosition().x - this->shape.getSize().x / 2.f;
}

float Mainclass::right()
{
	return this->shape.getPosition().x + this->shape.getSize().x / 2.f;
}

float Mainclass::top()
{
	return this->shape.getPosition().y - this->shape.getSize().y / 2.f;
}

float Mainclass::bottom()
{
	return this->shape.getPosition().y + this->shape.getSize().y / 2.f;
}



Vector2f Mainclass::getPosition()
{
	return this->shape.getPosition();
}

bool Mainclass::isGained()
{
	return this->gained;
}

void Mainclass::gain()
{
	this->gained = true;
}