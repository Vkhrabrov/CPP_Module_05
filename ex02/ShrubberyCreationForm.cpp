/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationAForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:45:07 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/08/01 18:45:39 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137), _target("Random place in the world"){
	std::cout << "Default Shrubbery Creation Form for " << _target << " has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery", 145, 137), _target(target){
	std::cout << "Shrubbery Creation Form for " << _target << " has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target){
    std::cout << "Copy of the Shrubbery Creation Form for " << _target << " has been created" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm& src){
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_target = src._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Shrubbery Creation Form for " << _target << " has been destroyed" << std::endl;
}

void ShrubberyCreationForm::performAction() const {
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile.is_open()) {
        throw std::runtime_error("Unable to create file: " + filename);
    }

                outfile << "    /\\    " << std::endl;
                outfile << "   /\\*\\   " << std::endl;
                outfile << "  /\\O\\*\\  " << std::endl;
                outfile << " /*/\\/\\/\\ " << std::endl;
                outfile << "/\\O\\/\\*\\/\\" << std::endl;
                outfile << "      ||    " << std::endl;
                outfile << "      ||    " << std::endl;
    
    outfile.close();
}