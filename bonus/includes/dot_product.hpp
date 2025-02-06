/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:39:18 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/29 08:40:10 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace dot_product
{
	template <typename K>
	void execute(const std::vector<std::pair<Vector<K>, Vector<K>>> &);
}
