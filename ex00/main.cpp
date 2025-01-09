/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:18:41 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/10 04:48:57 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

static void test1() {
  std::cout << "\n=== Test case 1: Default Constructor ===" << std::endl;
  try {
    Bureaucrat bureaucrat;

    std::cout << "Before promotion: " << bureaucrat << std::endl;
    bureaucrat.promote();
    std::cout << "After promotion : " << bureaucrat << std::endl;
    bureaucrat.demote();
    std::cout << "After demotion : " << bureaucrat << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }
}

static void test2() {
  std::cout << "\n=== Test case 2: Named Constructor ===" << std::endl;
  try {
    Bureaucrat bureaucrat("Pham", 44);

    std::cout << bureaucrat << std::endl;
    bureaucrat.promote();
    std::cout << "After promotion: " << bureaucrat << std::endl;
    bureaucrat.demote();
    std::cout << "After demotion : " << bureaucrat << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }
}

static void test3() {
  std::cout << "\n=== Test case 3: Exceptions ===" << std::endl;
  try {
    Bureaucrat invalidHigh("Lewis", 0);
  } catch (std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  try {
    Bureaucrat invalidLow("Zhou", 200);
  } catch (std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  try {
    Bureaucrat bureaucrat("Sebastian", 1);
    bureaucrat.promote();
  } catch (std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  try {
    Bureaucrat bureaucrat("Yuk", 150);
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
