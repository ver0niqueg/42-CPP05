/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:41:37 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/04 15:11:32 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(50), _gradeToExecute(40)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{     
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

AForm::~AForm()
{
}

const std::string& AForm::getName() const
{
	return (_name);
}

int AForm::getGrade() const
{
	return (_gradeToSign);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &flux, const AForm &myObject)
{
	flux << "Form " << myObject.getName()
	   << ", signed: " << (myObject.getSigned() ? "true" : "false")
	   << ", grade to sign: " << myObject.getGradeToSign()
	   << ", grade to execute: " << myObject.getGradeToExecute();
	return flux;
}