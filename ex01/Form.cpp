/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:30:58 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/08/01 19:56:16 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Empty Form"), _signed(0), _grade_to_sign(150), _grade_to_exec(100){
	std::cout << "Default Form is created" << std::endl;
}

Form::Form(const std::string name, const int grade_to_sign, const int grade_to_exec)
{
    this->_name = name;
        if (grade_to_sign > 150 || grade_to_exec > 150)
            throw GradeTooLowException();
        else if (grade_to_sign < 1 || grade_to_exec < 1)
            throw GradeTooHighException();

    this->_grade_to_sign = grade_to_sign;
    this->_grade_to_exec = grade_to_exec;
    std::cout << "Form " << this->_name << " has been created" << std::endl;
}

Form::Form(const Form& copy){
    *this = copy;
    std::cout << "Copy of the Form " << this->_name << " has been created" << std::endl;
}
		
Form &Form::operator = (const Form& src){
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_grade_to_sign = src.getGradeToSign();
        this->_grade_to_sign = src.getGradeToExec();
	
	return *this;
}
		
Form::~Form(){
    std::cout << "Form " << this->_name << " has been destroyed" << std::endl;
}

int Form::getGradeToSign() const{
    return this->_grade_to_sign;
}

int Form::getGradeToExec(void) const{
    return this->_grade_to_exec;
}

std::string Form::getName(void) const{
    return this->_name;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "The chosen grade for the form is too high.";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "The chosen grade for the form is too low.";
}

void Form::beSigned(Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() <= this->getGradeToSign())
        this->_signed = 1;
    if (this->_signed == 1)
            std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
        else
        {
            std::cout << bureaucrat.getName() << " could not sign " << this->_name << " because his grade is too low " << std::endl;
            std::cout << "The grade required to sign this form is " << this->_grade_to_sign << " and the " << bureaucrat.getName() << "'s grade is " << bureaucrat.getGrade() << std::endl;
            throw Bureaucrat::GradeTooLowException();
        }
}

void Form::isSigned(void){
    if (this->_signed == 1)
        std::cout << "The Form " << this->getName() << " is signed" << std::endl;
    else
        std::cout << "The Form " << this->getName() << " is not signed" << std::endl;
}

int Form::ifSigned(void) const{
    if (this->_signed == 1)
        return 1;
    else
        return 0;
}

// void Form::upGrade(int const grade){
//     if (_grade - grade < 1)
//         throw GradeTooHighException();
//     else if (_grade - grade > 150)
//         throw GradeTooLowException();
//     this->_grade -= grade;
// }

// void Form::downGrade(int const grade){
//     if (_grade + grade > 150)
//         throw GradeTooLowException();
//     else if (_grade + grade < 1)
//         throw GradeTooHighException();
//     this->_grade += grade;
// }

std::ostream& operator<<(std::ostream& os, const Form& Form) {
    os << Form.getName() << ", Form grade to sign is " << Form.getGradeToSign() << " and its grade to execute is " << Form.getGradeToExec();
    return os;
}