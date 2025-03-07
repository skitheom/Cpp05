/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:44:18 by north             #+#    #+#             */
/*   Updated: 2025/01/10 04:50:01 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

const std::string RobotomyRequestForm::kFormName = "RobotomyRequestForm";

RobotomyRequestForm::RobotomyRequestForm()
    : AForm(kFormName, kSignGrade_, kExecGrade_), target_("untitled") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm(kFormName, kSignGrade_, kExecGrade_), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target_(other.target_) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

const std::string RobotomyRequestForm::getTarget() const {
  return this->target_;
}

void RobotomyRequestForm::performAction() const {
  std::cout << "** Makes some drilling noises **" << std::endl;
  std::cout << "Drrrrrr..." << std::endl;
  std::srand(std::time(0));
  if (std::rand() % 2 == 0) {
    throw std::runtime_error("the robotomy failed");
  }
  std::cout << this->target_ << " has been robotomized successfully"
            << std::endl;
}