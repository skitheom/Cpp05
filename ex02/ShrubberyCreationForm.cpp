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
#include <iostream>

const std::string ShrubberyCreationForm::kFormName = "ShrubberyCreationForm";
/*
Create a file <target>_shrubbery in the working directory,
and writes ASCII trees inside it.

// NOTE: 直接 std::string を渡すとコンパイルできない環境がある
        const std::string fileName = target_ + "_shrubbery";
        std::ofstream file(fileName.c_str());
        if (!file.is_open())
                throw std::runtime_error("cannot open file");
        std::string shrubbery =
                        "     ^^^   \n"
                        "    ^^^^   \n"
                        "   ^^^^^   \n"
                        "  ^^^^^^^  \n"
                        " ^^^^^^^^^ \n"
                        "^^^^^^^^^^^\n";
        file << shrubbery;
        file.close();

 */
void ShrubberyCreationForm::performAction() const {

  const std::string fileName = std::string(this->target_ + "_shrubbery");
  std::ofstream file(fileName.c_str());

  try {
    if (!file.is_open()) {
      throw std::runtime_error("Error: Failed to create shrubbery file");
    }
    // going to write ASCII trees inside of it here (later to inmpriment)
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  file.close();
}

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", kSignGrade_, kExecGrade_),
      target_("untitled") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", kSignGrade_, kExecGrade_),
      target_(target) {}

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
