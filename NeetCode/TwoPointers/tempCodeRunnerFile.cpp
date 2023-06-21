class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0, e = height.size();
        int maxContent = 0;
        while(s < e){
            int content = (e - s) * min(height[s], height[e]);
            maxContent = max(maxContent, content);

            int move_right =  ((e - 1) - s) * min(height[s], height[e - 1]);
            int move_left =  (e - (s - 1)) * min(height[s - 1], height[e]);

            move_right > move_left ? e-- : s++;

        }
        return maxContent;
    }
};
