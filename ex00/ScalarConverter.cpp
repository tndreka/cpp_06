/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:01:47 by tndreka           #+#    #+#             */
/*   Updated: 2025/09/03 23:07:56 by tndreka          ###   ########.fr       */
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
		return CHAR;
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
		case INT:
			convert_i(str);
			break;
		case DOUBLE:
			convert_d(str);
			break;
		case FLOAT:
			convert_f(str);
			break;
		case SPECIAL_CASE:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
	}
}

void ScalarConverter::convert_ch(char c)
{
	std::cout <<"char: '"<< c << "'"<< std::endl;
	std::cout <<"int: "<< static_cast<int>(c) << std::endl;
	std::cout <<"float: "<< static_cast<float>(c) << std::endl;
	std::cout <<"double: "<< static_cast<double>(c) << std::endl;
}

void ScalarConverter::convert_i(const std::string& str)
{
	/*
		Convert str int to int
		c_str() -> since atoi requires a const char* as a param the fucntion used c_str() 
		return a C-style string null terminated charactar array frim a C++ string
	 */
	int value = std::atoi(str.c_str());
	//Value range
	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	//value not displayble
	else if(value < 32 || value > 126)
		std::cout << "char: Non displayable"<< std::endl;
	else
		std::cout << "char: '"<< static_cast<char>(value) << "'" << std::endl;
	//INT
	std::cout << "int: "<< value << std::endl;
	//FLOAT
	std::cout << "float: "<< static_cast<float>(value) << ".0f"<< std::endl;
	//DOUBLE
	std::cout << "double: "<< static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::convert_d(const std::string& str)
{
	double value = std::atof(str.c_str());
	//CHAR conversion
	if (value < 0 || value > 127 || value != static_cast<int>(value))
		std::cout << "char: impossible" << std::endl;
	//value not displayble
	else if(value < 32 || value > 126)
		std::cout << "char: Non displayable"<< std::endl;
	else
		std::cout << "char: '"<< static_cast<char>(static_cast<int>(value)) << "'" << std::endl;
	//INT
		//check limit
	if(value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout <<"int: "<< static_cast<int>(value) << std::endl;
	//FLOAT
	std::cout << "float: "<< static_cast<float>(value);
	if(value == static_cast<int>(value) && value >= -1000000 && value <= 1000000)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	//DOUBLE
	std::cout << "double: "<< value;
	if(value == static_cast<int>(value) && value >= -1000000 && value <= 1000000)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void ScalarConverter::convert_f(const std::string& str)
{
	float value = std::atof(str.c_str());
	//CHAR
	if (value < 0 || value > 127 || value != static_cast<int>(value))
		std::cout << "char: impossible" << std::endl;
	//value not displayble
	else if(value < 32 || value > 126)
		std::cout << "char: Non displayable"<< std::endl;
	else
		std::cout << "char: '"<< static_cast<char>(static_cast<int>(value)) << "'" << std::endl;
	//INT
		//check limit
	if(value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout <<"int: "<< static_cast<int>(value) << std::endl;
	//FLOAT
	std::cout << "float: "<< static_cast<float>(value);
	if(value == static_cast<int>(value) && value >= -1000000 && value <= 1000000)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	//DOUBLE
	std::cout << "double: "<< static_cast<double>(value);
	if(value == static_cast<int>(value) && value >= -1000000 && value <= 1000000)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;	
}