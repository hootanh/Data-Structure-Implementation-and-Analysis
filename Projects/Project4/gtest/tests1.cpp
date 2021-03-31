#include "gtest/gtest.h"
#include "MyAVLTree.hpp"
#include "proj4.hpp"
#include <string>
#include <sstream>
#include <vector>

namespace{


// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.

// The four tests marked "CheckPoint" are going to be run
// on your submission for the checkpoint code.
// This is worth one-sixth of your grade on the assignment
// and is due at the time marked "checkpoint"


// None of the "checkpoint" tests require you to have
// AVL functionality OR the counting of words.
// Implementing your tree as a plain binary search
// tree is more than enough to pass these tests.

// Of course, you are expected to implement AVL functionality
// for the full project.

// BE SURE TO FULLY TEST YOUR CODE.
// This means making sure your templating is not hard-coding for 
// a specific type, that every function is called somewhere in 
// your test cases, etc. 
// There will NOT be a project 2 style redo for this;  if your 
//  code does not compile, your score will be a zero. 


TEST(CheckPoint, CheckPoint_FindTheRoot)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");

	EXPECT_TRUE( tree.contains(5) && tree.size() == 1);
}

TEST(CheckPoint, CheckPoint_FindOneHop)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(10, "bar");

	EXPECT_TRUE( tree.contains(10) && tree.size() == 2);
}

TEST(CheckPoint, CheckPoint_FindTwoHops)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");

	EXPECT_TRUE( tree.contains(12) && tree.size() == 4);
}

TEST(CheckPoint, CheckPoint_Add5)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");

	EXPECT_TRUE( tree.size() == 5 && tree.contains(3));
}

TEST(CheckPoint, CheckPoint_Hootan_template_size_contains_insert)
{
	MyAVLTree<std::string, int> tree;
	tree.insert("foo", 5);
	tree.insert("bar", 10);

	EXPECT_TRUE( tree.contains("bar") && tree.size() == 2);
}

TEST(CheckPoint, CheckPoint_Hootan_template_size_contains_insert1)
{
	MyAVLTree<char, double> tree;
	tree.insert('A', 1);
	tree.insert('B', 2);
	tree.insert('C', 3);

	EXPECT_TRUE( tree.contains('A') &&  tree.contains('B') && tree.contains('C') && tree.size() == 3);
}

TEST(PostCheckPoint, PostCheckPoint_Hootan_Find)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(10, "bar");

	EXPECT_TRUE(tree.find(5) == "foo");
}

TEST(PostCheckPoint, InOrderTraversal)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");

	std::vector<int> trav = tree.inOrder();
	std::vector<int> expected = {3, 5, 10, 12, 15};
	EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, InOrderTraversal_Hootan_2)
{
	MyAVLTree<char, double> tree;
	tree.insert('A', 1.2);
	tree.insert('B', 1.4);
	tree.insert('C', 2.2);
	tree.insert('D', 5.5);
	tree.insert('E', 0.0);

	std::vector<char> trav = tree.inOrder();
	std::vector<char> expected = {'A', 'B', 'C', 'D', 'E'};
	EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, JackSparrow)
{
	std::string quote = "I'm dishonest, and a dishonest man you can ";
	quote += "always trust to be dishonest. Honestly. It's the honest ";
	quote += "ones you want to watch out for, because you can never ";
	quote += "predict when they're going to do something incredibly... stupid.";

	std::istringstream stream( quote );

	MyAVLTree<std::string, unsigned> tree;

	countWords(stream, tree);
	EXPECT_TRUE(tree.find("dishonest") == 3);
}

TEST(PostCheckPoint, Hootan_string)
{
	std::string temp = "today i'm going to workout and as you know workout is good for your body";
	std::istringstream a( temp );

	MyAVLTree<std::string, unsigned> tree;

	countWords(a, tree);
	EXPECT_TRUE(tree.find("workout") == 2);
}
}
