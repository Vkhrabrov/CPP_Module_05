/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestAForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:47:43 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/08/01 18:47:44 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(){
    this->_name = "Generic Robotomy Request Form"; 
    this->_signed = 0;
    this->_grade_to_sign = 72;
    this->_grade_to_exec = 45;
	std::cout << "Default Robotomy Request Form has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target){
    this->_name = target; 
    this->_signed = 0;
    this->_grade_to_sign = 72;
    this->_grade_to_exec = 45;
	std::cout << "Target Robotomy Request Form has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy){
    this->_name = copy._name; 
    std::cout << "Copy of the Robotomy Request Form has been created" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm& src){
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_grade_to_sign = src.getGradeToSign();
        this->_grade_to_exec = src.getGradeToExec();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Robotomy Request Form has been destroyed" << std::endl;
}

void RobotomyRequestForm::performAction() const {
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::cout << "* Drilling noises * Bzzz... Whirrr... Clank!" << std::endl;
    
    // 50% chance of success
    if (std::rand() % 2 == 0) {
        std::cout << _name << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed. " << _name << " remains unrobotomized." << std::endl;
    }
}