#include<iostream>
#include<string>

using namespace std;

// function to find length of longest common subsequence of 
// sequences X[0..-1] and Y[0..Y-1]
int LCSLength(string X, string Y, int m, int n)
{
    // return if we have reached the end of either sequence
    if(m == 0 || n == 0)
        return 0;
    
    // if last character of X and Y matches
    if(X[m-1] == Y[n-1])
        return LCSLength(X, Y, m-1, n-1) + 1;

    // else if last character of X and Y don't match
    return max(LCSLength(X, Y, m, n-1), LCSLength(X, Y, m-1, n));
}

int main()
{
    string X = "ABCBDAB", Y = "BDCABA";

    cout << "The length of LCS is "<<
            LCSLength(X, Y, X.length(), Y.length());
    return 0;
}