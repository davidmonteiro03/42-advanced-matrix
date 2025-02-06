/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:51:16 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/28 13:32:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

using shape_t = std::pair<size_t, size_t>;

template <typename K>
class Matrix : public std::vector<Vector<K>>
{
private:
	using std::vector<Vector<K>>::vector;

	void sortTheRowsByTheFirstNonZeroElement(void);
	void resetToZeroTheValuesBelowEachPivot(void);
	void resetToZeroTheValuesAboveEachPivot(void);
	void normalizeThePivotsValues(void);

	Matrix<K> minorMatrix(const size_t &, const size_t &) const;

public:
	shape_t shape(void) const;
	bool isSquare(void) const;
	Vector<K> reshape(void) const;

	Matrix<K> &operator+=(const Matrix<K> &);
	Matrix<K> &operator-=(const Matrix<K> &);
	Matrix<K> &operator*=(const K &);

	Matrix<K> operator+(const Matrix<K> &) const;
	Matrix<K> operator-(const Matrix<K> &) const;
	Matrix<K> operator*(const K &) const;

	Vector<K> operator*(const Vector<K> &) const;
	Matrix<K> operator*(const Matrix<K> &) const;

	K trace(void) const;

	Matrix<K> transpose(void) const;

	Matrix<K> row_echelon(void) const;

	K determinant(void) const;

	Matrix<K> inverse(void) const;

	size_t rank(void) const;
};

template <typename K>
Matrix(std::initializer_list<std::initializer_list<K>>) -> Matrix<K>;

template <typename K>
std::ostream &operator<<(std::ostream &, const Matrix<K> &);

template <typename K>
Matrix<K> projection(const K &, const K &, const K &, const K &);
