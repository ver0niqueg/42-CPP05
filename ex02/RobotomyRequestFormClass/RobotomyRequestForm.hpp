/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:23:12 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/04 15:24:37 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "../AFormClass/AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        const std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string _target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();
        
        void execute(Bureaucrat const &executor);
};

#endif