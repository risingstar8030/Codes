class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int index = searchNo(nums , 0 , n-1,target);
        return index;
    }
    
    int searchNo(vector<int>& nums , int l , int h , int key)
    {
        if(l > h)
            return -1;
        
        int mid = (l+h)/2;
        if(key == nums[mid])
            return mid;
        
        if(nums[l]<=nums[mid]) // elements in [l..mid] are sorted
        {
            if(key>=nums[l] && key<=nums[mid])
            {
                return searchNo(nums , l, mid-1,key);
            }
            return searchNo(nums , mid+1, h,key);
        }
        
        if(key>=nums[mid] && key<=nums[h]) // elements in [mid..h] are sorted
        {
            return searchNo(nums , mid+1, h,key);
        }
        
        return searchNo(nums , l, mid-1,key);
    }
};
