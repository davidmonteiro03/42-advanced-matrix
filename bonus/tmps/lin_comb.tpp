/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_comb.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:06:49 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/28 20:16:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace lin_comb
{
	template <typename K>
	void execute(const std::vector<std::pair<std::vector<Vector<K>>, std::vector<K>>> &tests)
	{
		for (size_t i = 0; i < tests.size(); i++)
		{
			const std::vector<Vector<K>> u = tests[i].first;
			const std::vector<K> coefs = tests[i].second;
			std::stringstream testStream;

			testStream << "Test " << i + 1;
			display::box(testStream.str(), '*', '*', '/', '/', ' ', BOX_SIZE, '\n');
			try
			{
				display::box(STRINGIFY(u), '~', '~', '>', '<', ' ', BOX_SIZE, '\n');
				display::vector(u);
			}
			catch (const std::exception &e)
			{
				display::error(e);
			}
			try
			{
				display::box(STRINGIFY(coefs), '~', '~', '>', '<', ' ', BOX_SIZE, '\n');
				display::vector(coefs);
			}
			catch (const std::exception &e)
			{
				display::error(e);
			}
			try
			{
				display::box(STRINGIFY(linear_combination(u, coefs)), '~', '~', '>', '<', ' ', BOX_SIZE, '\n');
				display::value(linear_combination(u, coefs));
			}
			catch (const std::exception &e)
			{
				display::error(e);
			}
		}
	}
}
