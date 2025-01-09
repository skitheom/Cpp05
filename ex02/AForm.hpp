/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: north <north@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:31:32 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/10 00:43:45 by north            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
#define A_FORM_HPP

#include <string>

class Bureaucrat;

class AForm {

private:
  static const int kHighestGrade = 1;
  static const int kLowestGrade = 150;
  const std::string name_;
  bool signed_;
  const int signGrade_;
  const int execGrade_;

  int validateGrade(int grade);
  virtual void performAction() const = 0;

public:
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class FormNotSignedException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  AForm();
  AForm(const std::string &name, int gradeToSign, int gradeToExecute);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  virtual ~AForm();

  void beSigned(const Bureaucrat &bureaucrat);
  void execute(Bureaucrat const &executor) const;

  const std::string &getName() const;
  bool isSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;
  virtual const std::string getTarget() const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif // A_FORM_HPP
