class Solution {
public: 	
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int max_l = 0;
		int  n = nums.size();
		int i = 0;
		while(i<n) {
			if(nums[i] == 1){
				int current_len = 1;
				int r = i + 1;
				while(r<n && nums[r]==1) {
					++r;
					++current_len;
				}

				// very IMPORTANT LINE:
				 // [1,1,1,1,1,1,1,0,1]
				i=r;
				// max() => if (max_l < current_len)max_l = current_len
				max_l = max(max_l, current_len);
			}
			else{
				++i;
			}
		} 
		return max_l;
	}
};