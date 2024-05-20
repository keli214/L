#include <vector>
#include <iostream>
#include <queue>
#include <float.h>
using namespace std;

/*
    BF: 1. back tracking to get all possible k number pairs 
    Sort by the ratio of wage/quality
        we can calculate the cost = totalQual * max(wage/quality) in the group 
        using pq to keep k min quality member
*/
double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    vector<vector<double>> pairs;
    for(int i = 0; i < quality.size(); i ++){
        pairs.push_back({double(wage[i])/quality[i], double(quality[i])});
    }
    sort(pairs.begin(), pairs.end());
    priority_queue<int> pq;
    double minCost = DBL_MAX, sumQual = 0;
    for(auto p: pairs){
        pq.push(p[1]);
        sumQual += p[1];
        if(pq.size() > k){
            sumQual -= pq.top();
            pq.pop();
        } 
        if(pq.size() == k)
            minCost = min(minCost, p[0] * sumQual);
    }
    return minCost;
}

int main(){
    vector<int> wage{8,14}, quality{4,5};
    int k = 2;
    cout<<mincostToHireWorkers(quality, wage, k);
}