#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::min;

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

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){
    vector<Interval> res;
    auto it = intervals.begin();
    for(; it != intervals.end(); it++){
        if((*it).start > newInterval.end) break;
        else if((*it).end < newInterval.start) res.push_back(*it);
        else {
            newInterval.start = min((*it).start, newInterval.start);
            newInterval.end = max((*it).end, newInterval.end);
        }
    }

    res.push_back(newInterval);

    while(it != intervals.end()){
        res.push_back(*it);
        it++;
    }
    return res;
}

int main(){
    vector<Interval> test = {Interval(1,3), Interval(6,9)};
    Interval newInterval(2,5);
    vector<Interval> results = insert(test, newInterval);
    for(auto i : results){
        i.printInfo();
    }
    return 0;
}