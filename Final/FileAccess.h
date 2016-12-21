#pragma once

/*
Name: Devinder Sodhi
Class: FileAccess
Inspired by professor Victor Miller's File access class for C++, this version is standalone, easy to swap in for small projects.
I m writing this class to (hopefully) facilitate read and write for all the projects that need it.

This Class will construct with a File name. and given a proper string name, will allow user to read through said file
in various ways. once its been converted to a stream.

Not threadsafe.

*/
#include <fstream>
#include <string>
#include <iostream>

//Devinder Sodhi
//Class: FileAccess
// provide the generally required functions for file reading
class FileAccess

{
public:
	FileAccess(std::string a_fileName);
	bool GetNextLine(std::string &a_buff);
	void rewind();

	~FileAccess();

private:

	std::ifstream m_fileReader; // the stream reader object
	std::string m_fileName; //incase we need it later
};
