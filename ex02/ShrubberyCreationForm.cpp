/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:32:21 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/10 04:49:48 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

const std::string ShrubberyCreationForm::kFormName = "ShrubberyCreationForm";

void ShrubberyCreationForm::performAction() const {
  const std::string fileName = this->target_ + "_shrubbery";
  std::ofstream file(fileName.c_str());
  if (!file.is_open()) {
    throw std::runtime_error("it failed to create a file " + fileName);
  }
  file << "         |\n"
       << "        -+-\n"
       << "         A\n"
       << "        /=\\\n"
       << "      i/ O \\i\n"
       << "      /=====\\\n"
       << "      /  i  \\\n"
       << "    i/ O * O \\i\n"
       << "    /=========\\\n"
       << "    /  *   *  \\\n"
       << "  i/ O   i   O \\i\n"
       << "  /=============\\\n"
       << "  /  O   i   O  \\\n"
       << "i/ *   O   O   * \\i\n"
       << "/=================\\\n"
       << "       |___|\n";
}

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm(kFormName, kSignGrade_, kExecGrade_), target_("untitled") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm(kFormName, kSignGrade_, kExecGrade_), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target_(other.target_) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string ShrubberyCreationForm::getTarget() const {
  return this->target_;
}
