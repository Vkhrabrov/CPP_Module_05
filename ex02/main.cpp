/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:48:14 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/08/13 21:30:02 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

int main(void)
{
    try {
        Bureaucrat bob("Bob", 4);
        // ShrubberyCreationForm shrubs("Home");
        // PresidentialPardonForm no_mercy("Mercy");
        RobotomyRequestForm johnny("John Doe");
        // shrubs.isSigned();
        johnny.isSigned();
        bob.signForm(johnny);
        johnny.isSigned();

        // no_mercy.isSigned();
        // bob.signForm(shrubs);
        // bob.signForm(no_mercy);
        // bob.signForm(shrubs);
        // no_mercy.isSigned();
        // shrubs.isSigned();
        bob.executeForm(johnny);
    } catch (const std::exception& e) {
        // std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}