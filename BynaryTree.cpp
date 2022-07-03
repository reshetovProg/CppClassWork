#include <iostream>
using namespace std;

template<typename T>
struct Node {
	T id;
	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
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
						iter->right = node;
						break;
					}
					else iter = iter->right;
				}
				else {
					if (iter->left == nullptr) {
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
};


int main()
{
	BinaryTree<int> tree(15);
	tree.add(9);
	tree.add(1);
	tree.add(0);
	tree.add(19);
	tree.add(25);
	tree.add(24);
	tree.add(18);
	tree.add(16);
	tree.add(17);
	tree.add(14);
	tree.add(30);
	tree.add(5);
	tree.add(10);
	tree.print();

}

