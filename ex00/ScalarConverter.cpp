/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:01:47 by tndreka           #+#    #+#             */
/*   Updated: 2025/09/03 14:19:49 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

//Casting in C++
/*
	static_cast<type>(data);
	this is the excplicit cast operator that converts expression in compile time.
*/
ScalarConverter::Type ScalarConverter::parseType(const std::string& str)
{
	//Parse Char
	if(str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
	{
		std::cout << "Char has been found\n";
		return CHAR;
	}
	else
	{
		std::cout<< "IMPOSSIBLE\n";
		return INVALID;
	}
}
void ScalarConverter::convert(const std::string& str)
{
	// //Char
	// if(str.length() == 1 && isalpha(static_cast<unsigned char>(str[0])))
	// 	std::cout << "Char: " << str << std::endl;
	// else
	// 	std::cout << "The input is: " << str << std::endl;

	//Parse INPUT
	Type input = parseType(str);

	if(input == CHAR)
	{
		char c = str[0];
		std::cout << "Char:  " << c << std::endl; 
	}
}