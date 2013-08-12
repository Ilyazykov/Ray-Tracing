#include "Colour.h"

Colour::Colour( void )
{
	b = g = r = 0;
}

Colour::Colour( uchar a )
{
	b = g = r = a;
}

Colour::Colour( uchar blue, uchar green, uchar red )
{
	this->b = blue;
	this->g = green;
	this->r = red;
}

Colour::Colour( const Colour& colour )
{
	this->b = colour.b;
	this->g = colour.g;
	this->r = colour.r;
}

Colour::Colour( Colour&& colour )
{
	this->b = std::move(colour.b);
	this->g = std::move(colour.g);
	this->r = std::move(colour.r);
}

Colour& Colour::operator=( const Colour& colour )
{
	this->b = colour.b;
	this->g = colour.g;
	this->r = colour.r;

	return *this;
}

Colour& Colour::operator=( Colour&& colour )
{
	this->b = std::move(colour.b);
	this->g = std::move(colour.g);
	this->r = std::move(colour.r);

	return *this;
}

uchar Colour::getBlue()
{
	return b;
}

uchar Colour::getGreen()
{
	return g;
}

uchar Colour::getRed()
{
	return r;
}

Colour Colour::white()
{
	return Colour(255);
}

Colour Colour::black()
{
	return Colour(0);
}

Colour Colour::blue()
{
	return Colour(255,0,0);
}

Colour Colour::green()
{
	return Colour(0,255,0);
}

Colour Colour::red()
{
	return Colour(0,0,255);
}

Colour::~Colour( void )
{

}
