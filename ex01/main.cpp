/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:55:55 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/10 18:30:10 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FormClass/Form.hpp"

int main()
{
    std::cout << CYAN << "==== TEST NORMAL GRADES ====" << RESET << std::endl;
    try
    {
        Bureaucrat vero("Vero", 50);
        Form firstContract("FirstContract", 100, 50);

        std::cout << vero << std::endl;
        std::cout << firstContract << std::endl;

        std::cout << "\nVero attempts to sign FirstContract:" << std::endl;
        vero.signForm(firstContract);
        std::cout << firstContract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << CYAN << "\n==== HIGH REQUIREMENTS ====" << RESET << std::endl;
    try
    {
        Bureaucrat vivi("Vivi", 120);
        Form secondContract("SecondContract", 20, 5);

        std::cout << vivi << std::endl;
        std::cout << secondContract << std::endl;

        std::cout << "\nVivi attempts to sign SecondContract:" << std::endl;
        vivi.signForm(secondContract);
        std::cout << secondContract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << CYAN << "\n==== TOP SECRET FORMS ====" << RESET << std::endl;
    try
    {
        Bureaucrat kim("Kim", 2);
        Form topSecret("TopSecret", 1, 5);

        std::cout << kim << std::endl;
        std::cout << topSecret << std::endl;

        std::cout << "\nKim attempts to sign TopSecret:" << std::endl;
        kim.signForm(topSecret);
        std::cout << topSecret << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << CYAN << "\n==== INVALID BUREAUCRAT ====" << RESET << std::endl;
    try
    {
        Bureaucrat yasmine("Yasmine", 0);
        std::cout << yasmine << std::endl;
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

    return 0;
}