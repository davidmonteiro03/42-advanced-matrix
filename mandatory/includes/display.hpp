/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:45:34 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/28 13:35:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace display
{
	void box(const std::string &,
			 const char &,
			 const char &,
			 const char &,
			 const char &,
			 const char &,
			 const size_t &,
			 const char &);

	void value(const bool &flag);

	template <typename T>
	void value(const T &);

	template <typename T>
	void vector(const std::vector<T> &);

	std::ostream &operator<<(std::ostream &, const shape_t &);

	template <typename A, typename B>
	std::ostream &operator<<(std::ostream &os, const std::pair<A, B> &pair);

	void error(const std::exception &);
}
