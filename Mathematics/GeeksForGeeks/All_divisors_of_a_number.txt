All divisors of a number:
Divisors of a number n can be considered as all the numbers that completely divides n.divisors of a number n will always lie from 1 to <=n.

For example:
n=15.
So,all the divisors of 15 will be 1 3 5 15 as n=15 is completely divisible by all these numbers.

Code:-
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i;
	for(i=1;i*i<n;i++)
	{
		if(n%i==0)
		{
			cout<<i<<" ";
		}
	}
	for(i;i>=1;i--)
	{
		if(n%i==0)
		{
			cout<<n/i<<" ";
		}
	}
}


Let's understand the above code with the value of n=15.

int i;
1)for(i=1;i*i<n;i++)
{
	if(n%i==0)
	{
		cout<<i<<" ";
	}
}
2)for(i;i>=1;i--)
{
	if(n%i==0)
	{
		cout<<n/i<<" ";
	}
}

Let's have a look at the 1st for loop.

Iteration 1:-
The value of i=1.so,1*1=1 < n=15,so,we will go inside that loop,then we will check whether 15%1==0 or not, if yes, then we will print the value of i (i.e 1) and move to the next iteration.but in case the if condition is not satisfied then in that case also we will move to the next iteration.

Iteration 2:-
The value of i=2.so,2*2=4 < n=15,so,we will go inside that loop,then we will check whether 15%4==0 or not, if yes, then we will print the value of i (i.e 2) and move to the next iteration but in case the if condition is not satisfied then in that case also we will move to the next iteration.

Iteration 3:-
The value of i=3.so,3*3=9 < n=15,so,we will go inside that loop,then we will check whether 15%3==0 or not, if yes, then we will print the value of i (i.e 3) and move to the next iteration but in case the if condition is not satisfied then in that case also we will move to the next iteration.

Iteration 4:-
The value of i=4.so,4*4=16 is not < n=15,so,we will not go inside that loop and we will simply move to 2nd for loop.

So,till this time,1 and 3 will be printed as our "if" condition is satisfied in 1st and 3rd iteration.


Lets's have a look at the 2nd for loop.

Iteration 1:-
The value of i=4.so,4*4=16 >= 1,so,we will go inside that loop,then we will check whether 15%4==0 or not, if yes, then we will print the value of n/i(i.e 15/4=3) and move to the next iteration but in case the if condition is not satisfied then in that case also we will move to the next iteration.

Iteration 2:-
The value of i=3.so,3*3=9 >= 1,so,we will go inside that loop,then we will check whether 15%3==0 or not, if yes, then we will print the value of n/i(i.e 15/3=5) and move to the next iteration but in case the if condition is not satisfied then in that case also we will move to the next iteration.

Iteration 3:-
The value of i=2.so,2*2=4 >= 1,so,we will go inside that loop,then we will check whether 15%2==0 or not, if yes, then we will print the value of n/i(i.e 15/2=7) and move to the next iteration but in case the if condition is not satisfied then in that case also we will move to the next iteration.

Iteration 4:-
The value of i=1.so,1*1=1 >= 1,so,we will go inside that loop,then we will check whether 15%1==0 or not, if yes, then we will print the value of n/i(i.e 15/1=15) and move to the next iteration but in case the if condition is not satisfied then in that case also we will move to the next iteration.

Iteration 5:-
The value of i=0.so,0*0=0 is not >= 1,so,we will not go inside that loop.

So, till this time 5 and 15 will be printed as "if" condition is satisfied in 2nd and 4th iteration.

So, 1 3 5 15 all of these will be printed and all of these are considered as the divisors of 15.