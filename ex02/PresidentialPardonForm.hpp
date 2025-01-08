/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 02:06:29 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/05 02:27:51 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
private:
  static const int kSignGrade_ = 25;
  static const int kExecGrade_ = 5;
  const std::string target_;

public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
  virtual ~PresidentialPardonForm();
};

#endif // PRESIDENTIAL_PARDON_FORM_HPP

/*
PresidentialPardonForm: Required grades: sign 25, exec 5

Informs that <target> has been pardoned by Zaphod Beeblebrox.

All of them take only one parameter in their constructor: the target of the
form. For example, "home" if you want to plant shrubbery at home.
 */
