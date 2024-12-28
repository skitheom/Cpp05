/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:28:52 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/29 01:15:00 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

Bureaucrat::Bureaucrat()
    : name_("John Doe"), grade_(enforceGrade(kLowestGrade)) {}

Bureaucrat::Bureaucrat(const std::string &name)
    : name_(name), grade_(enforceGrade(kLowestGrade)) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name_(name), grade_(enforceGrade(grade)) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name_(other.name_), grade_(enforceGrade(other.grade_)) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->grade_ = enforceGrade(other.grade_);
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

int Bureaucrat::enforceGrade(int grade) {
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

const std::string &Bureaucrat::getName() const { return this->name_; }

int Bureaucrat::getGrade() const { return this->grade_; }

void Bureaucrat::setGrade(int grade) { this->grade_ = enforceGrade(grade); }

void Bureaucrat::promote() { this->grade_ = enforceGrade(this->grade_ - 1); }

void Bureaucrat::demote() { this->grade_ = enforceGrade(this->grade_ + 1); }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return os;
}
