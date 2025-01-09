/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 03:16:24 by north             #+#    #+#             */
/*   Updated: 2025/01/10 04:49:57 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern {
private:
  AForm *makeShrubberyCreationForm(const std::string &target) const;
  AForm *makeRobotomyRequestForm(const std::string &target) const;
  AForm *makePresidentialPardonForm(const std::string &target) const;

public:
  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern();

  AForm *makeForm(const std::string &formName, const std::string &target) const;
};

#endif // INTERN_HPP
