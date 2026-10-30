class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void solve(vector<int>&nums,int target, int index){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(index == nums.size() || target<0){
            return;
        }
        for(int i = index;i<nums.size();i++){
            if(i > index && nums[i]==nums[i-1]) continue;
            if(nums[index] >target) break;
            curr.push_back(nums[i]);
            solve(nums,target - nums[i],i+1);
            curr.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0);
        return ans;
    }
};
