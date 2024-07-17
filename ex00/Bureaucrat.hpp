/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:51:18 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/07/17 22:04:26 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat{

	private:
		std::string _name;
		int _grade;

	public:
		Bureaucrat();
        Bureaucrat(std::string name);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat &operator = (const Bureaucrat& src);
		~Bureaucrat();

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

	int getGrade(void) const;
    std::string getName(void) const;
	void upGrade(int grade);
    void downGrade(int grade);
};

#endif