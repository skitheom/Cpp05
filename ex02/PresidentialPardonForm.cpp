/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:16:44 by north             #+#    #+#             */
/*   Updated: 2025/01/10 04:47:55 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

const std::string PresidentialPardonForm::kFormName = "PresidentialPardonForm";

void PresidentialPardonForm::performAction() const {
  std::cout << this->target_ << " has been pardoned by Zaphod Beeblebrox"
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm()
    : AForm(kFormName, kSignGrade_, kExecGrade_), target_("untitled") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm(kFormName, kSignGrade_, kExecGrade_), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), target_(other.target_) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string PresidentialPardonForm::getTarget() const {
  return this->target_;
}
