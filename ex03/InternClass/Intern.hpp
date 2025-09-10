/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:48:01 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/10 14:18:52 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "../AFormClass/AForm.hpp"

class Intern
{
    private:
        typedef AForm* (*FormCreator)(const std::string&);
        
        static AForm* createShrubbery(const std::string &target);
        static AForm* createRobotomy(const std::string &target);
        static AForm* createPresidentialPardon(const std::string &target);
        
    public:
        Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &other);
        ~Intern();
        
        class FormNotFoundException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        AForm* makeForm(std::string form, std::string target);
};

#endif