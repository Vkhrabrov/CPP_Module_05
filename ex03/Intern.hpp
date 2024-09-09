/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:47:13 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/09/09 19:43:45 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "RobotomyRequestForm.hpp"

class Intern {
    private:
        std::string formNames[3];

        static AForm* creationPP(const std::string& target);
        static AForm* creationRR(const std::string& target);
        static AForm* creationSC(const std::string& target);
    
    public:
        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& src);
        ~Intern();
        AForm* makeForm(const std::string form_name, const std::string target);
};

#endif