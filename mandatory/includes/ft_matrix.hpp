/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:06:26 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/29 10:01:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include <cmath>

template <typename K>
class Vector;

template <typename K>
class Matrix;

#include "./Vector.hpp"
#include "./Matrix.hpp"

#include "./display.hpp"
#include "./general.hpp"
#include "./add.hpp"
#include "./subtract.hpp"
#include "./multiply.hpp"
#include "./lin_comb.hpp"
#include "./lin_inter.hpp"
#include "./dot_product.hpp"
#include "./vector_norm.hpp"
#include "./cosine.hpp"
#include "./x_prod.hpp"
#include "./lin_map.hpp"
#include "./mat_trace.hpp"
#include "./mat_transpose.hpp"
#include "./mat_row_echelon.hpp"
#include "./mat_determinant.hpp"
#include "./mat_inverse.hpp"
#include "./mat_rank.hpp"

#define STRINGIFY(x) #x
#define BOX_SIZE 64

#include "../tmps/Vector.tpp"
#include "../tmps/Matrix.tpp"

#include "../tmps/display.tpp"
#include "../tmps/general.tpp"
#include "../tmps/add.tpp"
#include "../tmps/subtract.tpp"
#include "../tmps/multiply.tpp"
#include "../tmps/lin_comb.tpp"
#include "../tmps/lin_inter.tpp"
#include "../tmps/dot_product.tpp"
#include "../tmps/vector_norm.tpp"
#include "../tmps/cosine.tpp"
#include "../tmps/x_prod.tpp"
#include "../tmps/lin_map.tpp"
#include "../tmps/mat_trace.tpp"
#include "../tmps/mat_transpose.tpp"
#include "../tmps/mat_row_echelon.tpp"
#include "../tmps/mat_determinant.tpp"
#include "../tmps/mat_inverse.tpp"
#include "../tmps/mat_rank.tpp"
