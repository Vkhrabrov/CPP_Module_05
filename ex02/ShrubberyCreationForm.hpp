/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationAForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:45:34 by vkhrabro          #+#    #+#             */
/*   Updated: 2024/08/01 19:15:26 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class ShrubberyCreationAForm : public AForm{
    public:
        ShrubberyCreationAForm();
        ShrubberyCreationAForm(const std::string target);
        ShrubberyCreationAForm(const ShrubberyCreationAForm& copy);
        ShrubberyCreationAForm& operator=(const ShrubberyCreationAForm& src);
        ~ShrubberyCreationAForm();
};