// Implementation of O(nlogn) solution:


class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		// Step 1: Sort the numbers- nums vector
		sort(nums.begin(), nums.end());   // ascending order O(nlogn)


		// Calculate p1 and p2
		int n = nums.size();
		int p1 = nums[n-1]*nums[n-2]*nums[n-3];
		int p2 = nums[0]*nums[1]*nums[n-1]; 

		// return max of p1 and p2
		return max(p1, p2);

		/*if (p1>p2) return p1;
		else return p2;
		*/
	}
};





class Soltion {
public:
	int maximumProduct(vector<int>& a) {
		int max1=-1001, max2=-1001, max3=-1001, min1=1001, min2=1001;
		for(int i = 0; i<a.size(); ++i) {
			if(a[i]>=max3){
				 //max2 max3 a[i]
				max1 = max2;
				max2 = max3;
				max3 = a[i]; 
			}
			else if (a[i]>=max2) {
				 //max2 a[i] max3
				max1 = max2;
				max2 = a[i];
			}
			else if (a[i]>=max1) {
				//a[i] max2 max3
				max1=a[i];
			}

			if (a[i]<=min1) {
				min2 = min1;
				min1 = a[i];
			}
			else if (a[i]<=min2) {
				// min1 a[i]
				min2 =a[i];
			}
		}

		// calculate p1 and p2
		int p1 = max1 * max2 * max3;
		int p2 = max3 * min1 * min2;

		// return max of p1 and p2
		return max(p1, p2);
	}
};