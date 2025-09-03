/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:01:47 by tndreka           #+#    #+#             */
/*   Updated: 2025/09/03 21:37:50 by tndreka          ###   ########.fr       */
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
	Type intRes;
	Type floatRes;
	Type doubleRes;
	//Parse SPECIAL CASES => nan, nanf, +inf, -inf, +inff, -inff, inf,inff
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff" || str == "inf" || str == "inff")
		return SPECIAL_CASE;
	//Parse FLOAT
	if((floatRes = valid_f(str)) == FLOAT)
		return FLOAT;
	//Parse DOUBLE
	if((doubleRes = valid_d(str)) == DOUBLE)
		return DOUBLE;
	//Parse Char
	if(str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
	{
		std::cout << "Char has been found\n";
		return CHAR;
	}
	//PARSE--INT
	if((intRes = valid_i(str)) == INT)
		return INT;
	return INVALID;
}

ScalarConverter::Type ScalarConverter::valid_i(const std::string& str)
{
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
	return INVALID;
}

ScalarConverter::Type ScalarConverter::valid_d(const std::string& str)
{
	if(str.find('.') != std::string::npos)
	{
		size_t i = 0;
		bool ddot = false;
		bool ddigit = false;
		//check sign
		if(str[0] == '+' || str[0] == '-')
		{
			i = 1;
			if (str.length() == 1)
				return INVALID;
		}
		for (size_t count = i; count < str.length(); count++)
		{
			if (str[count] == '.')
			{
				if(ddot)
					return INVALID;
				ddot = true;
			}
			else if(std::isdigit(str[count]))
				ddigit = true;
			else
				return INVALID;
		}
		if(ddot && ddigit)
			return DOUBLE;
		else
			return INVALID;
	}
	return INVALID;
}

ScalarConverter::Type ScalarConverter::valid_f(const std::string& str)
{
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

	switch (input)
	{
		case CHAR:
			convert_ch(str[0]);
			break;
		// case INT:
		// 	convert_i(str);
		// 	break;
		// case DOUBLE:
		// 	convert_d(str);
		// 	break;
		// case FLOAT:
		// 	convert_f(str);
		// 	break;
		default:
			std::cout<< "not implemeted yet\n";
			break;
	}
}

void ScalarConverter::convert_ch(char c)
{
	std::cout <<"char: "<< c << std::endl;
	std::cout <<"int: "<< static_cast<int>(c) << std::endl;
	std::cout <<"float: "<< static_cast<float>(c) << std::endl;
	std::cout <<"double: "<< static_cast<double>(c) << std::endl;
}