/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:48:14 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/08/02 21:23:36 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

int main(void)
{
    try {
        Bureaucrat bob("Bob", 144);
        ShrubberyCreationForm shrubs("Home");
        shrubs.isSigned();
        bob.signForm(shrubs);
        bob.signForm(shrubs);
        shrubs.isSigned();
        bob.executeForm(shrubs);
    } catch (const std::exception& e) {
        // std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}