/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:09:40 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/01 12:08:16 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/ft_matrix.hpp"

template <typename K>
Matrix<K> Vector<K>::reshape(const size_t &m, const size_t &n) const
{
	const Vector<K> &u = *this;
	const size_t uSize = u.size();
	if (m * n != uSize)
		throw std::invalid_argument("Invalid reshape dimensions.");
	Matrix<K> result(n);
	for (size_t i = 0; i < n; i++)
	{
		result[i] = Vector<K>(m);
		for (size_t j = 0; j < m; j++)
			result[i][j] = u[j * n + i];
	}
	return result;
}

template <typename K>
Vector<K> &Vector<K>::operator+=(const Vector<K> &v)
{
	Vector<K> &u = *this;
	const size_t uSize = u.size();
	const size_t vSize = v.size();
	if (uSize != vSize)
		throw std::invalid_argument("Vectors must have the same size.");
	for (size_t i = 0; i < uSize; i++)
		u[i] += v[i];
	return *this;
}

template <typename K>
Vector<K> &Vector<K>::operator-=(const Vector<K> &v)
{
	Vector<K> &u = *this;
	const size_t uSize = u.size();
	const size_t vSize = v.size();
	if (uSize != vSize)
		throw std::invalid_argument("Vectors must have the same size.");
	for (size_t i = 0; i < uSize; i++)
		u[i] -= v[i];
	return *this;
}

template <typename K>
Vector<K> &Vector<K>::operator*=(const K &a)
{
	Vector<K> &u = *this;
	const size_t uSize = u.size();
	for (size_t i = 0; i < uSize; i++)
	{
		if (u[i] == static_cast<K>(0))
			continue;
		if (a == static_cast<K>(0))
			u[i] = static_cast<K>(0);
		else
			u[i] *= a;
	}
	return *this;
}

template <typename K>
Vector<K> Vector<K>::operator+(const Vector<K> &v) const
{
	Vector<K> result = *this;
	return result += v;
}

template <typename K>
Vector<K> Vector<K>::operator-(const Vector<K> &v) const
{
	Vector<K> result = *this;
	return result -= v;
}

template <typename K>
Vector<K> Vector<K>::operator*(const K &a) const
{
	Vector<K> result = *this;
	return result *= a;
}

template <typename K>
K Vector<K>::dot(const Vector<K> &v) const
{
	const Vector<K> &u = *this;
	const size_t uSize = u.size();
	const size_t vSize = v.size();
	if (uSize != vSize)
		throw std::invalid_argument("Vectors must have the same size.");
	K result = 0;
	for (size_t i = 0; i < uSize; i++)
		result += ft_dot(u[i], v[i]);
	return result;
}

template <typename K>
auto Vector<K>::norm_1(void) const
{
	const Vector<K> &u = *this;
	const size_t uSize = u.size();
	if (uSize == 0)
		return ft_abs(static_cast<K>(0));
	auto result = ft_abs(u[0]);
	for (size_t i = 1; i < uSize; i++)
		result += ft_abs(u[i]);
	return result;
}

template <typename K>
auto Vector<K>::norm(void) const
{
	const Vector<K> &u = *this;
	const size_t uSize = u.size();
	if (uSize == 0)
		return ft_abs(static_cast<K>(0));
	auto result = std::pow(ft_abs(u[0]), 2);
	for (size_t i = 1; i < uSize; i++)
		result += std::pow(ft_abs(u[i]), 2);
	return std::pow(result, 0.5);
}

template <typename K>
auto Vector<K>::norm_inf(void) const
{
	const Vector<K> &u = *this;
	const size_t uSize = u.size();
	if (uSize == 0)
		return ft_abs(static_cast<K>(0));
	auto result = ft_abs(u[0]);
	for (size_t i = 1; i < uSize; i++)
		result = std::max(result, ft_abs(u[i]));
	return result;
}

template <typename K>
std::ostream &operator<<(std::ostream &os, const std::complex<K> &a)
{
	const K realPart = a.real();
	const K imagPart = a.imag();
	const K imagAbs = ft_abs(imagPart);
	if (realPart == 0 && imagPart == 0)
		return os << 0;
	if (realPart != 0)
		os << realPart;
	if (imagPart != 0)
	{
		if (realPart != 0)
			os << (imagPart > 0 ? " + " : " - ");
		else if (imagPart < 0)
			os << '-';
		if (imagAbs != 1)
			os << imagAbs;
		os << 'i';
	}
	return os;
}

template <typename K>
std::ostream &operator<<(std::ostream &os, const Vector<K> &vec)
{
	os << '[';
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (i > 0)
			os << ", ";
		os << vec[i];
	}
	return os << ']';
}

template <typename K>
Vector<K> linear_combination(const std::vector<Vector<K>> &u, const std::vector<K> &coefs)
{
	const size_t uSize = u.size();
	const size_t coefsSize = coefs.size();
	if (uSize != coefsSize)
		throw std::invalid_argument("Vectors and coefficients must have the same size.");
	if (uSize == 0)
		return Vector<K>();
	const size_t elemSize = u[0].size();
	for (size_t i = 1; i < uSize; i++)
		if (u[i].size() != elemSize)
			throw std::invalid_argument("Vectors must have the same size.");
	Vector<K> result(elemSize);
	for (size_t i = 0; i < uSize; i++)
		result += u[i] * coefs[i];
	return result;
}

template <typename K>
K angle_cos(const Vector<std::complex<K>> &u, const Vector<std::complex<K>> &v)
{
	const size_t uSize = u.size();
	const size_t vSize = v.size();
	if (uSize != vSize)
		throw std::invalid_argument("Vectors must have the same size.");
	if (uSize == 0)
		return ft_abs(static_cast<K>(0));
	return u.dot(v).real() / (u.norm() * v.norm());
}

template <typename K>
K angle_cos(const Vector<K> &u, const Vector<K> &v)
{
	const size_t uSize = u.size();
	const size_t vSize = v.size();
	if (uSize != vSize)
		throw std::invalid_argument("Vectors must have the same size.");
	if (uSize == 0)
		return ft_abs(static_cast<K>(0));
	return u.dot(v) / (u.norm() * v.norm());
}

template <typename K>
Vector<K> cross_product(const Vector<K> &u, const Vector<K> &v)
{
	const size_t uSize = u.size();
	const size_t vSize = v.size();
	if (uSize != vSize)
		throw std::invalid_argument("Vectors must have the same size.");
	if (uSize != 3)
		throw std::invalid_argument("Cross product is only defined for 3D vectors.");
	return Vector<K>{u[1] * v[2] - u[2] * v[1],
					 u[2] * v[0] - u[0] * v[2],
					 u[0] * v[1] - u[1] * v[0]};
}

template <typename K>
ssize_t Vector<K>::firstNonZeroPos(void) const
{
	const Vector<K> &u = *this;
	const size_t uSize = u.size();
	for (size_t i = 0; i < uSize; i++)
		if (u[i] != static_cast<K>(0))
			return i;
	return -1;
}
