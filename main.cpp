/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:06:14 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/01 12:28:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mandatory/includes/ft_matrix.hpp"

using number_t = _Float32x;

template <typename K>
void ex00(void)
{
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Add vectors", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	add::execute<Vector<K>>({{{0, 0}, {0, 0}},
							 {{1, 0}, {0, 1}},
							 {{1, 1}, {1, 1}},
							 {{21, 21}, {21, 21}},
							 {{-21, 21}, {21, -21}},
							 {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}},
							 {{2, 3}, {5, 7}}});
	display::box("Add matrices", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	add::execute<Matrix<K>>({{{{0, 0}, {0, 0}}, {{0, 0}, {0, 0}}},
							 {{{1, 0}, {0, 1}}, {{0, 0}, {0, 0}}},
							 {{{1, 1}, {1, 1}}, {{1, 1}, {1, 1}}},
							 {{{21, 21}, {21, 21}}, {{21, 21}, {21, 21}}},
							 {{{1, 2}, {3, 4}}, {{7, 4}, {-2, 2}}}});
	display::box("Subtract vectors", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	subtract::execute<Vector<K>>({{{0, 0}, {0, 0}},
								  {{1, 0}, {0, 1}},
								  {{1, 1}, {1, 1}},
								  {{21, 21}, {21, 21}},
								  {{-21, 21}, {21, -21}},
								  {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}},
								  {{2, 3}, {5, 7}}});
	display::box("Subtract matrices", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	subtract::execute<Matrix<K>>({{{{0, 0}, {0, 0}}, {{0, 0}, {0, 0}}},
								  {{{1, 0}, {0, 1}}, {{0, 0}, {0, 0}}},
								  {{{1, 1}, {1, 1}}, {{1, 1}, {1, 1}}},
								  {{{21, 21}, {21, 21}}, {{21, 21}, {21, 21}}},
								  {{{1, 2}, {3, 4}}, {{7, 4}, {-2, 2}}}});
	display::box("Multiply vectors by scalars", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	multiply::execute<Vector<K>, K>({{{0, 0}, 1},
									 {{1, 0}, 1},
									 {{1, 1}, 2},
									 {{21, 21}, 2},
									 {{42, 42}, 0.5},
									 {{2, 3}, 2}});
	display::box("Multiply matrices by scalars", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	multiply::execute<Matrix<K>, K>({{{{0, 0}, {0, 0}}, 0},
									 {{{1, 0}, {0, 1}}, 1},
									 {{{1, 2}, {3, 4}}, 2},
									 {{{21, 21}, {21, 21}}, 0.5}});
}

template <typename K>
void ex01(void)
{
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Vectors linear combination", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	lin_comb::execute<K>({{{{-42., 42.}}, {-1.}},
						  {{{-42.}, {-42.}, {-42.}}, {-1., 1., 0.}},
						  {{{-42., 42.}, {1., 3.}, {10., 20.}}, {1., -10., -1.}},
						  {{{-42., 100., -69.5}, {1., 3., 5.}}, {1., -10.}},
						  {{{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}}, {10., -2., 0.5}},
						  {{{1., 2., 3.}, {0., 10., -100.}}, {10., -2.}}});
}

template <typename K>
void ex02(void)
{
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Scalars linear interpolation", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	lin_inter::execute<K, K>({{{0., 1.}, 0.},
							  {{0., 1.}, 1.},
							  {{0., 42.}, 0.5},
							  {{-42., 42.}, 0.5},
							  {{0., 1.}, 0.5},
							  {{21., 42.}, 0.3}});
	display::box("Vectors linear interpolation", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	lin_inter::execute<Vector<K>, K>({{{{-42., 42.}, {42., -42.}}, 0.5},
									  {{{2., 1.}, {4., 2.}}, 0.3}});
	display::box("Matrices linear interpolation", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	lin_inter::execute<Matrix<K>, K>({{{{{2., 1.}, {3., 4.}}, {{20., 10.}, {30., 40.}}}, 0.5}});
}

template <typename K>
void ex03(void)
{
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Vectors dot product", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	dot_product::execute<K>({{{0, 0}, {0, 0}},
							 {{1, 0}, {0, 0}},
							 {{1, 0}, {1, 0}},
							 {{1, 0}, {0, 1}},
							 {{1, 1}, {1, 1}},
							 {{4, 2}, {2, 1}},
							 {{0., 0.}, {1., 1.}},
							 {{-1., 6.}, {3., 2.}}});
}

template <typename K>
void ex04(void)
{
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Vectors norms", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	vector_norm::execute<K>({{0},
							 {1},
							 {0, 0},
							 {1, 0},
							 {2, 1},
							 {4, 2},
							 {-4, -2},
							 {0., 0., 0.},
							 {1., 2., 3.},
							 {-1., -2.}});
}

template <typename K>
void ex05(void)
{
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Vectors cosine similarity", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	cosine::execute<K>({{{1, 0}, {0, 1}},
						{{8, 7}, {3, 2}},
						{{1, 1}, {1, 1}},
						{{4, 2}, {1, 1}},
						{{-7, 3}, {6, 4}},
						{{1., 0.}, {1., 0.}},
						{{-1., 1.}, {1., -1.}},
						{{2., 1.}, {4., 2.}},
						{{1., 2., 3.}, {4., 5., 6.}}});
}

template <typename K>
void ex06(void)
{
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Vectors cross product", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	x_prod::execute<K>({{{0, 0, 0}, {0, 0, 0}},
						{{1, 0, 0}, {0, 0, 0}},
						{{1, 0, 0}, {0, 1, 0}},
						{{8, 7, -4}, {3, 2, 1}},
						{{1, 1, 1}, {0, 0, 0}},
						{{1, 1, 1}, {1, 1, 1}},
						{{0., 0., 1.}, {1., 0., 0.}},
						{{1., 2., 3.}, {4., 5., 6.}},
						{{4., 2., -3.}, {-2., -5., 16.}}});
}

template <typename K>
void ex07(void)
{
	const Vector<K> twoDimensionVector = {1, 2};
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Multiply matrices by vectors", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	lin_map::execute<K, Vector<K>>({{{{0, 0}, {0, 0}}, twoDimensionVector},
									{{{1, 0}, {0, 1}}, twoDimensionVector},
									{{{1, 1}, {1, 1}}, {4, 2}},
									{{{2, 0}, {0, 2}}, {2, 1}},
									{{{0.5, 0}, {0, 0.5}}, {4, 2}},
									{{{2., 0.}, {0., 2.}}, {4., 2.}},
									{{{2., -2.}, {-2., 2.}}, {4., 2.}}});
	display::box("Multiply matrices by matrices", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	lin_map::execute<K, Matrix<K>>({{{{1., 0.}, {0., 1.}}, {{1., 0.}, {0., 1.}}},
									{{{1., 0.}, {0., 1.}}, {{2., 1.}, {4., 2.}}},
									{{{3., -5.}, {6., 8.}}, {{2., 1.}, {4., 2.}}}});
}

template <typename K>
void ex08(void)
{
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Matrices traces", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	mat_trace::execute<K>({{{0, 0}, {0, 0}},
						   {{1, 0}, {0, 1}},
						   {{1, 2}, {3, 4}},
						   {{8, -7}, {4, 2}},
						   {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
						   {{2., -5., 0.}, {4., 3., 7.}, {-2., 3., 4.}},
						   {{-2., -8., 4.}, {1., -23., 4.}, {0., 6., 4.}}});
}

template <typename K>
void ex09(void)
{
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Matrices transpose", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	mat_transpose::execute<K>({{{0, 0}, {0, 0}},
							   {{1, 0}, {0, 1}},
							   {{1, 2}, {3, 4}},
							   {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
							   {{1, 2}, {3, 4}, {5, 6}}});
}

template <typename K>
void ex10(void)
{
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Matrices row_echelon", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	mat_row_echelon::execute<K>({{{0, 0}, {0, 0}},
								 {{1, 0}, {0, 1}},
								 {{4, 2}, {2, 1}},
								 {{-7, 2}, {4, 8}},
								 {{1, 2}, {4, 8}},
								 {{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}},
								 {{1., 2.}, {3., 4.}},
								 {{1., 2.}, {2., 4.}},
								 {{8., 5., -2., 4., 28.}, {4., 2.5, 20., 4., -4.}, {8., 5., 1., 4., 17.}}});
}

template <typename K>
void ex11(void)
{
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Matrices determinants", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	mat_determinant::execute<K>({{{0, 0}, {0, 0}},
								 {{1, 0}, {0, 1}},
								 {{2, 0}, {0, 2}},
								 {{1, 1}, {1, 1}},
								 {{0, 1}, {1, 0}},
								 {{1, 2}, {3, 4}},
								 {{-7, 5}, {4, 6}},
								 {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
								 {{1., -1.}, {-1., 1.}},
								 {{2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.}},
								 {{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}},
								 {{8., 5., -2., 4.}, {4., 2.5, 20., 4.}, {8., 5., 1., 4.}, {28., -4., 17., 1.}}});
}

template <typename K>
void ex12(void)
{
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Matrices inverse", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	mat_inverse::execute<K>({{{1, 0}, {0, 1}},
							 {{2, 0}, {0, 2}},
							 {{0.5, 0}, {0, 0.5}},
							 {{0, 1}, {1, 0}},
							 {{1, 2}, {3, 4}},
							 {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
							 {{2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.}},
							 {{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}}});
}

template <typename K>
void ex13(void)
{
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Matrices ranks", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	mat_rank::execute<K>({{{0, 0}, {0, 0}},
						  {{1, 0}, {0, 1}},
						  {{2, 0}, {0, 2}},
						  {{1, 1}, {1, 1}},
						  {{0, 1}, {1, 0}},
						  {{1, 2}, {3, 4}},
						  {{-7, 5}, {4, 6}},
						  {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
						  {{1., 2., 0., 0.}, {2., 4., 0., 0.}, {-1., 2., 1., 1.}},
						  {{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}, {21., 18., 7.}}});
}

int main(void)
{
	std::cout.precision(std::numeric_limits<number_t>::digits10);
	std::cerr.precision(std::numeric_limits<number_t>::digits10);

	ex00<number_t>();
	ex01<number_t>();
	ex02<number_t>();
	ex03<number_t>();
	ex04<number_t>();
	ex05<number_t>();
	ex06<number_t>();
	ex07<number_t>();
	ex08<number_t>();
	ex09<number_t>();
	ex10<number_t>();
	ex11<number_t>();
	ex12<number_t>();
	ex13<number_t>();

	return 0;
}
