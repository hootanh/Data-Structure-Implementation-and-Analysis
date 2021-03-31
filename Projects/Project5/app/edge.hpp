// DO NOT MODIFY THIS FILE

/*
Edge struct with < and == operators defined.  == means weight the same AND endpts match, but endpts in either order.

*/

#ifndef __GRAPH_EDGE_H
#define __GRAPH_EDGE_H

struct Edge{
	unsigned pt1, pt2;
	unsigned weight;
	Edge(unsigned u, unsigned v, unsigned wt) : pt1(u), pt2(v), weight(wt){}

	//  This overloads the < operator so that comparing two Edge insantiations 
	//	has a meaning.  In this case, one edge is < the other if and only if 
	//  the first one has a smaller weight. 
	bool operator<(const Edge & e) const{
		return weight < e.weight;
	}

	bool operator==(const Edge & e){
		return weight == e.weight && ((pt1 == e.pt1 && pt2 == e.pt2) ||(pt2 == e.pt1 && pt1 == e.pt2));
	}
};


#endif 