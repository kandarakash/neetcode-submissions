class Solution {
public:
    vector<vector<int>> ans;
    vector<int>curr;
    void solve(vector<int>&nums,int target, int index){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(index == nums.size() || target <0){
            return;
        }
        curr.push_back(nums[index]);
        solve(nums,target-nums[index],index);
        curr.pop_back();
        solve(nums,target,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(nums,target,0);
        return ans;
    }
};
