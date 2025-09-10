/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:40:58 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/10 15:58:46 by vgalmich         ###   ########.fr       */
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
        Intern someRandomIntern;
        Bureaucrat vero("Vero", 1);
        Bureaucrat vivi("Vivi", 140);
        Bureaucrat kim("Kim", 50);

        std::cout << CYAN << "=== TEST SHRUBBERY ===" << RESET << std::endl;
        AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "garden");
        vivi.signForm(*shrub);
        vivi.executeForm(*shrub);
        vero.executeForm(*shrub);
        delete shrub;

        std::cout << CYAN << "\n=== TEST ROBOTOMY ===" << RESET << std::endl;
        AForm* robo = someRandomIntern.makeForm("robotomy request", "dog");
        vivi.signForm(*robo);
        vero.executeForm(*robo);
        kim.signForm(*robo);
        kim.executeForm(*robo);
        vero.executeForm(*robo);
        delete robo;

        std::cout << CYAN << "\n=== TEST PARDON ===" << RESET << std::endl;
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "thief");
        vero.signForm(*pardon);
        vero.executeForm(*pardon);
        delete pardon;

        std::cout << CYAN << "\n=== TEST INVALID FORM ===" << RESET << std::endl;
        try
        {
            AForm* invalid = someRandomIntern.makeForm("invalid form", "nobody");
            delete invalid; // should not reach here
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