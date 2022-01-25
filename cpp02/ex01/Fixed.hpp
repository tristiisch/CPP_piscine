/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:07:05 by tglory            #+#    #+#             */
/*   Updated: 2022/01/25 22:15:05 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const float f);
		Fixed(const int i);
		Fixed(Fixed const &instance);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
		Fixed &operator=(Fixed const &instance);
		float toFloat(void) const;
		int toInt(void) const;

	private:
		static int const _fractional_bits;
		int _rawBits;

};

std::ostream &operator<<(std::ostream &outputFile, Fixed const &i);

#endif
