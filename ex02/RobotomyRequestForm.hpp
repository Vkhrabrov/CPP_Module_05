/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:47:46 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/09/11 19:23:52 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "PresidentialPardonForm.hpp"

class RobotomyRequestForm : public AForm{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
        virtual ~RobotomyRequestForm();
        void performAction() const;
};

#endif