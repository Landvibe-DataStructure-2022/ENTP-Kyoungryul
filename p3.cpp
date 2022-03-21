//#include <iostream>
//#include <string>
//using namespace std;
//
//class Node {
//private:
//	int value;
//	Node* next;
//public:
//	Node() {
//		this->value = 0;
//		this->next = nullptr;
//	}
//	friend class LinkedList;
//	friend class Stack;
//};
//
//class LinkedList {
//private:
//	Node* head;
//	Node* tail;
//	int size;
//public:
//	LinkedList() {
//		size = 0; 
//		head = NULL;
//		tail = NULL;
//	}
//
//	bool empty() {
//		if (this->size == 0)
//			return 1;
//		else
//			return 0;
//	}
//	void append(int x) {
//
//		Node* NewNode = new Node;
//		NewNode->value = x;
//		if (empty())
//			this->head = this->tail = NewNode;
//		else {
//			this->tail->next = NewNode;
//			this->tail = NewNode;
//		}
//		this->size++;
//	}
//
//	int deleteNode() {
//		int value = this->tail->value;
//
//		if (this->size == 1) {
//			delete this->head;
//			this->head = this->tail = nullptr;
//		}
//		else {
//			Node* curNode = this->head;
//			while (curNode->next != this->tail) {
//				curNode = curNode->next;
//			}
//			delete curNode->next;
//			curNode->next = nullptr;
//			this->tail = curNode;
//		}
//		this->size--;
//
//		return value;
//	}
//
//
//	friend class Stack;
//
//};
//
//class Stack {
//private:
//	LinkedList ll;
//	int size;
//
//public:
//	Stack() {
//		ll = LinkedList();
//		size = 0;
//	}
//	
//	bool empty() {
//		if (this->size == 0) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	void top() {
//		if (empty()) {
//			cout << "-1\n";
//		}
//		else {
//			cout << ll.tail->value << "\n";
//		}
//	}
//
//	void push(int x) {
//		ll.append(x);
//		this->size++;
//	}
//
//	void pop() {
//		if (empty()) {
//			cout << "-1\n";
//		}
//		else {
//			cout << ll.deleteNode() << "\n";
//			this->size--;
//		}
//	}
//};
//
//int main() {
//	int n;
//	cin >> n;
//	Stack st;
//	while (n--)
//	{
//		string s;
//		cin >> s;
//		if (s == "empty") {
//			cout << st.empty() << '\n';
//		}			
//		else if (s == "top")
//			st.top();
//		else if (s == "push") {
//			int N;
//			cin >> N;
//			st.push(N);
//		}
//		else if (s == "pop") {
//			st.pop();
//		}
//	}
//}