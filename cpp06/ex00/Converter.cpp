/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:04:50 by tglory            #+#    #+#             */
/*   Updated: 2022/02/04 02:25:36 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter() : raw("42") {}

Converter::Converter(const char *raw) : raw(raw) {}

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

const char *Converter::getRaw() const
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

	while (raw[i])
	{
		if (raw[i] < '0' || raw[i] > '9')
			return (false);
		++i;
	}
	return (true);
}

int Converter::toInt()
{
	long nb = static_cast<long>(std::strtold(raw, NULL));
	// if (nb > 2147483647 || nb < -2147483648 || raw == "nan" || raw == "nanf")
	if (nb > 2147483647 || nb < -2147483648)
		throw Converter::ConvertImpossible();
	return (static_cast<int>(nb));
}

char Converter::toChar()
{
	if (isDigit()) {
		int i;
		try
		{
			i = toInt();
		} catch (std::exception &e) {
			throw e;
		}
		if (i < ' ' || i > '~')
			throw Converter::NotDisplayable();
		return static_cast<char>(i);
	}
	if (std::strlen(raw) > 1)
		throw Converter::ConvertImpossible();
	char c = static_cast<char>(raw[0]);
	if (c < ' ' || c > '~')
		throw Converter::NotDisplayable();
	return (c);
}

float Converter::toFloat(void)
{
	return static_cast<float>(std::strtof(this->raw, NULL));
}

double Converter::toDouble(void)
{
	return static_cast<double>(std::strtod(this->raw, NULL));
}