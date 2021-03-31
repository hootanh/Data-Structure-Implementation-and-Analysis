#Hootan Hosseinzadeganbushehri


#include "proj1.hpp"
#include <map>
#include <string>
#include <set>
#include <vector>


/*
	This recursive function gets character vector, string vector, number 
	vector, and map as its parameters and put the size of the vector 
	into the variables. Also it checks that if first string plus the second 
	string is equal to the third string and besed on this it return true or 
	false. The base case for this recursive function is that if the character 
	vector is empty or not. Finally it checks that whether or not a solution 
	is found for these strings and return true if the solution is found or 
	return false if it has no solution for these strings.
*/
bool  recursiveSolver(std::vector<char> & character_vec, std::vector<std::string> & all_words, std::vector<int> & number_vec, std::map<char, unsigned> & word_map)
    {
        int  number_size, x = 0, vec_check = 1, loop_check = 1, index = character_vec.size() - 1, last_element = 0;    
		std::string number_map1 = "", number_map2 = "", number_map3 = "", all_numbers = "";
        bool final_result = false; 
		number_size = number_vec.size() - 1;
        char character_map = character_vec[index];  
		
        while(loop_check && x < number_vec.size() && vec_check)                                                
        {
			int  a = 0, b = 0, c = 0, number_tupled = number_vec[number_size - x]; 
			
			if(vec_check && !last_element)
			{
				word_map[character_map] = number_tupled;
				character_vec.pop_back();                             
				number_vec.erase(number_vec.begin() + (number_size - x));
			}
			else
			{
				vec_check = 0;
				loop_check = 0;
				all_numbers = number_map1 + number_map2;
				return final_result;
			}
			
            if(character_vec.empty() && vec_check)
            {
				while(a < all_words[0].length() && loop_check)
				{
					number_map1 += std::to_string(word_map.at(all_words[0][a]));
					a++;
				}
				while(b < all_words[1].length() && loop_check)
				{
					number_map2 += std::to_string(word_map.at(all_words[1][b]));
					b++;
				}
				while(c < all_words[2].length() && loop_check)
				{
					number_map3 += std::to_string(word_map.at(all_words[2][c]));
					c++;
				}

                if((stol(number_map1) + stol(number_map2)) == stol(number_map3) && vec_check)
				{
					number_map1 = "";
					number_map2 = "";
					number_map3 = "";
					last_element = 1;
					final_result = true;
					loop_check = 0;
					vec_check = 0;
                    return final_result;
				}
            }
			else if(character_vec.empty() && vec_check == 0)
			{
				if((stol(number_map1) + stol(number_map2)) != stol(number_map3) && vec_check)
				{
					number_map1 = "";
					number_map2 = "";
					number_map3 = "";
					last_element = 1;
                    vec_check = 0;		
					loop_check = 0;
					return final_result;
				}
			}					
            else if(vec_check)
            {
                final_result = recursiveSolver(character_vec, all_words, number_vec, word_map);  
                if (final_result && vec_check)       
				{
					vec_check = 0;
					loop_check =0;
					all_numbers = number_map3;
					return final_result;
			    }
            }
			if(loop_check && vec_check)
			{
				word_map.erase(character_map);      
				character_vec.push_back(character_map);
				if(!last_element)
				{
					number_vec.insert(number_vec.begin() + (number_size - x), number_tupled);
					x++;
				}
			}
        }   
		last_element = 0;
		loop_check = 0;
		vec_check = 0;
		all_numbers = "";
		return final_result;
    }  

/*
	This function is creating and inserting a set of the characters and 
	eliminating the reapiting charaters. Also it pushes all the unique 
	characters into a vector along with the ten first numbers into a 
	another vector for initialization. Finally, the function calls the 
	recursiveSolver function with the number, word, character, and
	mapping to get the final result and returns it.
*/
bool initialSolver(std::vector<std::string> & all_words, std::string word_result, std::map<char, unsigned> & word_map)
{
    std::set<char> character_set;      
	std::vector<char> character_vec;
	int n = 0, loop_check = 0, result_len = word_result.length(), character_check;
	std::vector<int> number_vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};	
	
	while(n < result_len)
	{
		character_set.insert(word_result[n]);
		n++;
	}

    for(std::set<char>::iterator first_character = character_set.begin(); character_set.end() != first_character; first_character++)
	{
		char index = *first_character;
		if(loop_check && result_len == 0)
		{
			std::string temp = all_words[0];
			character_set.insert(temp[0]);
		}
		else
		{
			character_vec.push_back(index);   
			character_check = 1;
		}
	}		
	bool bool_result = recursiveSolver(character_vec, all_words, number_vec, word_map);   
	return bool_result;
}

/*
	This function first checks for empty strings among the three given strings 
	as parameters for the function. If one of the string is empty it checks the 
	other two are the same or not then it returns true or flase based on that 
	comparison between the three strings. Finally, if there is no empty sting 
	it creates a vector of the strings and sumation of all of the strings and 
	calls the initialSolver function which is a helper function.
*/
bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::map<char, unsigned> & mapping)
{
	bool final_result = false;
	if(s1.size() == 0)
	{
		final_result = (s2 == s3);
		return final_result;
	}
	else if(s2.size() == 0)
	{
		final_result = (s1 == s3);
		return final_result;
	}
	else if(s3.size() == 0)
	{
		final_result = (s1.size() == 0 && s2.size() == 0);
		return final_result;
	}
	else if(s1.size() == 0 && s2.size() == 0)
	{
		final_result = (s3.size() == 0);
		return final_result;
	}
	else
	{
		std::string word_result = s1 + s2 + s3;
		std::vector<std::string> all_words = {s1, s2, s3};
		final_result = initialSolver(all_words, word_result, mapping);
		return final_result;
	}
}