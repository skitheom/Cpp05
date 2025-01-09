/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: north <north@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 02:01:27 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/10 00:43:55 by north            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
private:
  static const std::string kFormName;
  static const int kSignGrade_ = 72;
  static const int kExecGrade_ = 45;
  const std::string target_;

  virtual void performAction() const;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
  virtual ~RobotomyRequestForm();

  virtual const std::string getTarget() const;
};

#endif // ROBOTOMY_REQUEST_FORM_HPP
