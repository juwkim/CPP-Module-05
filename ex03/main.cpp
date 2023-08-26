/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:27:05 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/27 05:54:37 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void)
{
	Intern juwon;
	AForm *form;

	form = juwon.makeForm("koko", "kaka");
	std::cout << '\n';
	delete form;

	form = juwon.makeForm("PresidentialPardonForm", "kaka");
	std::cout << *form << '\n';
	delete form;

	form = juwon.makeForm("RobotomyRequestForm", "kaka");
	std::cout << *form << '\n';
	delete form;

	form = juwon.makeForm("ShrubberyCreationForm", "kaka");
	std::cout << *form << '\n';
	delete form;

	return 0;
}
