
#include "Fixed.hpp"

Fixed::Fixed ()
{
	value = 0;
	std::cout<<"Default constructor called"<<std::endl;	
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout<<"Copy constructor called"<<std::endl;	
	*this = copy;
}

Fixed *Fixed::operator = (const Fixed &src)
{
	std::cout<<"Copy assignment operator called"<<std::endl;	
	this->value = src.getRawBits();
	return this;
}

int	Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;	
	std::cout<<(1<<8);
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
