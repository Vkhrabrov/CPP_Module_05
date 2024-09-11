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

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), 
    _target("Random citizen"){
	std::cout << "Default Presidential Pardon Form Form has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Pardon Form", 25, 5), 
    _target(target){
	std::cout << "Target Presidential Pardon Form has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy), _target(copy._target){
    std::cout << "Copy of the Presidential Pardon Form has been created" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm& src){
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_target = src._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Presidential Pardon Form has been destroyed" << std::endl;
}

void PresidentialPardonForm::performAction() const {
    std::cout << this->_name << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}