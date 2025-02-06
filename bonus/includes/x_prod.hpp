/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_prod.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:10:33 by dcaetano          #+#    #+#             */
/*   Updated: 2025/01/29 08:43:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace x_prod
{
	template <typename K>
	void execute(const std::vector<std::pair<Vector<K>, Vector<K>>> &);
}
