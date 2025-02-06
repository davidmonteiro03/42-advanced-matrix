/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:13:48 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/29 11:50:56 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/ft_matrix.hpp"

template <typename K>
Vector<K> operator*(const K &a, const Vector<K> &u) { return u * a; }

template <typename K>
Matrix<K> operator*(const K &a, const Matrix<K> &u) { return u * a; }

template <typename K>
K ft_dot(const K &a, const K &b) { return a * b; }

template <typename K>
K ft_abs(const K &a) { return a >= static_cast<K>(0) ? a : -a; }

template <typename V, typename K>
V lerp(const V &u, const V &v, const K &t) { return u * (static_cast<K>(1) - t) + v * t; }
