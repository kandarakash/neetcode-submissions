class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void solve(vector<int>&nums,int index){
        if(index == nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        solve(nums,index+1);
        curr.pop_back();
        solve(nums,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        solve(nums,0);
        return ans;
    }
};
