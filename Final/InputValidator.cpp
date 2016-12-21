#include "InputValidator.h"

/**
 * This function splits tab and space separated text and returns vector of strings.
 * 
 * 	//team mates, if youre interested in tokenizing like we talked about: 
	//http://stackoverflow.com/questions/236129/split-a-string-in-c
	// https://www.codeproject.com/kb/recipes/tokenizer.aspx
 */
std::vector<std::string> splitThisString(std::string a_splitThis)
{
	std::istringstream iss(a_splitThis);

	return std::vector<std::string> { std::istream_iterator<std::string>{iss},
		std::istream_iterator<std::string>{} };
}
