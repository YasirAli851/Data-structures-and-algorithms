/*
Iterative power(Binary exponentiation):-In this question we are going to calculate X to the power N using iterative method and binary exponentiation.

Binary exponentiation:-

Suppose the value of N=5,X=4.

So,binary representation of 5 is 0 1 0 1.

So,we will go from LSB(Least significant bit) to MSB(Max significant bit).

MSB: 0:-the value here will be 4 to the power 8.

1:-the value here will be 4 to the power 4. 

0:- the value here will be 4 to the power 2 .

LSB 1:- the value here will be 4 to the power 1.

We will calculate only that value whose bit is 1.

So,  1st bit=1 from LSB is having value=4 to the power 1.

And 2nd bit=1 is having value=4 to the power 4.

So, we will do the multiplication of the values that we have got from each bit equals to 1.so the value will be 4 to the power 1 = 4   *    4 to the power 4 = 256,so, 4 * 256 = 1024.

So,our answer will be 1024.

Now,lets have a look on the code to perform this operation:-

*/

#include<iostream>
using namespace std;
int main()
{
    int n=5,x=4;
    int res=1;
    while(n>0)
    {
        if(n%2!=0)
        {
            res=res*x;
        }
        x=x*x;
        n=n/2;
    }
    cout<<res<<endl;
}

/*

Lets understand how code is working:-
Suppose the value of N=5 , X=4 and res=1.


Iteration 1:-

N=5 that is more than 0. so,we will go inside while loop:-

We will check if 5 % 2 != 0 ,so ,yes, condition become true.so:-

res=res*x that means 1 = 1 * 4, so,res = 4 and then after coming out from if condition we will do:-

x = x * x that means 4 = 4 * 4, so, x = 16 and after that we will do n=n/2 that means 5 = 5/2 that means n = 2.

So, after this process and after 1st iteration:-

res=4

x=16

n=2

Iteration 2:-

N=2 that is more than 0. so,we will go inside while loop:-

We will check if 2 % 2 != 0 ,so ,no, condition become false.so ,we won't go inside if condition.

x = x * x that means x = 16 * 16, so, x = 256 and after that we will do n=n/2 that means 2 = 2/2 that means n = 1.

So, after this process and after 2nd iteration:-

res=4

x=256

n=1

Iteration 3:-

N=1 that is more than 0. so, we will go inside while loop:-

We will check if 1 % 2 != 0 ,so ,yes, condition become true.so:-

res=res*x that means 4 = 4 * 256, so,res = 1024 and then after coming out from if condition we will do:-

x = x * x that means 256 = 256 * 256, so, x = 65536 and after that we will do n=n/2 that means 1 = 1/2 that means n = 0.

So, after this process and after 3rd iteration:-

res=1024

x=65536

n=0


Iteration 4:-
N=0 so we will not go inside while loop so, we will just print the value of res=1024 and 4 to the power 5 is equals to 1024.

*/
