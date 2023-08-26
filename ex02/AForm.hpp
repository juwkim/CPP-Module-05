/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:39:56 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/27 04:41:00 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		virtual ~AForm(void);
		AForm(void);
		AForm(const std::string &name, const std::string &target, const int signGrade, const int executeGrade);
		AForm(const AForm& form);
		AForm& operator=(const AForm& form);

		const std::string&	getName(void) const;
		const std::string&	getTarget(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;

		void				beSigned(const Bureaucrat& bureaucrat);
		bool				isExecutable(const Bureaucrat& executor) const;
		virtual bool		execute(const Bureaucrat& executor) const = 0;
	
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
		class NotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string mName;
		const std::string mTarget;
		bool              mSigned;
		const int         mSignGrade;
		const int         mExecuteGrade;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);
