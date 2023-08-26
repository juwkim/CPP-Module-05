/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:27:05 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/27 03:45:13 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat juwon("juwon", 100);
	Form low("low", Bureaucrat::MinGrade, Bureaucrat::MinGrade);
	Form high("high", Bureaucrat::MaxGrade, Bureaucrat::MaxGrade);

	juwon.signForm(low);
	juwon.signForm(high);
	return 0;
}
