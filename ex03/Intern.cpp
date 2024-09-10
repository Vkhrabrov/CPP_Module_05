/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:47:01 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/09/10 20:05:31 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
  std::cout << "Intern is created" << std::endl;
}

Intern::Intern(const Intern& copy){
    *this = copy;
}

Intern& Intern::operator=(const Intern& src){
	if (this != &src)
    return *this;
  return *this;
}

Intern::~Intern(){
    std::cout << "Intern has left his duty" << std::endl;
}

AForm* Intern::creationPP(const std::string& target){
  return new PresidentialPardonForm(target);
}

AForm* Intern::creationRR(const std::string& target){
  return new RobotomyRequestForm(target);
}

AForm* Intern::creationSC(const std::string& target){
  return new ShrubberyCreationForm(target);
}
        
AForm* Intern::makeForm(const std::string form_name, const std::string target){
    std::string formNameList[3] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};

    AForm* (*functionArray[3])(const std::string&);
    functionArray[0] = &creationPP;
    functionArray[1] = &creationRR;
    functionArray[2] = &creationSC;

  for (int i = 0; i < 3; i++){
    if (form_name == formNameList[i]){
      std::cout << "Intern has created " << form_name << std::endl;
      return functionArray[i](target);
    }
  }
  std::cout << "Intern couldn't create " << form_name << ". Check the spelling of your Form Request!" << std::endl;
  std::cout << "Must be Shrubbery Creation/Presidential Pardon/Robotomy Request" << std::endl;
  throw std::runtime_error("Couldn't create " + form_name + " Form");
}