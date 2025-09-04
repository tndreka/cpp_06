/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 23:39:47 by tndreka           #+#    #+#             */
/*   Updated: 2025/09/04 19:29:27 by tndreka          ###   ########.fr       */
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
	return 0;
}