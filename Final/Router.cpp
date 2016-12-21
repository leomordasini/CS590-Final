#include "Router.h"

Router::Router()
{
		router_ID = -1;
}

void Router::ClearObject()
{
	router_ID = NULL;
	network_name = "";
	routing_table.clear();
}

void Router::receivePacket()
{
}

void Router::originatePacket()
{
}
