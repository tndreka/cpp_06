/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:44:04 by tndreka           #+#    #+#             */
/*   Updated: 2025/10/09 18:08:12 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//Static_cast
int main(int ac, char *av[])
{
	if (ac == 1)
	{
		std::cout << "ERROR: Wrong number of arguments" <<std::endl;
		std::cout << "Try: <./Program_NAME> <INPUT>" <<std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}