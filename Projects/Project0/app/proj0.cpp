#Hootan Hosseinzadeganbushehri

#include <map>
#include <string>
#include "proj0.hpp"


bool verifySolution(std::string s1, std::string s2, std::string s3, const std::map<char, unsigned> & mapping)
{  
	int answer = 0, total = 0, size_1 = s1.size(), size_2 = s2.size(), size_3 = s3.size();
	
	for(int i = 0; i < size_1; i++)
	{
		total += mapping.at(s1[size_1 - 1]); 
	}
	
	for(int j = 0; j < size_2; j++)
	{
		total += mapping.at(s2[size_2 - 1]); 
	}
	
	for(int k = 0; k < size_3; k++)
	{
		answer += mapping.at(s3[size_3 - 1]); 
	}
   
    return (answer == total);
}