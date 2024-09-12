/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:48:14 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/09/12 19:37:21 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

int main(void)
{
    try {
        Bureaucrat bob("Bob", 4);
        RobotomyRequestForm johnny("John Doe");
        ShrubberyCreationForm house("home");
        PresidentialPardonForm peter("Peter");
        johnny.isSigned();
        bob.signForm(johnny);
        johnny.isSigned();

        bob.executeForm(johnny);
    } catch (const std::exception& e) {
        // std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}