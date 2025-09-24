/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:48:01 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/24 13:41:33 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "../AFormClass/AForm.hpp"

class Intern
{
    private:
        typedef AForm* (Intern::*FormCreator)(const std::string&);
        
        AForm* createShrubbery(const std::string &target);
        AForm* createRobotomy(const std::string &target);
        AForm* createPresidentialPardon(const std::string &target);
        
    public:
        Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &other);
        ~Intern();
        
        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        AForm* makeForm(const std::string &form, const std::string &target);
};

#endif