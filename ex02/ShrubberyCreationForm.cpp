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

ShrubberyCreationForm::ShrubberyCreationForm(){
    this->_name = "Generic Shrubbery Form"; 
    this->_signed = 0;
    this->_grade_to_sign = 145;
    this->_grade_to_exec = 137;
	std::cout << "Default Shrubbery Creation Form has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target){
    this->_name = target; 
    this->_signed = 0;
    this->_grade_to_sign = 145;
    this->_grade_to_exec = 137;
	std::cout << "Target Shrubbery Creation Form has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy){
    this->_name = copy._name; 
    std::cout << "Copy of the Shrubbery Creation Form has been created" << std::endl;
}

// AForm &AForm::operator = (const AForm& src){
//     std::cout << "Copy assignment operator called" << std::endl;
// 	if (this != &src)
// 		this->_grade_to_sign = src.getGradeToSign();
//         this->_grade_to_exec = src.getGradeToExec();
	
// 	return *this;
// }

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm& src){
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_grade_to_sign = src.getGradeToSign();
        this->_grade_to_exec = src.getGradeToExec();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Shrubbery Creation Form has been destroyed" << std::endl;
}

void ShrubberyCreationForm::performAction() const {
    std::string filename = _name + "_shrubbery";
    std::ofstream outfile(filename.c_str());  // C++98 doesn't have string literals to char*
    
    if (!outfile.is_open()) {
        throw std::runtime_error("Unable to create file: " + filename);
    }

    // Seed the random number generator
                outfile << "    /\\    " << std::endl;
                outfile << "   /\\*\\   " << std::endl;
                outfile << "  /\\O\\*\\  " << std::endl;
                outfile << " /*/\\/\\/\\ " << std::endl;
                outfile << "/\\O\\/\\*\\/\\" << std::endl;
                outfile << "      ||    " << std::endl;
                outfile << "      ||    " << std::endl;
    
    outfile.close();
}