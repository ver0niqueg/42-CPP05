/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:18:56 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/10 19:24:41 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureaucratClass/Bureaucrat.hpp"
#include "ShrubberyCreationFormClass/ShrubberyCreationForm.hpp"
#include "RobotomyRequestFormClass/RobotomyRequestForm.hpp"
#include "PresidentialPardonFormClass/PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat a("Vero", 1);
        Bureaucrat b("Vivi", 140);
        Bureaucrat c("Kim", 50);

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robo("dog");
        PresidentialPardonForm pardon("thief");

        std::cout << CYAN << "=== TEST SHRUBBERY ===" << RESET << std::endl;
        b.signForm(shrub);
        b.executeForm(shrub);
        a.executeForm(shrub);
        c.executeForm(shrub);

        std::cout << CYAN << "\n=== TEST ROBOTOMY ===" << RESET << std::endl;
        b.signForm(robo);
        a.executeForm(robo);
        c.signForm(robo);
        c.executeForm(robo);
        a.executeForm(robo);

        std::cout << CYAN << "\n=== TEST PARDON ===" << RESET << std::endl;
        a.signForm(pardon);
        a.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << "exception: " << e.what() << std::endl;
    }

    return 0;
}