/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:19:36 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/07/31 19:21:24 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

class AForm {
protected:
    const std::string _name;
    bool _signed;
    const int _grade_to_sign;
    const int _grade_to_exec;

public:
    AForm();
    AForm(const std::string name, int grade_to_sign, int grade_to_exec);
    AForm(const AForm& copy);
    AForm& operator=(const AForm& src);
    virtual ~AForm();

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class TheDocumentIsNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class TheDocumentIsAlreadySignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    int getGradeToSign(void) const;
    int getGradeToExec(void) const;
    std::string getName(void) const;

    void isSigned(void);
    void beSigned(Bureaucrat& bureaucrat);
    int ifSigned(void) const;
    void execute(Bureaucrat const & executor) const;
    virtual void performAction() const = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif