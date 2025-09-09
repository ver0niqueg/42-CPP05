/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:18:56 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/09 12:02:52 by vgalmich         ###   ########.fr       */
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
        Bureaucrat vero("Vero", 1);
        Bureaucrat vivi("Vivi", 140);
        Bureaucrat kim("Kim", 50);

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robo("dog");
        PresidentialPardonForm pardon("thief");

        std::cout << CYAN << "=== TEST SHRUBBERY ===" << RESET << std::endl;
        vivi.signForm(shrub);
        vivi.executeForm(shrub);
        vero.executeForm(shrub);
        kim.executeForm(shrub);

        std::cout << CYAN << "\n=== TEST ROBOTOMY ===" << RESET << std::endl;
        vivi.signForm(robo);
        vero.executeForm(robo);
        kim.signForm(robo);
        kim.executeForm(robo);
        vero.executeForm(robo);

        std::cout << CYAN << "\n=== TEST PARDON ===" << RESET << std::endl;
        vero.signForm(pardon);
        vero.executeForm(pardon);

        std::cout << CYAN << "\n=== TEST FORM NON SIGNE ===" << RESET << std::endl;
        PresidentialPardonForm notSigned("Ford Prefect");
        vero.executeForm(notSigned);
    }
    catch (std::exception &e)
    {
        std::cerr << "exception: " << e.what() << std::endl;
    }

    return 0;
}