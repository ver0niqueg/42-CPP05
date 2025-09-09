/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:48:01 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/09 13:56:24 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "../AFormClass/AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &other);
        ~Intern();
        
        AForm* makeForm(std::string form, std::string target);
};

#endif