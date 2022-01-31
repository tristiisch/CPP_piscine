/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:02:07 by tglory            #+#    #+#             */
/*   Updated: 2022/01/31 11:35:03 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed(): _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Creates a new Fixed instance from an existing one
Fixed::Fixed(Fixed const &instance) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = instance;
}

// Convertss int to fixed-point
// Moves 8 bits to left
Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = i << this->_fractional_bits;
}

// Converts float to fixed-point
// 1 << fractional_bits == 2^(fractional_bits)
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = (int)roundf(f * (1 << this->_fractional_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Creates a new Fixed instance from an existing one when using =
Fixed &Fixed::operator=(Fixed const &instance)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = instance.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
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

// Calls toFloat and returns it in the right format to be printed
std::ostream &operator<<(std::ostream &outputFile, Fixed const &i)
{
	outputFile << i.toFloat();
	return (outputFile);
}
