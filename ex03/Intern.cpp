/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 05:33:39 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/27 05:52:20 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::~Intern(void)
{
}

Intern::Intern(void)
{
}

Intern::Intern(const Intern& intern)
{
	(void)intern;
}

Intern&	Intern::operator=(const Intern& intern)
{
	(void)intern;
	return *this;
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	AForm* form;
	const int n_form = 3;
	std::string forms[n_form] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	int i;
	for (i = 0; i < n_form; ++i) {
		if (name == forms[i])
			break;
	}
	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cerr << "Intern can not create a form called " << name << std::endl;
			return NULL;
	}
	std::cout << "Intern creates " << name << std::endl;
	return form;
}
