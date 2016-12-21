#pragma once
//This is traditionally the file where I put my "global functions"
//Keeps them in a nice interface/implementation format and out of my entrypoint

#include <string>

#include <algorithm>
#include <vector>
#include <iterator>
#include "Router.h"
#include <string>
#include <memory>
#include <functional>
#include<ctype.h>
#include<numeric>
#include <iomanip>
#include <sstream>
#include <iostream>

//might need limits here..


std::vector<std::string> splitThisString(std::string a_splitThis);

void GenerateRoutersFromInput(std::vector <std::shared_ptr<Router>> & a_RouterList);

void AskUserForInput(std::vector <std::shared_ptr<Router>> & a_RouterList);

bool validateInput(int & a_input);
bool validateInput(std::string & a_input);


void confirmOverZero(int & a_inputNum, std::string a_whatToSay);
void confirmOverZero(std::string & a_inputNum, std::string a_whatToSay);