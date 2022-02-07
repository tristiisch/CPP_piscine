/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:46:40 by tglory            #+#    #+#             */
/*   Updated: 2022/02/07 00:45:49 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <sstream>
# include <algorithm>
# include <limits>

class Span
{
	public:
		Span(unsigned int N);
		Span(Span const &instance);
		Span &operator=(Span const &instance);
		~Span();

		void addNumber(int number);
		void addNumber(std::vector<int>::iterator firstNumber, std::vector<int>::iterator lastNumber);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		unsigned int getTotal() const;
		std::string print() const;
	private:
		Span();

		unsigned int const total;
		std::vector<int> *numbers;
		void checkIsFull();
		void checkHasEnoughElements();
		class SpanFullException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\e[0;31mSpanFullException: Span is full\e[0m");
				}
		};

		class SpanNotEnough : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\e[0;31mSpanNotEnough: You need to have minimum 2 ints\e[0m");
				}
		};
};

std::ostream &operator<<(std::ostream &outputFile, Span const &instance);

#endif