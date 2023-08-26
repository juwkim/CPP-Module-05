/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:39:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/27 04:38:25 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::~AForm(void)
{
}

AForm::AForm(void)
	:mName("default"),
	mTarget("default"),
	mSigned(false),
	mSignGrade(Bureaucrat::MaxGrade),
	mExecuteGrade(Bureaucrat::MaxGrade)
{
}

AForm::AForm(const std::string &name, const std::string &target, const int signGrade, const int executeGrade)
	:mName(name),
	mTarget(target),
	mSigned(false),
	mSignGrade(signGrade),
	mExecuteGrade(executeGrade)
{
	if (signGrade < Bureaucrat::MaxGrade || executeGrade < Bureaucrat::MaxGrade)
		throw Bureaucrat::GradeTooHighException();
	if (signGrade > Bureaucrat::MinGrade || executeGrade > Bureaucrat::MinGrade)
		throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm& form):
	mName(form.mName),
	mTarget(form.mTarget),
	mSigned(form.mSigned),
	mSignGrade(form.mSignGrade),
	mExecuteGrade(form.mExecuteGrade)
{
}

AForm& AForm::operator=(const AForm& form)
{
	*const_cast<std::string *>(&mName) = form.mName;
	*const_cast<std::string *>(&mTarget) = form.mTarget;
	mSigned = form.mSigned;
	*const_cast<int *>(&mSignGrade) = form.mSignGrade;
	*const_cast<int *>(&mExecuteGrade) = form.mExecuteGrade;
	return *this;
}

const std::string& AForm::getName(void) const
{
	return mName;
}

const std::string& AForm::getTarget(void) const
{
	return mTarget;
}

bool AForm::getSigned(void) const
{
	return mSigned;
}

int	AForm::getSignGrade(void) const
{
	return mSignGrade;
}

int	AForm::getExecuteGrade(void) const
{
	return mExecuteGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (mSigned == true)
		throw AForm::AlreadySignedException();
	if (mSignGrade < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
	mSigned = true;
}

bool AForm::isExecutable(const Bureaucrat& executor) const
{
	if (mSigned == false)
		throw AForm::NotSignedException();
	if (mExecuteGrade < executor.getGrade())
		throw AForm::GradeTooLowException();
	return true;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char*	AForm::AlreadySignedException::what() const throw()
{
	return "Already signed";
}

const char*	AForm::NotSignedException::what() const throw()
{
	return "Not signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	out << AForm.getName() << ", AForm"
		<< " signed: " << AForm.getSigned()
		<< " signGrade:" << AForm.getSignGrade()
		<< " executeGrade:" << AForm.getExecuteGrade() << '\n';
	return out;
}
