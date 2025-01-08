/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:32:30 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/04 10:55:23 by sakitaha         ###   ########.fr       */
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

/*



#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

static void replaceStr(std::ifstream &inFile, std::ofstream &outFile,
                       const std::string &s1, const std::string &s2) {
  std::string line;
  while (std::getline(inFile, line)) {
    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos) {
      line.erase(pos, s1.length());
      line.insert(pos, s2);
      pos += s2.length();
    }
    outFile << line << std::endl;
  }
  if (inFile.fail() && !inFile.eof()) {
    throw std::runtime_error("Error: Failed to read from file");
  }
}

int main(int argc, const char *argv[]) {

  const std::string outFileName = std::string(argv[1]) + ".replace";
  std::ifstream inFile(argv[1]);
  std::ofstream outFile(outFileName.c_str());
  try {
    if (!inFile.is_open()) {
      throw std::runtime_error("Error: Failed to open input file");
    }
    if (!outFile.is_open()) {
      throw std::runtime_error("Error: Failed to create output file");
    }
    replaceStr(inFile, outFile, argv[2], argv[3]);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    if (inFile.is_open())
      inFile.close();
    if (outFile.is_open())
      outFile.close();
    return EXIT_FAILURE;
  }
  inFile.close();
  outFile.close();
  return EXIT_SUCCESS;
}


 */