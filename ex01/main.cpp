/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:48:14 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/09/11 18:42:59 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void){
    
    try {

        Bureaucrat bob("Bob", 100);
        Form list("Simple List", 120, 50);
        list.isSigned();
        bob.signForm(list);
        list.isSigned();
        Bureaucrat pete = bob;
        std::cout << pete << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}