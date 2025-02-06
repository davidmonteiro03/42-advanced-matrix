/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:28:13 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/28 19:29:36 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_matrix.hpp"

namespace display
{
	void box(const std::string &str,
			 const char &top,
			 const char &bottom,
			 const char &left,
			 const char &right,
			 const char &fill,
			 const size_t &width,
			 const char &last)
	{
		size_t tmpWidth = width;
		if (str.size() + 4 > tmpWidth)
			tmpWidth = str.size() + 4;
		for (size_t i = 0; i < tmpWidth; i++)
			std::cout << top;
		std::cout << std::endl;
		size_t fillSize = tmpWidth - str.size() - 2;
		std::cout << left;
		for (size_t i = 0; i < fillSize / 2; i++)
			std::cout << fill;
		std::cout << str;
		for (size_t i = 0; i < fillSize / 2 + (str.size() % 2 != tmpWidth % 2); i++)
			std::cout << fill;
		std::cout << right << std::endl;
		for (size_t i = 0; i < tmpWidth; i++)
			std::cout << bottom;
		std::cout << std::endl
				  << last;
	}

	void value(const bool &flag)
	{
		std::cout << (flag == true ? "Yes" : "No") << std::endl
				  << std::endl;
	}

	std::ostream &operator<<(std::ostream &os, const shape_t &shape)
	{
		os << shape.second << " x " << shape.first;
		return os;
	}

	void error(const std::exception &e)
	{
		std::cerr << e.what() << std::endl
				  << std::endl;
	}
}
