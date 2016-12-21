#pragma once
// ReSharper disable CppUnusedIncludeDirective
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <memory>


class Router
{

	typedef std::pair<int,int> IdCost;
public:

	// Constructor 
	Router(int a_routerID, std::string a_routerName, int a_networkCost);




	// GET Functions
	int GetRouterID()
	{
		return m_routerId;
	}
	std::string GetNetworkName()
	{
		return m_networkName;
	}
	bool IsShutDown()
	{
		return m_shutdownFlag;
	}

	//get Routing table
	std::vector<std::tuple<std::string, int, int>> GetRoutingTable()
	{
		return m_routingTable;
	}

	int GetTick() const
	{
		return m_tick;
	}

	int getLSPCounter() const
	{
		return m_LSPCounter;
	}





	// SET Functions
	void SetRouterStatus(bool request)
	{
		m_shutdownFlag = request;
	}

	void InsertRoutingTable(std::string network, int cost, int outgoingLink)
	{

		m_routingTable.push_back(std::tuple<std::string, int, int>(network, cost, outgoingLink));
	}

	void InsertConnectedRouterInfo(std::pair<int,int> a_tempPair)
	{

		m_connectedRouterIdCost.push_back(a_tempPair);
	}

	void SetRouterListReference(std::vector <std::shared_ptr<Router>> * a_RouterList)
	{
		m_routerListReference = a_RouterList;
	}




	void ClearObject();
	// Other functions
	void receivePacket();
	void originatePacket();

	

private:
	

	void SetTick(int tick) //might not use this at all.
	{
		m_tick = tick;
	}

	void SetLSPCounter(int lsp_counter)
	{
		m_LSPCounter = lsp_counter;
	}

	void SetRouterID(int routerID)
	{
		m_routerId = routerID;
	}
	void SetNetworkName(std::string networkName)
	{
		m_networkName = networkName;
	}

	void SetNetworkCost(int a_networkCost)
	{
		m_networkCost = a_networkCost;
	}

	//defaullt vals.
	int m_routerId = -1;
	std::string m_networkName = "none";
	int m_networkCost = -1;
	int m_tick;
	int m_LSPCounter;
	
	bool m_shutdownFlag = false;

	std::vector <std::shared_ptr<Router>> * m_routerListReference;
	//DirectlyConnectedRouters
	//note when using this, say Idcost nameofit (1,1) followerd by map.insert(std::make_pair( nameofit, RouterPointer);
	// Network, Cost, Outgoing Link
	//std::map<IdCost, Router*> DirectlyConnectedRouters;


	std::vector<std::pair<int,int>> m_connectedRouterIdCost;


	
	std::vector <std::tuple<std::string, int, int>> m_routingTable;
};



/**

* 1. Routers should be a class <--working on this now.
*   a. maintain a data struct that stores references to other "directly connected routers",
*      which can be referenced by id, along with the cost of the link.
*      should have etters and setters for ID and cost?
*   b. Routers will exchangee necessary info to build routing table.
*   c. Each router will advertise access to a particular named network. which is a string that should
*      be stored in that router class
*   d. will need to store other information in the Router cllass to enable the remainder of the algorithm
*      to work, such as an undirected graph to representing the network of routers as the router currently
*      understands
*   e. Also need an undirected graph of the network as the router understands it.

**/