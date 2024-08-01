/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:48:14 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/08/01 20:09:00 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

int main(void)
{
    try {
        Bureaucrat bob("Bob", 121);
        AForm list("Simple List", 100, 50);
        list.isSigned();
        bob.signAForm(list);
        list.isSigned();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}