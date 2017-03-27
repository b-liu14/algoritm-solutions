class Solution {
public:
	int find_mid(vector<int>& nums, int l, int r)
	{
		if(l == r)
			return r;
		int pos = (r+l)/2;
		if(nums[pos] >= nums[0] && nums[pos+1] < nums[0])
			return pos;
		else if(nums[pos] < nums[0])
			return find_mid(nums, l, pos-1);
		else
			return find_mid(nums, pos+1, r);
	};

	int binary_search(vector<int>& nums, int target, int l, int r)
	{
		if(l > r)
			return -1;

		int mid = (l+r)/2;
		if(nums[mid] == target)
			return mid;
		else if(nums[mid] < target)
			return binary_search(nums, target, mid+1, r);
		else
			return binary_search(nums, target, l, mid-1);
	}

    int search(vector<int>& nums, int target) {
        int mid = find_mid(nums, 0, nums.size()-1);

        if(nums[0] > target)
		{
			if(mid < nums.size()-1)
        		return binary_search(nums, target, mid+1, nums.size()-1);
			else
				return -1;
		}
        else
        	return binary_search(nums, target, 0, mid);
    };
};

// Clever solution from https://discuss.leetcode.com/topic/34491/clever-idea-making-it-simple/2
class Solution {
public:
	int search(vector<int>& nums, int target) {
	    int lo = 0, hi = nums.size() - 1;
	    while (lo <= hi) {
	        int mid = (lo + hi) / 2;

	        int num = (nums[mid] < nums[0]) == (target < nums[0])
	                   ? nums[mid]
	                   : target < nums[0] ? INT_MIN : INT_MAX;

	        if (num < target) {
				lo = mid + 1;
			}
			else if (num > target) {
				hi = hi - 1;
			}
			else {
				return mid;
			}
	    }
	    return -1;
	}
};
