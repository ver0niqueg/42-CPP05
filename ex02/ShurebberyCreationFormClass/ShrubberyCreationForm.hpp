/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:06:02 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/04 15:23:35 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "../AFormClass/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string _target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();
        
        void execute(Bureaucrat const &executor);
};

#endif