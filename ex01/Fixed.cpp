
#include "Fixed.hpp"

Fixed::Fixed ()
{
	value = 0;
	std::cout<<"Default constructor called"<<std::endl;	
}

Fixed::Fixed (const int val)
{
	(void)val;
	std::cout<<"Int constructor called"<<std::endl;	
}

Fixed::Fixed (const float val)
{
	(void)val;
	std::cout<<"Float constructor called"<<std::endl;	
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout<<"Copy constructor called"<<std::endl;	
	*this = copy;
}

Fixed& Fixed::operator = (const Fixed &src)
{
	std::cout<<"Copy assignment operator called"<<std::endl;	
	this->value = src.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;	
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

Fixed::~Fixed()
{
	std::cout<<"Deconstructor called"<<std::endl;	
}

float Fixed::toFloat(void) const
{

	return (0.0);
}

int Fixed::toInt(void) const
{

	return (0);
}

std::ostream& operator<< (std::ostream& out, const Fixed& src)
{
	out<<src.getRawBits();
	return out;
}

