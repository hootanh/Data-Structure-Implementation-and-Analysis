#include "gtest/gtest.h"
#include "LLQueue.hpp"
#include "proj2.hpp"
#include <iostream>


namespace{


// NOTE:  these are not intended as exhaustive tests.
	// This should get you started testing.
	// You should make your own additional tests for both queue
	// and for the social network question.
	// VERY IMPORTANT:  if your LLQueue is not templated, or if 
	//		it is not linked-list based, your score for this project
	//		will be zero.  Be sure your LLQueue compiles and runs 
	// 		with non-numeric data types. 

TEST(QueueTest, QueueTest1)
{
	LLQueue<int> a;
	a.enqueue(5);
	EXPECT_TRUE( a.front() == 5 );
}

TEST(QueueTest, QueueTest2)
{
	LLQueue<int> a;
	a.enqueue(5);
	a.enqueue(3);
	EXPECT_TRUE( a.front() == 5 );
}

TEST(QueueTest, QueueTest3)
{
	LLQueue<int> a;
	a.enqueue(5);
	a.enqueue(3);
	a.dequeue();
	EXPECT_TRUE( a.front() == 3 );
}

TEST(QueueTest, QueueTest4)
{
	LLQueue<int> a;
	a.enqueue(1);
	a.enqueue(2);
	a.dequeue();
	a.enqueue(1);
	a.dequeue();
	EXPECT_TRUE( a.front() == 1 );
}

TEST(QueueTest, QueueTest5)
{
	LLQueue<char> a;
	a.enqueue('H');
	a.enqueue('B');
	a.dequeue();
	a.enqueue('C');
	a.dequeue();
	EXPECT_TRUE( a.front() == 'C' );
}

TEST(QueueTest, QueueTest6)
{
	LLQueue<std::string> a;
	std::string h = "Hooty";
	std::string b = "Bob";
	std::string c = "Cat";
	std::cout << a.size() << std::endl;
	std::cout << a.isEmpty() << std::endl;
	a.enqueue(h);
	std::cout << a.front() << std::endl;
	a.enqueue(b);
	a.dequeue();
	a.enqueue(c);
	a.dequeue();
	EXPECT_TRUE( a.front() == c );
}

TEST(QueueTest, QueueTest7)
{
	LLQueue<double> a;
	a.enqueue(1.1);
	a.enqueue(2.5);
	a.dequeue();
	a.enqueue(1.8);
	a.dequeue();
	EXPECT_TRUE( a.front() == 1.8 );
}

TEST(GraphTest, GraphTest1)
{
	std::vector< std::vector<unsigned> > g1 = {
		{1,2}, {0,3}, {0,3}, {1,2}
	};
	std::vector<unsigned> pathLengths(4);
	std::vector<unsigned> numShortestPaths(4);
	
	countPaths(g1, 0, pathLengths, numShortestPaths);

	std::vector<unsigned> expPathLengths = {0, 1, 1, 2};
	std::vector<unsigned> expNumSP = {1, 1, 1, 2};

	EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);

}


TEST(GraphTest, GraphTest2)
{
	std::vector< std::vector<unsigned> > g1 = {
		{1, 2, 4}, {0,3}, {0,3}, {1,2,5}, {0, 5}, {3, 4}
	};
	
	std::vector<unsigned> pathLengths(6);
	std::vector<unsigned> numShortestPaths(6);
	
	countPaths(g1, 0, pathLengths, numShortestPaths);

	std::vector<unsigned> expPathLengths = {0, 1, 1, 2, 1, 2};
	std::vector<unsigned> expNumSP = {1, 1, 1, 2, 1, 1};

	EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);
}

TEST(GraphTest, GraphTest3)
{
	std::vector< std::vector<unsigned> > g1 = {
		{1, 2, 4}, {0,3}, {0,3}, {1,2,5, 7}, {0, 5, 6}, {3, 4}, {4, 7}, {3, 6},
	};
	
	std::vector<unsigned> pathLengths(8);
	std::vector<unsigned> numShortestPaths(8);
	
	countPaths(g1, 0, pathLengths, numShortestPaths);

	std::vector<unsigned> expPathLengths = {0, 1, 1, 2, 1, 2, 2, 3};
	std::vector<unsigned> expNumSP = {1, 1, 1, 2, 1, 1, 1, 3};

	EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);

}
}