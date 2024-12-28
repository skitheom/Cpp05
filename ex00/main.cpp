/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:18:41 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/29 01:14:58 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

static void test1() {
  std::cout << "\n=== Test case 1: Default Constructor ===" << std::endl;
  try {
    Bureaucrat bureaucrat;
    std::cout << "Before setGrade: " << bureaucrat << std::endl;
    bureaucrat.setGrade(42);
    std::cout << "After setGrade : " << bureaucrat << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }
}

static void test2() {
  std::cout << "\n=== Test case 2: Named Constructor ===" << std::endl;
  try {
    Bureaucrat bureaucrat("Pham", 50);
    std::cout << bureaucrat << std::endl;

    bureaucrat.promote();
    std::cout << "After promotion: " << bureaucrat << std::endl;

    bureaucrat.demote();
    bureaucrat.demote();
    std::cout << "After demotion : " << bureaucrat << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }
}

static void test3() {
  std::cout << "\n=== Test case 3: Exceptions ===" << std::endl;
  try {
    Bureaucrat invalidHigh("Bob", 0);
  } catch (std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  try {
    Bureaucrat invalidLow("Charlie", 200);
  } catch (std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  try {
    Bureaucrat bureaucrat("Dave", 1);
    bureaucrat.promote();
  } catch (std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  try {
    Bureaucrat bureaucrat("Eve", 150);
    bureaucrat.demote();
  } catch (std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}
