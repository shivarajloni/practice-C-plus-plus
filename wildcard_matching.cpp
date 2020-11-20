#include <stdio.h>
#include <string.h>

#define LEN 20

int lookup[LEN][LEN];

int isMatching(char str[], char pattern[], int n, int m)
{
	if (m < 0 && n < 0)
		return 1;

	else if (m < 0)
		return 0;

	else if (n < 0)
	{
		for (int i = 0; i <= m; i++)
			if (pattern[i] != '*')
				return 0;

		return 1;
	}

	if (lookup[m][n] == -1)
	{
		if (pattern[m] == '*')
		{
			lookup[m][n] = isMatching(str, pattern, n - 1, m) ||
						isMatching(str, pattern, n, m - 1);
		}
		else
		{
			// If the current character is not a wildcard character, it
			// should match with current character in the input string
			if (pattern[m] != '?' && pattern[m] != str[n])
				lookup[m][n] = 0;

			// check if pattern[0..m-1] matches str[0..n-1]
			else
				lookup[m][n] = isMatching(str, pattern, n - 1, m - 1);
		}
	}

	return lookup[m][n];
}

int main(void)
{
	char str[] = "xyxzzxy";
	char pattern[] = "x***x?";

	memset(lookup, -1, sizeof(lookup));

	if (isMatching(str, pattern, strlen(str) - 1, strlen(pattern) - 1))
		printf("Match");
	else
		printf("No Match");

	return 0;
}