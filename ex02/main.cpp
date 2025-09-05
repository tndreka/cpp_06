/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 23:39:47 by tndreka           #+#    #+#             */
/*   Updated: 2025/09/05 03:39:17 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	//we set the rand generator
	std::srand(std::time(NULL));

	std::cout << "========== Testing Generate() & pointer identify ================" << std::endl;
	Base *obj[6];
	for(int i = 0; i < 6; i++)
	{
		obj[i] = generate();
		std::cout << "OBJECT GENERATED " << i + 1  << ": ";
		identify(obj[i]);
	}
	for (int i = 0; i < 6; i++)
		delete obj[i];
	std::cout << "========== Testing Generate() & reference identify ================" << std::endl;
	Base *obj2[6];
	for(int i = 0; i < 6; i++)
	{
		obj2[i] = generate();
		std::cout << "OBJECT GENERATED " << i + 1  << ": ";
		std::cout << std::endl;
		identify(*obj2[i]);
	}
	
	return 0;
}