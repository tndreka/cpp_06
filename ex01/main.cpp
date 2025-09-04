/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 23:39:37 by tndreka           #+#    #+#             */
/*   Updated: 2025/09/04 17:19:29 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{

	std::cout << "=============== TEST 1 ==================== " << std::endl;
	
	Data myptr; //obj
	myptr.id = 1;
	myptr.name = "taulant";
	
	Data *ptr = &myptr; 
	
	std::cout << "The adress of ptr: " << ptr << std::endl;
	
	uintptr_t raw = Serializer::serialize(ptr);
	std::cout << "pointer uintptr_t value: " << raw << std::endl;
	
	Data *deserialized;
	deserialized = Serializer::deserialize(raw);
	if (deserialized == ptr)
		std::cout << "Pointer have the same address " << deserialized << std::endl;
	else
		std::cout << " DESERIALIZED WENT WRONG ! ! !" << std::endl;

	std::cout << "The id of ptr: " << ptr->id << std::endl;
	std::cout << "The name of ptr: " << ptr->name << std::endl;
	std::cout << "The id of deserialized ptr: " << deserialized->id << std::endl;
	std::cout << "The name of deserialized ptr: " << deserialized->name << std::endl;
	
	std::cout << "=============== TEST 2 ==================== " << std::endl;

	Data *p = new Data;
	p->id = 2;
	p->name = "Ndreka";
	
	std::cout << "The adress of ptr: " << p << std::endl;
	uintptr_t r = Serializer::serialize(p);
	std::cout << "pointer uintptr_t value: " << r << std::endl;

	Data *ds;
	ds = Serializer::deserialize(r);
	if (ds == p)
		std::cout << "Pointer have the same address " << ds << std::endl;
	else
		std::cout << " DESERIALIZED WENT WRONG ! ! !" << std::endl;
	
		std::cout << "The id of ptr: " << p->id << std::endl;
	std::cout << "The name of ptr: " << p->name << std::endl;
	std::cout << "The id of deserialized ptr: " << ds->id << std::endl;
	std::cout << "The name of deserialized ptr: " << ds->name << std::endl;
	
	delete p;
	return 0;
}