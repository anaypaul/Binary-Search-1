/**
// Time Complexity : O(log n), where n is the probable index of the target. 
// Space Complexity : O(1)
// Did this code successfully run on Leetcode : yes
// Any problem you faced while coding this : no



 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int low = 0;
        int high = 1;
        while(reader.get(high) < target) {
            low = high;
            high= 2 * high;
        }
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(reader.get(mid) == target) {
                return mid;
            }else if(reader.get(mid) > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};