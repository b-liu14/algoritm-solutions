// O(N^3) time exceeded
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        for (int i = 0; i < A.size(); i ++) {
            for (int j = 0; j < B.size(); j ++) {
                int left = 0;
                int right = (int)D.size() - 1;
                int curTarget = 0 - A[i] - B[j];
                while (left < C.size() && right >= 0) {
                    int sum = C[left] + D[right];
                    if (sum < curTarget) {
                        left ++;
                    }
                    else if (sum > curTarget) {
                        right --;
                    }
                    else {
                        int l = left + 1;
                        int r = right - 1;
                        while (l < C.size() && C[l] == C[left]) {
                            l ++;
                        }
                        while (r >= 0 && D[r] == D[right]) {
                            r --;
                        }
                        ans += (l - left) * (right - r);
                        left = l;
                        right = r;
                    }
                }
            }
        }
        return ans;
    }
};

// O(N^2) 4 -> 2 -> 1
class Solution {
public:
    vector<int> sorted_sum(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sum;
        for (auto n1: nums1) {
            for (auto n2: nums2) {
                sum.push_back(n1+n2);
            }
        }
        sort(sum.begin(), sum.end());
        return sum;
    }
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        vector<int> sum1 = sorted_sum(A, B);
        vector<int> sum2 = sorted_sum(C, D);
        int left = 0;
        int right = (int)sum2.size() - 1;
        int curTarget = 0;
        while (left < sum1.size() && right >= 0) {
            int sum = sum1[left] + sum2[right];
            if (sum < curTarget) {
                left ++;
            }
            else if (sum > curTarget) {
                right --;
            }
            else {
                int l = left + 1;
                int r = right - 1;
                while (l < sum1.size() && sum1[l] == sum1[left]) {
                    l ++;
                }
                while (r >= 0 && sum2[r] == sum2[right]) {
                    r --;
                }
                ans += (l - left) * (right - r);
                left = l;
                right = r;
            }
        }
        return ans;
    }
};
