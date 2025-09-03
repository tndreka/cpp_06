/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:01:36 by tndreka           #+#    #+#             */
/*   Updated: 2025/09/03 21:58:54 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>


class ScalarConverter
{
private:
	enum Type
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		SPECIAL_CASE,
		INVALID
	};
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();
	static Type parseType(const std::string& str);
	static Type valid_f(const std::string& str);
	static Type valid_d(const std::string& str);
	static Type valid_i(const std::string& str);
	static void convert_ch(char c);
	static void convert_i(const std::string& str);
	static void convert_d(const std::string& str);
	// static void convert_f(const std::string& str);
public:
	static void convert(const std::string& str);
};

#endif