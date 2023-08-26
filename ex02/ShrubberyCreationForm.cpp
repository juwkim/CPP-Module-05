/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:51:33 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/27 05:10:54 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", "default", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	:AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm)
	:AForm(shrubberyCreationForm)
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm&shrubberyCreationForm)
{
	new (this) ShrubberyCreationForm(shrubberyCreationForm);
	return (*this);
}

bool ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (isExecutable(executor) == false)
		return false;

	std::string name = getTarget();
	std::ofstream out(name.append("_shrubbery").c_str(), std::ios_base::out);
	
	if (out.is_open() == false)
		return false;
	out << "         v" << '\n'
		<< "        >X<" << '\n'
		<< "         A" << '\n'
		<< "        d$b" << '\n'
		<< "      .d\\$$b." << '\n'
		<< "    .d$i$$\\$$b." << '\n'
		<< "       d$$@b" << '\n'
		<< "      d\\$$$ib" << '\n'
		<< "    .d$$$\\$$$b" << '\n'
		<< "  .d$$@$$$$\\$$ib." << '\n'
		<< "      d$$i$$b" << '\n'
		<< "     d\\$$$$@$b" << '\n'
		<< "  .d$@$$\\$$$$$@b." << '\n'
		<< ".d$$$$i$$$\\$$$$$$b." << '\n'
		<< "        ###" << '\n'
		<< "        ###" << '\n'
		<< "        ###" << '\n';
	out.close();
	return true;
}
