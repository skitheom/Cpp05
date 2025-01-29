/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 03:16:30 by north             #+#    #+#             */
/*   Updated: 2025/01/10 04:49:57 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstddef>
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other) {
  if (this != &other) {
  }
  return *this;
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) const {
  const size_t kNumOfFunc = 3;
  const std::string formType[kNumOfFunc] = {
      "shrubbery creation", "robotomy request", "presidential pardon"};
  AForm *(Intern::*func[kNumOfFunc])(const std::string &) const = {
      &Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm,
      &Intern::makePresidentialPardonForm};

  for (size_t i = 0; i < kNumOfFunc; i++) {
    if (formName == formType[i]) {
      try {
        AForm *form = (this->*func[i])(target);
        std::cout << "Intern creates " << formName << " form." << std::endl;
        return form;
      } catch (const std::bad_alloc &e) {
        std::cerr << "Error: Intern could not create form: " << e.what()
                  << std::endl;
        return NULL;
      }
    }
  }
  std::cerr << "Error: Intern could not find " << formName << " form."
            << std::endl;
  return NULL;
}

AForm *Intern::makeShrubberyCreationForm(const std::string &target) const {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target) const {
  return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string &target) const {
  return new PresidentialPardonForm(target);
}
