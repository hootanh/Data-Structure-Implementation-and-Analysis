#ifndef __PROJ_THREE_AVL_HPP
#define __PROJ_THREE_AVL_HPP

#include "runtimeexcept.hpp"
#include <string>
#include <vector>

class ElementNotFoundException : public RuntimeException 
{
public:
	ElementNotFoundException(const std::string & err) : RuntimeException(err) {}
};

template<typename Key, typename Value>
class Tree_Nodes
{
	private:
		bool find_root;
	public:
		int tree_tall;
		Key node_key;
		Tree_Nodes<Key, Value> * child_l; 	
		Value node_value;
		Tree_Nodes<Key, Value> * child_r; 	
		bool node_span;
		Tree_Nodes<Key, Value> * child_p; 	
		Tree_Nodes(const Key & temp_key, const Value & temp_value)
		{
			find_root = true;
			node_value = temp_value;
			child_l = nullptr;
			node_key = temp_key;
			child_r = nullptr;
			node_span = true;
			child_p = nullptr;
		}
		~Tree_Nodes() 
		{
			find_root = false;
			delete child_l;
			node_span = false;
			delete child_r;
		}
};

template<typename Key, typename Value>
class MyAVLTree
{
	private:
		bool tree_c, inserted, is_root = true, preOrder_check = false, inOrder_check = false, postOrder_check = false,  left_child, right_child;	
		int tree_size, tree_check = 0, insert_count = 0, find_check = true; 
		void recursive_inOrder(Tree_Nodes<Key,Value> * inOrder_node, std::vector<Key> & inOrder_v) const;  
		int recursive_tall(Tree_Nodes<Key,Value> * present_tall); 
		void recursive_preOrder(Tree_Nodes<Key,Value> * preOrder_node, std::vector<Key> & preOrder_v) const; 
		Tree_Nodes<Key, Value> * tree_root; 	
		void recursive_postOrder(Tree_Nodes<Key,Value> * postOrder_node, std::vector<Key> & postOrder_v) const; 
	public:
		MyAVLTree();
		~MyAVLTree()
		{
			tree_c = false;
			delete tree_root;
			inserted = false;
		}
		size_t size() const noexcept;
		bool isEmpty() const noexcept;
		bool contains(const Key & k) const; 
		Value & find(const Key & k);
		const Value & find(const Key & k) const;
		void insert(const Key & k, const Value & v);
		std::vector<Key> inOrder() const;
		std::vector<Key> preOrder() const;
		std::vector<Key> postOrder() const;
};

template<typename Key, typename Value>
MyAVLTree<Key,Value>::MyAVLTree()
{
	inserted = false;
	tree_root = nullptr; 
	tree_c = true;
	tree_size = 0; 
}

template<typename Key, typename Value>
size_t MyAVLTree<Key, Value>::size() const noexcept
{
	return tree_size;
}

template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::isEmpty() const noexcept
{
	if(tree_size != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::contains(const Key & k) const
{
	Tree_Nodes<Key, Value> * present_node = tree_root; 
	while(true)
	{
		if(present_node == nullptr)
		{
			return false;
		}
		if(present_node -> node_key == k) 
		{
			return true;
		}
		else if(present_node -> node_key <= k) 
		{
			present_node = present_node -> child_r;
		}
		else if(present_node -> node_key > k) 
		{
			present_node = present_node -> child_l;
		}
	}
	return false; 
}

template<typename Key, typename Value>
Value & MyAVLTree<Key, Value>::find(const Key & k)	
{
	Tree_Nodes<Key, Value> * present_node = tree_root;
	if(find_check == true && contains(k) == false)
	{
		throw ElementNotFoundException("Element not found in tree!!!");
	}
	while(true)
	{
		if(present_node == nullptr || present_node -> node_key == k) 
		{
			break;
		}
		else if(find_check == true && present_node -> node_key <= k)
		{
			present_node = present_node -> child_r;
		}
		else if(find_check == true && present_node -> node_key > k)
		{
			present_node = present_node -> child_l;
		}
	}
	return present_node -> node_value;
}

template<typename Key, typename Value>
const Value & MyAVLTree<Key, Value>::find(const Key & k) const
{
	Tree_Nodes<Key, Value> * present_node = tree_root;
	if(find_check == true && contains(k) == false)
	{
		throw ElementNotFoundException("Element not found in tree!!!");
	}
	while(true)
	{
		if(present_node == nullptr || present_node -> node_key == k) 
		{
			break;
		}
		else if(find_check == true && present_node -> node_key <= k)
		{
			present_node = present_node -> child_r;
		}
		else if(find_check == true && present_node -> node_key > k)
		{
			present_node = present_node -> child_l;
		}
	}
	return present_node -> node_value;
}

template<typename Key, typename Value>
void MyAVLTree<Key, Value>::insert(const Key & k, const Value & v)
{
	Tree_Nodes<Key, Value> * added_node;
	bool loop_check = true, is_balanced = true, check_balance, right_r, left_r, rotation_r = true, rotation_l = true;
	int first_result, second_result, tree_balance;
	if(tree_root != nullptr)
	{
		Tree_Nodes<Key, Value> * new_node = tree_root;
		insert_count = tree_size + 1;
		while(true) 
		{
			if(loop_check == true && new_node -> node_key <= k) 
			{
				if(loop_check == true && new_node -> child_r == nullptr) 
				{
					new_node -> child_r = new Tree_Nodes<Key, Value> (k, v); 
					tree_size++; 
					insert_count += tree_size;
					added_node = new_node -> child_r; 
					inserted = false;
					added_node -> child_p = new_node; 
					break;
				}
				else if(new_node -> child_r != nullptr)
				{
					inserted = true;
					insert_count--;
				}
				insert_count++;
				new_node = new_node -> child_r; 
				inserted = true;
			}
			else if(loop_check == true && new_node -> node_key > k) 
			{
				if(loop_check == true && new_node -> child_l == nullptr)
				{
					new_node -> child_l = new Tree_Nodes<Key, Value> (k, v); 
					tree_size++; 
					insert_count += tree_size;
					added_node = new_node -> child_l; 
					inserted = false;
					added_node -> child_p = new_node; 
					break;
				}
				else if(new_node -> child_l != nullptr)
				{
					inserted = true;
					insert_count--;
				}
				insert_count++;
				new_node = new_node -> child_l; 
				inserted = true;
			}
			else
			{
				insert_count--;
				inserted = false;
				continue;
			}
		}
		recursive_tall(tree_root);  
		Key temp_k = added_node -> node_key; 
		while(loop_check == true && added_node != tree_root)
		{
			added_node = added_node -> child_p; 
			if(added_node -> child_l == nullptr) 
			{
				insert_count++;
				first_result = -1;
			}
			else
			{
				insert_count--;
				first_result = added_node -> child_l -> tree_tall;
			}
			if (added_node -> child_r == nullptr)
			{
				insert_count++;
				second_result = -1;
			}
			else
			{
				insert_count--;
				second_result = added_node -> child_r -> tree_tall;
			}
			if(is_balanced == true)
			{
				tree_balance = first_result - second_result;
				inserted = false;
				check_balance = tree_balance > 1 || tree_balance < -1;
			}
			if(check_balance && tree_balance < -1) 
			{
				inserted = true;
				if(temp_k > added_node -> child_r -> node_key) 
				{	
					Tree_Nodes<Key,Value> * rotate_r1 = added_node -> child_r; 
					added_node -> child_r = rotate_r1 -> child_l; 
					if(rotation_r == true && added_node -> child_r != nullptr) 
					{
						insert_count += tree_size;
						added_node -> child_r -> child_p = added_node; 
					}
					rotate_r1 -> child_l = added_node; 
					rotate_r1 -> child_p = added_node->child_p;  
					added_node -> child_p = rotate_r1; 
					if(rotation_r == true && rotate_r1 -> child_p != nullptr) 
					{
						insert_count++;
						if(rotation_r == true && rotate_r1 -> node_key <= rotate_r1 -> child_p -> node_key)
						{
							right_r = false;
							rotate_r1 -> child_p -> child_l = rotate_r1;
						}
						else if(rotation_r == true)
						{
							right_r = true;
							rotate_r1 -> child_p -> child_r = rotate_r1;
						}
					}
					else 
					{
						right_r = true;
						insert_count++;
						tree_root = rotate_r1;
					}
					break;
				}
			}
			else if(check_balance && tree_balance > 1) 
			{
				inserted = true;
				if(temp_k < added_node -> child_l -> node_key)
				{
					Tree_Nodes<Key,Value> * rotate_l1 = added_node -> child_l; 
					added_node -> child_l = rotate_l1 -> child_r;
					if(rotation_l == true && added_node -> child_l != nullptr) 
					{
						insert_count += tree_size;
						added_node -> child_l -> child_p = added_node;
					}
					rotate_l1 -> child_r = added_node; 
					rotate_l1 -> child_p = added_node -> child_p; 
					added_node -> child_p = rotate_l1; 
					if(rotation_l == true && rotate_l1 -> child_p != nullptr) 
					{
						insert_count++;
						if(rotation_l == true && rotate_l1 -> node_key <= rotate_l1 -> child_p -> node_key) 
						{
							left_r = false;
							rotate_l1 -> child_p -> child_l = rotate_l1;
						}
						else if(rotation_l == true)
						{
							left_r = true;
							rotate_l1 -> child_p -> child_r = rotate_l1;
						}
					}
					else 
					{
						left_r = true;
						insert_count++;
						tree_root = rotate_l1;
					}
					break;
				}
				else if(temp_k > added_node -> child_l -> node_key)
				{
					Tree_Nodes<Key,Value> * rotate_r2 = added_node -> child_l -> child_r; 
					added_node -> child_l -> child_r = rotate_r2 -> child_l; 
					if(rotation_r == true && added_node -> child_l -> child_r != nullptr) 
					{
						insert_count += tree_size;
						added_node -> child_l -> child_r -> child_p = added_node -> child_l; 
					}
					rotate_r2 -> child_l = added_node -> child_l; 
					rotate_r2 -> child_p = added_node -> child_l -> child_p;  
					added_node -> child_l -> child_p = rotate_r2; 
					if(rotation_r == true && rotate_r2 -> child_p != nullptr) 
					{
						insert_count++;
						if(rotation_r == true && rotate_r2 -> node_key <= rotate_r2 -> child_p -> node_key)
						{
							right_r = false;
							rotate_r2 -> child_p -> child_l = rotate_r2;
						}
						else if(rotation_r == true)
						{
							right_r = true;
							rotate_r2 -> child_p -> child_r = rotate_r2;
						}
					}
					else 
					{
						right_r = true;
						insert_count++;
						tree_root = rotate_r2;
					}
					Tree_Nodes<Key,Value> * rotate_l2 = added_node -> child_l; 
					added_node -> child_l = rotate_l2 -> child_r;
					if(rotation_l == true && added_node -> child_l != nullptr) 
					{
						insert_count += tree_size;
						added_node -> child_l -> child_p = added_node;
					}
					rotate_l2 -> child_r = added_node; 
					rotate_l2 -> child_p = added_node -> child_p; 
					added_node -> child_p = rotate_l2; 
					if(rotation_l == true && rotate_l2 -> child_p != nullptr) 
					{
						insert_count++;
						if(rotation_l == true && rotate_l2 -> node_key <= rotate_l2 -> child_p -> node_key) 
						{
							left_r = false;
							rotate_l2 -> child_p -> child_l = rotate_l2;
						}
						else if(rotation_l == true)
						{
							left_r = true;
							rotate_l2 -> child_p -> child_r = rotate_l2;
						}
					}
					else 
					{
						left_r = true;
						insert_count++;
						tree_root = rotate_l2;
					}
					break;
				}
			}
			else if(check_balance) 
			{
				inserted = true;
				Tree_Nodes<Key,Value> * rotate_l3 = added_node -> child_r -> child_l; 
				added_node -> child_r -> child_l = rotate_l3 -> child_r;
				if(rotation_l == true && added_node -> child_r -> child_l != nullptr) 
				{
					insert_count += tree_size;
					added_node -> child_r -> child_l -> child_p = added_node -> child_r;
				}
				rotate_l3 -> child_r = added_node -> child_r; 
				rotate_l3 -> child_p = added_node -> child_r -> child_p; 
				added_node -> child_r -> child_p = rotate_l3; 
				if(rotation_l == true && rotate_l3 -> child_p != nullptr) 
				{
					insert_count++;
					if(rotation_l == true && rotate_l3 -> node_key <= rotate_l3 -> child_p -> node_key) 
					{
						left_r = false;
						rotate_l3 -> child_p -> child_l = rotate_l3;
					}
					else if(rotation_l == true)
					{
						left_r = true;
						rotate_l3 -> child_p -> child_r = rotate_l3;
					}
				}
				else 
				{
					left_r = true;
					insert_count++;
					tree_root = rotate_l3;
				}
				Tree_Nodes<Key,Value> * rotate_r3 = added_node -> child_r; 
				added_node -> child_r = rotate_r3 -> child_l; 
				if(rotation_r == true && added_node -> child_r != nullptr) 
				{
					insert_count += tree_size;
					added_node -> child_r -> child_p = added_node; 
				}
				rotate_r3 -> child_l = added_node; 
				rotate_r3 -> child_p = added_node -> child_p;  
				added_node -> child_p = rotate_r3; 
				if(rotation_r == true && rotate_r3 -> child_p != nullptr) 
				{
					insert_count++;
					if(rotation_r == true && rotate_r3 -> node_key <= rotate_r3 -> child_p -> node_key)
					{
						right_r = false;
						rotate_r3 -> child_p -> child_l = rotate_r3;
					}
					else if(rotation_r == true)
					{
						right_r = true;
						rotate_r3 -> child_p -> child_r = rotate_r3;
					}
				}
				else 
				{
					right_r = true;
					insert_count++;
					tree_root = rotate_r3;
				}
				break;
			}
		}
		recursive_tall(tree_root);  
	}
	else if(is_root == true && tree_root == nullptr) 
	{
		inserted = true;
		tree_root = new Tree_Nodes<Key, Value> (k, v); 
		insert_count = tree_size + 1;
		tree_size++; 
		return; 
	}
	else if(is_root == true && contains(k) == true) 
	{
		insert_count += tree_size;
		inserted = false;
		return;
	}
	else
	{
		inserted = true;
		insert_count -= tree_size;
		is_root = true;
	}
}

template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::inOrder() const
{
	std::vector<Key> inOrder_v;
	if(inOrder_check == false)
	{
		recursive_inOrder(tree_root, inOrder_v);
	}
	return inOrder_v;
}

template<typename Key, typename Value>
void MyAVLTree<Key, Value>::recursive_inOrder(Tree_Nodes<Key, Value> * inOrder_node, std::vector<Key> & inOrder_v) const	
{
	if(inOrder_check == false && inOrder_node != nullptr)
	{
		recursive_inOrder(inOrder_node -> child_l, inOrder_v);
		inOrder_v.push_back(inOrder_node -> node_key);
		recursive_inOrder(inOrder_node -> child_r, inOrder_v);
	}
	else if(inOrder_check == false)
	{
		return;
	}
}

template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::preOrder() const	
{
	std::vector<Key> preOrder_v;
	if(preOrder_check == false)
	{
		recursive_preOrder(tree_root, preOrder_v);
	}
	return preOrder_v; 
}

template<typename Key, typename Value>
void MyAVLTree<Key, Value>::recursive_preOrder(Tree_Nodes<Key, Value> * preOrder_node, std::vector<Key> & preOrder_v) const	
{
	if(preOrder_check == false && preOrder_node != nullptr)
	{
		preOrder_v.push_back(preOrder_node -> node_key);
		recursive_preOrder(preOrder_node -> child_l, preOrder_v);
		recursive_preOrder(preOrder_node -> child_r, preOrder_v);
	}
	else if(preOrder_check == false)
	{
		return;
	}
}

template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::postOrder() const	
{
	std::vector<Key> postOrder_v;
	if(postOrder_check == false)
	{
		recursive_postOrder(tree_root, postOrder_v);
	}
	return postOrder_v; 
}

template<typename Key, typename Value>
void MyAVLTree<Key, Value>::recursive_postOrder(Tree_Nodes<Key, Value> * postOrder_node, std::vector<Key> & postOrder_v) const 	
{
	if(postOrder_check == false && postOrder_node != nullptr)
	{
		recursive_postOrder(postOrder_node -> child_l, postOrder_v);
		recursive_postOrder(postOrder_node -> child_r, postOrder_v);
		postOrder_v.push_back(postOrder_node -> node_key);
	}
	else if(postOrder_check == false)
	{
		return;
	}
}

template<typename Key, typename Value>
int MyAVLTree<Key,Value>::recursive_tall(Tree_Nodes<Key, Value> * present_tall)	
{
	int left_tall, right_tall, no_tall = -1;
	if(present_tall != nullptr)
	{
		left_tall= recursive_tall(present_tall -> child_l);
		left_child = false;
		right_tall = recursive_tall(present_tall -> child_r);
		right_child = false;
		if(left_tall <= right_tall)
		{
			right_child = true;
			present_tall -> tree_tall = right_tall + 1; 
		}
		else
		{
			left_child = true;
			present_tall -> tree_tall = left_tall + 1;
		}
		return  present_tall -> tree_tall; 
	}
	else
	{
		right_child = false;
		left_child = false;
		return no_tall;
	}
}
#endif 