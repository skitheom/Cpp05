/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:51:25 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/10 04:50:04 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm();

  const std::string getTarget() const;

private:
  static const std::string kFormName;
  static const int kSignGrade_ = 145;
  static const int kExecGrade_ = 137;
  const std::string target_;

  void performAction() const;
};

#endif // SHRUBBERY_CREATION_FORM_HPP
