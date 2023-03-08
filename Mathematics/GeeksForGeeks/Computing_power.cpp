/* 
Computing powers:-In this question, we will be having two variables X and N where we will be computing X raise to the power N.for an example, X=3 and N=5, so the answer 3 raise to the power 5 will be 243.

Lets have a look on the recursive code:-
*/

#include<iostream>
#include<vector>
using namespace std;
int power(int x,int n)
{
    if(n==0)
    {
        return 1;
    }
    int ans=power(x,n/2);
    ans=ans*ans;
    if(n%2==0)
    {
        return ans;
    }
    else
    {
        return ans*x;
    }
}
int main()
{
   int n;
   cout<<"enter the value of n"<<endl;
   cin>>n;
   int x;
   cout<<"enter the value of x"<<endl;
   cin>>x;
   int answer=power(x,n);
   cout<<answer<<endl;
}

/*

Let's have a look on power function.

int power(int x,int n)
{
    if(n==0)
    {
        return 1;
    }
    int ans=power(x,n/2);
    ans=ans*ans;
    if(n%2==0)
    {
        return ans;
    }
    else
    {
        return ans*x;
    }
}

1st call:-
temp=power(3,5):-The caller of this is main.
Now,in this call, the value of x is 3 and n is 5.so,we haven't reached our base case(n==0) till now.so,the function will call itself again with the value x=3 and n=5/2=2.

2nd call:-

temp=power(3,2):-The caller of this function is power(3,5).
Now,in this call, the value of x is 3 and n is 2.so,we haven't reached our base case(n==0) till now.so,the function will call itself again with the value x=3 and n=2/2=1.

3rd call:-

temp=power(3,1):-The caller of this is power(3,2).
Now,in this call, the value of x is 3 and n is 1.so,we haven't reached our base case(n==0) till now.so,the function will call itself again with the value x=3 and n=1/2=0.

4th call:-

temp=power(3,0):-The caller of this is power(3,1).
Now,in this call, the value of x is 3 and n is 0.so,we haven reached our base case(n==0),so 1 will be stored to temp of power(3,0) because 1 is being returned from base case.
----------------------------------------------------------------------------------

Now,current function is power(3,0),we will do temp=temp*temp that is 1=1*1 and then we will check the value of n of our callers, the caller of power(3,0) is power(3,1) and 1 is an odd number so, we will return temp * x that is = 1*3=3.

Now,the caller temp=power(3,1) have the value equals to 3 which is returned from power(3,0).

Now,current function is power(3,1),we will do the temp=temp*temp that is 3=3*3 which is equals to 9 and then we will check the value of n of our callers, the caller of power(3,1) is power(3,2) and 2 is an even number so, we will return temp that is = 9.

Now,the caller temp=power(3,2) have the value equals to 9 which is returned from power(3,1).

Now,current function is power(3,2),we will do the temp=temp*temp that is 9=9*9 which is equals to 81 and then we will check the value of n of our callers, the caller of power(3,2) is power(3,5) and 5 is an odd number so, we will return temp*x that is = 81*3=243 to power(3,5).

Now,current function is power(3,5) with the value as 243,and the caller of power(3,5) is main function.so,243 will be returned to the main function.