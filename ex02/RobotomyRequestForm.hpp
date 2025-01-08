/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 02:01:27 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/05 02:26:11 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
private:
  static const int kSignGrade_ = 72;
  static const int kExecGrade_ = 45;
  const std::string target_;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const AForm &other);
  RobotomyRequestForm &operator=(const AForm &other);
  virtual ~RobotomyRequestForm();
};

#endif // ROBOTOMY_REQUEST_FORM_HPP

/*
RobotomyRequestForm: Required grades: sign 72, exec 45

Makes some drilling noises. Then, informs that <target> has been robotomized
successfully 50% of the time. Otherwise, informs that the robotomy failed

All of them take only one parameter in their constructor: the target of the
form. For example, "home" if you want to plant shrubbery at home.
*/
