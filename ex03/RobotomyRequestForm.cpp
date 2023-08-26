/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:50:33 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/27 05:20:59 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm::RobotomyRequestForm(void)
	:AForm("RobotomyRequestForm", "default", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	:AForm("RobotomyRequestForm", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm)
	:AForm(robotomyRequestForm)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm&robotomyRequestForm)
{
	new (this) RobotomyRequestForm(robotomyRequestForm);
	return *this;
}

bool RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (isExecutable(executor) == false)
		return false;
	if (std::time(NULL) & 1)
		std::cout << getTarget() << " has been robotomized successfully 50% of the time." << '\n';
	else
		std::cout << getTarget() << " robotomy failed." << '\n';
	return true;
}
