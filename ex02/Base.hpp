/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:20:29 by tndreka           #+#    #+#             */
/*   Updated: 2025/09/04 19:23:28 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP


#include <iostream>
#include <cstdlib> // for std::rand()
#include <ctime>

class Base
{
	public:
		virtual	~Base();
};

Base* generate(void);
void identify(Base *p);
void identify(Base &p);

#endif