#include <iostream>
#include <vector>
using namespace std;

class Node {
private:
	Node* parent;
	vector<Node*>child;
	int value;
	int level;
public:
	Node() {
		parent = nullptr;
		value = 0;
		
	}
	Node(int v) {
		value = v;
		parent = nullptr;
		
	}
	Node(Node* p, int v) {
		parent = p;
		value = v;

	}
	friend class Tree;
};

class Tree {
private:
	Node* root;
	vector<Node*>nodelist;
public:
	Tree() {
		root = new Node(-1);
		
	}
	Node* findnode(int x) {
		for (int i = 0; i < nodelist.size(); i++) {
			if (nodelist[i]->value == x) {
				return nodelist[i];
			}
		}
		return nullptr;
	}

	void insert(int x, int y) {

		if (nodelist.size() == 0) {
			root = new Node(x);
			nodelist.push_back(root);
			root->level = 0;
		}

		Node* parentnode = findnode(x);			
			Node* newnode = new Node(parentnode, y);
			parentnode->child.push_back(newnode);
			nodelist.push_back(newnode);
			newnode->level = parentnode->level + 1;
		
	}

	void level(int x) {
		Node* curnode = findnode(x);
		if (curnode != nullptr)
			cout << curnode->level << endl;
		else
			cout << "-1\n";
	}
};

int main() {
	Tree* tree=new Tree();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int n, m;
		cin >> n >> m;
		tree->insert(n, m);
	}
	for (int j = 0; j < m; j++) {
		int num;
		cin >> num;
		tree->level(num);
	}
}