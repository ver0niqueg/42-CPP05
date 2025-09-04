/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:25:13 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/04 15:26:07 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "../AFormClass/AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        const std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string _target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();
        
        void execute(Bureaucrat const &executor);
};

#endif