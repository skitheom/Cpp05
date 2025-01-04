/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 01:21:35 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/29 02:07:48 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Form {
private:
  static const int kHighestGrade = 1;
  static const int kLowestGrade = 150;
  const std::string name_;
  bool signed_;
  const int signGrade_;
  const int execGrade_;

  int validateGrade(int grade);

public:
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  Form();
  Form(const std::string &name, int gradeToSign, int gradeToExecute);
  Form(const Form &other);
  Form &operator=(const Form &other);
  virtual ~Form();

  void beSigned(const Bureaucrat &bureaucrat);

  const std::string &getName() const;
  bool isSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif // FORM_HPP
