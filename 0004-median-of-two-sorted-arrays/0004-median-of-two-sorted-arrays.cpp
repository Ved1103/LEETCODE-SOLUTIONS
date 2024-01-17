// Brute Force approach O(n+m*log(n+m))
typedef long long ll;
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         ll n = nums1.size();
//         ll m = nums2.size();
//         vector<int> v;

//         for(int i = 0; i < n; i++) {
//             v.push_back(nums1[i]);
//         }
//         for(int i = 0; i < m; i++) {
//             v.push_back(nums2[i]);
//         }

//         sort(v.begin(), v.end());

//         int size = v.size();

//         if (size % 2 == 1) {
//             return static_cast<double>(v[size / 2]);
//         } else {
//             int mid1 = v[size / 2 - 1];
//             int mid2 = v[size / 2];
//             return static_cast<double>((mid1 + mid2) / 2.0);
//         }
//     }
// };
// Binary Search solution using pointers aray partition : O(log(m+n))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2); // Ensure nums1 is the smaller array
        }

        int x = nums1.size();
        int y = nums2.size();

        int low = 0;
        int high = x;

        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;

            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];

            int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            if (maxX <= minY && maxY <= minX) {
                if ((x + y) % 2 == 0) {
                    return (max(maxX, maxY) + min(minX, minY)) / 2.0;
                } else {
                    return max(maxX, maxY);
                }
            } else if (maxX > minY) {
                high = partitionX - 1;
            } else {
                low = partitionX + 1;
            }
        }
        return 0;

    }
};
