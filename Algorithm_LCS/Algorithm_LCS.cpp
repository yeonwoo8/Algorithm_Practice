﻿#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int solution(string str1, string str2);


int main()
{
	string str1 = "ABCBDAB";
	string str2 = "BDCAB";

	int result = 0;

	result = solution(str1, str2);

	cout << result;
}

int solution(string str1, string str2)
{
	int m = str1.length();
	int n = str2.length();

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[m][n];
}
