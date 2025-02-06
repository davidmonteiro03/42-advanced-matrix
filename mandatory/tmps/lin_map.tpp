/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_map.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:39:13 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/29 09:06:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace lin_map
{
	template <typename K, typename V>
	void execute(const std::vector<std::pair<Matrix<K>, V>> &tests)
	{
		for (size_t i = 0; i < tests.size(); i++)
		{
			const Matrix<K> u = tests[i].first;
			const V v = tests[i].second;
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
				display::box(STRINGIFY(v), '~', '~', '>', '<', ' ', BOX_SIZE, '\n');
				display::value(v);
			}
			catch (const std::exception &e)
			{
				display::error(e);
			}
			try
			{
				display::box(STRINGIFY(u * v), '~', '~', '>', '<', ' ', BOX_SIZE, '\n');
				display::value(u * v);
			}
			catch (const std::exception &e)
			{
				display::error(e);
			}
		}
	}
}
