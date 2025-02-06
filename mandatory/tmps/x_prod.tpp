/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_prod.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:01:07 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/29 09:07:30 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace x_prod
{
	template <typename K>
	void execute(const std::vector<std::pair<Vector<K>, Vector<K>>> &tests)
	{
		for (size_t i = 0; i < tests.size(); i++)
		{
			const Vector<K> u = tests[i].first;
			const Vector<K> v = tests[i].second;
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
				display::box(STRINGIFY(cross_product(u, v)), '~', '~', '>', '<', ' ', BOX_SIZE, '\n');
				display::value(cross_product(u, v));
			}
			catch (const std::exception &e)
			{
				display::error(e);
			}
		}
	}
}
