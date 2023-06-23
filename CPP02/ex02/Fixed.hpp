/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:14:29 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/25 22:35:12 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(Fixed const &copy);
        Fixed(int const value);
        Fixed(float const value);
        ~Fixed();
        Fixed & operator=(Fixed const &copy);
        Fixed & operator++(void);
        Fixed operator++(int);
        Fixed & operator--(void);
        Fixed operator--(int);
        Fixed operator+(Fixed const &rhs);
        Fixed operator-(Fixed const &rhs);
        Fixed operator*(Fixed const &rhs);
        Fixed operator/(Fixed const &rhs);
        bool operator>(Fixed const &rhs);
        bool operator<(Fixed const &rhs);
        bool operator>=(Fixed const &rhs);
        bool operator<=(Fixed const &rhs);
        bool operator==(Fixed const &rhs);
        bool operator!=(Fixed const &rhs);
        int toInt(void) const;
        float toFloat(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
        static Fixed min(Fixed const &a, Fixed const &b);
        static Fixed max(Fixed const &a, Fixed const &b);
        static const Fixed & min(Fixed &a, Fixed &b);
        static const Fixed & max(Fixed &a, Fixed &b);
};

std::ostream & operator<<(std::ostream &o, Fixed const &rhs);

#endif