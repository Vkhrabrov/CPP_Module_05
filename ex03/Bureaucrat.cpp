/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:51:22 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/09/10 19:56:56 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("John Doe"), _grade(1){
	std::cout << "Default Bureaucrat is now on duty" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name){
    this->_name = name;
    this->_grade = 1;
    std::cout << "Bureaucrat " << this->_name << " is now on duty" << std::endl;

}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    this->_name = name;
        if (grade > 150)
            throw GradeTooLowException();
        else if (grade < 1)
            throw GradeTooHighException();
    this->_grade = grade;
    std::cout << "Bureaucrat " << this->_name << " is now on duty" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy){
    *this = copy;
    std::cout << "Copy Bureaucrat " << this->_name << " is now on duty" << std::endl;
}
		
Bureaucrat &Bureaucrat::operator = (const Bureaucrat& src){
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_grade = src.getGrade();
	
	return *this;
}
		
Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat " << this->_name << " has left the duty" << std::endl;
}

int Bureaucrat::getGrade() const{
    return this->_grade;
}

std::string Bureaucrat::getName(void) const{
    return this->_name;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat's grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat's grade is too low";
}

void Bureaucrat::upGrade(int const grade){
if (_grade - grade < 1)
        throw GradeTooHighException();
else if (_grade - grade > 150)
        throw GradeTooLowException();
    this->_grade -= grade;
}

void Bureaucrat::downGrade(int const grade){
    if (_grade + grade > 150)
        throw GradeTooLowException();
    else if (_grade + grade < 1)
        throw GradeTooHighException();
    this->_grade += grade;
}

void Bureaucrat::signForm(AForm& AForm){
   AForm.beSigned(*this);
      if (AForm.ifSigned() == 1)
            std::cout << this->_name << " signed " << AForm.getName() << std::endl;
        else
        {
            std::cout << this->_name << " could not sign " << AForm.getName() << " because his grade is too low " << std::endl;
            std::cout << "The grade required to sign this Form is " << AForm.getGradeToSign() << " and the " << this->_name << "'s grade is " << this->_grade << std::endl;
            throw GradeTooLowException();
        }
}

void Bureaucrat::executeForm(AForm const & form){
    // form.execute(*this);
      if (this->_grade <= form.getGradeToExec()){
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
      }
        else
        {
            std::cout << this->_name << " could not execute " << form.getName() << " because his grade is too low " << std::endl;
            std::cout << "The grade required to execute this Form is " << form.getGradeToExec() << " and the " << this->_name << "'s grade is " << this->_grade << std::endl;
            throw GradeTooLowException();
        }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

