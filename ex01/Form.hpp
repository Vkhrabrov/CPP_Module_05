/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:19:36 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/09/11 18:50:28 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
private:
    const std::string _name;
    bool _signed;
    const int _grade_to_sign;
    const int _grade_to_exec;

public:
    Form();
    Form(const std::string name, int grade_to_sign, int grade_to_exec);
    Form(const Form& copy);
    Form& operator=(const Form& src);
    ~Form();

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    int getGradeToSign(void) const;
    int getGradeToExec(void) const;
    std::string getName(void) const;

    void isSigned(void);
    void beSigned(Bureaucrat& bureaucrat);
    int ifSigned(void) const;

};

std::ostream& operator<<(std::ostream& os, const Form& Form);

#endif