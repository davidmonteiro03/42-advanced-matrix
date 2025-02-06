/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_map.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:39:13 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/29 08:50:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace lin_map
{
	template <typename K, typename V>
	void execute(const std::vector<std::pair<Matrix<K>, V>> &);
}
