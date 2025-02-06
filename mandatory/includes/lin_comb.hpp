/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_combination.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:06:49 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/28 20:11:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace lin_comb
{
	template <typename K>
	void execute(const std::vector<std::pair<std::vector<Vector<K>>, std::vector<K>>> &);
}
