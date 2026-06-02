class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            maxSum = max(nums[i], nums[i]+maxSum);
            result = max(result, maxSum);
        }
        return result;
    }
};