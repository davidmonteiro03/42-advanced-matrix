/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_inter.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:06:49 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/28 20:30:54 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace lin_inter
{
	template <typename V, typename K>
	void execute(const std::vector<std::pair<std::pair<V, V>, K>> &tests)
	{
		for (size_t i = 0; i < tests.size(); i++)
		{
			const V u = tests[i].first.first;
			const V v = tests[i].first.second;
			const K t = tests[i].second;
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
				display::box(STRINGIFY(t), '~', '~', '>', '<', ' ', BOX_SIZE, '\n');
				display::value(t);
			}
			catch (const std::exception &e)
			{
				display::error(e);
			}
			try
			{
				display::box(STRINGIFY(lerp(u, v, t)), '~', '~', '>', '<', ' ', BOX_SIZE, '\n');
				display::value(lerp(u, v, t));
			}
			catch (const std::exception &e)
			{
				display::error(e);
			}
		}
	}
}
