/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_norm.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 07:39:36 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/29 08:42:16 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace vector_norm
{
	template <typename K>
	void execute(const std::vector<Vector<K>> &tests)
	{
		for (size_t i = 0; i < tests.size(); i++)
		{
			const Vector<K> u = tests[i];
			std::stringstream testStream;

			testStream << "Test " << i + 1;
			display::box(testStream.str(), '*', '*', '/', '/', ' ', BOX_SIZE, '\n');
			try
			{
				display::box(STRINGIFY(u), '~', '~', '>', '<', ' ', BOX_SIZE, '\n');
				display::value(u);
			}
			catch (const std::exception &e)
			{
				display::error(e);
			}
			try
			{
				display::box(STRINGIFY(u.norm_1()), '~', '~', '>', '<', ' ', BOX_SIZE, '\n');
				display::value(u.norm_1());
			}
			catch (const std::exception &e)
			{
				display::error(e);
			}
			try
			{
				display::box(STRINGIFY(u.norm()), '~', '~', '>', '<', ' ', BOX_SIZE, '\n');
				display::value(u.norm());
			}
			catch (const std::exception &e)
			{
				display::error(e);
			}
			try
			{
				display::box(STRINGIFY(u.norm_inf()), '~', '~', '>', '<', ' ', BOX_SIZE, '\n');
				display::value(u.norm_inf());
			}
			catch (const std::exception &e)
			{
				display::error(e);
			}
		}
	}
}
