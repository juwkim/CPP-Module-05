/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:58:04 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/27 03:31:27 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		virtual ~Form(void);
		Form(void);
		Form(const std::string &name, const int signGrade, const int executeGrade);
		Form(const Form& form);
		Form& operator=(const Form& form);

		const std::string&	getName(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;

		void				beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class AlreadySignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string mName;
		bool              mSigned;
		const int         mSignGrade;
		const int         mExecuteGrade;
};

std::ostream& operator<<(std::ostream& out, const Form& form);
