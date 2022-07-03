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
	T search(T data) {
		Node<T>* iter = root;
		while (true) {
			if (data == iter->id) return iter->id;
			else if (data > iter->id) {
				if (iter->right == nullptr) {
					return -1;
				}
				else iter = iter->right;
			}
			else if (data < iter->id) {
				if (iter->left == nullptr) {
					return -1;
				}
				else iter = iter->left;
			}
		}
	}
	void remove(T data) {

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
	tree.print();


}

