#include <iostream>
using namespace std;

class Node {
private:
	Node* next;
	Node* prev;

	int value;
public:
	Node() {
		next = nullptr;
		prev = nullptr;
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
	Iterator(Node* n) {
		node = n;
	}

	Iterator* operator++() {
		node = node->next;
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

	void insert(Iterator&p,int e) {
		Node* newNode = new Node(e);
		p.node->prev->next = newNode;
		newNode->prev = p.node->prev;
		p.node->prev = newNode;
		newNode->next = p.node;

		size++;
	}

	Node* begin() {
		return head->next;
	}

	void findMax(Iterator& p) {
		if (p.node->prev == head) {
			int num1 = 0;
			int num2 = p.node->value;
			int num3 = p.node->next->value;

			cout << max(num1, max(num2, num3))<<" ";
		}
		else if (p.node->next == tail) {
			int num1 = 0;
			int num2 = p.node->value;
			int num3 = p.node->prev->value;

			cout << max(num1, max(num2, num3)) << " ";
		}
		else {
			int num1 = p.node->next->value;
			int num2 = p.node->value;
			int num3 = p.node->prev->value;

			cout << max(num1, max(num2, num3)) << " ";
		}
	}
};

int main() {
	int t, n;
	cin >> t;

	while (t--) {
		Sequence seq = Sequence();
		Iterator p = Iterator(seq.begin());

		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;

			seq.insert(p, num);
		}

		p = seq.begin();

		for (int i = 0; i < n; i++) {
			seq.findMax(p);
			++p;
		}
		cout << "\n";
	}

	return 0;
}
