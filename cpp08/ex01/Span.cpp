/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 08:52:34 by tglory            #+#    #+#             */
/*   Updated: 2022/02/11 18:00:52 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : total(0) {}

Span::Span(unsigned int N) : total(N), numbers(new std::vector<int>[N]) {}

Span &Span::operator=(Span const &instance)
{
	for (unsigned int i = 0; i < this->getTotal(); ++i)
		this->numbers[i] = instance.numbers[i];
	return (*this);
}

Span::Span(Span const &instance) : total(instance.getTotal()), numbers(new std::vector<int>[this->total])
{
	*this = instance;
}

Span::~Span()
{
	delete[] numbers;
}

unsigned int Span::getTotal()const
{
	return (this->total);
}

void Span::checkIsFull() const
{
	if (this->numbers->size() == this->total)
		throw SpanFullException();
}

void Span::checkHasEnoughElements() const
{
	if ((this->total == 0) || (this->numbers->size() <= 1))
		throw SpanNotEnough();
}

void Span::addNumber(int number)
{
	this->checkIsFull();
	this->numbers->push_back(number);
}

void Span::addNumber(std::vector<int>::iterator firstNumber, std::vector<int>::iterator lastNumber)
{
	try {
		while (firstNumber != lastNumber)
		{
			this->checkIsFull();
			this->numbers->push_back(*firstNumber++);
		}
	} catch (std::exception &e) {
		throw e;
	}
}

unsigned int Span::shortestSpan() const
{
	checkHasEnoughElements();

	long span = -1;
	unsigned int temp;
	for (unsigned int i = 0; i < this->numbers->size(); ++i)
	{
		for (unsigned int j = 0; j < i; ++j)
		{
			if ((*this->numbers)[i] > (*this->numbers)[j])
			{
				if (span > (temp = (*this->numbers)[i] - (*this->numbers)[j]) || span == -1)
					span = temp;
			}
			else if ((*this->numbers)[i] < (*this->numbers)[j])
			{
				if (span > (temp = (*this->numbers)[j] - (*this->numbers)[i]) || span == -1)
					span = temp;
			}
			else if (span == -1 || span > 0)
				span = 0;
		}
	}
	return (static_cast<unsigned int>(span));
}

unsigned int Span::longestSpan() const
{
	checkHasEnoughElements();

	long span = -1;
	unsigned int temp;
	for (unsigned int i = 0; i < this->numbers->size(); ++i)
	{
		for (unsigned int j = 0; j < i; ++j)
		{
			if ((*this->numbers)[i] > (*this->numbers)[j])
			{
				if (span < (temp = (*this->numbers)[i] - (*this->numbers)[j]) || span == -1)
					span = temp;
			}
			else if ((*this->numbers)[i] < (*this->numbers)[j])
			{
				if (span < (temp = (*this->numbers)[j] - (*this->numbers)[i]) || span == -1)
					span = temp;
			}
			else if (span == -1)
				span = 0;
		}
	}
	return (static_cast<unsigned int>(span));
}

std::string Span::print() const
{
	std::stringstream ss;

	for (unsigned int i = 0; i < this->numbers->size(); ++i)
	{
		ss << (*this->numbers)[i];
		if (i != this->numbers->size() - 1)
			ss << ", ";
	}
	return ss.str();
}

std::ostream &operator<<(std::ostream &outputFile, Span const &instance)
{
	outputFile << instance.print();
	return outputFile;
}
