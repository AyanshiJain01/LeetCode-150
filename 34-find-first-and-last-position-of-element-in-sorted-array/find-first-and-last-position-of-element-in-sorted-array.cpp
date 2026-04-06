class Solution {
public:

    int firstOccourance(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size()-1;
        int ans = -1;

        while(start <= end)
        {
            int mid = start+(end - start)/2;
            if(target == nums[mid])
            {
                ans = mid;
                end = mid - 1;
            }
            else if(target > nums[mid])
            {
                start = mid+1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }

    int lastOccourance(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size()-1;
        int ans = -1;

        while(start <= end)
        {
            int mid = start+(end - start)/2;
            if(target == nums[mid])
            {
                ans = mid;
                start= mid+1;
            }
            else if(target > nums[mid])
            {
                start = mid+1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccourance(nums,target);
        int last = lastOccourance(nums,target);

        return {first,last};
    }
};