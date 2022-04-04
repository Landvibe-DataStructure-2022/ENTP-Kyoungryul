#include <iostream>
using namespace std;

class Node {
private:
	Node* next;
	Node* prev;

	int value;
public:
	Node() {
		next =prev= nullptr;
		value = 0;
	}
	Node(int v) {
		next = nullptr;
		prev = nullptr;
		value = v;
	}
	friend class Iterator;
	friend class Sequence;
};

class Iterator {
private:
	Node* node;

public:
	Iterator() {
		node = nullptr;

	}
	Iterator(Node*n) {
		node = n;
	}
	Iterator* operator++() {
		node = node->next;
		return this;
	}
	Iterator* operator--() {
		node = node->prev;
		return this;
	}
	friend class Sequence;
};

class Sequence {
private:
	Node* head;
	Node* tail;
	int size;
public:
	Sequence() {
		head = new Node;
		tail = new Node;

		head->next = tail;
		tail->prev = head;
		size = 0;
	}
	Node* begin() {
		return head->next;
	}
	Node* end() {
		return tail;
	}

	void insert(Iterator& p, int e) {
		Node* newNode = new Node(e);
		p.node->prev->next = newNode;
		newNode->prev = p.node->prev;
		newNode->next = p.node;
		p.node->prev = newNode;

		size++;

	}

	void erase(Iterator& p) {
		if (size == 0) {
			cout << "Empty" << endl;
	}
		else {
			Node* deleteNode = p.node;
			deleteNode->prev->next = deleteNode->next;
			deleteNode->next->prev = deleteNode->prev;

			p.node = begin();
			size--;

			delete deleteNode;
		}
	}

	void print() {
		if (size == 0) {
			cout << "Empty" << endl;

		}
		else {
			Node* curNode = head->next;
			
			while (curNode!=tail)
			{
				cout << curNode->value << " ";
				curNode = curNode->next;
			}
			cout << endl;
		}
	}

	void find(int e) {
		if (size == 0) {
			cout << "Empty" << endl;
		}
		else {
			Node* curNode = head->next;
			int index = 0;

			while (curNode!=tail)
			{
				if (curNode->value == e) {
					cout << index << endl;
					return;
				}
				else {
					curNode = curNode->next;
					index++;
				}
			}
			cout << "-1" << endl;
		}
	}

};

int main() {
	int n;
	cin >> n;

	Sequence seq = Sequence();
	Iterator p = Iterator(seq.begin());

	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "begin") {
			p = seq.begin();
		}
		else if (cmd == "end") {
			p = seq.end();
		}
		else if (cmd == "insert") {
			int e;
			cin >> e;
			seq.insert(p, e);
		}
		else if (cmd == "erase") {
			seq.erase(p);
		}
		else if (cmd == "++") {
			++p;
		}
		else if (cmd == "--") {
			--p;
		}
		else if (cmd == "print") {
			seq.print();
		}
		else if (cmd == "find") {
			int e;
			cin >> e;
			seq.find(e);
		}
	}

}