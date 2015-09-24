#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

vector< vector<int> > triangle;

int maxSum = 0;

// check every possible route
void recurse(int i, int j, int sum) {
    if(i == triangle.size() - 1) {
        maxSum = max(maxSum, sum + triangle[i][j]);
        return;
    }

    recurse(i + 1, j, sum + triangle[i][j]);
    recurse(i + 1, j + 1, sum + triangle[i][j]);
}

int main() {
    // read in values from triangle into array
    int num;
    int count = 1;
    while(scanf("%d", &num) == 1) {
        vector<int> line;
        line.push_back(num);
        for(int i = 0; i < count - 1; i++) {
            scanf("%d", &num);
            line.push_back(num);
        }
        triangle.push_back(line);
        count++;
    }

    recurse(0, 0, 0);

    cout << maxSum << "\n";

    return 0;
}
