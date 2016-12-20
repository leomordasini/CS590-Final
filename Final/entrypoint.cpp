#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <tuple>
#include <regex>
#include <vector>
#include "Router.h"
//#include "Graph.h"

void GenerateRoutersFromInput(std::vector<Router> & RouterList)
{
	std::ifstream input_file("infile.dat");
	std::string line;
	Router tempRouter;
	int tempRouterID;
	int tempOutgoingLink;
	int tempcost;
	std::string tempNetwork;

	// Read in infile.dat file, create and initialize routers
	while (std::getline(input_file, line))
	{
		std::istringstream iss(line);

		// Check if first character is not a space (initial declaration of router)
		if (!isspace(line.at(0)))
		{
			// Push previous router onto vector
			if (tempRouter.getRouterID() != -1)
			{
				RouterList.push_back(tempRouter);
				tempRouter.ClearObject();
			}
			// Parse line and insert new router info into new Router Object
			iss >> tempRouterID >> tempNetwork;
			tempRouter.SetRouterID(tempRouterID);
			tempRouter.SetNetworkName(tempNetwork);
		}
		else
		{
			iss >> tempOutgoingLink >> tempcost;
			tempRouter.InsertRoutingTable(tempNetwork, tempcost, tempOutgoingLink);
		}
	}
};

void AskUserForInput(std::vector<Router> & RouterList)
{
	std::cout << "Please enter one of the following commands:" << std::endl << std::endl;
	std::cout << "[C] - Continue" << std::endl << "[Q] - Quit" << std::endl << "[P#] - Print the routing table of a router (replace # with Router ID)"
		<< std::endl << "[S#] - Shutdown a router (replace # with Router ID)" << std::endl << "[T#] - Startup a router (replace # with Router ID)" << std::endl;

	std::string UserInput;
	std::cin >> UserInput;

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
		// Print out vector content
		for (auto i = 0; i < RouterList.size(); i++)
		{
			std::cout << RouterList[i].getNetworkName() << std::endl;
			std::vector <std::tuple<std::string, int, int>> tempRoutingTable;
			tempRoutingTable = RouterList[i].getRoutingTable();

			for (const auto& j : tempRoutingTable)
			{
				std::cout << "Network: " << std::get<0>(j) << " Cost: " << std::get<1>(j) << " OutGoing Link: " << std::get<2>(j) << std::endl;
			}
		}
	}
	else if (UserInput == "S#")
	{
		std::cout << "Still need to implement this piece" << std::endl;
	}
	else if (UserInput == "T#")
	{
		std::cout << "Still need to implement this piece" << std::endl;
	}
	else
	{
		std::cout << "You entered an invalid input. Please try again" << std::endl;
	}
}

int main()
{
	// Create Vector of Routers
	std::vector <Router> RouterList;

	// Generate Routers from Input file
	GenerateRoutersFromInput(RouterList);

	// Ask User for Input
	while (true)
	{
		AskUserForInput(RouterList);
	}
	

	return 0;
}
/*
 *
 * Devinder's Notes: temporary
 * 
 *  Goal:  create a virtual network of routers that send routing data to one another.
 * 
 * 1. Routers should be a class
 *  a. maintain a data struc that stores references to other "directly connected routers"
 *  should have etters and setters for ID and link cost
 *  
 *  Routers will EXCHANEGe necessary info to build routing table.
 *  Each router will advertise access to a particular named network. , string
 *  
 *  Also need an undirected graph of the network as the router understands it.
 */