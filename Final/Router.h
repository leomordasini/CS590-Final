#pragma once
// ReSharper disable CppUnusedIncludeDirective
#include <string>
#include <vector>
#include <tuple>


class Router
{
public:
	// Constructor 
	Router();



	// GET Functions
	int getRouterID()
	{
		return router_ID;
	}
	std::string getNetworkName()
	{
		return network_name;
	}
	bool isShutDown()
	{
		return ShutDownFlag;
	}
	std::vector<std::tuple<std::string, int, int>> getRoutingTable()
	{
		return routing_table;
	}

	// SET Functions
	void SetRouterStatus(bool request)
	{
		ShutDownFlag = request;
	}
	void InsertRoutingTable(std::string network, int cost, int outgoingLink)
	{
		routing_table.push_back(std::tuple<std::string, int, int>(network, cost, outgoingLink));
	}
	void SetRouterID(int routerID)
	{
		router_ID = routerID;
	}
	void SetNetworkName(std::string networkName)
	{
		network_name = networkName;
	}
	void ClearObject();
	// Other functions
	void receivePacket();
	void originatePacket();

private:
	int router_ID;
	std::string network_name;
	bool ShutDownFlag = false;
	// Network, Cost, Outgoing Link
	std::vector <std::tuple<std::string, int, int>> routing_table;
};



/*
class LSP
{

public:

private:
	std::string ID;
	int sequence;
	int TTL = 10;


};

*/