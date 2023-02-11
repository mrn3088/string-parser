#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <ostream>
#include <algorithm>

namespace Parser {

static size_t getArgCnt(const std::string& aStr) {
	size_t theIndex = 0;
	size_t theCnt = 0;
	while ((theIndex = aStr.find("{}", theIndex)) != std::string::npos) {
		theIndex += 2;
		theCnt++;
	}
	return theCnt;
}

template<typename Arg, typename ...Args>
static void unfold(const std::string& aStr, std::string& anOutput, size_t aPos, Arg&& arg, Args&&... args) {
	size_t thePos = aStr.find("{}", aPos);
	anOutput.append(aStr.substr(aPos, thePos - aPos));
	anOutput.append(arg);
	if constexpr (sizeof...(args) > 0) 
		unfold(aStr, anOutput, thePos + 2, args...);
	else {
		anOutput.append(aStr.substr(thePos + 2));
	}
}

template<typename Arg, typename ...Args>
static std::string formatted(const std::string& aStr, Arg&& arg, Args&&... args) {
	size_t theCount = getArgCnt(aStr);
	std::string theString("");
	if  (((sizeof...(args)) + 1) > theCount) {
		throw std::invalid_argument( "Too many arguments!" );
	}
	unfold(aStr, theString, 0, arg, args...);
	return theString;
}

};
