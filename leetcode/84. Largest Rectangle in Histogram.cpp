class Solution {
public:
   int largestRectangleArea(vector<int>& height) {
 		height.push_back(0);
 		stack<int> s;
 		int ans = 0;
 		for(int i = 0; i < height.size(); i ++) {
 			while(! s.empty() && height[i] < height[s.top()]) {
 				int index = s.top();
 				s.pop();
 				int indexLeft = s.empty()?-1:s.top();
				ans = max(ans, height[index]*(i-1-indexLeft));
 			};
 			s.push(i);
 		};
 		return ans;
   };
};
