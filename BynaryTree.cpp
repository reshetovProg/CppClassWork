#include <iostream>
using namespace std;

template<typename T>
struct Node {
	T id;
	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
	Node<T>* parent = nullptr;
};

template<typename T>
class BinaryTree {
	Node<T>* root = nullptr;
	int size = 0;
public:
	BinaryTree() {}
	BinaryTree(T data) {
		Node<T>* node = new Node<T>{ data };
		root = node;
		size++;
	}
	void add(T data) {
		if (size == 0) {
			BinaryTree(data);
		}
		else {
			Node<T>* iter = root;
			Node<T>* node = new Node<T>{ data };
			while (true) {
				if (node->id > iter->id) {
					if (iter->right == nullptr) {
						node->parent = iter;
						iter->right = node;
						break;
					}
					else iter = iter->right;
				}
				else {
					if (iter->left == nullptr) {
						node->parent = iter;
						iter->left = node;
						break;
					}
					else iter = iter->left;
				}
			}
			size++;
		}

	}
	void print(Node<T>* node = nullptr) {
		if (node == nullptr) node = root;
		cout << node->id<<" ";
		if (node->left != nullptr) {
			print(node->left);
		}
		if (node->right != nullptr) {
			print(node->right);
		}
	}
	Node<T>* search(T data) {
		Node<T>* iter = root;
		while (true) {
			if (data == iter->id) return iter;
			else if (data > iter->id) {
				if (iter->right == nullptr) {
					return nullptr;
				}
				else iter = iter->right;
			}
			else if (data < iter->id) {
				if (iter->left == nullptr) {
					return nullptr;
				}
				else iter = iter->left;
			}
		}
	}
	void remove(T data) {
		Node<T>* node = search(data);
		if (node->left == nullptr && node->right == nullptr) {
			if (node->parent->left == node) {
				node->parent->left = nullptr;
			}
			else node->parent->right = nullptr;
			delete node;
		}
		else if (node->left == nullptr) {
			if (node->parent->left == node) {
				node->parent->left = node->right;
			}
			else node->parent->right = node->right;
			delete node;
		}
		else if (node->right == nullptr) {
			if (node->parent->left == node) {
				node->parent->left = node->left;
			}
			else node->parent->right = node->left;
			delete node;
		}
		else {
			if (node == root) {
				Node<T>* iter = node->right;
				while (iter->left != nullptr) {
					iter = iter->left;
				}
				Node<T>* tmp = node;
				node = iter;
				if (node->left == nullptr && node->right == nullptr) {
					node->parent->left = nullptr;
				}
				else {	
					node->parent->left = node->right;
				}
				//node->parent = tmp->parent;
				node->left = tmp->left;
				node->right = tmp->right;
				//node->parent->left = node;
				node->left->parent = node;
				node->right->parent = node;
				node->parent = nullptr;
				delete tmp;
				root = node;

			}
			else if (node->id < node->parent->id) {
				Node<T>* iter = node->right;
				while (iter->left != nullptr) {
					iter = iter->left;
				}
				Node<T>* tmp = node;
				node = iter;				
				if (node->left == nullptr && node->right == nullptr) {
					node->parent->left = nullptr;					
				}
				else {					
					node->parent->left = node->right;					
				}
				node->parent = tmp->parent;
				node->left = tmp->left;
				node->right = tmp->right;
				node->parent->left = node;
				node->left->parent = node;
				node->right->parent = node;
				delete tmp;
			}
			else {
				Node<T>* iter = node->left;
				while (iter->right != nullptr) {
					iter = iter->right;
				}
				Node<T>* tmp = node;
				node = iter;
				if (node->left == nullptr && node->right == nullptr) {
					node->parent->right = nullptr;
				}
				else {
					node->parent->right = node->left;
				}
				node->parent = tmp->parent;
				node->left = tmp->left;
				node->right = tmp->right;			
				node->parent->right = node;
				node->left->parent = node;
				node->right->parent = node;
				delete tmp;
			}
		}
		size--;
	}
};


int main()
{
	BinaryTree<double> tree(15);
	tree.add(10);
	tree.add(8);
	tree.add(6);
	tree.add(12);
	tree.add(11);
	tree.add(11.5);
	tree.add(14);
	tree.add(13);
	tree.add(20);
	tree.add(24);
	tree.add(19);
	tree.add(18);
	tree.add(19.5);
	tree.print();
	cout << endl;
	tree.remove(15);
	tree.print();
}

