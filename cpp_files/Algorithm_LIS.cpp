#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(const vector<int> nums)
{
	int n = nums.size();
	vector<int> dp(n, 1);

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	return *max_element(dp.begin(), dp.end());
}

int main()
{
	vector<int> nums = { 1,4,2,3,1,5,7,3 };

	int result = solution(nums);
	cout << result;
}