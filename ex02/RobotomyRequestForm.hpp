/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:51:09 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/27 05:20:32 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &robotomyRequestForm);

		bool execute(const Bureaucrat& executor) const;
};
