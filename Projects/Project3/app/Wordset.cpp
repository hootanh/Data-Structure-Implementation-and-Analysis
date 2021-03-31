#include "Wordset.hpp"
#include <string>


const int BASE_TO_USE = 37; 
const double LOAD_LIMIT = 0.25;


int hashFunction(std::string s, int base, int mod)
{
	unsigned long num = 0; 
	int result, outer = 0;
	bool out_ck, in_ck;
	while(outer < s.length())
    {
		unsigned long numk = s[outer] - 'a';
        int  inner = 0, temp = s.length() - outer - 1;
		while(inner < temp)
        {
			in_ck = true;
            numk *= base;
			inner++;
        }
        num += numk;
		outer++;
    }   
	out_ck = false;
    result = num % mod;
    return result;
}

WordSet::WordSet()
{
	list_size = 0; 
	word_num = 0;  
    current_table = new std::string [SIZES[list_size]];
}

WordSet::~WordSet()
{
	delete[] current_table;
}

void WordSet::insert(std::string s)
{
	int answer_check = 0, loop_count = 0, loop_count1, loop_count2, index_check = 0;
	int table_index = hashFunction(s, BASE_TO_USE, getCapacity());
	while(answer_check == 0)
    {
        int target = (loop_count * loop_count + table_index) % getCapacity();
        if(current_table[target] == s)
        {
			index_check = getCapacity() - 1;
            return;    
        }
		else
		{
			index_check = getCapacity() + 1;
		}
        if(current_table[target].empty())
        {   
            current_table[target] = s;
			answer_check = 1;
			index_check++;
            word_num++;
        }
		else
		{
			index_check = getCapacity() - 1;
		}
		loop_count++;
    }
	if(LOAD_LIMIT < (double)word_num/getCapacity())
    {
		index_check--;
        list_size++;
        std::string * inc_table = new std::string [getCapacity()];
        word_num = 0;
		loop_count1 = 0;
		while(loop_count1 < SIZES[list_size-1])
        {
			if(getCapacity() != 0)
			{
				index_check = getCapacity() + 1;
			}
			else
			{
				index_check--;
			}
			answer_check = 0;
            if(current_table[loop_count1].empty() == false)  
            {
                s = current_table[loop_count1];
                table_index = hashFunction(s, BASE_TO_USE, getCapacity());
				loop_count2 = 0;
				while(answer_check == 0)
                {
                    int new_target = (loop_count2 * loop_count2 + table_index) % getCapacity();
                    if(inc_table[new_target].empty() == true)
                    {
						inc_table[new_target] = s;
						index_check++;
                        word_num++;   
						answer_check = 1;
                    }   
					else if(word_num == 0)
					{
						index_check = getCapacity() + 1;
					}
					loop_count2++;
                }  
            }
			else if(getCapacity() == word_num)
			{
				index_check = getCapacity() - 1;
			}
			loop_count1++;
        }
        delete[] current_table; 
		index_check--;
        current_table = inc_table;
    }   
}

bool WordSet::contains(std::string s) const
{
	int present_table = hashFunction(s, BASE_TO_USE, getCapacity());
	return searchItem(present_table, s);
}

int WordSet::getCount() const
{
	return word_num;
}

int WordSet::getCapacity() const
{
	return SIZES[list_size];
}

bool WordSet::searchItem(int temp_table, std::string temp_word) const
{
	int loop_counter = 0, found_target = 0;
	while(found_target == 0)
    {
        int free_loc = (loop_counter * loop_counter + temp_table) % getCapacity();
		if(current_table[free_loc].empty() == true)   
        {                        
			found_target = 1;
        }
        else if(current_table[free_loc] == temp_word)
        {
			found_target = 1;
            return true;
        }
		loop_counter++;
    }
	return false;
}
