/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:04:50 by tglory            #+#    #+#             */
/*   Updated: 2022/02/06 18:00:28 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter() : raw("42") {}

Converter::Converter(std::string raw) : raw(raw) {}

Converter::Converter(Converter const &instance) : raw(instance.getRaw())
{
	*this = instance;
}

Converter &Converter::operator=(Converter const &instance)
{
	(void)instance;
	return *this;
}

Converter::~Converter() {}

const std::string Converter::getRaw() const
{
	return (this->raw);
}

void Converter::print()
{
	std::cout << "char: ";
	try
	{
		char c = this->toChar();
		std::cout << "'" << c << "'";
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << std::endl;

	std::cout << "int: ";
	try
	{
		std::cout << this->toInt();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << std::endl;

	std::cout << "float: ";
	try
	{
		std::cout << std::fixed << std::setprecision(1) << this->toFloat() << "f";
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << std::endl;

	std::cout << "double: ";
	try
	{
		std::cout << this->toDouble();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << std::endl;
}

bool Converter::isDigit()
{
	int i = 0;

	if (raw == "-inff" || raw == "+inff" || raw == "nanf" || raw == "-inf" || raw == "+inf" || raw == "nan")
		return (true);
	if (raw[i] == '-')
		++i;
	while (this->raw[i])
	{
		if (this->raw[i] == '.')
		{
			++i;
			break;
		}
		else if (this->raw[i] < '0' || this->raw[i] > '9')
			return (false);
		++i;
	}
	while (this->raw[i])
	{
		if (this->raw[i] == 'f' && !this->raw[i + 1])
			return (true);
		else if (this->raw[i] < '0' || this->raw[i] > '9')
			return (false);
		++i;
	}
	return (true);
}

bool Converter::isChar()
{
	int i = 0;

	while (this->raw[i])
	{
		if (this->raw[i] < ' ' || this->raw[i] > '~')
			return (false);
		++i;
	}
	return (true);
}

int Converter::charToDigit()
{
	if (this->raw.length() > 1)
		throw Converter::ConvertImpossible();
	int i = static_cast<int>(this->raw[0]);
	if (i < 0 || i > 128)
		throw Converter::ConvertImpossible();
	if (i < ' ' || i > '~')
		throw Converter::NotDisplayable();
	return (i);
}

char Converter::toChar()
{
	if (this->isDigit())
	{
		int i = toInt();
		if (i < ' ' || i > '~')
			throw Converter::NotDisplayable();
		double d = toDouble();
		if (i != d)
			throw Converter::ConvertImpossible();
		return static_cast<char>(i);
	}
	else if (this->isChar())
	{
		if (this->raw.length() > 1)
			throw Converter::ConvertImpossible();
		char c = static_cast<char>(this->raw[0]);
		if (c < 0)
			throw Converter::ConvertImpossible();
		if (c < ' ' || c > '~')
			throw Converter::NotDisplayable();
		return (c);
	}
	throw Converter::ConvertImpossible();
}

int Converter::toInt()
{
	if (this->isDigit())
	{
		double nb;
		try
		{
			nb = static_cast<double>(std::strtod(this->raw.c_str(), NULL));
		} catch (std::invalid_argument &e) {
			throw Converter::ConvertImpossible();
		} catch (std::out_of_range &e) {
			throw Converter::ConvertImpossible();
		}
		if (nb > std::numeric_limits<int>::max() || nb < std::numeric_limits<int>::min() || raw == "nan" || raw == "nanf")
			throw Converter::ConvertImpossible();
		return (static_cast<int>(nb));
	}
	else if (this->isChar())
			return (this->charToDigit());
	throw Converter::ConvertImpossible();
}

float Converter::toFloat()
{
	if (this->isDigit())
	{
		try
		{
			return static_cast<float>(std::strtof(this->raw.c_str(), NULL));
		} catch (std::invalid_argument &e) {
			throw Converter::ConvertImpossible();
		} catch (std::out_of_range &e) {
			throw Converter::ConvertImpossible();
		}
	}
	else if (this->isChar())
		return (this->charToDigit());
	throw Converter::ConvertImpossible();
}

double Converter::toDouble()
{
	if (this->isDigit())
	{
		try
		{
			return static_cast<double>(std::strtod(this->raw.c_str(), NULL));
		} catch (std::invalid_argument &e) {
			throw Converter::ConvertImpossible();
		} catch (std::out_of_range &e) {
			throw Converter::ConvertImpossible();
		}
	}
	else if (this->isChar())
		return (this->charToDigit());
	throw Converter::ConvertImpossible();
}
