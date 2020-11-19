// C++ dynamic programming solution for longest palindrome in a sub-string

#include <bits/stdc++.h> 

using namespace std; 

void printSubStr( 
	string str, int low, int high) 
{ 
	for (int i = low; i <= high; ++i) 
		cout << str[i]; 
} 

int longestPalSubstr(string str) 
{ 
	int n = str.size(); 

	bool table[n][n]; 

	memset(table, 0, sizeof(table)); 

	// All substrings of length 1 are palindromes 
	int maxLength = 1; 

	for (int i = 0; i < n; ++i) 
		table[i][i] = true; 

	// check for sub-string of length 2. 
	int start = 0; 
	for (int i = 0; i < n - 1; ++i) { 
		if (str[i] == str[i + 1]) { 
			table[i][i + 1] = true; 
			start = i; 
			maxLength = 2; 
		} 
	} 

	// Check for lengths greater than 2. k is length of substring 
	for (int k = 3; k <= n; ++k) { 
		for (int i = 0; i < n - k + 1; ++i) { 
			int j = i + k - 1; 
			// jth index iff str[i+1] to str[j-1] is a palindrome 
			if (table[i + 1][j - 1] && str[i] == str[j]) { 
				table[i][j] = true; 

				if (k > maxLength) { 
					start = i; 
					maxLength = k; 
				} 
			} 
		} 
	} 

	cout << "Longest palindrome substring is: "; 
	printSubStr(str, start, start + maxLength - 1); 

	return maxLength; 
} 

int main() 
{ 
	string str = "forgeeksskeegfor"; 
	cout << "\nLength is: "
		<< longestPalSubstr(str); 
	return 0; 
} 
