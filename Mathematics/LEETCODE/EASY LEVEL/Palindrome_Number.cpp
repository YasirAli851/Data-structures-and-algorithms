link to the question:- https://leetcode.com/problems/palindrome-number/
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:-
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:-
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:-
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

My Approach:-

Step 1:-I have created a string variable (s) where i have stored the number X in the form of string inside string variable (s).

Step 2:-I have created another string variable (s1) where i have stored the string (s) and reversed the string (s1).

Step 3:-Now,i have created a varibale named cnt and initialized 0 to it.Now i am traversing from index 0 to s.size() - 1 and checking if the value at each index of string s1 and s is equal or not.If they are equal then we will increment the value of cnt by 1.

step 4:-Now if the value of cnt will be equal to s.size() then we can say that both the string s1 and s are equal while traversing from left to right and right to left and then we will return true else we will return false if cnt will not be equal to s.size().

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x); //step 1
        string s1=s; //step 2
        reverse(s1.begin(),s1.end()); //step 2
        int cnt=0; //step 3
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==s1[i]) //step 3
            {
                cnt++; 
            }
        }
        if(cnt==s.size()) //step 4
        {
            return true;
        }
        else //step 4
        {
            return false;
        }
        
    }
};
int main()
{
    Solution s;
    bool res=s.isPalindrome(-121);
    if(res)
    {
        cout<<"Palindrome "<<endl;
    }
    else
    {
        cout<<"Not palindrome "<<endl;
    }
}