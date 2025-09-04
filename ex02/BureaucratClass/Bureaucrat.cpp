/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:44:45 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/04 15:09:05 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "../FormClass/Form.hpp"

Bureaucrat::Bureaucrat () : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	++_grade;
}

void Bureaucrat::signForm(Form& Form)
{
	try
	{
		Form.beSigned(*this);
		std::cout << _name << " signed " << Form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << Form.getName() << " because " << e.what() << std::endl;
	}	
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &flux, const Bureaucrat &myObject)
{
	flux << myObject.getName() << ", bureaucrat grade " << myObject.getGrade();
	return (flux);
}
