#include <vector>

using std::vector, std::swap;

void wiggleSort(vector<int>& nums) {
    // find the median and put all the num less than median before it
    // and all the num greater than median after it but not in specific order
    int n = nums.size();
    vector<int>::iterator nth = next(nums.begin(), n/2);
    nth_element(nums.begin(), nth, nums.end());
    
    int median = *nth;

    auto m = [n](int i) {
        //n | 1  if n is even -> n + 1 else n
        //0 1 2 3 4 -- m --> 1 3 0 2 4
        return (1 + 2*i) % (n | 1);
    };
    //first: first odd pos, last: last even pos
    int first = 0, mid = 0, last = n-1;
    while(mid <= last){
        //put num > median in first odd pos
        if(nums[m(mid)] > median){
            swap(nums[m(mid)], nums[m(first)]);
            ++first;
            ++mid;
        //put num < median in last even pos
        }else if(nums[m(mid)] < median){
            swap(nums[m(mid)], nums[m(last)]);
            --last;
        //put median in remaining pos
        }else{
            ++mid;
        }
    }       
}