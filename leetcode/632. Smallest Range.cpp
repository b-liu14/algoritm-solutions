
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> data;   // first: number, second: the list the num comes from
        vector<int> hascover(nums.size(), 0);  // num of elements from each list in current range
        vector<int> result;

        for (int i=0; i<nums.size(); i++) {
            for (int each: nums[i]) {
                data.push_back({each, i});
            }
        }
        sort(data.begin(), data.end());

        int minindex = 0;
        int mindiff = INT_MAX;
        int count = nums.size();  // nums of lists are in the range, 0 means all

        for (int i=0; i<data.size(); i++) {
            if (hascover[data[i].second] == 0) count--;
            hascover[data[i].second]++;

            while (count==0 && minindex <= i) {
                int minnum = data[minindex].first;
                int maxnum = data[i].first;
                if (maxnum - minnum < mindiff) {
                    mindiff = maxnum - minnum;
                    result.clear();
                    result.push_back(minnum);
                    result.push_back(maxnum);
                }
                hascover[data[minindex].second]--;
                if (hascover[data[minindex].second] == 0) count++;
                minindex++;
            }
        }
        return result;
    }

};
