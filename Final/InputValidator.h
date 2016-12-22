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
#include <limits>



// to introduce "neighbours", I m going to use some typedefs and a max distance concept for dijsktra
typedef int routerId_t;
typedef int linkCost_t;

const linkCost_t maxDistance = std::numeric_limits<int>::infinity();
struct connectedRouter {
	//for now lets attempt this with a list of all this info
	std::string networkId;
	int routerId;
	linkCost_t linkCost;
	int lastLSPCount;
	connectedRouter(int a_routerId, linkCost_t a_linkCost)
		: routerId(a_routerId), linkCost(a_linkCost) { }
};




std::vector<std::string> splitThisString(std::string a_splitThis);

void GenerateRoutersFromInput(std::vector <std::shared_ptr<Router>> & a_RouterList);

void AskUserForInput(std::vector <std::shared_ptr<Router>> & a_RouterList);

bool validateInput(int & a_input);
bool validateInput(std::string & a_input);


void confirmOverZero(int & a_inputNum, std::string a_whatToSay);
void confirmOverZero(std::string & a_inputNum, std::string a_whatToSay);