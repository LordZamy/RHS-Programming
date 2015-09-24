#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

vector< vector<int> > triangle;

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

    // start from second to last row and add maximum of the two numbers under it to it
    for(int i = triangle.size() - 2; i >= 0; i--) {
        for(int j = 0; j < triangle[i].size(); j++) {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    // output first element in triangle
    cout << triangle[0][0] << "\n";

    return 0;
}
