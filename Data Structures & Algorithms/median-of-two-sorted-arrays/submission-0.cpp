class Solution { 
public: 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 

        if (nums1.size() > nums2.size()) { 
            // nums1 should be the smaller array
            return findMedianSortedArrays(nums2, nums1); 
        } 
 
        int m = nums1.size(); 
        int n = nums2.size(); 
 
        int half = (m + n + 1) / 2; 
 
        int start = 0; 
        int end = m; 
 
        while (start <= end) { 

            int partitionA = start + (end - start) / 2; 
            int partitionB = half - partitionA; 
 
            int leftA = (partitionA != 0) 
                        ? nums1[partitionA - 1] 
                        : INT_MIN; 

            int leftB = (partitionB != 0) 
                        ? nums2[partitionB - 1] 
                        : INT_MIN; 

            int rightA = (partitionA == m) 
                         ? INT_MAX 
                         : nums1[partitionA]; 

            int rightB = (partitionB == n) 
                         ? INT_MAX 
                         : nums2[partitionB]; 
 
            // Correct partition
            if (leftA <= rightB && leftB <= rightA) { 

                if ((m + n) % 2 == 0) { 
                    // Even
                    return (max(leftA, leftB) + 
                            min(rightA, rightB)) / 2.0; 
                } 
                else { 
                    // Odd
                    return max(leftA, leftB); 
                } 
            } 
            
            else if (leftA > rightB) { 
                // Too many elements from A on the left
                end = partitionA - 1; 
            } 
            else { 
                // Too few elements from A on the left
                start = partitionA + 1; 
            } 
        } 
 
        return 0.0; 
    } 
};