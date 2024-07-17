/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:48:14 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/07/17 22:20:47 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void){
    Bureaucrat bob("Bob");
    // // bob.downGrade(100);
    //     std::cout << "Bob's grade is " << bob.getGrade() <<std::endl;
    //     bob.upGrade(100);
    //     std::cout << "Bob's grade is " << bob.getGrade() <<std::endl;
    
    try {
        // bob.downGrade(100);
        bob.upGrade(200);
        
          // This will throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // Program continues running
    }
    
    std::cout << "Program continues..." << std::endl;
    // Without try-catch:
    // bob.setGrade(0); 
    return 0;
}