class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        vector<int> factor = {2, 3, 5};
        pq.push(1);
        int count = 1;
        while (count < n) {
            int top = pq.top();
            while (!pq.empty() && pq.top() == top) {
                pq.pop();
            }
            for (auto i: factor) {
                pq.push((long long)i*top);
            }
            count ++;
        }
        return pq.top();
    }
};
