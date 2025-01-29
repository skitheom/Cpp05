/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:31:32 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/10 04:49:54 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
#define A_FORM_HPP

#include <string>

class Bureaucrat;

class AForm {
public:
  AForm();
  AForm(const std::string &name, int gradeToSign, int gradeToExecute);
  AForm(const AForm &other);
  virtual ~AForm();

  AForm &operator=(const AForm &other);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  class FormNotSignedException : public std::exception {
  public:
    const char *what() const throw();
  };

  const std::string &getName() const;
  bool isSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;
  virtual const std::string getTarget() const = 0;

  void beSigned(const Bureaucrat &bureaucrat);
  void execute(Bureaucrat const &executor) const;

private:
  static const int kHighestGrade = 1;
  static const int kLowestGrade = 150;
  const std::string name_;
  bool signed_;
  const int signGrade_;
  const int execGrade_;

  int validateGrade(int grade) const;
  virtual void performAction() const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif // A_FORM_HPP
