#ifndef __PROJECT5_HPP
#define __PROJECT5_HPP

#include <vector>
#include "edge.hpp"



// Compute the minimum spanning tree of the given graph and return it as a vector of Edge.
// Your function MAY assume that this is a complete graph (as that is part of project specification).
std::vector<Edge> compute_mst(std::vector< std::vector<unsigned> > & graph);

// Returns the cost of the edges in the given vector,
// This does not confirm that it is a MST at all.  
unsigned mstCost(const std::vector<Edge> & vE); 

#endif 
