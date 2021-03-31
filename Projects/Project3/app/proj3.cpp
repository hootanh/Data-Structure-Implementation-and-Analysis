#Hootan Hosseinzadeganbushehri


#include "proj3.hpp"
#include "Wordset.hpp"
#include <iostream>
#include <set>
#include <sstream>
#include <map>
#include <stack>
#include <queue>


void loadWordsIntoTable(WordSet & words, std::istream & in)
{
	std::string line, word;
	std::stringstream ss;
	while(	getline(in, line) )
	{
		ss.clear();
		ss << line;
		while( ss >> word )
		{
			words.insert( word );
		}
	}
}

std::string convert(std::string s1, std::string s2, const WordSet & words)
{
	std::vector <char> a_z = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	std::string result_word, present_word, temp_word, combined_word, absent_word;
    std::map <std::string, std::string> map_word;    
	bool l_check1, l_check2;
	int word_counter = 0, index_counter = 0, a_z_num = 26;
    std::queue <std::string> queue_word;
	l_check1 = true;
    queue_word.push(s1);
	while(queue_word.empty() == false || l_check1 == true)
    {
        present_word = queue_word.front();
		l_check2 = true;
		index_counter = 0;
        queue_word.pop();
        if(present_word != s2)
        {
			int word_size = present_word.size();
			l_check2 = false;
			int outer_l = 0;
			while(outer_l < word_size)
            {                                       
				int inner_l = 0;
				l_check2 = true;
				while(inner_l < a_z_num)
                {
                    temp_word = present_word;
					absent_word = combined_word + temp_word;
                    temp_word[outer_l] = a_z[inner_l];
                    if(words.contains(temp_word) && (map_word.count(temp_word) == false))  
                    {
                            map_word[temp_word] = present_word;
							absent_word = present_word + temp_word;
                            queue_word.push(temp_word);
							word_counter++;
                    }
					else
					{
						l_check2 = false;
						index_counter += word_counter;
						word_counter++;
					}
					word_counter--;
					inner_l++;
                }
				l_check2 = false;
				outer_l++;
            }
        }
        else
        {
            std::string word_char = s2;
			l_check2 = false;
			for(int loop_counter = 0 ; word_char != s1; loop_counter++)
            {
                combined_word = word_char + result_word;
                result_word = " --> " + combined_word;
				absent_word += combined_word;
				word_counter += 1;
                word_char = map_word[word_char];
            }
			word_counter++;
            result_word = s1 + result_word;
			l_check2 = false;
            return result_word;
        }
    }
	return "No result!!!!!"; 
}
