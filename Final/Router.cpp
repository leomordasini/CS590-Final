#include "Router.h"

Router::Router()
{
	
}

Router::Router(int a_routerID, std::string a_networkName, int a_networkCost)
{
	SetRouterID(a_routerID);
	SetNetworkName(a_networkName);
	SetNetworkCost(a_networkCost);
}


void Router::ClearObject()
{
	m_routerId = NULL;
	m_networkName = "";
	m_routingTable.clear();
}

void Router::receivePacket()
{

}

void Router::originatePacket()
{

}
