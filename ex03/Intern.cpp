/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: north <north@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 03:16:30 by north             #+#    #+#             */
/*   Updated: 2025/01/10 04:19:52 by north            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &other) {
  if (this != &other) {
  }
  return *this;
}

Intern::~Intern() {}

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
        return nullptr;
      }
    }
  }
  std::cerr << "Error: Intern could not find " << formName << " form."
            << std::endl;
  return nullptr;
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

// Intern creates <form>