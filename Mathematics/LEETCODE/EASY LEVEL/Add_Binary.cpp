Given two binary strings a and b, return their sum as a binary string.

Example 1:-
Input: a = "11", b = "1"
Output: "100"

Example 2:-
Input: a = "1010", b = "1011"
Output: "10101"

My Approach:-

Step 1:-I will check whether the size of both the strings a and b is same or not.If any of the string will be shorter then i will find the difference 
between the size of string a and string b and append zeroes (size of a - size of b if string a is larger ) times or (size of b - size of a if string b is
larger ) times at the the beginning of shorter string to make both the string equal for further calculations.

step 2:-in step 2,we are creating a vector called carry where we will keep the carry.

step 3:-initially our vector named carry will be empty.now,we will start iterating from the last index of any string between two(string a or string b),
and check for the following conditions:-

    condition 1:-we will check if string a[i]==0 && string b[i]==1 or string a[i]==1 && string b[i]==0,if this  condition will be satisfied then we will 
    check that whether our vector of carry is empty or not,if vector of carry is empty then we will simply put "1" in the resultant string.if vector of 
    carry will not be empty then we will first empty the vector of carry then we will put "0" in the resultant string and then push_back 1 in the carry.

    condition 2:-if condition 1 will not be satisfied then we will check this condition 2.So,we will check if string a[i]==1 && string b[i]==1,if this
    condition will be satisfied then we  will check that whether our vector of carry is empty or not,if vector of carry is empty then we will simply  
    put "0" in the resultant string and push_back 1 in the vector of carry.if vector of carry will not be empty then we will first empty the vector of 
    carry then we will put "1" in the resultant string and then push_back 1 in the carry.

    condition 3:-if condition 2 will not be satisfied then we will check this condition 3.So,we will check if string a[i]==0 && string b[i]==0,if this 
    condition will be satisfied then we  will check that whether our vector of carry is empty or not,if vector of carry is empty then we will simply  put "0" 
    in the resultant string.if vector of carry will not be empty then we will first empty the vector of  carry then we will put "1" in the resultant string.

    above conditions will be checked for each and every index starting from (a.size()-1 or b.size()-1) to index 0.

step 4:-after performing the step 3 we will check if the vector of carry is empty or not,if yes then we will simply reverse the resultant string and 
return that resultant string.but if the vector of carry will not be empty then we will first add "1" at the end of the resultant string then reverse the 
resultant string and then return it.

My naive approached code:-

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        if(a.size()!=b.size()) //this is step 1.
        {
            if(a.size()>b.size())
            {
                int diff=a.size()-b.size();
                for(int i=1;i<=diff;i++)
                {
                    b="0"+b;
                }
            }
            else
            {
                int diff=b.size()-a.size();
                for(int i=1;i<=diff;i++)
                {
                    a="0"+a;
                }
            }
        }
            vector<int>carry; //this is step 2.
            for(int i=a.size() - 1;i>=0;i--)
            {
                if(((a[i]-'0')==0 && (b[i]-'0')==1) || ((a[i]-'0')==1 && (b[i]-'0')==0))//step 3 condition 1
                {
                    if(carry.empty())
                    {
                        res+="1";
                    }
                    else
                    {
                        carry.pop_back();                        
                        res+="0";
                        carry.push_back(1);
                    }
                }
                else if((a[i]-'0')==1 && (a[i]-'0')==1) //step 3 condition 2
                {
                    if(carry.empty())
                    {
                        res+="0";
                        carry.push_back(1);
                    }
                    else
                    {
                        carry.pop_back();
                        res+="1";
                        carry.push_back(1);
                    }
                }
                else
                {
                    if((a[i]-'0')==0 && (a[i]-'0')==0) //step 3 condition 3
                    {
                        if(carry.empty())
                        { 
                            res+="0";
                        }
                        else
                        {
                            carry.pop_back();
                           
                            res+="1";
                        }
                    }
                }
            }
            if(carry.empty()) //step 4
            {
                reverse(res.begin(),res.end());
                return res;
            }
            else //step 4
            {
                res+="1";
                reverse(res.begin(),res.end());
                return res;
            }
        
    }
};
int main()
{
    Solution s1;
    string s=s1.addBinary("1010","1011");
    cout<<s<<endl;
}

