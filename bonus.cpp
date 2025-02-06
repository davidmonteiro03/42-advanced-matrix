/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:06:14 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/29 13:36:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bonus/includes/ft_matrix.hpp"

using real_t = _Float32x;
using complex_t = std::complex<real_t>;

template <typename K>
void ex00(void)
{
	using vector_add_sub_tests_t = std::vector<std::pair<Vector<K>, Vector<K>>>;
	using matrix_add_sub_tests_t = std::vector<std::pair<Matrix<K>, Matrix<K>>>;
	using vector_mul_tests_t = std::vector<std::pair<Vector<K>, K>>;
	using matrix_mul_tests_t = std::vector<std::pair<Matrix<K>, K>>;

	const vector_add_sub_tests_t testsAddSubVector = {{{{1., 2.}, {3., 4.}},
													   {{5., 6.}, {7., 8.}}}};
	const matrix_add_sub_tests_t testsAddSubMatrix = {{{{{1., 2.}, {3., 4.}},
														{{5., 6.}, {7., 8.}}},
													   {{{9., 10.}, {11., 12.}},
														{{13., 14.}, {15., 16.}}}}};
	const vector_mul_tests_t testsMulVector = {{{{1., 2.}, {3., 4.}}, {5., 6.}}};
	const matrix_mul_tests_t testsMulMatrix = {{{{{1., 2.}, {3., 4.}},
												 {{5., 6.}, {7., 8.}}},
												{9., 10.}}};
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Add vectors", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	add::execute<Vector<K>>(testsAddSubVector);
	display::box("Add matrices", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	add::execute<Matrix<K>>(testsAddSubMatrix);
	display::box("Subtract vectors", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	subtract::execute<Vector<K>>(testsAddSubVector);
	display::box("Subtract matrices", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	subtract::execute<Matrix<K>>(testsAddSubMatrix);
	display::box("Multiply vectors by scalars", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	multiply::execute<Vector<K>, K>(testsMulVector);
	display::box("Multiply matrices by scalars", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	multiply::execute<Matrix<K>, K>(testsMulMatrix);
}

template <typename K>
void ex01(void)
{
	using vector_comb_tests_t = std::vector<std::pair<std::vector<Vector<K>>, std::vector<K>>>;

	const vector_comb_tests_t tests = {{{{{1., 2.}, {3., 4.}},
										 {{5., 6.}, {7., 8.}},
										 {{9., 10.}, {11., 12.}}},
										{{13., 14.}, {15., 16.}, {17., 18.}}}};
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Vectors linear combination", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	lin_comb::execute<K>(tests);
}

template <typename K>
void ex02(void)
{
	using scalar_inter_tests_t = std::vector<std::pair<std::pair<K, K>, typename K::value_type>>;
	using vector_inter_tests_t = std::vector<std::pair<std::pair<Vector<K>, Vector<K>>, typename K::value_type>>;
	using matrix_inter_tests_t = std::vector<std::pair<std::pair<Matrix<K>, Matrix<K>>, typename K::value_type>>;

	const scalar_inter_tests_t testsScalar = {{{{1., 2.}, {3., 4.}}, 0.},
											  {{{1., 2.}, {3., 4.}}, 0.5},
											  {{{1., 2.}, {3., 4.}}, 1.}};
	const vector_inter_tests_t testsVector = {{{{{1., 2.}, {3., 4.}},
												{{5., 6.}, {7., 8.}}},
											   0.},
											  {{{{1., 2.}, {3., 4.}},
												{{5., 6.}, {7., 8.}}},
											   0.5},
											  {{{{1., 2.}, {3., 4.}},
												{{5., 6.}, {7., 8.}}},
											   1.}};
	const matrix_inter_tests_t testsMatrix = {{{{{{1., 2.}, {3., 4.}},
												 {{5., 6.}, {7., 8.}}},
												{{{9., 10.}, {11., 12.}},
												 {{13., 14.}, {15., 16.}}}},
											   0.},
											  {{{{{1., 2.}, {3., 4.}},
												 {{5., 6.}, {7., 8.}}},
												{{{9., 10.}, {11., 12.}},
												 {{13., 14.}, {15., 16.}}}},
											   0.5},
											  {{{{{1., 2.}, {3., 4.}},
												 {{5., 6.}, {7., 8.}}},
												{{{9., 10.}, {11., 12.}},
												 {{13., 14.}, {15., 16.}}}},
											   1.}};
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Scalars linear interpolation", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	lin_inter::execute<K, typename K::value_type>(testsScalar);
	display::box("Vectors linear interpolation", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	lin_inter::execute<Vector<K>, typename K::value_type>(testsVector);
	display::box("Matrices linear interpolation", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	lin_inter::execute<Matrix<K>, typename K::value_type>(testsMatrix);
}

template <typename K>
void ex03(void)
{
	using vector_dot_prod_tests_t = std::vector<std::pair<Vector<K>, Vector<K>>>;

	const vector_dot_prod_tests_t tests = {{{{1., 2.}, {3., 4.}},
											{{5., 6.}, {7., 8.}}}};
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Vectors dot product", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	dot_product::execute<K>(tests);
}

template <typename K>
void ex04(void)
{
	using vector_norm_tests_t = std::vector<Vector<K>>;

	const vector_norm_tests_t tests = {{{1., 2.}, {3., 4.}, {5., 6.}, {7., 8.}}};
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Vectors norms", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	vector_norm::execute<K>(tests);
}

template <typename K>
void ex05(void)
{
	using vector_cosine_tests_t = std::vector<std::pair<Vector<K>, Vector<K>>>;

	const vector_cosine_tests_t tests = {{{{1., 2.}, {3., 4.}, {5., 6.}, {7., 8.}},
										  {{9., 10.}, {11., 12.}, {13., 14.}, {15., 16.}}}};
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Vectors cosine similarity", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	cosine::execute<K>(tests);
}

template <typename K>
void ex06(void)
{
	using vector_x_prod_tests_t = std::vector<std::pair<Vector<K>, Vector<K>>>;

	const vector_x_prod_tests_t tests = {{{{1., 2.}, {3., 4.}, {5., 6.}},
										  {{7., 8.}, {9., 10.}, {11., 12.}}}};
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Vectors cross product", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	x_prod::execute<K>(tests);
}

template <typename K>
void ex07(void)
{
	using matrix_mul_vector_tests_t = std::vector<std::pair<Matrix<K>, Vector<K>>>;
	using matrix_mul_matrix_tests_t = std::vector<std::pair<Matrix<K>, Matrix<K>>>;

	const matrix_mul_vector_tests_t testsMatrixMulVector = {{{{{1., 2.}, {3., 4.}},
															  {{5., 6.}, {7., 8.}}},
															 {{9., 10.}, {11., 12.}}}};
	const matrix_mul_matrix_tests_t testsMatrixMulMatrix = {{{{{1., 2.}, {3., 4.}},
															  {{5., 6.}, {7., 8.}}},
															 {{{9., 10.}, {11., 12.}},
															  {{13., 14.}, {15., 16.}}}}};
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Multiply matrices by vectors", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	lin_map::execute<K, Vector<K>>(testsMatrixMulVector);
	display::box("Multiply matrices by matrices", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	lin_map::execute<K, Matrix<K>>(testsMatrixMulMatrix);
}

template <typename K>
void ex08(void)
{
	using matrix_trace_tests_t = std::vector<Matrix<K>>;

	const matrix_trace_tests_t tests = {{{{1., 2.}, {3., 4.}, {5., 6.}},
										 {{7., 8.}, {9., 10.}, {11., 12.}},
										 {{13., 14.}, {15., 16.}, {17., 18.}}}};
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Matrices traces", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	mat_trace::execute<K>(tests);
}

template <typename K>
void ex09(void)
{
	using matrix_transpose_tests_t = std::vector<Matrix<K>>;

	const matrix_transpose_tests_t tests = {{{{1., 2.}, {3., 4.}, {5., 6.}},
											 {{7., 8.}, {9., 10.}, {11., 12.}},
											 {{13., 14.}, {15., 16.}, {17., 18.}}}};
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Matrices transpose", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	mat_transpose::execute<K>(tests);
}

template <typename K>
void ex10(void)
{
	using matrix_row_echelon_tests_t = std::vector<Matrix<K>>;

	const matrix_row_echelon_tests_t tests = {{{{1., 2.}, {3., 4.}, {5., 6.}},
											   {{7., 8.}, {9., 10.}, {11., 12.}},
											   {{13., 14.}, {15., 16.}, {17., 18.}}}};
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Matrices row_echelon", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	mat_row_echelon::execute<K>(tests);
}

template <typename K>
void ex11(void)
{
	using matrix_determinant_tests_t = std::vector<Matrix<K>>;

	const matrix_determinant_tests_t tests = {{{{-1., 2.}, {3., 4.}, {5., 6.}},
											   {{7., 8.}, {9., 10.}, {11., 12.}},
											   {{13., 14.}, {15., 16.}, {17., 18.}}}};
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Matrices determinants", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	mat_determinant::execute<K>(tests);
}

template <typename K>
void ex12(void)
{
	using matrix_inverse_tests_t = std::vector<Matrix<K>>;

	const matrix_inverse_tests_t tests = {{{{-1., 2.}, {3., 4.}, {5., 6.}},
										   {{7., 8.}, {9., 10.}, {11., 12.}},
										   {{13., 14.}, {15., 16.}, {17., 18.}}}};
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Matrices inverse", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	mat_inverse::execute<K>(tests);
}

template <typename K>
void ex13(void)
{
	using matrix_rank_tests_t = std::vector<Matrix<K>>;

	const matrix_rank_tests_t tests = {{{{-1., 2.}, {3., 4.}, {5., 6.}},
										{{7., 8.}, {9., 10.}, {11., 12.}},
										{{13., 14.}, {15., 16.}, {17., 18.}}}};
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Matrices ranks", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	mat_rank::execute<K>(tests);
}

template <typename K>
void ex14(void)
{
	const K angle = 70.;

	const K fov = angle * static_cast<K>(M_PI) / static_cast<K>(180.);
	const K ratio = 1.;
	const K near = 1.;
	const K far = 50.;

	const Matrix<K> proj = projection(fov, ratio, near, far);
	display::box(__func__, '#', '#', '#', '#', ' ', BOX_SIZE, '\n');
	display::box("Projection matrix", '=', '=', '|', '|', ' ', BOX_SIZE, '\n');
	display::box(STRINGIFY(proj), '~', '~', '>', '<', ' ', BOX_SIZE, '\n');
	display::value(proj);
}

int main(void)
{
	std::cout.precision(std::numeric_limits<real_t>::digits10);
	std::cerr.precision(std::numeric_limits<real_t>::digits10);

	ex14<real_t>();
	ex00<complex_t>();
	ex01<complex_t>();
	ex02<complex_t>();
	ex03<complex_t>();
	ex04<complex_t>();
	ex05<complex_t>();
	ex06<complex_t>();
	ex07<complex_t>();
	ex08<complex_t>();
	ex09<complex_t>();
	ex10<complex_t>();
	ex11<complex_t>();
	ex12<complex_t>();
	ex13<complex_t>();

	return 0;
}
