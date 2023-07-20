
#include "Fixed.hpp"

Fixed::Fixed ()
{
	value = 0;
}

Fixed::Fixed (const int val)
{
	value = val << bits;
}

Fixed::Fixed (const float val)
{
	value = roundf(val * (1 << bits));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed& Fixed::operator = (const Fixed &src)
{
	this->value = src.value;
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

Fixed::~Fixed()
{
}

float Fixed::toFloat(void) const
{
	float val;

	val = ((float)value / (1 << bits));
	return (val);
}

int Fixed::toInt(void) const
{
	return (value >> bits);
}

std::ostream& operator<< (std::ostream& out, const Fixed& src)
{
	out<<src.toFloat();
	return out;
}

bool Fixed::operator < (const Fixed &src) const
{
	return (value < src.getRawBits());
}

bool Fixed::operator > (const Fixed &src) const
{
	return (value > src.getRawBits());
}

bool Fixed::operator == (const Fixed &src) const
{
	return (value == src.getRawBits());
}

bool Fixed::operator != (const Fixed &src) const
{
	return (value != src.getRawBits());
}

bool Fixed::operator <= (const Fixed &src) const
{
	return (value <= src.getRawBits());
}

bool Fixed::operator >= (const Fixed &src) const
{
	return (value >= src.getRawBits());
}

Fixed Fixed::operator + (const Fixed &src) 
{
	Fixed out(toFloat() + src.toFloat());

	return (out);
}

Fixed Fixed::operator - (const Fixed &src) 
{
	Fixed out(toFloat() - src.toFloat());

	return (out);
}

Fixed Fixed::operator * (const Fixed &src) 
{
	Fixed out(toFloat() * src.toFloat());

	return (out);
}

Fixed Fixed::operator / (const Fixed &src) 
{
	Fixed out(toFloat() / src.toFloat());

	return (out);
}

Fixed& Fixed::operator++(void)
{
	value++;
	return *this;
}

Fixed& Fixed::operator--(void)
{
	value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed out(*this);
	value++;
	return (out);
}

Fixed Fixed::operator--(int)
{
	Fixed out(*this);
	value--;
	return (out);
}

Fixed Fixed::min (Fixed &first, Fixed &second)
{
	if (first > second)
		return (second);
	return (first);
}

Fixed Fixed::max (Fixed &first, Fixed &second)
{
	if (first < second)
		return (second);
	return (first);
}

const Fixed Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first > second)
		return (second);
	return (first);
}

const Fixed Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first < second)
		return (second);
	return (first);
}
