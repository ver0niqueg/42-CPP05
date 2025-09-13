/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:55:55 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/13 14:42:11 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FormClass/Form.hpp"

int main()
{
    std::cout << CYAN << "==== TEST NORMAL GRADES ====" << RESET << std::endl;
    try
    {
        Bureaucrat a("Vero", 50);
        Form firstContract("FirstContract", 100, 50);

        std::cout << a << std::endl;
        std::cout << firstContract << std::endl;

        std::cout << "\nVero attempts to sign FirstContract:" << std::endl;
        a.signForm(firstContract);
        std::cout << firstContract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << CYAN << "\n==== HIGH REQUIREMENTS ====" << RESET << std::endl;
    try
    {
        Bureaucrat b("Vivi", 120);
        Form secondContract("SecondContract", 20, 5);

        std::cout << b << std::endl;
        std::cout << secondContract << std::endl;

        std::cout << "\nVivi attempts to sign SecondContract:" << std::endl;
        b.signForm(secondContract);
        std::cout << secondContract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << CYAN << "\n==== TOP SECRET FORMS ====" << RESET << std::endl;
    try
    {
        Bureaucrat c("Kim", 2);
        Form topSecret("TopSecret", 1, 5);

        std::cout << c << std::endl;
        std::cout << topSecret << std::endl;

        std::cout << "\nKim attempts to sign TopSecret:" << std::endl;
        c.signForm(topSecret);
        std::cout << topSecret << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << CYAN << "\n==== INVALID BUREAUCRAT ====" << RESET << std::endl;
    try
    {
        Bureaucrat d("Yasmine", 0);
        std::cout << d << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Cannot create Yasmine: " << e.what() << std::endl;
    }

    std::cout << CYAN << "\n==== INVALID FORM ====" << RESET << std::endl;
    try
    {
        Form invalidForm("InvalidForm", 0, 10);
        std::cout << invalidForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Cannot create InvalidForm: " << e.what() << std::endl;
    }
    
    return (0);
}