/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:09:40 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/01 12:03:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/ft_matrix.hpp"

template <typename K>
shape_t Matrix<K>::shape(void) const
{
	const Matrix<K> &self = *this;
	size_t m = self.size();
	if (m == 0)
		return shape_t(0, 0);
	size_t n = self[0].size();
	for (size_t i = 1; i < m; i++)
		if (self[i].size() != n)
			throw std::invalid_argument("The matrix must be rectangular.");
	return shape_t(m, n);
}

template <typename K>
bool Matrix<K>::isSquare(void) const
{
	const Matrix<K> &self = *this;
	const shape_t selfShape = self.shape();
	return selfShape.first == selfShape.second;
}

template <typename K>
Vector<K> Matrix<K>::reshape(void) const
{
	const Matrix<K> &self = *this;
	const shape_t selfShape = self.shape();
	const size_t resultSize = selfShape.first * selfShape.second;
	Vector<K> result(resultSize);
	for (size_t j = 0; j < selfShape.second; j++)
		for (size_t i = 0; i < selfShape.first; i++)
			result[j * selfShape.first + i] = self[i][j];
	return result;
}

template <typename K>
Matrix<K> &Matrix<K>::operator+=(const Matrix<K> &v)
{
	Matrix<K> &u = *this;
	const shape_t uShape = u.shape();
	const shape_t vShape = v.shape();
	if (uShape != vShape)
		throw std::invalid_argument("Matrices must have the same shape.");
	for (size_t i = 0; i < uShape.first; i++)
		u[i] += v[i];
	return *this;
}

template <typename K>
Matrix<K> &Matrix<K>::operator-=(const Matrix<K> &v)
{
	Matrix<K> &u = *this;
	const shape_t uShape = u.shape();
	const shape_t vShape = v.shape();
	if (uShape != vShape)
		throw std::invalid_argument("Matrices must have the same shape.");
	for (size_t i = 0; i < uShape.first; i++)
		u[i] -= v[i];
	return *this;
}

template <typename K>
Matrix<K> &Matrix<K>::operator*=(const K &a)
{
	Matrix<K> &self = *this;
	const shape_t selfShape = self.shape();
	for (size_t i = 0; i < selfShape.first; i++)
		self[i] *= a;
	return *this;
}

template <typename K>
Matrix<K> Matrix<K>::operator+(const Matrix<K> &mat) const
{
	Matrix<K> self = *this;
	return self += mat;
}

template <typename K>
Matrix<K> Matrix<K>::operator-(const Matrix<K> &mat) const
{
	Matrix<K> self = *this;
	return self -= mat;
}

template <typename K>
Matrix<K> Matrix<K>::operator*(const K &a) const
{
	Matrix<K> self = *this;
	return self *= a;
}

template <typename K>
Vector<K> Matrix<K>::operator*(const Vector<K> &vec) const
{
	const Matrix<K> &self = *this;
	const shape_t selfShape = self.shape();
	const size_t vecSize = vec.size();
	if (selfShape.second != vecSize)
		throw std::invalid_argument("The vector size must be equal to the number of columns of the matrix.");
	Vector<K> result(selfShape.first);
	for (size_t i = 0; i < selfShape.first; i++)
		for (size_t j = 0; j < selfShape.second; j++)
			result[i] += self[i][j] * vec[j];
	return result;
}

template <typename K>
Matrix<K> Matrix<K>::operator*(const Matrix<K> &mat) const
{
	const Matrix<K> &self = *this;
	const shape_t selfShape = self.shape();
	const shape_t matShape = mat.shape();
	if (selfShape.first != matShape.second || selfShape.second != matShape.first)
		throw std::invalid_argument("The number of columns of the matrix must the the number of rows of the other and vice-versa.");
	Matrix<K> result(selfShape.first);
	for (size_t i = 0; i < selfShape.first; i++)
	{
		result[i] = Vector<K>(matShape.second);
		for (size_t j = 0; j < matShape.second; j++)
			for (size_t k = 0; k < matShape.first; k++)
				result[i][j] += self[i][k] * mat[k][j];
	}
	return result;
}

template <typename K>
K Matrix<K>::trace(void) const
{
	const Matrix<K> &self = *this;
	const shape_t selfShape = self.shape();
	if (self.isSquare() != true)
		throw std::invalid_argument("The matrix must be square.");
	K result = 0;
	for (size_t i = 0; i < selfShape.first; i++)
		result += self[i][i];
	return result;
}

template <typename K>
Matrix<K> Matrix<K>::transpose(void) const
{
	const Matrix<K> &self = *this;
	const shape_t selfShape = self.shape();
	Matrix<K> result(selfShape.second);
	for (size_t i = 0; i < selfShape.second; i++)
	{
		result[i] = Vector<K>(selfShape.first);
		for (size_t j = 0; j < selfShape.first; j++)
			result[i][j] = self[j][i];
	}
	return result;
}

template <typename K>
void Matrix<K>::sortTheRowsByTheFirstNonZeroElement(void)
{
	Matrix<K> &self = *this;
	const shape_t selfShape = self.shape();
	std::vector<ssize_t> pivotsPoss(selfShape.first);
	for (size_t i = 0; i < selfShape.first; i++)
		pivotsPoss[i] = self[i].firstNonZeroPos();
	for (size_t i = 0; i < selfShape.first; i++)
	{
		for (size_t j = i + 1; j < selfShape.first; j++)
		{
			if (pivotsPoss[j] == -1)
				continue;
			if (pivotsPoss[i] == -1 || pivotsPoss[i] > pivotsPoss[j] ||
				(pivotsPoss[i] == pivotsPoss[j] && ft_abs(self[i][pivotsPoss[i]]) > ft_abs(self[j][pivotsPoss[j]])))
			{
				std::swap(pivotsPoss[i], pivotsPoss[j]);
				std::swap(self[i], self[j]);
			}
		}
	}
}

template <typename K>
void Matrix<K>::resetToZeroTheValuesBelowEachPivot(void)
{
	Matrix<K> &self = *this;
	self.sortTheRowsByTheFirstNonZeroElement();
	const shape_t selfShape = self.shape();
	for (size_t j = 0; j < selfShape.second; j++)
	{
		for (size_t i = j + 1; i < selfShape.first; i++)
		{
			ssize_t currPivotPos = self[i].firstNonZeroPos();
			ssize_t prevPivotPos = self[j].firstNonZeroPos();
			if (currPivotPos == prevPivotPos)
				self[i] = self[i] * self[j][prevPivotPos] - self[j] * self[i][currPivotPos];
		}
	}
}

template <typename K>
void Matrix<K>::resetToZeroTheValuesAboveEachPivot(void)
{
	Matrix<K> &self = *this;
	self.sortTheRowsByTheFirstNonZeroElement();
	const shape_t selfShape = self.shape();
	for (size_t i = 0; i < selfShape.first; i++)
	{
		for (size_t j = i + 1; j < selfShape.first; j++)
		{
			ssize_t pivotPos = self[j].firstNonZeroPos();
			if (pivotPos == -1)
				continue;
			self[i] = self[i] * self[j][pivotPos] - self[j] * self[i][pivotPos];
		}
	}
}

template <typename K>
void Matrix<K>::normalizeThePivotsValues(void)
{
	Matrix<K> &self = *this;
	self.sortTheRowsByTheFirstNonZeroElement();
	const shape_t selfShape = self.shape();
	for (size_t i = 0; i < selfShape.first; i++)
	{
		ssize_t pivotPos = self[i].firstNonZeroPos();
		if (pivotPos == -1)
			continue;
		self[i] *= static_cast<K>(1) / self[i][pivotPos];
	}
}

template <typename K>
Matrix<K> Matrix<K>::row_echelon(void) const
{
	Matrix<K> result = *this;
	result.resetToZeroTheValuesBelowEachPivot();
	result.resetToZeroTheValuesAboveEachPivot();
	result.normalizeThePivotsValues();
	return result;
}

template <typename K>
Matrix<K> Matrix<K>::minorMatrix(const size_t &m, const size_t &n) const
{
	const Matrix<K> &self = *this;
	const shape_t selfShape = self.shape();
	Matrix<K> extracted(selfShape.first - 1);
	size_t extractedRow = 0;
	for (size_t i = 0; i < selfShape.first; i++)
	{
		if (i == m)
			continue;
		extracted[extractedRow] = Vector<K>(selfShape.second - 1);
		size_t extractedColumn = 0;
		for (size_t j = 0; j < selfShape.second; j++)
		{
			if (j == n)
				continue;
			extracted[extractedRow][extractedColumn++] = self[i][j];
		}
		extractedRow++;
	}
	return extracted;
}

template <typename K>
K Matrix<K>::determinant(void) const
{
	const Matrix<K> &self = *this;
	const shape_t selfShape = self.shape();
	if (self.isSquare() != true)
		throw std::invalid_argument("The matrix must be square.");
	if (selfShape.first == 0)
		return static_cast<K>(1);
	if (selfShape.first == 1)
		return self[0][0];
	if (selfShape.first == 2)
		return self[0][0] * self[1][1] - self[0][1] * self[1][0];
	K result = 0;
	for (size_t i = 0; i < selfShape.first; i++)
	{
		const Matrix<K> extract = self.minorMatrix(0, i);
		if (extract.determinant() == static_cast<K>(0))
			continue;
		result += self[0][i] * (i % 2 == 0 ? extract.determinant() : -extract.determinant());
	}
	return result;
}

template <typename K>
Matrix<K> Matrix<K>::inverse(void) const
{
	const Matrix<K> &self = *this;
	const shape_t selfShape = self.shape();
	if (self.isSquare() != true)
		throw std::invalid_argument("The matrix must be square.");
	Matrix<K> result(selfShape.first);
	for (size_t i = 0; i < selfShape.first; i++)
	{
		result[i] = Vector<K>(selfShape.second);
		for (size_t j = 0; j < selfShape.second; j++)
		{
			Matrix<K> extract = self.minorMatrix(i, j);
			if (extract.determinant() == static_cast<K>(0))
				continue;
			result[i][j] = (i + j) % 2 == 0 ? extract.determinant() : -extract.determinant();
		}
	}
	result = result.transpose();
	if (self.determinant() == static_cast<K>(0))
		throw std::invalid_argument("The matrix must be invertible.");
	result *= static_cast<K>(1) / self.determinant();
	return result;
}

template <typename K>
size_t Matrix<K>::rank(void) const
{
	const Matrix<K> reduced = this->row_echelon();
	const shape_t reducedShape = reduced.shape();
	size_t result = 0;
	for (size_t i = 0; i < reducedShape.first; i++)
	{
		ssize_t pivotPos = reduced[i].firstNonZeroPos();
		result += pivotPos != -1;
	}
	return result;
}

template <typename K>
std::ostream &operator<<(std::ostream &os, const Matrix<K> &mat)
{
	const shape_t matShape = mat.shape();
	os << '[';
	for (size_t i = 0; i < matShape.first; i++)
	{
		if (i > 0)
			os << std::endl
			   << ' ';
		os << mat[i];
	}
	return os << ']';
}
