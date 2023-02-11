#include "parser.hpp"

int main() {
	std::string a = "abc{}ef{}";
	std::string b = "My favorite {} is {}{}!";
	std::cout << Parser::formatted(a, "d", "g") << std::endl;
	std::cout << Parser::formatted(b, "class", "ECE", "141A") << std::endl;

	// exception
	try {
		std::cout << Parser::formatted(b, "class", "ECE", "141", "A") << std::endl;
	} catch (std::invalid_argument& e) {
		std::cout << "exception caught!" << std::endl;
	}


}
