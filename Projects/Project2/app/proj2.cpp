#Hootan Hosseinzadeganbushehri


#include "proj2.hpp"
#include "LLQueue.hpp"
#include <vector>

// This function is getting a nested vector of nodes in which the inner vector is the list of the connecting 
// edges from the current node to other connected nodes from the current node and also gets an starting
// node to calculate the distinct paths and shortest paths from the starting node to all other nodes in the 
// vector and puts the results into the given vectors(pathLengths and numShortestPaths) in the parameter
void countPaths(const std::vector< std::vector<unsigned> > & friends, unsigned start, std::vector<unsigned> & pathLengths, std::vector<unsigned> & numShortestPaths)
{	
	std::vector<unsigned> visited_nodes(100);
	LLQueue<unsigned> path_queue;
    path_queue.enqueue(start);
	visited_nodes[start] = 1;
    pathLengths[start] = 0;
    numShortestPaths[start] = 1;
	unsigned queue_front;
    
    while(path_queue.isEmpty() == false)
    {
        queue_front = path_queue.front();
		unsigned path_size = friends[queue_front].size();
        path_queue.dequeue();
        for(unsigned n = 0; n < path_size; n++)
        {
            if(visited_nodes[friends[queue_front][n]] == 0)
            {
                visited_nodes[friends[queue_front][n]] = 1;
                pathLengths[friends[queue_front][n]] = pathLengths[queue_front] + 1;
				numShortestPaths[friends[queue_front][n]] = numShortestPaths[queue_front];
                path_queue.enqueue(friends[queue_front][n]);
            }
			else if(pathLengths[friends[queue_front][n]] == pathLengths[queue_front] + 1)
			{
                numShortestPaths[friends[queue_front][n]] += numShortestPaths[queue_front];
			}
			else
			{
				continue;
			}
        }
    }
}
