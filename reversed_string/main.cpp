#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <string>


int32_t main(int32_t, char**) {
	std::string message = "he saw a racecar";
	std::string rmessage;
	for (int32_t i = message.length() - 1; i >= 0; --i) {
		rmessage.append(message.substr(i, 1));
	}
	std::cout << message << std::endl;
	std::cout << rmessage << std::endl;
	exit(EXIT_SUCCESS);
}
