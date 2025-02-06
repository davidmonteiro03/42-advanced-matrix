/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:13:48 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/29 11:57:36 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/ft_matrix.hpp"

template <typename K>
Vector<K> operator*(const K &a, const Vector<K> &u) { return u * a; }

template <typename K>
Matrix<K> operator*(const K &a, const Matrix<K> &u) { return u * a; }

template <typename K>
std::complex<K> ft_dot(const std::complex<K> &a, const std::complex<K> &b)
{
	return a * std::complex<K>(b.real(), -b.imag());
}

template <typename K>
K ft_dot(const K &a, const K &b) { return a * b; }

template <typename K>
K ft_abs(const std::complex<K> &a)
{
	const K realPart = a.real();
	const K imagPart = a.imag();
	const K realPow2 = std::pow(realPart, 2);
	const K imagPow2 = std::pow(imagPart, 2);
	return std::pow(realPow2 + imagPow2, 0.5);
}

template <typename K>
K ft_abs(const K &a) { return a >= static_cast<K>(0) ? a : -a; }

template <typename V, typename K>
V lerp(const V &u, const V &v, const K &t) { return u * (static_cast<K>(1) - t) + v * t; }
