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

    // holds maximum possible sum up till (i, j)
    int best[triangle.size()][triangle.size()];

    best[0][0] = triangle[0][0];

    for(int i = 1; i < triangle.size(); i++) {
        for(int j = 0; j < triangle[i].size(); j++) {
            // case for the leftmost element in the row
            // position is (i, 0) and accessing best[i - 1][j - 1] would be invalid
            if(j == 0) {
                best[i][j] = best[i - 1][j] + triangle[i][j];
                continue;
            }
            // case for rightmost element in the row
            // position is (i, j) and accessing best[i - 1][j] would be invalid
            if(j == triangle[i].size() - 1) {
                best[i][j] = best[i - 1][j - 1] + triangle[i][j];
                continue;
            }
            // case for the middle elements
            best[i][j] = triangle[i][j] + max(best[i - 1][j - 1], best[i - 1][j]);
        }
    }

    // output maximum element in the last row
    cout << *max_element(best[triangle.size() - 1], best[triangle.size() - 1] + triangle.size()) << "\n";

    return 0;
}
