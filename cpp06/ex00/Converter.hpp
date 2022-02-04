/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:05:06 by tglory            #+#    #+#             */
/*   Updated: 2022/02/04 02:20:12 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <cstdlib>
# include <cstring>
# include <iomanip>

class Converter
{
	public:
		Converter();
		Converter(const char *raw);
		Converter(Converter const &instance);
		Converter &operator=(Converter const &instance);
		~Converter();
		const char *getRaw() const; 
		void print();
		
		class ConvertImpossible : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("impossible");
				}
		};		
		class NotDisplayable : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Non displayable");
				}
		};
	private:
		const char *raw;
		bool			isDigit(void);
		int				toInt(void);
		float			toFloat(void);
		double			toDouble(void);
		char			toChar(void);
};

#endif
