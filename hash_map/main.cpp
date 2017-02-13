/* Copyright(C)
 * For free
 * All right reserved
 */
/**
 * @file main.cpp
 * @Synopsis  Example for hash map in CPP.
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2013-09-20
 */

#include <cstdlib>
#include <iostream>
#include <functional>
#include <string>

int main(void) {
	char nts1[] = "Test";
	char nts2[] = "Test";
	std::string str1(nts1);
	std::string str2(nts2);

	std::hash<char*> ptr_hash;
	std::hash<std::string> str_hash;

	std::cout << "same hash:\n" << std::boolalpha;;
	std::cout << "nst1 and nts2: " << (ptr_hash(nts1) == ptr_hash(nts2)) << '\n';
	std::cout << "str1 and str2: " << (str_hash(str1) == str_hash(str2)) << '\n';
	return EXIT_SUCCESS;
}
