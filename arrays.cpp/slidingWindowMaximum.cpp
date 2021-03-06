#include <deque>
class Solution {
public:
    //create a double ended queue that will store indexes of array lements that are useful
    //in every window and it will maintain decreasing order of values from front to rear in Qi
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> output={};
        
    int n=nums.size();
    // Create a Double Ended Queue, 
    // Qi that will store indexes 
    // of array elements
    // The queue will store indexes 
    // of useful elements in every 
    // window and it will
    // maintain decreasing order of 
    // values from front to rear in Qi, i.e.,
    // arr[Qi.front[]] to arr[Qi.rear()] 
    // are sorted in decreasing order
    std::deque<int> Qi(k);
 
    /* Process first k (or first window) 
     elements of array */
    int i;
    for (i = 0; i < k; ++i) 
    {
     
        // For every element, the previous
        // smaller elements are useless so
        // remove them from Qi
        while ((!Qi.empty()) && nums[i] >= 
                            nums[Qi.back()])
           
             // Remove from rear
            Qi.pop_back();
 
        // Add new element at rear of queue
        Qi.push_back(i);
    }
 
    // Process rest of the elements, 
    // i.e., from arr[k] to arr[n-1]
    for (; i < n; ++i) 
    {
     
        // The element at the front of 
        // the queue is the largest element of
        // previous window, so print it
        cout << nums[Qi.front()] << " ";
        output.push_back(nums[Qi.front()]);
        // Remove the elements which 
        // are out of this window
        while ((!Qi.empty()) && Qi.front() <= 
                                           i - k)
           
            // Remove from front of queue
            Qi.pop_front(); 
 
        // Remove all elements 
        // smaller than the currently
        // being added element (remove 
        // useless elements)
        while ((!Qi.empty()) && nums[i] >= 
                             nums[Qi.back()])
            Qi.pop_back();
 
        // Add current element at the rear of Qi
        Qi.push_back(i);
    }
 
    // Print the maximum element 
    // of last window
    cout << nums[Qi.front()];
            output.push_back(nums[Qi.front()]);

        
        
     return output;   
        
        
   https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/     
        
        
        
        
    }
};
