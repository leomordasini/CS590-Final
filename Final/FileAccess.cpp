#include "FileAccess.h"


/**/
/*
FileAccess::FileAccess()

NAME
FileAccess::FileAccess - Constructor that takes in a string to read file.

SYNOPSIS
FileAccess::FileAccess(std::string a_string)
a_string		--> the string we read the file name (or path) from.

DESCRIPTION
Constructs the File Access given a file name. If bad file name, exits with cerr and error 1.

RETURNS
nothing

AUTHOR

Devinder Sodhi

SOURCES
Professor Victor Miller from Ramapo College introduced this File Access idea to me

DATE
sometime midday (function was changed a lot) 10/28/2014 -> modified 10/20/2016
*/
/**/
FileAccess::FileAccess(std::string a_string)
{
	m_fileName = a_string;
	m_fileReader.open(m_fileName, std::ios::in);

	if (!m_fileReader)
	{
		//I m going to assert, until I come up with a better way to deal with this situation
		std::cerr << "Could not Read file" << std::endl;
		exit(1);
	}
	else { std::cout << "yay!, we can read the file!" << std::endl; }


}
/* FileAccess::FileAccess(std::string a_string) */


/**/
/*
FileAccess::~FileAccess()

NAME
FileAccess::~FileAccess()

SYNOPSIS
FileAccess::~FileAccess()

DESCRIPTION
Destructs the FileAccess Class, clsoes out m_fileReader

RETURNS
nothing

AUTHOR

Devinder Sodhi

SOURCES
Professor Victor Miller from Ramapo College introduced this File Access idea to me

DATE
10/30/2016*/
/**/
FileAccess::~FileAccess()
{
	m_fileReader.close();
}
/* FileAccess::~FileAccess() */


/**/
/*
FileAccess::GetNextLine  FileAccess::GetNextLine

FileAccess::GetNextLine - gets the next line

SYNOPSIS
bool FileAccess::GetNextLine(string &a_buff)
a_buff		--> where we plug in whatevers in our line

DESCRIPTION

grabs the content of the next line in the file
RETURNS
Bool if its possible to return something
AUTHOR

Devinder Sodhi

DATE
sometime midday (function was changed a lot) 10/28/2014 -> modified 10/20/2016
*/
/**/
bool FileAccess::GetNextLine(std::string &a_buff)
{
	if (m_fileReader.eof()) return false;
	getline(m_fileReader, a_buff);
	return true;
}
/*bool FileAccess::GetNextLine(string &a_buff)*/


/**/
/*
void FileAccess::rewind()

NAME
void FileAccess::rewind() --> sets the fstream reader back to the beginning, incase  we need it.

SYNOPSIS
void FileAccess::rewind()
a_string		--> the string we read the file name (or path) from.

DESCRIPTION

This function just rewinds the pointer to the beginning of the file.

RETURNS
nothing

AUTHOR

Devinder Sodhi

SOURCES
Professor Victor Miller from Ramapo College introduced this File Access idea to me

DATE
sometime midday (function was changed a lot) 10/28/2014 -> modified 10/28/2016
*/
/**/
void FileAccess::rewind()
{
	m_fileReader.clear();
	m_fileReader.seekg(0, std::ios::beg);
}
/* void FileAccess::rewind() */