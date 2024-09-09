/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:48:14 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/09/09 20:26:34 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
    try {
        Intern someIntern;
        AForm* rrf;
        AForm* ppf;

        rrf = someIntern.makeForm("Robotomy Request", "Bobby");
        Bureaucrat bob("Bob", 4);
        // ShrubberyCreationForm shrubs("Home");
        // PresidentialPardonForm no_mercy("Mercy");
        // RobotomyRequestForm johnny("John Doe");
        rrf->isSigned();
        // johnny.isSigned();
        bob.signForm(*rrf);
        // johnny.isSigned();

        // no_mercy.isSigned();
        // bob.signForm(shrubs);
        // bob.signForm(no_mercy);
        // bob.signForm(shrubs);
        // no_mercy.isSigned();
        // shrubs.isSigned();
        bob.executeForm(*rrf);
        ppf = someIntern.makeForm("Presidential Pardon", "Alex");
        delete rrf;
        delete ppf;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}