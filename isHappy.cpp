/***********************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-27
Description : leetcode 202. Happy Number 
***********************************************************/
#include <unordered_map>
#include <iostream>

using std::unordered_map;
using std::cout;
using std::endl;

int integerSum(int);

/**
 * Method 1 : 
 * Use the mapping to detect the cycle 
 */
bool isHappy1(int n) {
    //the mapping from number to sum. 
    //If the count more than 1, the process enters the loop.
    unordered_map<int, int> map;
    int sum = n;
    while(sum != 1){
        cout << sum << endl;
        if(map[sum]++ == 1) return false;
        int number = sum;
        sum = 0;
        for(int i = number % 10 ; number != 0; number /= 10, i = number % 10){
            sum += i * i;
        }
    }
    return true;
}

/**
 * Method 2 : 
 * 龟兔赛跑
 */
bool isHappy2(int n) {
    int slow = n, fast = n;
    do{
        slow = integerSum(slow);
        fast = integerSum(fast);
        fast = integerSum(fast);
    }while(slow != fast);
    if(slow == 1) return true;
    return false;
}

int main(){
    int n = 2;
    bool  res = isHappy2(n);
    return 0;
}

/**
 * compute the sum of the digital by bit
 */
int integerSum(int number){
    int sum = 0;
    for(int i = number % 10 ; number != 0; number /= 10, i = number % 10){
        sum += i * i;
    }
    return sum;
}