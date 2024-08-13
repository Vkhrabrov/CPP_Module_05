/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:30:58 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/07/31 20:38:59 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Empty AForm"), _signed(0), _grade_to_sign(150), _grade_to_exec(100){
	std::cout << "Default AForm is created" << std::endl;
}

AForm::AForm(const std::string name, const int grade_to_sign, const int grade_to_exec)
{
    this->_name = name;
        if (grade_to_sign > 150 || grade_to_exec > 150)
            throw GradeTooLowException();
        else if (grade_to_sign < 1 || grade_to_exec < 1)
            throw GradeTooHighException();

    this->_grade_to_sign = grade_to_sign;
    this->_grade_to_exec = grade_to_exec;
    std::cout << "AForm " << this->_name << " has been created" << std::endl;
}

AForm::AForm(const AForm& copy){
    *this = copy;
    std::cout << "Copy of the AForm " << this->_name << " has been created" << std::endl;
}
		
AForm &AForm::operator = (const AForm& src){
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_grade_to_sign = src.getGradeToSign();
        this->_grade_to_exec = src.getGradeToExec();
	
	return *this;
}
		
AForm::~AForm(){
    std::cout << this->_name << " has been destroyed" << std::endl;
}

int AForm::getGradeToSign() const{
    return this->_grade_to_sign;
}

int AForm::getGradeToExec(void) const{
    return this->_grade_to_exec;
}

std::string AForm::getName(void) const{
    return this->_name;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "The chosen grade for the AForm is too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "The chosen grade for the AForm is too low.";
}

const char* AForm::TheDocumentIsNotSignedException::what() const throw() {
    return "The document isn't signed so it can't be executed.";
}

const char* AForm::TheDocumentIsAlreadySignedException::what() const throw() {
    return "The document has beed signed already.";
}

void AForm::beSigned(Bureaucrat& bureaucrat){

    if (bureaucrat.getGrade() <= this->getGradeToSign())
    {   if (this->_signed != 1)
            this->_signed = 1;
        else{
            std::cout << "The document is already signed, it can not be signed twice" << std::endl;
            throw TheDocumentIsAlreadySignedException();
        }
    }
}

void AForm::execute(Bureaucrat const & executor) const{
    if (this->ifSigned() == 1){
        if (executor.getGrade() <= this->getGradeToExec())
            this->performAction();
        else{
            std::cout << "The Document can't be executed, the bureaucrat's grade is too low." << std::endl;
            throw GradeTooLowException();
        }
    }
    else{
        std::cout << "The Document can't be executed, it must be signed first." << std::endl;
        throw TheDocumentIsNotSignedException();
    }
}

void AForm::isSigned(void){
    if (this->_signed == 1)
        std::cout << this->getName() << " is signed" << std::endl;
    else
        std::cout << this->getName() << " is not signed" << std::endl;
}

int AForm::ifSigned(void) const{
    if (this->_signed == 1)
        return 1;
    else
        return 0;
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
    os << AForm.getName() << ", AForm grade to sign is " << AForm.getGradeToSign() << " and its grade to execute is " << AForm.getGradeToExec();
    return os;
}