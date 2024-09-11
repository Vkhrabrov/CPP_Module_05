/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:48:14 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/09/11 18:45:31 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void){
    Bureaucrat bob("Bob");
    Bureaucrat steve("Steve");
    
        std::cout << bob << std::endl;
        std::cout << steve << std::endl;
    
    Bureaucrat pete = bob;
    std::cout << pete << std::endl;
    
    // try {

    //     Bureaucrat claudia("Claude", 151);
    //     bob.downGrade(3);

    //     std::cout << bob << std::endl;
    //     std::cout << steve << std::endl;
        
    // } catch (const std::exception& e) {
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }
    return 0;
}