class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int result = INT_MAX;

        while(r < n)
        {
            sum += nums[r];
            while(sum >= target)
            {
                result = min(result, r-l+1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return result == INT_MAX ? 0: result;
    }
};