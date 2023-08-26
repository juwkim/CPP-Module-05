/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:57:45 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/27 04:07:03 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::~Form(void)
{
}

Form::Form(void)
	:mName("default"),
	mSigned(false),
	mSignGrade(Bureaucrat::MaxGrade),
	mExecuteGrade(Bureaucrat::MaxGrade)
{
}

Form::Form(const std::string &name, const int signGrade, const int executeGrade)
	:mName(name),
	mSigned(false),
	mSignGrade(signGrade),
	mExecuteGrade(executeGrade)
{
	if (signGrade < Bureaucrat::MaxGrade || executeGrade < Bureaucrat::MaxGrade)
		throw Bureaucrat::GradeTooHighException();
	if (signGrade > Bureaucrat::MinGrade || executeGrade > Bureaucrat::MinGrade)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form& form):
	mName(form.mName),
	mSigned(form.mSigned),
	mSignGrade(form.mSignGrade),
	mExecuteGrade(form.mExecuteGrade)
{
}

Form& Form::operator=(const Form& form)
{
	*const_cast<std::string *>(&mName) = form.mName;
	mSigned = form.mSigned;
	*const_cast<int *>(&mSignGrade) = form.mSignGrade;
	*const_cast<int *>(&mExecuteGrade) = form.mExecuteGrade;
	return *this;
}

const std::string& Form::getName(void) const
{
	return mName;
}

bool Form::getSigned(void) const
{
	return mSigned;
}

int	Form::getSignGrade(void) const
{
	return mSignGrade;
}

int	Form::getExecuteGrade(void) const
{
	return mExecuteGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (mSigned == true)
		throw Form::AlreadySignedException();
	if (mSignGrade < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	mSigned = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return "Already signed";
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << form.getName() << ", form"
		<< " signed: " << form.getSigned()
		<< " signGrade:" << form.getSignGrade()
		<< " executeGrade:" << form.getExecuteGrade() << '\n';
	return out;
}
