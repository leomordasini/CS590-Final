#include "InputValidator.h"
#include "FileAccess.h"

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

void GenerateRoutersFromInput(std::vector <std::shared_ptr<Router>> & a_RouterList)
{

	FileAccess fileaccess("infile.dat");
	std::string singleLine;

	


	int tempRouterID;
	int tempOutgoingLink;
	int tempNetworkCost = -1;

	int tempLinkCost = -1;
	int tempLinkedRouterId;
	std::string tempNetworkName;


	std::shared_ptr<Router> tempRouterPtr; //temp variable for each run


	// Read in infile.dat file, create and initialize routers
	while (fileaccess.GetNextLine(singleLine)) 
	{
		//First Generate an outer Router Given a
		std::stringstream iss(singleLine);

		// Check if first character is not a space (initial declaration of router)
		if (!isspace(singleLine.at(0)))
		{
			iss >> tempRouterID >> tempNetworkName;

			//bool testValidity;
			//testValidity = iss >> tempNetworkCost;
			if (!iss >> tempNetworkCost)
			{
				tempNetworkCost == 1;
			}

			tempRouterPtr.reset(new Router(tempRouterID, tempNetworkName, tempNetworkCost));

			//no space, so register a new router.
			//if no network name, the the Network Cos
			//if we don't start with a space or tab, we generate a new Router
			a_RouterList.push_back(tempRouterPtr);
		}
		else
		{
			//ad to routing table...


			iss >> tempLinkedRouterId;

			if (!iss >> tempLinkCost)
			{
				tempLinkCost == 1;
			}
			std::pair<int, int> idcost(tempLinkedRouterId, tempLinkCost);
			tempRouterPtr->InsertConnectedRouterInfo(idcost);

			//tempRouter.InsertRoutingTable(tempNetworkName, tempcost, tempOutgoingLink);
		}
	}
};

void AskUserForInput(std::vector <std::shared_ptr<Router>> & a_RouterList)
{




	std::cout << "Please enter one of the following commands:" << std::endl << std::endl;
	std::cout << "[C] - Continue" << std::endl 
			  << "[Q] - Quit" << std::endl 
			  << "[P #] - Print the routing table of a router (replace # with Router ID)" << std::endl 
	          << "[S #] - Shutdown a router (replace # with Router ID)" << std::endl 
	          << "[T #] - Startup a router (replace # with Router ID)" << std::endl;


	

	std::string UserInput;
	int routerID;
	//first input is always a string.
	confirmOverZero(UserInput, "Please enter a validChoice");


	if (UserInput == "C")
	{
		std::cout << "Still need to implement this piece" << std::endl;
	}
	else if (UserInput == "Q")
	{
		exit(0);
	}
	else if (UserInput == "P")
	{
		confirmOverZero(routerID, "router id was not an int");
		std::cout << "Printing procedure will go here" << std::endl;

		//this will be useful soon as we have Dijkstra working.

		//// Print out vector content
		//for (auto i = 0; i < a_RouterList.size(); i++)
		//{
		//	std::cout << a_RouterList[i]->GetNetworkName() << std::endl;
		//	std::vector <std::tuple<std::string, int, int>> tempRoutingTable;
		//	
		//	//this is not yet generated in our Code.
		//	tempRoutingTable = a_RouterList[i]->GetRoutingTable();

		//	for (const auto& j : tempRoutingTable)
		//	{
		//		std::cout << "Network: " << std::get<0>(j) << " Cost: " << std::get<1>(j) << " OutGoing Link: " << std::get<2>(j) << std::endl;
		//	}
		//}
	}
	else if (UserInput == "S")
	{
		confirmOverZero(routerID, "router id was not an int");

		std::cout << "shut down procedure goes here" << std::endl;
	}
	else if (UserInput == "T")
	{
		confirmOverZero(routerID, "router id was not an int");

		std::cout << "startup procedure goes here" << std::endl;
	}
	else
	{
		std::cout << "You entered an invalid input. Please try again" << std::endl;
	}
}



/***********************************************************************
NAME:
bool validateInput(int & a_input)

SYNOPSIS:
bool validateInput(int & a_input) -> validates input as int

a_input -> input to act on

DESCRIPTION:
This function will provide a nice clean method of checking entries as integers.
RETURNS:
Returns a boolean, true if integer was input, false otherwise

AUTHOR:
Devinder Sodhi
SOURCES:
my own code from Canoga ++ project in 2015
DATE:
11:09 9/16/2016

***************************************************************************/

bool validateInput(int & a_input)
{
	//a failure of the stream is checkable with this means.
	if (!(std::cin >> a_input)) {
		std::cerr << "Please Enter a valid Integer" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
	return true;
}

/* 	bool validateInput(int & a_input) */

bool validateInput(std::string & a_input)
{
	//a failure of the stream is checkable with this means.
	if (!(std::cin >> a_input)) {
		std::cerr << "Please Enter a valid String" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
	return true;
}

void confirmOverZero(int & a_inputNum, std::string a_whatToSay)
{
	do
	{
		do
		{
			std::cout << a_whatToSay << std::endl;
		} while (!validateInput(a_inputNum));

	} while (a_inputNum <= 0);
}



void confirmOverZero(std::string & a_inputNum, std::string a_whatToSay)
{
	do
	{
		do
		{
			std::cout << a_whatToSay << std::endl;
		} while (!validateInput(a_inputNum));

	} while (!std::all_of(a_inputNum.begin(), a_inputNum.end(), isalpha));
}




