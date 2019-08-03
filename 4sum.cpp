class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> output;
        
        if(nums.size() <4)
            return output;
        if(target == 0 )
        {
            int count=0;
           for(int i=0;i<nums.size();i++)
           {
               if(nums[i]==0)
                   count++;
           }
            if(count==nums.size())
            {
                vector<int> v(nums.size(),0);
                output.push_back(v);
                return output;
            }
            
        }
      

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-3;i++)
        {
            if(i>0 && nums[i] == nums[i-1]) 
                continue;
            for(int j=i+1;j<nums.size()-2;j++)
            {
                if(j>0 && nums[j] == nums[j-1]) 
                    continue;
                int left = j+1;
                int right = nums.size()-1;
                while(left < right)
                {
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum < target)
                        left++;
                    else if(sum > target)
                        right--;
                    else
                    {
                        vector<int> vec;
                        vec.push_back(nums[i]);vec.push_back(nums[j]);
                        vec.push_back(nums[left]);vec.push_back(nums[right]);left++;right--;
                        output.push_back(vec);
                        while(left < right && nums[left] == nums[left-1])
                            left++;
                        while(left < right && nums[right] == nums[right+1])
                            right--;
                    }
                    
                }
                
            }
        }

        return output; 
    }
};