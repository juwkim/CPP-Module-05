/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:27:05 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/27 03:12:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat high("high", Bureaucrat::MaxGrade);
	try {
		high.increment();
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << '\n';
	}
	
	Bureaucrat low("low", Bureaucrat::MinGrade);
	try {
		low.decrement();
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << '\n';
	}

	try {
		Bureaucrat high("high", Bureaucrat::MaxGrade - 1);
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << '\n';
	}

	try {
		Bureaucrat low("low", Bureaucrat::MinGrade + 1);
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}
