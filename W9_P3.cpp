#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
    vector<int>v;
public:
    void push(int e) {
        v.push_back(e);
    }

    int pop() {
        auto p = v.begin();
        for (auto i = v.begin(); i != v.end(); i++) {
            if (*p > *i) {
                p = i;
            }
        }
        int maxValue = *p;
        v.erase(p);
        return maxValue;
    }

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> v;
        PriorityQueue pq;

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            v.push_back(num);
        }

        for (int i = 0; i < n; i++) {
            pq.push(v.front());
            v.erase(v.begin());
        }

        for (int i = 0; i < n; i++) {
            v.push_back(pq.pop());
        }

        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}