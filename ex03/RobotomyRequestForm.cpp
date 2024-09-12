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

RobotomyRequestForm::RobotomyRequestForm() : AForm("Generic Robotomy Request Form", 72, 45), _target("Some random poor lad"){
	std::cout << "Default Robotomy Request Form for " << _target << " has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Generic Robotomy Request Form", 72, 45), _target(target){
	std::cout << "Robotomy Request Form for " << _target << " has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy), _target(copy._target){ 
    std::cout << "Copy of the Robotomy Request Form for " << _target << " has been created" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm& src){
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_target = src._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Robotomy Request Form for " << _target << " has been destroyed" << std::endl;
}

void RobotomyRequestForm::performAction() const {
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::cout << "* Drilling noises * Bzzz... Whirrr... Clank!" << std::endl;
    
    // 50% chance of success
    if (std::rand() % 2 == 0) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed. " << _target << " remains unrobotomized." << std::endl;
    }
}