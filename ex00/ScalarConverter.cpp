/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:01:47 by tndreka           #+#    #+#             */
/*   Updated: 2025/09/03 16:23:07 by tndreka          ###   ########.fr       */
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

	//PARSE--INT
	if(str.length() >= 1)
	{
		size_t i = 0;
		//check sign
		if(str[0] == '+' || str[0] == '-')
		{
			i = 1;
			if (str.length() == 1)
				return INVALID;
		}
		//check the the other digits
		bool isInt = true;
		for (size_t count = i; count < str.length(); count++)
		{
			if (!std::isdigit(str[count]))
			{
				isInt = false;
				break;
			}
		}
		if (isInt)
			return INT;
	}
	//Parse FLOAT
	if(str.length() > 1 && str.back() == 'f')
	{
		std::string floatpart = str.substr(0, str.length() - 1);
		//check empty
		if(floatpart.empty())
			return INVALID;
		size_t i = 0;
		bool dot = false;
		bool digit = false;
		//check sign
		if(floatpart[0] == '+' || floatpart[0] == '-')
		{
			i = 1;
			if (floatpart.length() == 1)
				return INVALID;
		}
		//check digit & dot
		for(size_t count = i; count < floatpart.length(); count++)
		{
			if(floatpart[count] == '.')
			{
				if(dot)
					return INVALID;
				dot = true;
			}
			else if(std::isdigit(floatpart[count]))
				digit = true;
			else
				return INVALID;
				
		}
		if(dot && digit)
			return FLOAT;
		else
			return INVALID;
	}
	//Parse DOUBLE
	if(str.find('.') != std::string::npos)
		return DOUBLE;
	//Parse SPECIAL CASES => nan, nanf, +inf, -inf, +inff, -inff, inf,inff
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff" || str == "inf" || str == "inff")
		return SPECIAL_CASE;
	return INVALID;
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
	else if (input == INT)
	{
		std::cout<<"int detected \n";
	}
	else if (input == FLOAT)
	{
		std::cout<<"float detected \n";
	}
	else if (input == DOUBLE)
	{
		std::cout<<"Double detected \n";
	}
	else if (input == SPECIAL_CASE)
	{
		std::cout<<"Special case detected \n";
	}
	else
	{
		std::cout<<"INVALID detected \n";
	}
}