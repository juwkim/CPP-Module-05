/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:26:44 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/27 03:12:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>

class Bureaucrat
{
	public:
		virtual ~Bureaucrat(void);
		Bureaucrat(void);
		Bureaucrat(const std::string &name, const int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat& operator=(const Bureaucrat& bureaucrat);
	
		const std::string getName(void) const;
		int getGrade(void) const;
		void increment(void);
		void decrement(void);

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
		static const int MaxGrade = 1;
		static const int MinGrade = 150;
	private:
		const std::string mName;
		int mGrade;
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);
