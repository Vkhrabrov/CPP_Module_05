/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:48:14 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/09/10 20:02:38 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
    try {
        Intern someIntern;
        AForm* rrf;
        AForm* ppf;

        rrf = someIntern.makeForm("Robotomy Request", "Lobotomy for Kondrat");
        Bureaucrat bob("Bob", 4);
        Bureaucrat sandra("Sandra", 71);
        Bureaucrat peter("Peter", 70);
        rrf->isSigned();
        sandra.signForm(*rrf);
    
        ppf = someIntern.makeForm("Presidential Pardon", "Form for Alex");
        ppf->isSigned();
        bob.signForm(*ppf);
        bob.executeForm(*ppf);
        // sandra.executeForm(*rrf);

        AForm* scf;
        scf = someIntern.makeForm("Shrubbery form", "You shall not pass!");
        delete rrf;
        delete ppf;
        delete scf;
    } catch (const std::exception& e) {
        // std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}