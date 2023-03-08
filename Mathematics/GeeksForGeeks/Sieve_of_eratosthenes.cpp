Sieve of Eratosthenes:-We use sieve of Eratosthenes in order to get all the prime number from 2 upto n.
Input:
n=12
output:
2,3,5,7,11.

Approach:-The approach is that:
Step 1)we will create a boolean vector of size n+1 and initialize all the elements as true.

step 2)After step 1,we will iterate through the vector from index 2 and mark all the value at composite number's index as false upto n.

Step 3)after step 2,we iterate through the vector and print only that index i where the value of vector is marked as true.

Lets have a look on code:-

#include<iostream>
#include<vector>
using namespace std;
void sieve_of_eratosthenes(int n)
{
    vector<bool>vec(n+1,true);
    for(int i=2;i*i<=n;i++)
    {
        if(vec[i])
        {
            for(int j = 2*i; j <= n; j = j+i)
            {
                vec[j] = false;
            }
        }
    }
    for(int i=2;i<vec.size();i++)
    {
        if(vec[i]==true)
        {
            cout<<i<<" ";
        }
    }
}
int main()
{
    int n=12;
    sieve_of_eratosthenes(n);
}


Lets understand the sieve_of_eratosthenes function:

vector<bool>vec(n+1,true);
  for(int i=2;i*i<=n;i++)
  {
   if(vec[i])
   {
        3)for(int j = 2*i; j <= n; j = j+i)
        {
           vec[j] = false;
        }
   }
  }
  for(int i=2;i<vec.size();i++)
  {
   if(vec[i]==true)
   {
       cout<<i<<" ";
   }
  }

Suppose the value of n is 12.

So,our vector will be of size 13 with all the values as true.

vector<bool>vec(n+1,true);

vec:-[true,true,true,true,true,true,true,true,true,true,true,true,true]

first loop:-

I=2 and I*I=4 <= 12,so we went inside first loop.

*)we will check if vec[2]==true then we will go to 2nd loop.

Second loop:-
I=2

*)j=2*i=4   4<=12,we will go inside 2nd loop.

*)we will mark vec[j]=false that means vec[4] is false.

Updated vector below:-
vec:[true,true,true,true,false,true,true,true,true,true,true,true,true]

*)J will be incremented by I.so I=2,j=4,so,j=j+I that means j=6.

*)We will again check that if j=6 <= 12,if yes,then we will mark vec[6]=false.

Updated vector below:-
vec:[true,true,true,true,false,true,false,true,true,true,true,true,true]

*)J will be incremented by I.so,i=2,j=6,j=j+I that means j=8.

*)we will again check if j=8 <= 12,if yes then we will mark vec[8]=false.

Updated vector below:-
vec:[true,true,true,true,false,true,false,true,false,true,true,true,true]

*)J will be incremented by I.so,i=2,j=8,j=j+I that means j=10.

*)we will again check if j=10 <= 12,if yes then we will mark vec[10]=false.

Updated vector below:-
vec:[true,true,true,true,false,true,false,true,false,true,false,true,true]

*)J will be incremented by I.so,i=2,j=10,j=j+I that means j=12.

*)we will again check if j=12 <= 12,if yes then we will mark vec[12]=false.

Updated vector below:-
vec:[true,true,true,true,false,true,false,true,false,true,false,true,false]

*)J will be incremented by I.so,i=2,j=12,j=j+I that means j=14.

*)we will again check if j=14 <= 12.no.so we will come out of 2nd for loop and move to the first loop.
-------------------------------------------------------------------------------------------------
First for loop:-

I got incremented by 1.
So, I=3.

I=3 and I*I=9 <= 12,so we went inside first loop.

*)we will check if vec[3]==true then we will go to 2nd loop.

Second loop:-
I=3

*)j=2*i=6  6<=12,we will go inside 2nd loop.

*)we will mark vec[j]=false that means vec[6] as false.(already false).

Updated vector below:-
vec:[true,true,true,true,false,true,false,true,false,true,false,true,false]

*)J will be incremented by I.so I=3,j=6,so,j=j+I that means j=9.

*)We will again check that if j=9 <= 12,if yes,then we will mark vec[9]=false.

Updated vector below:-
vec:[true,true,true,true,false,true,false,true,false,false,false,true,false]

*)J will be incremented by I.so I=3,j=9,so,j=j+I that means j=12.

*)We will again check that if j=12 <= 12,if yes,then we will mark vec[12]=false.(already false)

Updated vector below:-
vec:[true,true,true,true,false,true,false,true,false,false,false,true,false]

*)J will be incremented by I.so I=3,j=12,so,j=j+I that means j=15.

*)We will again check that if j=15 <= 12.no,so we move out of second loop and go to first loop.

-----------------------------------------------------------------------------------------------

First for loop:-

I got incremented by 1.

so,I=4.

So, we will check if I*I=16 <= 12.No.so we won't go inside 1st loop and that's the point when we are not supposed to do any operation and our vector is modified in a way where all the index equals to composite numbers are marked as false.

Final boolean vector:-

vec:[true,true,true,true,false,true,false,true,false,false,false,true,false]

Now,in the third loop, we will iterate from 2 to <= 12.

So,the value on the vector at index 2,3,5,7 and 11 are marked as true.So,only that indexes will be printed simply.

Output:- 2,3,5,7,11. 

