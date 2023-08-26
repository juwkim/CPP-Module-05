/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:27:05 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/27 05:16:34 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test(Bureaucrat &bure)
{
	ShrubberyCreationForm	shu("shu");
	RobotomyRequestForm		robo("robo");
	PresidentialPardonForm	pre("pre");

	bure.signForm(shu);
	bure.executeForm(shu);
	std::cout << '\n';

	bure.signForm(robo);
	bure.executeForm(robo);
	std::cout << '\n';

	bure.signForm(pre);
	bure.executeForm(pre);
	std::cout << '\n';
}

int	main(void)
{
	Bureaucrat ju("ju", Bureaucrat::MaxGrade);
	Bureaucrat won("won", Bureaucrat::MinGrade);

	test(ju);
	test(won);
	return 0;
}
