/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:45:47 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/09/11 18:35:45 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include <ostream>
// #include "Form.hpp"

class Form;

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string name);
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat& operator=(const Bureaucrat& src);
    
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
    void signForm(Form& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif