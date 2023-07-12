Link to question:- https://leetcode.com/problems/reverse-integer/ 
Question:-Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:-
Input: x = 123
Output: 321

Example 2:-
Input: x = -123
Output: -321

Example 3:-
Input: x = 120
Output: 21

Approach:-

step 1:- There are chances that after reversing,the value of integer can become more than (2 to the power 31  - 1) or the value of integer can become less than (- 2 to the power 31).so,we will store the number inside a variable of long long data type.

step 2:-so,if we get the negative number then we will first convert the negative number into positive number by multiplying that number with -1.

step 3:-after that we will check that whether the value after reversing is more than (2 to the power 31  - 1) or less than (- 2 to the power 31),if any one of these conditions will be satisfied,then i will return 0.
if the value is less than INT_MIN then we can say that the value is less than (- 2 to the power 31) or if the value is more than INT_MAX then we can say that the value is more than (2 to the power 31 - 1).

step 4:-in case no any condition satisfies of step 3,we will simply typecast the reversed long long value to int and return that variable.

code:-

#include<bits/stdc++.h>
using namespace std;
class Solution {                      
public:
    int reverse(int x) {
        long long n=x;//storing given integer number in long long variable.
        int chk=1;
        if(x<0) //checking that whether the value is negative or not.
        {
            n=n* -1; //converting negative number to positive number just for the ease of calculation to reverse the number.

            chk=0;//assigned 0 to chk because we have converted negative number into positive number,so,after some steps,we will check that if the value inside chk is zero or not,if chk will be equals to 0 then we will again convert the reversed positive value into negative because answer must be in negative if the given value is negative.
        }
        long long v=0; //will store reversed value in this variable v.
        while(n>0)
        {
            long long rem=n%10;
            v=v*10 + rem;
            n=n/10;
        }
        if(chk==0) //if chk==0 then we are again changing positive reversed value to negative reversed value as reversed number must be negative in terms of output because input has been negative.
        {
            v=v * -1;  
        }
        if(v<INT_MIN || v>INT_MAX) //check if final reversed value is less than (- 2 to the power 31) or more than (2 to the power 31 - 1),if yes then we will return 0. 
        {
            return 0;
        }
        return (int)v; //changing the final reversed value from long long to int as return type of the function is int.
    }
}; 
int main()
{
    Solution s1;
    int res=s1.reverse(-123);
    cout<<res<<endl;
}