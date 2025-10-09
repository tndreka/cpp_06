/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:23:31 by tndreka           #+#    #+#             */
/*   Updated: 2025/10/09 18:11:50 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}


//Generate we use rand() to randomize the obj creation of the three classes A, B, and C
Base* generate(void)
{
	int random;

	random = std::rand() % 3;
	if (random == 0)
		return new A;
	else if (random == 1)
		return new B;
	else
		return new C;
}


/*
	dynamic_cast
	-> this type of casting is used to safly convert convert
	pointer references within an inheritance hierarchy.
	-> it is used in cases with pholymorfic_types, classes that have at leats one 
	virtual function.
	->
	
*/
void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

/*
	with refrence you need to use try and catch blocks because unlike pointters 
	referenceses doesnt return a boolean covertible value but they throw std::bad_cast execption.
*/
void identify(Base &p)
{
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch(std::bad_cast&) {}
	try{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch(std::bad_cast&) {}
	try{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch(std::bad_cast&) {}
	std::cout << "Unknown type" << std::endl;	
}
