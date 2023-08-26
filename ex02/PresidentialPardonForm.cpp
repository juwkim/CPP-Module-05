/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:49:48 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/27 05:01:27 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm::PresidentialPardonForm(void)
	:AForm("PresidentialPardonForm", "default", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	:AForm("PresidentialPardonForm", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm)
	:AForm(presidentialPardonForm)
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialPardonForm)
{
	new (this) PresidentialPardonForm(presidentialPardonForm);
	return (*this);
}

bool PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (isExecutable(executor) == false)
		return false;
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << '\n';
	return true;
}
