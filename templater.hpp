#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>
#include <sstream>
#include <ostream>
#include <algorithm>

class stringTemplate {
public:
	stringTemplate(const std::string& aPlaceholder = "{}"): 
		placeholder(aPlaceholder), placeholderSize(aPlaceholder.size()){}

	stringTemplate(const stringTemplate& aStringTemplate): 
		placeholder(aStringTemplate.placeholder), 
		placeholderSize(aStringTemplate.placeholderSize) {}


	stringTemplate& usePlaceHolder(const std::string& aPlaceholder){
		placeholder = aPlaceholder;
		placeholderSize = aPlaceholder.size();
		return *this;
	}

	template<typename Arg, typename ...Args>
	std::string templateString(const std::string& aStr, Arg&& arg, Args&&... args) {
		if (((sizeof...(args)) + 1) > getArgCnt(aStr)) {
			throw std::invalid_argument( "Too many arguments!" );
		}
		std::ostringstream os;
		unfold(aStr, 0, os, arg, args...);
		return os.str();
	}

	std::string getPlaceholder() {
		return placeholder;
	}

	friend std::ostream& operator<<(std::ostream& os, const stringTemplate& aStringTemplate) {
		os << "stringTemplate with placeholder: " << aStringTemplate.placeholder;
		return os;
	}

protected:
	std::string placeholder;
	size_t placeholderSize;

	template<typename Arg, typename ...Args>
	void unfold(const std::string& aStr, size_t aPos, std::ostream& os, Arg&& arg) {
		size_t thePos = aStr.find(placeholder, aPos);
		os << aStr.substr(aPos, thePos - aPos);
		os << std::forward<Arg>(arg);
		os << aStr.substr(thePos + placeholderSize);
	}

	template<typename Arg, typename ...Args>
	void unfold(const std::string& aStr, size_t aPos, std::ostream& os, Arg&& arg, Args&&... args) {
		size_t thePos = aStr.find(placeholder, aPos);
		os << aStr.substr(aPos, thePos - aPos);
		os << std::forward<Arg>(arg);
		unfold(aStr, thePos + placeholderSize, os, std::forward<Args>(args)...);
	}

	size_t getArgCnt(const std::string& aStr) {
		size_t theIndex = 0;
		size_t theCnt = 0;
		while ((theIndex = aStr.find(placeholder, theIndex)) != std::string::npos) {
			theIndex += placeholderSize;
			theCnt++;
		}
		return theCnt;
	}
};



