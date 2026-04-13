class Solution {
public:
    
    int max(vector<int>& nums){
        int n = nums.size();
        int maxval = nums[0];

       for(int i = 0;i<n;i++){
        if(nums[i] > maxval){
            maxval = nums[i];
        }
       }
       return maxval;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int left = max(nums); //largest element in nums
        int right = 0; //entire nums sum
        int mid = 0;

        for(int i = 0;i<n;i++){
            right += nums[i];
        }
         
         while(left < right){
            mid = left + (right - left)/2; // mid is maximum allowed subarray sum

            int currentsum = 0;
            int count = 1;

            for(int i = 0; i < n; i++){
                if(currentsum + nums[i] <= mid){
                currentsum += nums[i];
                }    
             
             else { // split the array
               count++;
            currentsum = nums[i];
                  }
            } 

            if(count <= k){ // valid mid but we can try for smaller value 
                right = mid;
            }
            else{ 
                left = mid + 1;
            }
            
         }
         return left; // smallest value that satisfies the condition

    }
};
