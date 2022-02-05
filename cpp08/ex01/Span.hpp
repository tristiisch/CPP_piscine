
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

class Span
{
private:
	unsigned int const	_total;
	std::vector<int>	*_numbers;
	void				_checkIsFull(void);
	void				_chechIsEnoughElements(void);

	Span(void);

	class IsFullException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("\e[0;31mSpan is full\e[0m");
			}
	};

	class noSpanException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("\e[0;31mthere is no span to find\e[0m");
			}
	};

public:
	Span(unsigned int N);
	Span(Span const &instance);
	~Span(void);

	Span			&operator=(Span const &rightHandSize);
	void			addNumber(int number);
	void			addNumber(std::vector<int>::iterator firstNumber, std::vector<int>::iterator lastNumber);
	int				shortestSpan(void);
	int				longestSpan(void);
	unsigned int	getTotal(void)const;
};

#endif