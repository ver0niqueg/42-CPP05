/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:40:58 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/13 19:32:47 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureaucratClass/Bureaucrat.hpp"
#include "InternClass/Intern.hpp"
#include "ShrubberyCreationFormClass/ShrubberyCreationForm.hpp"
#include "RobotomyRequestFormClass/RobotomyRequestForm.hpp"
#include "PresidentialPardonFormClass/PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Intern randomIntern;
        Bureaucrat a("Vero", 1);
        Bureaucrat b("Vivi", 140);
        Bureaucrat c("Kim", 50);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;

        std::cout << CYAN << "\n=== TEST SHRUBBERY ===" << RESET << std::endl;
        AForm* shrub = randomIntern.makeForm("shrubbery creation", "garden");
        b.signForm(*shrub);
        b.executeForm(*shrub);
        a.executeForm(*shrub);
        delete shrub;

        std::cout << CYAN << "\n=== TEST ROBOTOMY ===" << RESET << std::endl;
        AForm* robo = randomIntern.makeForm("robotomy request", "dog");
        b.signForm(*robo);
        a.executeForm(*robo);
        c.signForm(*robo);
        c.executeForm(*robo);
        a.executeForm(*robo);
        delete robo;

        std::cout << CYAN << "\n=== TEST PARDON ===" << RESET << std::endl;
        AForm* pardon = randomIntern.makeForm("presidential pardon", "thief");
        a.signForm(*pardon);
        a.executeForm(*pardon);
        delete pardon;

        std::cout << CYAN << "\n=== TEST INVALID FORM ===" << RESET << std::endl;
        try
        {
            AForm* invalid = randomIntern.makeForm("invalid form", "nobody");
            delete invalid;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "exception: " << e.what() << std::endl;
    }

    return 0;
}