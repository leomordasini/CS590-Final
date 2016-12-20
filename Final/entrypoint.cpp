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
 * 1. Routers should be a class <--working on this now.
 *   a. maintain a data struct that stores references to other "directly connected routers",
 *      which can be referenced by id, along with the cost of the link.
 *      should have etters and setters for ID and link cost?
 *   b. Routers will exchangee necessary info to build routing table.
 *   c. Each router will advertise access to a particular named network. which is a string that should 
 *      be stored in that router class
 *   d. will need to store other information in the oruter cllass to enable the remainder of the algorithm 
 *      to work, such as an undirected graph to representing the network of routers as the router currently
 *      understands 
 *   e. Also need an undirected graph of the network as the router understands it.
it
 * 
 * 2. Implement the "link state routing algorithm. They work by sending a "link state packet" 
 *    around the network with routers forwarding the packet "as appropriate"
 *    We will simulate this packet with instances of another class, that will contain the following info:
 * LSP CLASS:
 *   a. ID of the router that originates the LSP
 *   b. A sequence number indicating how many LSPs have been sent by the originating router; ie each newly
 *      origninated LSP has a higher sequence number should be 1. Igore the possibility of wraparound.
 *   c. Time to live, devremented each time the LSP is forwarded, with an initial value of 10.
 *   d. Either of the following:
 * 	   i. A list that indicates each reachable network (indicated by the networkk name stored in the 
 *	      router's string)
 *	      and its cost.
 *	   ii. A  list that indicates each directly connected router, the network behind each one, 
 *		   and the cost to get to that router. <- looks better
 * 3. The router class should contain a function/method named something similar to 
 *    receievePacket that should take as its only argument an instance of the link state packet class.
 *    
 *   a. A router thtat receives an LSP should first decrement the LSP's TTL. Next the receiving router
 *      should discard the LSP and not use its information if either 
 *     i. the TTLL has reached Zero, OR 
 *     ii. the receiving router has already seen an LSP from teh same origignating router with a 
 *          sequence number higher than or rqual to the sequence number in the received LSP.
 *   b. if the LSP is not discarded, its information should be compared to the receiving router's 
 *      connectivity graph and the LSP should be sent out (in the form of function calls) to all directly
 *      connected routers except the one on which it was received.
 * 4. The Router Class should also contain a function named something similar to originatePackket that
 *    takes no arguments. This function will perform two functions.
 *   a. It should cause the router to generate an LSP packket based on the current state of the network 
 *      as it understands it, and sent it to all directly connected routers. Before it sends the packet 
 *      however, it should also increment a "tick" counter and consider if there are any directly 
 *      connected routers from which it has not received a packet in 2 ticks. If that occurs, 
 *      the router should alter its graph to reflect the cost of the link to the other router is now 
 *      infinity (or some huge number)
 * 5. Each router should maintain a "routing table" consisting of <network, cost, outgoinglink> triples.
 *    If connectivity has changed (as indicated by a receiveid link state packet), the receiving router
 *    should run "Dijsktra's all-pairs shortest path algorithm on its updated connectivity graph to re-computer
 *    its routing table of <network, cost, outgoinglink> triples. 
 *   a. "Outgoing link" means the directly connected router to which this router would send data in order 
 *       to route the data using the "shortest path", it does not mean the destination router or the
 *       destination network.
 *       
 *       (Consider the advantages and disadwantages of implementing the
 *        graph using an adjacency matrics or using and adjacent list. )
 *        
 * 6. The initial network will be set up by reading in a file, infile.dat, that has the following format:
 *	  [router-id][network-name][network-cost]
 *	   [directly-linked-router-id][link-cost]
 *	   [directly-linked-router-id][link-cost]
 *	   [directly-linked-router-id][link-cost]
 *	   etc....
 *	  [router-id][network-name][network-cost]
 *	   [directly-linked-router-id][link-cost]
 *	   [directly-linked-router-id][link-cost]
 *	   [directly-linked-router-id][link-cost]
 *	   etc...
 *    and so on.
 *   a. Each bracketed text above represents the name of the bit of data, and will not appear with the 
 *   b.  brackets around it in the file. "etc..." represents the pattern above it will be repeated.
 *   c. link-cost and network cost are optional and should be assumed 1 if missing.
 *   d. he explains this with a picture to make it easier to understand.
 *  
 * 7. Write a main function that proceeds as follows:
 *   a. At the begininning of the program , create routers and initiatlize their direct links by reading
 *      in infile.dat.
 *   b. Prompt the user if they would like to 
 *	   i.   continue (enter "C")
 *	   ii.  quit( enter "Q") 
 *	   iii. print the routing table of a router ("P" followed by the router's id number)
 *	   iv.  shut down a router (enter "S" followed by the id number).
 *	   v.   startup up a router (enter "T" followed by the id number).
 *	 c. If the user chooses to continue, you should call teh originatePacket() function on every router
 *		in whatever order you choose. Then prompt again.
 *	 d. If the user shuts down a router, change the router object so that it does not send out any LSP or 
 *	    do anything in response to originatePacket or receivePackket function calls.
 *	 e. If the user starts up a router, change the router object so it once again bbehaves normally, 
 *	    (Routers initially are started, not stopped)
 *	 f. if the user chooses tto print the routing table, display the table in the following format, 
 *	    then prompt again:
 *	     network,cost,outgoing link
 *	     network,cost,outgoing link
 *	     network,cost,outgoing link
 *	 g. if the user chooses to quit, exit the program.
 *	
 * 8. In all the above file formats, all non-newline whitespace may be represented 
 *    by one or more tab or space characters.
 *      
 *   
 *		
 *  
 *  
 */