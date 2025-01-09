/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:40:43 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/10 04:47:37 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

int AForm::validateGrade(int grade) {
  if (grade < kHighestGrade) {
    throw GradeTooHighException();
  }
  if (kLowestGrade < grade) {
    throw GradeTooLowException();
  }
  return grade;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "The form must be signed before execution!";
}

AForm::AForm()
    : name_("Untitled"), signed_(false),
      signGrade_(validateGrade(kLowestGrade)),
      execGrade_(validateGrade(kLowestGrade)) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name_(name), signed_(false), signGrade_(validateGrade(gradeToSign)),
      execGrade_(validateGrade(gradeToExecute)) {}

AForm::AForm(const AForm &other)
    : name_(other.name_), signed_(other.signed_),
      signGrade_(validateGrade(other.signGrade_)),
      execGrade_(validateGrade(other.execGrade_)) {}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    this->signed_ = other.signed_;
  }
  return *this;
}

AForm::~AForm() {}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->signGrade_) {
    throw GradeTooLowException();
  }
  signed_ = true;
}

void AForm::execute(Bureaucrat const &executor) const {

  if (!this->isSigned()) {
    throw FormNotSignedException();
  }
  if (executor.getGrade() > this->execGrade_) {
    throw GradeTooLowException();
  }
  performAction();
}

const std::string &AForm::getName() const { return this->name_; }

bool AForm::isSigned() const { return this->signed_; }

int AForm::getSignGrade() const { return this->signGrade_; }

int AForm::getExecGrade() const { return this->execGrade_; }

std::ostream &operator<<(std::ostream &os, const AForm &form) {
  os << "Form: " << form.getName()
     << " | Signed: " << (form.isSigned() ? "Yes" : "No")
     << " | Sign Grade: " << form.getSignGrade()
     << " | Exec Grade: " << form.getExecGrade()
     << " | Target: " << form.getTarget();
  return os;
}
