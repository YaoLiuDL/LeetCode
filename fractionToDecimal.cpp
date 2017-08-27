/*******************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-24
Desctiption : leetcode 166. Fraction to Recurring Decimal 
*******************************************************/

#include <string>

using std::string;

/**
 * get the string answer by given numerator and denominator
 */
string fractionToDecimal(int numerator, int denominator) {
    string res;

    // if numerator is zero, return "0"
    if(numerator == 0) return "0";

    // determine the sign of the string answer
    if((numerator > 0 && denominator < 0) || 
        numerator < 0 && denominator > 0) res += "-";

    

    
}