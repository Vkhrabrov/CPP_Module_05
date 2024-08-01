/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:48:14 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/08/01 19:58:22 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void){
    
    // Bureaucrat steve("Steve");
    
    // // bob.downGrade(100);
    //     std::cout << "Bob's grade is " << bob.getGrade() <<std::endl;
    //     bob.upGrade(100);  
        // std::cout << bob << std::endl;
        // std::cout << steve << std::endl;
    
    try {
        // Bureaucrat larry("Larry", 200);
        // Form brochure("A simple brochure", 100, 50);
        // brochure.isSigned();
        // brochure.beSigned(larry, brochure);
        // brochure.isSigned();

        // std::cout << std::endl;

        Bureaucrat bob("Bob", 151);
        Form list("Simple List", 120, 50);
        // bob.getGrade();
        list.isSigned();
        bob.signForm(list);
        list.isSigned();
        // Bureaucrat claudia("Claude", 151);
        // bob.downGrade(3);
        
        // steve.upGrade(1);
        // std::cout << "Bob's grade is " << bob.getGrade() <<std::endl;
        // bob.upGrade(-200);
        // std::cout << bob << std::endl;
        // std::cout << steve << std::endl;
        
          // This will throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // Program continues running
    }
    
    // std::cout << "Program continues..." << std::endl;
    // Without try-catch:
    // bob.setGrade(0); 
    return 0;
}