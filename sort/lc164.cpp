#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
    Find the max and min of the nums, split the elements in nums into 
    n-1 buckets. The max gap is (max-min)/(n-1)
    Using bucket sort to divide the nums into n-1 buckets, and store the max
    and min elements in each bucket, the max gap is 
*/

int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    int n = nums.size(),
        maxE = *max_element(nums.begin(), nums.end()), 
        minE = *min_element(nums.begin(), nums.end()),
        gap = (maxE-minE)/(n-1);
    vector<pair<int,int>> buckets_min_max(n-1, pair<int,int>(INT_MAX, INT_MIN));
    for(int i = 0; i < n; i++){
        int idx = (nums[i]-minE)/gap;
        if(idx > n-2){
            idx = n-2;
        }
        if(buckets_min_max[idx].first > nums[i])
            buckets_min_max[idx].first = nums[i];
        if(buckets_min_max[idx].second < nums[i])
            buckets_min_max[idx].second = nums[i];    
    }
    int maxGap = INT_MIN, prev = minE;
    for(int i = 0; i < n-1; i++){
        if(buckets_min_max[i].first == INT_MAX)
            continue;
        maxGap = max(maxGap, buckets_min_max[i].first-prev);
        prev = buckets_min_max[i].second;
    }

    return maxGap;
}

int main(){
    vector<int> nums {12115,10639,2351,29639,31300,11245,16323,24899,8043,4076,17583,15872,19443,12887,5286,6836,31052,25648,17584,24599,13787,24727,12414,5098,26096,23020,25338,28472,4345,25144,27939,10716,3830,13001,7960,8003,10797,5917,22386,12403,2335,32514,23767,1868,29882,31738,30157,7950,20176,11748,13003,13852,19656,25305,7830,3328,19092,28245,18635,5806,18915,31639,24247,32269,29079,24394,18031,9395,8569,11364,28701,32496,28203,4175,20889,28943,6495,14919,16441,4568,23111,20995,7401,30298,2636,16791,1662,27367,2563,22169,1607,15711,29277,32386,27365,31922,26142,8792};
    cout<<maximumGap(nums);
}