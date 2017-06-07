#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

// https://www.hackerrank.com/challenges/common-child

// Given two strings a and b of equal length, what's the longest string (S) that can be constructed such that it is a child of both? 
//
// A string x is said to be a child of a string y if x can be formed by deleting 0 or more characters from y. 
//
// For example, ABCD and ABDC has two children with maximum length 3, ABC and ABD. Note that we will not consider ABCD as a common child because C doesn't occur before D in the second string.

// Sample Input #0
//
// HARRY
// SALLY
// Sample Output #0
//
// 2
// The longest possible subset of characters that is possible by deleting zero or more characters from HARRY and SALLY is AY, whose length is 2.

using namespace std;

void print_matrix(std::vector<std::vector<int> > &mat) {
    int n = mat.size();

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cout << mat[i][j] << ' ';
        }
        std::cout << std::endl;
    }

}

int commonChild(string s1, string s2){
    // Complete this function
    int n = s1.size();
    int max = 0;
    std::string common;
    
    std::vector<std::vector<int> > m(n+1);
    std::vector<int> zeros(n+1, 0);
    for(int i = 0; i <= n; ++i) {
        m[i] = zeros;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(s1[j-1] == s2[i-1]){
                if(m[i-1][j] == m[i][j-1] & m[i-1][j] <= m[i-1][j-1]){
                    m[i][j] = std::max(m[i-1][j], m[i][j-1]) + 1;
                    if(m[i][j] > max) {
                        common += s1[j-1];
                        max = m[i][j];
                    }
                } else {
                    m[i][j] = std::max(m[i-1][j], m[i][j-1]);
                }
            } else{
                m[i][j] = std::max(m[i-1][j], m[i][j-1]);
            }
        }
    }
    
    print_matrix(m);
    std::cout << "common child = " << common << std::endl;
    return m[n][n];
}

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int result = commonChild(s1, s2);
    cout << result << endl;
    return 0;
}

