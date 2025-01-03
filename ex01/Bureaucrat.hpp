/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:22:02 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/04 10:54:11 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Form;

class Bureaucrat {
private:
  static const int kHighestGrade = 1;
  static const int kLowestGrade = 150;
  const std::string name_;
  int grade_;

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

  Bureaucrat();
  Bureaucrat(const std::string &name);
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  virtual ~Bureaucrat();

  void promote();
  void demote();
  void signForm(Form &form) const;

  const std::string &getName() const;
  int getGrade() const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif // BUREAUCRAT_HPP
