/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 08:52:34 by tglory            #+#    #+#             */
/*   Updated: 2022/02/05 08:53:28 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

Span::Span(void) : _total(0) {}

Span::Span(unsigned int N) : _total(N), _numbers(new std::vector<int>[N])
{
	return ;
}

Span::~Span(void)
{
	delete[] _numbers;
	return ;
}

Span::Span(Span const &instance) : _total(instance.getTotal()), _numbers(new std::vector<int>[this->_total])
{
	*this = instance;
}

Span &Span::operator=(Span const &rightHandSize)
{
	for (unsigned int i = 0; i < this->getTotal(); i++)
		this->_numbers[i] = rightHandSize._numbers[i];
	return (*this);
}

unsigned int	Span::getTotal(void)const
{
	return (this->_total);
}


void	Span::_checkIsFull(void)
{
	if (this->_numbers->size() == this->_total)
		throw IsFullException();
}

void	Span::_chechIsEnoughElements(void)
{
	if ((this->_total == 0) || (this->_numbers->size() <= 1))
		throw noSpanException();
}

void	Span::addNumber(int number)
{
	try
	{
		this->_checkIsFull();
		this->_numbers->push_back(number);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Span::addNumber(std::vector<int>::iterator firstNumber, std::vector<int>::iterator lastNumber)
{
	try
	{
		while (firstNumber != lastNumber)
		{
			this->_checkIsFull();
			this->_numbers->push_back(*firstNumber);
			firstNumber++;
		}
		this->_numbers->push_back(*lastNumber);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int		Span::shortestSpan(void)
{
	_chechIsEnoughElements();
	return (*min_element(this->_numbers->begin(), this->_numbers->end()));
}

int		Span::longestSpan(void)
{
	_chechIsEnoughElements();
	return (*max_element(this->_numbers->begin(), this->_numbers->end()));
}