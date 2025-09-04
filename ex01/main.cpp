/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 23:39:37 by tndreka           #+#    #+#             */
/*   Updated: 2025/09/04 16:58:48 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{

	std::cout << "=============== TEST 1 ==================== " << std::endl;
	Data myptr;
	myptr.id = 1;
	myptr.name = "taulant";
	Data *ptr = &myptr;
	
	uintptr_t raw = Serializer::serialize(ptr);
	std::cout << "pointer uintptr_t value: " << raw << std::endl;
	
	std::cout << "=============== TEST 2 ==================== " << std::endl;
	
	return 0;
}