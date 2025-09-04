/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 23:42:25 by tndreka           #+#    #+#             */
/*   Updated: 2025/09/04 17:00:45 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return *this;
}

Serializer::~Serializer(){}

/*
	reinterpret_cast<data_type>
	- this cast is used when you want to reinterpret the binary bits of a value
	as another type.
	- it does not change the actual bit but tells the compiler to treat those bits as if they 
	were a different type without losing information in the conversion. 
	- it uses uintptr_t because the that is capable of holding a pointer.
*/
uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}


Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);	
}