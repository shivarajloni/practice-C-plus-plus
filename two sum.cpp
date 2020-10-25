// Implementing the O(nlogn) Solution:

/*
	struct pair{
		int first;
		int ssecond;
	};
*/


 class Solution {
 public:
 	vector<int> twoSum(vector<int>& nums, int target) {
 		//Sort all the numbers
 		// i=0, j=n-1
 		// if (nums[i]+nums[j]==target) return (i,j)
 		// if (nums[i]+nums[j]>target) --j
 		// if(num[i]+num[j]<target)++i
		// pair<int, int> p;
		// p.first -> int p.second -> int
		// pair<int, int> nums[i], i

		vector< pair<int, int> > nums2;
		 for(int i=0; i<nums.size(); ++i){
		 	pair<int, int> temp(nums[i], i);
		 	nums2.push_back(temp);
		 }

		 // Sort nums2
		 sort(nums2.begin(), nums2.end());

		 //i=0; j=n-1
		 int i=0;
		 int j = nums2.size()-1;
		 while(i<j){
		 	if (nums[i].first + nums2[j] == target){
		 		vector<int> t(nums2[i].second, nums2[j].second);
		 		return t;
		 	}
		 	else if (nums2[i].first + nums2[j].first > target){
		 		--j;
		 	}
		 	else{
		 		++i;
		 	}
		 }
 	}  
 };