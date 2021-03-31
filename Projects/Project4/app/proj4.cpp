#Hootan Hosseinzadeganbushehri


#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include "proj4.hpp"

std::string keepOnlyLetters(std::string s);

void countWords(std::istream & in, MyAVLTree<std::string, unsigned> & counter)
{
	std::string line, word;
	std::stringstream ss;
	while(getline(in, line) )
	{
		ss.clear();
		ss << line;
		while( ss >> word )
		{
			word = keepOnlyLetters(word);
			if( word != "")	
			{
				if (counter.contains(word) == false)
				{
					counter.insert(word, 1);
				}
				else 
				{
					counter.find(word)++;
				}
			}
		}
	}
}

std::string keepOnlyLetters(std::string s)
{
	std::string ret = "";
	for (size_t i=0; i < s.length(); i++)
	{
		if ( isalpha(s[i]) ) 
		{
			ret += std::tolower( s[i] );
		}
	}
	return ret;
}