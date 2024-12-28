/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:22:02 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/29 00:59:48 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
private:
  static const int kHighestGrade = 1;
  static const int kLowestGrade = 150;
  const std::string name_;
  int grade_;

  int enforceGrade(int grade);

public:
  Bureaucrat();
  Bureaucrat(const std::string &name);
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  virtual ~Bureaucrat();

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  const std::string &getName() const;
  int getGrade() const;
  void setGrade(int grade);

  void promote();
  void demote();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif // BUREAUCRAT_HPP

/*  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too high!"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too low!"; }
  }; */
