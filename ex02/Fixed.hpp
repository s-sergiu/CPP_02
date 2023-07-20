
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
	private:
		int	value;
		static const int bits = 8;

	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed &copy);
		Fixed& operator = (const Fixed &src);
		bool operator < (const Fixed &src) const;
		bool operator > (const Fixed &src) const;
		bool operator == (const Fixed &src) const;
		bool operator != (const Fixed &src) const;
		bool operator <= (const Fixed &src) const;
		bool operator >= (const Fixed &src) const;
		Fixed operator + (const Fixed &src); 
		Fixed operator - (const Fixed &src); 
		Fixed operator / (const Fixed &src); 
		Fixed operator * (const Fixed &src); 
		Fixed& operator -- (void); 
		Fixed& operator ++ (void); 
		Fixed operator -- (int); 
		Fixed operator ++ (int); 
		static Fixed min (Fixed &first, Fixed &second);
		static Fixed max (Fixed &first, Fixed &second);
		static const Fixed min(const Fixed &first, const Fixed &second);
		static const Fixed max(const Fixed &first, const Fixed &second);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<< (std::ostream &out, const Fixed &src);

#endif
