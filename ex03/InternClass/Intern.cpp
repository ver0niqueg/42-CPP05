/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:56:27 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/13 19:49:24 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "../ShrubberyCreationFormClass/ShrubberyCreationForm.hpp"
#include "../RobotomyRequestFormClass/RobotomyRequestForm.hpp"
#include "../PresidentialPardonFormClass/PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardon(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return "Intern: Form not found!";
}

AForm* Intern::makeForm(const std::string &form, const std::string &target)
{
    struct FormType
    {
        const char* name;
        FormCreator createFunction;
    };
    
    FormType forms[] =
    {
        {"shrubbery creation", &Intern::createShrubbery},
        {"robotomy request", &Intern::createRobotomy},
        {"presidential pardon", &Intern::createPresidentialPardon},
    };
    for (size_t i = 0; i < sizeof(forms) / sizeof(forms[0]); ++i)
    {
        if (form == forms[i].name)
        {
            std::cout << "Intern creates " << form << std::endl;
            return (this->*forms[i].createFunction)(target);   
        }
    }
    throw FormNotFoundException();
}