/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:32:30 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/10 04:49:33 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

static void test1() {
  std::cout << "\n=== Test case 1: Default Constructor ===" << std::endl;
  try {
    Bureaucrat bureaucrat;
    Form form;
    std::cout << "Before promote: " << bureaucrat << std::endl;
    bureaucrat.promote();
    std::cout << "After promote : " << bureaucrat << std::endl;
    bureaucrat.demote();
    std::cout << "After demotion : " << bureaucrat << std::endl;
    std::cout << "Before sign: " << form << std::endl;
    bureaucrat.signForm(form);
    std::cout << "After sign: " << form << std::endl;
  } catch (std::exception &e) {
    std::cerr << "[Exception] " << e.what() << std::endl;
  }
}

static void test2() {
  std::cout << "\n=== Test case 2: Named Constructor ===" << std::endl;
  try {
    Bureaucrat bureaucrat("Pham", 42);
    Form form("sample form", 44, 101);

    std::cout << bureaucrat << std::endl;
    bureaucrat.promote();
    std::cout << "After promotion: " << bureaucrat << std::endl;
    bureaucrat.demote();
    std::cout << "After demotion : " << bureaucrat << std::endl;

    std::cout << "Before sign: " << form << std::endl;
    bureaucrat.signForm(form);
    std::cout << "After sign: " << form << std::endl;

  } catch (std::exception &e) {
    std::cerr << "[Exception] " << e.what() << std::endl;
  }
}

static void test3() {
  std::cout << "\n=== Test case 3: Exceptions ===" << std::endl;
  try {
    Bureaucrat invalidHigh("Bob", 0);
  } catch (std::exception &e) {
    std::cerr << "[Exception] Invalid Bureaucrat: " << e.what() << std::endl;
  }

  try {
    Bureaucrat invalidLow("Charlie", 200);
  } catch (std::exception &e) {
    std::cerr << "[Exception] Invalid Bureaucrat: " << e.what() << std::endl;
  }

  try {
    Bureaucrat bureaucrat("Dave", 1);
    bureaucrat.promote();
  } catch (std::exception &e) {
    std::cerr << "[Exception] Promote Error: " << e.what() << std::endl;
  }

  try {
    Form invalidHigh("invalidHigh", 0, 150);
  } catch (std::exception &e) {
    std::cerr << "[Exception] Invalid Form: " << e.what() << std::endl;
  }

  try {
    Bureaucrat bureaucrat("Pham", 150);
    Form form("highLevel", 1, 1);
    bureaucrat.signForm(form);
  } catch (std::exception &e) {
    std::cerr << "[Exception] Sign Error: " << e.what() << std::endl;
  }
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}
