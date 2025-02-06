/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:28:13 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/28 13:36:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_matrix.hpp"

namespace display
{
	template <typename T>
	void value(const T &value)
	{
		std::cout << value << std::endl
				  << std::endl;
	}

	template <typename T>
	void vector(const std::vector<T> &vector)
	{
		for (size_t i = 0; i < vector.size(); i++)
			std::cout << vector[i] << std::endl;
		std::cout << std::endl;
	}

	template <typename A, typename B>
	std::ostream &operator<<(std::ostream &os, const std::pair<A, B> &pair)
	{
		os << '(' << pair.first << ", " << pair.second << ')';
		return os;
	}
}
