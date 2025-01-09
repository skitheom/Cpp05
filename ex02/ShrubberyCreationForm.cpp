/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:32:21 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/07 15:50:53 by sakitaha         ###   ########.fr       */
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
    throw std::runtime_error("Error: Failed to create shrubbery file");
    return;
  }
  file << "         |" << std::endl;
  file << "        -+-" << std::endl;
  file << "         A" << std::endl;
  file << "        /=\\" << std::endl;
  file << "      i/ O \\i" << std::endl;
  file << "      /=====\\" << std::endl;
  file << "      /  i  \\" << std::endl;
  file << "    i/ O * O \\i" << std::endl;
  file << "    /=========\\" << std::endl;
  file << "    /  *   *  \\" << std::endl;
  file << "  i/ O   i   O \\i" << std::endl;
  file << "  /=============\\" << std::endl;
  file << "  /  O   i   O  \\" << std::endl;
  file << "i/ *   O   O   * \\i" << std::endl;
  file << "/=================\\" << std::endl;
  file << "       |___|" << std::endl;
  file << std::endl;
  file.close();
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
