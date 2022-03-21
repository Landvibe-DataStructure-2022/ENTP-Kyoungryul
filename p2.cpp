#include <iostream>
#include <string>
using namespace std;

int n, t;

class stack {
private:
	int arr[100]{};
	int arrsize;
public:
	stack() {
		arrsize = 0;
	}

	bool empty() {
		if (arrsize == 0) {
			return 1;
		}
		else
			return 0;
	}

	int top() {
			return arr[arrsize - 1];
	}

	void push(int x) {
		

			arr[arrsize] = x;
			arrsize++;
		
	}

	void pop() {
			arrsize--;	
	}


};

int main() {
	int n;
	cin >> n;
		while (n--) {
			string s;
			stack st=stack();
			cin >> s;

			for (int i = 0; i < s.length(); i++) {
				if (s[i]  >= 48 && s[i] <= 57) {
					st.push(s[i] - '0');
				}
				else {
					int num2 = st.top();
					st.pop();
					int num1 = st.top();
					st.pop();
					if (s[i] == '+') {
						st.push((num1 + num2));
					}
					else if (s[i] == '-') {
						st.push((num1 - num2));
					}
					else if (s[i] == '*') {
						st.push((num1 * num2));
					}
				}
			}
			cout << st.top() << "\n";
		}




}