/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:55:55 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/04 14:53:29 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FormClass/Form.hpp"

int main()
{
	try
	{
		std::cout << CYAN << "=== Bureaucrates creation ===" << RESET << std::endl;
		Bureaucrat a("Vero", 50);
		Bureaucrat b("Vivi", 120);
		Bureaucrat c("Kim", 2);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		std::cout << CYAN << "\n=== Forms creation ===" << RESET << std::endl;
		Form firstcontract("FirstContract", 100, 50);
		Form secondcontract("SecondContract", 20, 5);
		Form topSecret("TopSecret", 1, 5);

		std::cout << firstcontract << std::endl;
		std::cout << secondcontract << std::endl;
		std::cout << topSecret << std::endl;
		try 
		{
		Form InvalidForm("InvalidForm", 0, 10);
		std::cout << InvalidForm << std::endl;
		} 
		catch (std::exception &e) {
		std::cout << "Exception during form creation: " << e.what() << std::endl;
	}

		std::cout << CYAN << "\n=== Signing attemps ===" << RESET << std::endl;
		a.signForm(firstcontract);
		a.signForm(secondcontract);
		a.signForm(topSecret);
		b.signForm(firstcontract);
		b.signForm(secondcontract);
		b.signForm(topSecret);
		c.signForm(firstcontract);
		c.signForm(secondcontract);
		c.signForm(topSecret);

		std::cout << CYAN << "\n=== State of forms ===" << RESET << std::endl;
		std::cout << firstcontract << std::endl;
		std::cout << secondcontract << std::endl;
		std::cout << topSecret << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception  : " << e.what() << std::endl;
	}
	return 0;
}