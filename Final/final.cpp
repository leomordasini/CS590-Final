#include <string>
#include <iostream>
#include <fstream>

#include "Graph.h"
#include "NetworkInterface.h"

using namespace std;

int main()
{
	
	ifstream input_file("infile.dat");
	

	if (input_file.is_open()) {
	
	}
	else {
		cout << "Unable to open file";
	}

	return 0;
}
