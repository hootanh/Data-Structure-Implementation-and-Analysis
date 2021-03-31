#Hootan Hosseinzadeganbushehri


#include "proj5.hpp"
#include "MyPriorityQueue.hpp"
//#include <iostream>


std::vector<Edge> compute_mst(std::vector< std::vector<unsigned>> & graph)
{
	std::vector<Edge> mst;
	int vecs = graph[0].size();
	MyPriorityQueue<Edge> queue;
	std::vector<int> key(vecs, 9999999);
	std::vector<bool> inMST(vecs, false);
	queue.insert(Edge(0,0, graph[0][0]));
	key[0] = 0;
	while (!queue.isEmpty())
	{
		Edge cr = queue.min();
		queue.extractMin();
		if (cr.pt1 != cr.pt2)
		{
			mst.push_back(cr);
		}
		inMST[cr.pt2] = true;
		
		for (int i = 0; i < graph[0].size(); i++)
		{
			if (!inMST[i] && key[i] > (int)graph[cr.pt2][i] && (int)graph[cr.pt2][i] != 0)
			{
				key[i] = graph[cr.pt2][i];
				queue.insert(Edge(cr.pt2, i, graph[cr.pt2][i]));
			}
		}
	}
	//for (int i = 0; i < graph[0].size(); i++)
		//std::cout << mst[i].pt1 << " " << mst[i].pt2 << " " << mst[i].weight << "\n";
	return mst;
}

unsigned mstCost(const std::vector<Edge> & vE) 
{
	unsigned sum =0;
	for(auto e: vE)
	{
		sum += e.weight;
	}
	return sum;
}