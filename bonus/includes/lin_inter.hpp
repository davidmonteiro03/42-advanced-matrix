/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_inter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:06:49 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/28 20:29:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace lin_inter
{
	template <typename V, typename K>
	void execute(const std::vector<std::pair<std::pair<V, V>, K>> &);
}
