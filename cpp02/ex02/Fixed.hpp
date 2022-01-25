/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:07:05 by tglory            #+#    #+#             */
/*   Updated: 2022/01/25 23:00:38 by tglory           ###   ########lyon.fr   */
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
		static const Fixed &min(Fixed const &value1, Fixed const &value2);
		static const Fixed &max(Fixed const &value1, Fixed const &value2);

		Fixed();
		Fixed(const float f);
		Fixed(const int i);
		Fixed(Fixed const &instance);
		~Fixed();

		Fixed &operator=(Fixed const &instance);
		Fixed operator+(Fixed const &instance);
		Fixed operator-(Fixed const &instance);
		Fixed operator*(Fixed const &instance);
		Fixed operator/(Fixed const &instance);


		bool operator>(Fixed const &instance) const;
		bool operator>=(Fixed const &instance) const;
		bool operator<(Fixed const &instance) const;
		bool operator<=(Fixed const &instance) const;
		bool operator==(Fixed const &instance) const;
		bool operator!=(Fixed const &instance) const;

		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		float toFloat(void) const;
		int toInt(void) const;

		int getRawBits() const;
		void setRawBits(int const raw);

	private:
		static int const _fractional_bits;
		int _rawBits;

};

std::ostream &operator<<(std::ostream &outputFile, Fixed const &i);

#endif
