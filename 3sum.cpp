class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        if(n < 3)
        {
            return ans;
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;            
                
                int left = i+1;
                int right = n-1;
                
               while(left < right)
               {
                 int sum = nums[i]+nums[left]+nums[right];
                    if(sum  < 0)
                        left++;
                    else if(sum >0)
                        right--;
                   else
                   {
                       vector<int> vec;
                       vec.push_back(nums[i]);vec.push_back(nums[left]);vec.push_back(nums[right]);
                       ans.push_back(vec);
                       left++;
                       right--;
                       while(nums[left]== nums[left-1] && left < right)
                            left++;
                       while(nums[right]==nums[right+1] && left < right)
                           right--;
                   }
                   
               }
                    
        }
        return ans;
        
    }
};