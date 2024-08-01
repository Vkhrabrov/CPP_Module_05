/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:51:22 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/08/01 19:58:11 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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

void Bureaucrat::signForm(Form& form){
   form.beSigned(*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

