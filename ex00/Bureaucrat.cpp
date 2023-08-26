/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:26:12 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/27 03:26:31 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(void)
{	
}

Bureaucrat::Bureaucrat(void)
	:mName("default"),
	mGrade(MinGrade)
{	
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade)
	:mName(name),
	mGrade(grade)
{
	if (mGrade < MaxGrade)
		throw Bureaucrat::GradeTooHighException();
	if (mGrade > MinGrade)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
	:mName(bureaucrat.mName),
	mGrade(bureaucrat.mGrade)
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	*const_cast<std::string *>(&mName) = bureaucrat.mName;
	mGrade = bureaucrat.mGrade;
	return *this;
}

const std::string Bureaucrat::getName(void) const
{
	return mName;
}

int	Bureaucrat::getGrade(void) const
{
	return mGrade;
}

void Bureaucrat::increment(void)
{
	if (mGrade == MaxGrade)
		throw Bureaucrat::GradeTooHighException();
	--mGrade;
}

void Bureaucrat::decrement(void)
{
	if (mGrade == MinGrade)
		throw Bureaucrat::GradeTooLowException();
	++mGrade;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
