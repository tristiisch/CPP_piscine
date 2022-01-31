/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:02:07 by tglory            #+#    #+#             */
/*   Updated: 2022/01/31 15:28:18 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed(): _rawBits(0) {}

Fixed::Fixed(Fixed const &instance)
{
	*this = instance;
}

Fixed::Fixed(const int i): _rawBits(i << this->_fractional_bits) {}

Fixed::Fixed(const float f): _rawBits((int)roundf(f * (1 << this->_fractional_bits))) {}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(Fixed const &instance)
{
	this->_rawBits = instance.getRawBits();
	return (*this);
}

// Add
Fixed Fixed::operator+(Fixed const &instance)
{
	return (this->toFloat() + instance.toFloat());
}

// Substract
Fixed Fixed::operator-(Fixed const &instance)
{
	return (this->toFloat() - instance.toFloat());
}

// Multiply
Fixed Fixed::operator*(Fixed const &instance)
{
	return (this->toFloat() * instance.toFloat());
}

// Divide
Fixed Fixed::operator/(Fixed const &instance)
{
	return (this->toFloat() / instance.toFloat());
}

bool Fixed::operator>(Fixed const &instance) const
{
	return (this->getRawBits() > instance.getRawBits());
}

bool Fixed::operator>=(Fixed const &instance) const
{
	return (this->getRawBits() >= instance.getRawBits());
}

bool Fixed::operator<(Fixed const &instance) const
{
	return (this->getRawBits() < instance.getRawBits());
}

bool Fixed::operator<=(Fixed const &instance) const
{
	return (this->getRawBits() <= instance.getRawBits());
}

bool Fixed::operator==(Fixed const &instance) const
{
	return (this->getRawBits() == instance.getRawBits());
}

bool Fixed::operator!=(Fixed const &instance) const
{
	return (this->getRawBits() != instance.getRawBits());
}

// Pre-Incrementation
Fixed &Fixed::operator++(void)
{
	this->_rawBits++;
	return (*this);
}

// Pre-Decrementation
Fixed &Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}

// Post-Incrementation
Fixed Fixed::operator++(int)
{
	Fixed result(*this);
	this->_rawBits++;
	return (result);
}

// Post-Decrementation
Fixed Fixed::operator--(int)
{
	Fixed result(*this);
	this->_rawBits--;
	return (result);
}

// Return the lowest
Fixed const &Fixed::min(Fixed const &value1, Fixed const &value2)
{
	if (value1 < value2)
		return (value1);
	return (value2);
}

// Return the greatest
Fixed const &Fixed::max(Fixed const &value1, Fixed const &value2)
{
	if (value1 > value2)
		return (value1);
	return (value2);
}

// Converts fixed-point to float
// 1 << fractional_bits == 2^(fractional_bits)
float Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (float)(1 << this->_fractional_bits));
}

// Converts fixed-point to int
// Move 8 bits to right
int Fixed::toInt(void) const
{
	return (this->_rawBits >> this->_fractional_bits);
}

int	Fixed::getRawBits() const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

// When print this class in std::cout, call toFloat and return it, in good format
std::ostream &operator<<(std::ostream &outputFile, Fixed const &i)
{
	outputFile << i.toFloat();
	return (outputFile);
}
