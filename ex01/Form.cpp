/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 01:47:25 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/07 14:53:36 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int Form::validateGrade(int grade) {
  if (grade < kHighestGrade) {
    throw GradeTooHighException();
  }
  if (kLowestGrade < grade) {
    throw GradeTooLowException();
  }
  return grade;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}

Form::Form()
    : name_("Untitled"), signed_(false),
      signGrade_(validateGrade(kLowestGrade)),
      execGrade_(validateGrade(kLowestGrade)) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name_(name), signed_(false), signGrade_(validateGrade(gradeToSign)),
      execGrade_(validateGrade(gradeToExecute)) {}

Form::Form(const Form &other)
    : name_(other.name_), signed_(other.signed_),
      signGrade_(validateGrade(other.signGrade_)),
      execGrade_(validateGrade(other.execGrade_)) {}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    this->signed_ = other.signed_;
  }
  return *this;
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->signGrade_) {
    throw GradeTooLowException();
  }
  signed_ = true;
}

const std::string &Form::getName() const { return this->name_; }

bool Form::isSigned() const { return this->signed_; }

int Form::getSignGrade() const { return this->signGrade_; }

int Form::getExecGrade() const { return this->execGrade_; }

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form: " << form.getName()
     << " | Signed: " << (form.isSigned() ? "Yes" : "No")
     << " | Sign Grade: " << form.getSignGrade()
     << " | Exec Grade: " << form.getExecGrade();
  return os;
}
