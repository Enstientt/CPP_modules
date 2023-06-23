/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:14:25 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/27 14:00:19 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->_fixedPointValue = 0;
}

Fixed::Fixed(Fixed const &copy)
{
    *this = copy;
}

Fixed::Fixed(int const n)
{
      if (n > (1 << 23) - 1 || n < -(1 << 23))
    {
        std::cerr << "Error: integer value out of range for fixed-point format" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->_fixedPointValue = n << this->_fractionalBits;
}

Fixed::Fixed(float const n)
{
    float max_value = (float)((1 << 23) - 1) / (1 << this->_fractionalBits);
    float min_value = -(float)(1 << 23) / (1 << this->_fractionalBits);
    if (n > max_value || n < min_value) {
        std::cerr << "Error: float value out of range for fixed-point format" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->_fixedPointValue = roundf(n * (1 << this->_fractionalBits));
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
    return (this->_fixedPointValue);
}

Fixed & Fixed::operator=(Fixed const &copy)
{
    if (this != &copy)
        this->_fixedPointValue = copy.getRawBits();
    return (*this);
}


void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->_fixedPointValue >> this->_fractionalBits);
}

std::ostream & operator<<(std::ostream &o, Fixed const &rhs)
{
    o << rhs.toFloat();
    return (o);
}
Fixed & Fixed::operator++(void)
{
    (this->_fixedPointValue)++;
    return *this;
}
Fixed  Fixed::operator++(int)
{
    Fixed obj  = *this;
    operator++();
    return obj;
}

Fixed & Fixed::operator--(void)
{
    --(this->_fixedPointValue);
    return *this;
}
Fixed  Fixed::operator--(int)
{
    Fixed obj  = *this;
    operator--();
    return obj;
}
Fixed Fixed::operator+(Fixed const &rhs)
{
    Fixed ret(this->toFloat() + rhs.toFloat());
    return ret;
}

Fixed Fixed::operator-(Fixed const &rhs)
{
    Fixed ret(this->toFloat() - rhs.toFloat());
    return ret;
}

Fixed Fixed::operator*(Fixed const &rhs)
{
    Fixed ret(this->toFloat() * rhs.toFloat());
    return ret;
}

Fixed Fixed::operator/(Fixed const &rhs)
{
    Fixed ret(this->toFloat() / rhs.toFloat());
    return ret;
}

bool Fixed::operator>(Fixed const &rhs)
{
    return this->_fixedPointValue > rhs._fixedPointValue;
}

bool Fixed::operator>=(Fixed const &rhs)
{
    return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator<=(Fixed const &rhs)
{
    return this->_fixedPointValue <= rhs._fixedPointValue;
}

bool Fixed::operator<(Fixed const &rhs)
{
    return this->_fixedPointValue < rhs._fixedPointValue;
}

bool Fixed::operator==(Fixed const &rhs)
{
    return this->_fixedPointValue == rhs._fixedPointValue;
}

bool Fixed::operator!=(Fixed const &rhs)
{
    return this->_fixedPointValue != rhs._fixedPointValue;
}

Fixed Fixed::min(Fixed const &a,Fixed const &b)
{
    if (a._fixedPointValue > b._fixedPointValue)
        return (b);
    return (a);
}

Fixed Fixed::max(Fixed const &a,Fixed const &b)
{
       if (a._fixedPointValue > b._fixedPointValue)
        return (a);
    return (b);
}

const Fixed & Fixed::min(Fixed &a,Fixed &b)
{
    if (a._fixedPointValue > b._fixedPointValue)
        return (b);
    return (a);
}

const Fixed & Fixed::max(Fixed  &a,Fixed  &b)
{
    if (a._fixedPointValue > b._fixedPointValue)
        return (a);
    return (b);
}