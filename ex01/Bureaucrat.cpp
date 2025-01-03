/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:28:52 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/04 10:54:06 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int Bureaucrat::validateGrade(int grade) {
  if (grade < kHighestGrade) {
    throw GradeTooHighException();
  }
  if (kLowestGrade < grade) {
    throw GradeTooLowException();
  }
  return grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}

Bureaucrat::Bureaucrat()
    : name_("John Doe"), grade_(validateGrade(kLowestGrade)) {}

Bureaucrat::Bureaucrat(const std::string &name)
    : name_(name), grade_(validateGrade(kLowestGrade)) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name_(name), grade_(validateGrade(grade)) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name_(other.name_), grade_(validateGrade(other.grade_)) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->grade_ = validateGrade(other.grade_);
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::promote() { this->grade_ = validateGrade(this->grade_ - 1); }

void Bureaucrat::demote() { this->grade_ = validateGrade(this->grade_ + 1); }

void Bureaucrat::signForm(Form &form) const {
  std::cout << this->getName();
  if (form.isSigned()) {
    std::cout << " couldn't sign " << form.getName()
              << " because it is already signed." << std::endl;
    return;
  }
  try {
    form.beSigned(*this);
    std::cout << " signed " << form.getName() << "." << std::endl;

  } catch (Form::GradeTooLowException &e) {
    std::cout << " couldn't sign " << form.getName()
              << " due to insufficient grade." << std::endl;
  }
}

const std::string &Bureaucrat::getName() const { return this->name_; }

int Bureaucrat::getGrade() const { return this->grade_; }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return os;
}
