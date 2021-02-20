#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int BFS(string str) {
    map<string, int> myMap;
    queue<string> sequence;
    sequence.push(str);
    myMap[str] = 0;
    int answer = -1;
    while (!sequence.empty()) {
        string current = sequence.front();
        sequence.pop();
        if (current.find("2012") != -1) {
            answer = myMap[current];
            break;
        }
        for (int i = 0; i < current.size() - 1; i++) {
            string newStr = current;
            swap(newStr[i], newStr[i + 1]);
            if (myMap.count(newStr) == 0) {
                sequence.push(newStr);
                myMap[newStr] = myMap[current] + 1;
            }
        }
    }
    return answer;
}

int main() {
    int n;
    while (cin >> n) {
        string str;
        cin >> str;
        cout << BFS(str) << endl;
    }
    return 0;
}
