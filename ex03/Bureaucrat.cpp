/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:28:52 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/10 04:49:55 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
    : name_("John Doe"), grade_(validateGrade(kLowestGrade)) {}

Bureaucrat::Bureaucrat(const std::string &name)
    : name_(name), grade_(validateGrade(kLowestGrade)) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name_(name), grade_(validateGrade(grade)) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name_(other.name_), grade_(validateGrade(other.grade_)) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->grade_ = validateGrade(other.grade_);
  }
  return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}

const std::string &Bureaucrat::getName() const { return this->name_; }

int Bureaucrat::getGrade() const { return this->grade_; }

void Bureaucrat::promote() { this->grade_ = validateGrade(this->grade_ - 1); }

void Bureaucrat::demote() { this->grade_ = validateGrade(this->grade_ + 1); }

void Bureaucrat::signForm(AForm &form) const {
  std::cout << this->getName();
  if (form.isSigned()) {
    std::cout << " couldn't sign " << form.getName()
              << " because it is already signed." << std::endl;
    return;
  }
  try {
    form.beSigned(*this);
    std::cout << " signed " << form.getName() << "." << std::endl;

  } catch (AForm::GradeTooLowException &e) {
    std::cout << " couldn't sign " << form.getName()
              << " due to insufficient grade." << std::endl;
  }
}

void Bureaucrat::executeForm(const AForm &form) const {
  try {
    form.execute(*this);
    std::cout << this->getName() << " executed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->getName() << " couldn't execute " << form.getName()
              << " because <" << e.what() << ">." << std::endl;
  }
}

int Bureaucrat::validateGrade(int grade) const {
  if (grade < kHighestGrade) {
    throw GradeTooHighException();
  }
  if (kLowestGrade < grade) {
    throw GradeTooLowException();
  }
  return grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return os;
}
