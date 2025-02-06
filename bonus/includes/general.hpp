/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:42:14 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/29 11:52:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename K>
Vector<K> operator*(const K &, const Vector<K> &);

template <typename K>
Matrix<K> operator*(const K &, const Matrix<K> &);

template <typename K>
std::complex<K> ft_dot(const std::complex<K> &, const std::complex<K> &);

template <typename K>
K ft_dot(const K &, const K &);

template <typename K>
K ft_abs(const std::complex<K> &);

template <typename K>
K ft_abs(const K &);

template <typename V, typename K>
V lerp(const V &, const V &, const K &);
