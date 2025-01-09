/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:44:09 by north             #+#    #+#             */
/*   Updated: 2025/01/10 04:49:41 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

static void test1() {
  std::cout << "\n=== Test case 1: Default Constructor ===" << std::endl;
  try {
    Bureaucrat bureaucrat;
    ShrubberyCreationForm sForm;
    RobotomyRequestForm rForm;
    PresidentialPardonForm pForm;

    std::cout << "Bureaucrat: " << bureaucrat << std::endl;
    std::cout << sForm << std::endl;
    std::cout << rForm << std::endl;
    std::cout << pForm << std::endl;
  } catch (std::exception &e) {
    std::cerr << "[Exception] " << e.what() << std::endl;
  }
}

static void test2() {
  std::cout << "\n=== Test case 2: Named Constructor ===" << std::endl;
  try {
    Bureaucrat bureaucrat("Pham", 42);
    ShrubberyCreationForm sForm("sTarget");
    RobotomyRequestForm rForm("rTarget");
    PresidentialPardonForm pForm("pTarget");

    std::cout << "Bureaucrat: " << bureaucrat << std::endl;
    std::cout << sForm << std::endl;
    std::cout << rForm << std::endl;
    std::cout << pForm << std::endl;
  } catch (std::exception &e) {
    std::cerr << "[Exception] " << e.what() << std::endl;
  }
}

static void signTest(Bureaucrat &bureaucrat, AForm &form) {
  std::cout << "!! Attempting to sign form..." << std::endl;
  bureaucrat.signForm(form);
}

static void execTest(Bureaucrat &bureaucrat, AForm &form) {
  std::cout << "!! Attempting to execute form..." << std::endl;
  bureaucrat.executeForm(form);
}

static void testShrubberyCreationForm(Bureaucrat &b1, Bureaucrat &b2) {
  std::cout << "\n=== Test case: ShrubberyCreationForm ===" << std::endl;
  try {
    ShrubberyCreationForm form("jovianPlanet");

    std::cout << form << std::endl;
    signTest(b2, form); // failure
    signTest(b1, form); // success
    signTest(b1, form); // failure
    execTest(b2, form); // failure
    execTest(b1, form); // success
  } catch (std::exception &e) {
    std::cerr << "[Exception] " << e.what() << std::endl;
  }
}

static void testRobotomyRequestForm(Bureaucrat &b1, Bureaucrat &b2) {
  std::cout << "\n=== Test case: RobotomyRequestForm ===" << std::endl;
  try {
    RobotomyRequestForm form("hesperus");

    std::cout << form << std::endl;
    signTest(b2, form); // failure
    signTest(b1, form); // success
    signTest(b1, form); // failure
    execTest(b2, form); // failure
    execTest(b1, form);
  } catch (std::exception &e) {
    std::cerr << "[Exception] " << e.what() << std::endl;
  }
}

static void testPresidentialPardonForm(Bureaucrat &b1, Bureaucrat &b2) {
  std::cout << "\n=== Test case: PresidentialPardonForm ===" << std::endl;
  try {
    PresidentialPardonForm form("lagomorph");

    std::cout << form << std::endl;
    signTest(b2, form); // failure
    signTest(b1, form); // success
    signTest(b1, form); // failure
    execTest(b2, form); // failure
    execTest(b1, form); // success
  } catch (std::exception &e) {
    std::cerr << "[Exception] " << e.what() << std::endl;
  }
}

static void test3() {
  std::cout << "\n=== Test case 3: Form ===" << std::endl;
  try {
    Bureaucrat b1("Vice President Pham", 3);
    Bureaucrat b2("Novice Marsh", 147);

    std::cout << "Bureaucrat: " << b1 << std::endl;
    std::cout << "Bureaucrat: " << b2 << std::endl;
    testShrubberyCreationForm(b1, b2);
    testRobotomyRequestForm(b1, b2);
    testPresidentialPardonForm(b1, b2);
  } catch (std::exception &e) {
    std::cerr << "[Exception] " << e.what() << std::endl;
  }
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}
