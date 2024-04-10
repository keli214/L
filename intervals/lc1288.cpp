#include <vector>
#include <iostream>
#include <set>

using namespace std;
/*
    sort the intervals by the start time
    for each interval, check the intervals with a bigger start time to see if it can cover them
    if an interval can be covered, the one cover it will cover all the intervals it can cover too
    remove covered intervals 
*/
int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const auto a, const auto b){
        if(a[0]==b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    });
    int prev = 0, res = 0;
    for(auto p: intervals){
        if(p[1] > prev){
            res++;
            prev = p[1];
        }
    }
    return res;
}

int main(){
    vector<vector<int>> intervals{{1,4},{3,6}, {2,8}};
    cout<<removeCoveredIntervals(intervals);
}