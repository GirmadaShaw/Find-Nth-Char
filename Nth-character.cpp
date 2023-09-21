/*
Given a decimal number m, convert it into a binary string and apply n iterations, 
in each iteration 0 becomes “01” and 1 becomes “10”.
 Find ith(based indexing) index character in the string after nth iteration.

 Input: m = 5 i = 5 n = 3
Output: 1
Explanation
In the first case m = 5, i = 5, n = 3. 
Initially, the string is  101  ( binary equivalent of 5 )
After 1st iteration -   100110
After 2nd iteration - 100101101001
After 3rd iteration -   100101100110100110010110 
The character at index 5 is 1, so 1 is the answer

Input: m = 11 i = 6 n = 4
Output: 1
*/

// C++ program to find i’th Index character
// in a binary string obtained after n iterations
#include <bits/stdc++.h>
using namespace std;

// Function to find the i-th character
void KthCharacter(int m, int n, int k)
{
	// distance between two consecutive
	// elements after N iterations
	int distance = pow(2, n);
	int Block_number = k / distance;
	int remaining = k % distance;

	int s[32], x = 0;

	// binary representation of M
	for (; m > 0; x++) {
		s[x] = m % 2;
		m = m / 2;
	}

	// kth digit will be derived from root for sure
	int root = s[x - 1 - Block_number];

	if (remaining == 0) {
		cout << root << endl;
		return;
	}

	// Check whether there is need to
	// flip root or not
	bool flip = true;
	while (remaining > 1) {
		if (remaining & 1) {
			flip = !flip;
		}
		remaining = remaining >> 1;
	}

	if (flip) {
		cout << !root << endl;
	}
	else {
		cout << root << endl;
	}
}

// Driver Code
int main()
{
	int m = 5, k = 5, n = 3;
	KthCharacter(m, n, k);
	return 0;
}
