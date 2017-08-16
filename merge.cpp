#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::max;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
    void printInfo(){ 
        cout << "[" << start << "," << end << "]" << endl;
    }
};

vector<Interval> merge(vector<Interval>& intervals) {
    if(intervals.empty()) return intervals;
    sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
    vector<Interval> res = {intervals[0]};
    for(int i = 0; i < intervals.size(); i++){
        if(intervals[i].start <= res.back().end) 
            res.back().end = max(intervals[i].end, res.back().end);
        else
            res.push_back(intervals[i]);
    }
    return res;
}

int main(){
    vector<Interval> test = {Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18)};
    vector<Interval> results = merge(test);
    for(auto i : results){
        i.printInfo();
    }
    return 0;
}

