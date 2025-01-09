/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: north <north@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:51:25 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/10 00:44:00 by north            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
  static const std::string kFormName;
  static const int kSignGrade_ = 145;
  static const int kExecGrade_ = 137;
  const std::string target_;

  virtual void performAction() const;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
  virtual ~ShrubberyCreationForm();

  virtual const std::string getTarget() const;
};

#endif // SHRUBBERY_CREATION_FORM_HPP
