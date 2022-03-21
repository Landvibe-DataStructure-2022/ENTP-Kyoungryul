//#include <iostream>
//#include <string>
//using namespace std;
//
//int n, t;
//
//class stack {
//private:
//	int arr[10];
//	int arrsize;
//public:
//	stack() {
//		arrsize = 0;
//
//	}
//
//	bool empty() {
//		if (arrsize == 0) {
//			return 1;
//		}
//		else
//			return 0;
//	}
//
//	void top() {
//		if (empty()) {
//			cout << "-1" << '\n';
//		}
//		else 
//		cout << arr[arrsize-1] << '\n';
//	}
//
//	void push(int x) {
//		if (arrsize == t) {
//			cout << "full" << '\n';
//		}
//		else {
//			arr[arrsize] = x;
//			arrsize++;
//		}
//	}
//
//	void pop() {
//		if (empty())
//			cout << "-1" << '\n';
//		else {
//			top();
//			arrsize--;
//		}
//	}
//	
//
//};
//
//int main() {
//	cin >> t >> n;
//	stack st;
//	for (int i = 0; i < n; i++) {
//		string s;
//		cin >> s;
//		if (s == "empty") {
//			cout << st.empty() << '\n';
//		}
//		else if (s == "top") {
//			st.top();
//		}
//		else if (s == "push") {
//			int n;
//			cin >> n;
//			st.push(n);
//		}
//		else if (s == "pop") {
//			st.pop();
//		}
//			
//		
//	}
//}