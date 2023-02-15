#include "templater.hpp"
int main() {
	std::string a = "abc{}ef{}";
	std::string b = "My favorite {} is {}{}!";
	std::string c = "CSE";

	stringTemplate theTemplate;
	std::cout << theTemplate.templateString(a,"d","g") << std::endl;
	std::cout << theTemplate.getPlaceholder() << std::endl;
	std::cout << theTemplate.usePlaceHolder("CS").templateString(c,"EC") << std::endl;
	std::cout << theTemplate << std::endl;
	std::cout << theTemplate.usePlaceHolder("{}").templateString(b,"class", "ECE", 141) << std::endl;
}
