/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonAForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:47:40 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/08/01 18:47:41 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){
    this->_name = "Generic Presidential Pardon Form"; 
    this->_signed = 0;
    this->_grade_to_sign = 25;
    this->_grade_to_exec = 5;
	std::cout << "Default Presidential Pardon Form Form has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target){
    this->_name = target; 
    this->_signed = 0;
    this->_grade_to_sign = 25;
    this->_grade_to_exec = 5;
	std::cout << "Target Presidential Pardon Form has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy){
    this->_name = copy._name; 
    std::cout << "Copy of the Presidential Pardon Form has been created" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm& src){
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_grade_to_sign = src.getGradeToSign();
        this->_grade_to_exec = src.getGradeToExec();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Presidential Pardon Form has been destroyed" << std::endl;
}

void PresidentialPardonForm::performAction() const {
    std::cout << this->_name << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}