/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:48:14 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/09/12 19:34:10 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
    try {
        Intern someIntern;
        AForm* rrf;
        AForm* ppf;

        rrf = someIntern.makeForm("Robotomy Request Form", "Kondrat");
        Bureaucrat bob("Bob", 4);
        Bureaucrat sandra("Sandra", 4);
        Bureaucrat peter("Peter", 70);
        rrf->isSigned();
        sandra.signForm(*rrf);
        sandra.executeForm(*rrf);

        std::cout << std::endl;
    
        ppf = someIntern.makeForm("Presidential Pardon Form", "Alex");
        ppf->isSigned();
        bob.signForm(*ppf);
        bob.executeForm(*ppf);
        // sandra.executeForm(*rrf);

        std::cout << std::endl;
        
        AForm* scf;
        scf = someIntern.makeForm("Shrubbery Creation form", "Backyard");
        delete rrf;
        delete ppf;
        delete scf;
    } catch (const std::exception& e) {
        // std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}