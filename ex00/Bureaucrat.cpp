/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:28:52 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/07 14:51:19 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

const std::string &Bureaucrat::getName() const { return this->name_; }

int Bureaucrat::getGrade() const { return this->grade_; }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return os;
}
