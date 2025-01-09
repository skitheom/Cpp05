/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:32:30 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/10 04:48:14 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

static void test1() {
  std::cout << "\n=== Test case 1: ShrubberyCreationForm ===" << std::endl;

  AForm *form = nullptr;
  try {
    Bureaucrat bureaucrat("President Cat", 1);
    Intern novice;

    form = novice.makeForm("shrubbery creation", "Apple");
    if (!form) {
      return;
    }

    std::cout << "Bureaucrat: " << bureaucrat << std::endl;
    std::cout << *form << std::endl;

    std::cout << "!! Attempting to sign form..." << std::endl;
    bureaucrat.signForm(*form);

    std::cout << "!! Attempting to execute form..." << std::endl;
    bureaucrat.executeForm(*form);

  } catch (std::exception &e) {
    std::cerr << "[Exception] " << e.what() << std::endl;
  }
  delete form;
}

static void test2() {
  std::cout << "\n=== Test case 2: RobotomyRequestForm ===" << std::endl;

  AForm *form = nullptr;
  try {
    Bureaucrat bureaucrat("President Cat", 1);
    Intern novice;

    form = novice.makeForm("robotomy request", "Orange");
    if (!form) {
      return;
    }

    std::cout << "Bureaucrat: " << bureaucrat << std::endl;
    std::cout << *form << std::endl;

    std::cout << "!! Attempting to sign form..." << std::endl;
    bureaucrat.signForm(*form);

    std::cout << "!! Attempting to execute form..." << std::endl;
    bureaucrat.executeForm(*form);

  } catch (std::exception &e) {
    std::cerr << "[Exception] " << e.what() << std::endl;
  }
  delete form;
}

static void test3() {
  std::cout << "\n=== Test case 3: PresidentialPardonForm ===" << std::endl;

  AForm *form = nullptr;
  try {
    Bureaucrat bureaucrat("President Cat", 1);
    Intern novice;

    form = novice.makeForm("presidential pardon", "Kiwi");
    if (!form) {
      return;
    }

    std::cout << "Bureaucrat: " << bureaucrat << std::endl;
    std::cout << *form << std::endl;

    std::cout << "!! Attempting to sign form..." << std::endl;
    bureaucrat.signForm(*form);

    std::cout << "!! Attempting to execute form..." << std::endl;
    bureaucrat.executeForm(*form);

  } catch (std::exception &e) {
    std::cerr << "[Exception] " << e.what() << std::endl;
  }
  delete form;
}

static void test4() {
  std::cout << "\n=== Test case 4: ??? Form ===" << std::endl;

  AForm *form = nullptr;
  try {
    Bureaucrat bureaucrat("President Cat", 1);
    Intern novice;

    form = novice.makeForm("?", "Green");
    if (!form) {
      return;
    }

    std::cout << "Bureaucrat: " << bureaucrat << std::endl;
    std::cout << *form << std::endl;

    std::cout << "!! Attempting to sign form..." << std::endl;
    bureaucrat.signForm(*form);

    std::cout << "!! Attempting to execute form..." << std::endl;
    bureaucrat.executeForm(*form);

  } catch (std::exception &e) {
    std::cerr << "[Exception] " << e.what() << std::endl;
  }
  delete form;
}

int main() {
  test1();
  test2();
  test3();
  test4();
  return 0;
}
