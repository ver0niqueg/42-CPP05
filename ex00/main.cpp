/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:06:30 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/04 13:54:56 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
	std::cout << CYAN << "==== FIRST TEST ====" << RESET << std::endl;
	
	try 
	{
		Bureaucrat a("Vero", 2);
		std::cout << a << std::endl;

		a.incrementGrade();
		std::cout << "After grade up: " << a << std::endl;

		a.incrementGrade();
		std::cout << "After grade up: " << a << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << CYAN << "\n==== SECOND TEST ====" << RESET << std::endl;

	try 
	{
		Bureaucrat b("Vivi", 149);
		std::cout << b << std::endl;

		b.decrementGrade();
		std::cout << "After grade down: " << b << std::endl;

		b.decrementGrade();
		std::cout << "After grade down: " << b << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << CYAN << "\n==== THIRD TEST ====" << RESET << std::endl;

	try 
	{
		Bureaucrat c("Kim", 151);
		std::cout << c << std::endl;

		c.incrementGrade();
		std::cout << "After grade up: " << c << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try 
	{
		Bureaucrat d("Yasmine", 0);
		std::cout << d << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}