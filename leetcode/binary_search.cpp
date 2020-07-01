#include <iostream>
#include <vector>
using namespace std;

// return low bound of val in the sorted array: nums
int my_lower_bound(vector<int>& nums, int val) {
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] < val) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int my_upper_bound(vector<int>& nums, int val) {
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] <= val) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    vector<int> nums{1, 3, 3, 3, 3, 5};
    for (int i = 0; i < 6; i++) {
        cout << "lower bound of " << i << ": "
             << my_lower_bound(nums, i) << " = "
             << lower_bound(nums.begin(), nums.end(), i) - nums.begin() << endl;
    }
    cout << endl;
    for (int i = 0; i < 6; i++) {
        cout << "upper bound of " << i << ": "
             << my_upper_bound(nums, i) << " = "
             << upper_bound(nums.begin(), nums.end(), i) - nums.begin() << endl;
    }
}