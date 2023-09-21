Link to the question:- https://leetcode.com/problems/add-binary/
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

Lets have a look on the optimised code of this questions:-
So,we will basically use modulo(%) for remainder and division(/) for quotient to make our work easy.

Now,lets have a look on the approach step by step:-
Step 1:-I will check whether the size of both the strings a and b is same or not.If any of the string will be shorter then i will find the difference 
between the size of string a and string b and append zeroes (size of a - size of b if string a is larger ) times or (size of b - size of a if string b is
larger ) times at the the beginning of shorter string to make both the string equal for further calculations.

step 2:-we will create a carry variable and initialise 0 to it initially.

step 3:-we will keep one iterator = i and start iterating from the index (string.size() - 1) and will do the addition of string_1[i] + string_2[i]+carry and store it in a variable "add".

    step 3.1:-after step 3 we will do the add%2 and store the remainder at the end of the resultant array in the form of string.
    step 3.2:-after step 3.1 , we will do add/2 and store the quotient in the variable carry.

Note:-step 3 , 3.1 and 3.2 will be done for all the elements from index string.size() -1 to index 0.  

step 4:-once the step 3, 3.1 and 3.2 is done for all the element of the strings.we will check if the value inside our carry is 1 or not.if 1 will be there inside carry then we will append 1 at the end of the resultant string and reverse the string and return it.but if 1 will not be there at the end in the variable carry then we will just reverse the resultant string and return it.

lets have a look on the code of this optimised solution:-

class Solution {
public:
    string addBinary(string s1, string s2) {
        if(s1.size()!=s2.size()) //step 1
        {
            if(s1.size()>s2.size())
            {
                int diff=s1.size()-s2.size();
                for(int i=1;i<=diff;i++)
                {
                    s2="0"+s2;
                }
            }
            else
            {
                int diff=s2.size()-s1.size();
                for(int i=1;i<=diff;i++)
                {
                    s1="0"+s1;
                }
            }
        }
        int carry=0; //step 2
        string result;
        for(int i=s1.size()-1;i>=0;i--) //step 3.
        {
            int quo = (carry + s1[i] - '0' + s2[i]-'0') / 2; //step 3.2
            int rem= (carry + s1[i] - '0' + s2[i]-'0') % 2;  //step 3.1
            result+=to_string(rem); //step 3.1
            carry=quo; //step 3.2
        }
        if(carry==1) //step 4
        {
            result+="1";
            reverse(result.begin(),result.end());
            return result;
        }
        else //step 4
        {
            reverse(result.begin(),result.end());
            return result;
        }
    }
};


Lets do the dry run of this code:-

s1 = "1010"
s2 = "1011"

ITERATION  1:-
result=""
carry=0
i=3(string.size()-1).

s1[3]=0 and s2[3]=1 and carry = 0.

add= (s1[3]=0) + (s2[3] = 1) + (carry = 0),add=1.
add % 2 , i.e 1 % 2 = 1, so result="1".
add / 2 , i.e 1 / 2 = 0, so carry=0.

ITERATION  2:-
result="1"
carry=0
i=2

s1[2]=1 and s2[2]=1 and carry = 0.

add= (s1[2]=1) + (s2[2] = 1) + (carry = 0),add=2.
add % 2 , i.e 2 % 2 = 0, so result="10".
add / 2 , i.e 2 / 2 = 1, so carry=1.

ITERATION 3:-
result="10"
carry=1
i=1

s1[1]=0 and s2[1]=0 and carry = 1.

add= (s1[1]=0) + (s2[1] = 0) + (carry = 1),add=1.
add % 2 , i.e 1 % 2 = 1, so result="101".
add / 2 , i.e 1 / 2 = 0, so carry=0.

ITERATION  4:-
result="101"
carry=0
i=0

s1[0]=1 and s2[0]=1 and carry = 0.

add= (s1[0]=1) + (s2[0] = 1) + (carry = 0),add=2.
add % 2 , i.e 2 % 2 = 0, so result="1010".
add / 2 , i.e 2 / 2 = 1, so carry=1.

We have done the full iteration.now we will check whether 1 is present in the carry or not?so yes,1 is present so we will add one at the end of the resultant string and reverse it.

result="10101" after appending 1 at the end.
reverse form of result is = "10101".