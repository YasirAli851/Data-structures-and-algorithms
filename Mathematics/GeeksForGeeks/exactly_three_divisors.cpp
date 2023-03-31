Exactly 3 divisors:-Given a positive integer value N. The task is to find how many numbers less than or equal to N have numbers of divisors exactly equal to 3.

Input:
N = 6
Output: 1
Explanation: The only number less than 6 with 
3 divisors is 4.

Input:
N = 10
Output: 2
Explanation: 4 and 9 have 3 divisors.

Lets have a look on code:-

#include<iostream>
using namespace std;
bool check_prime(int n)
{
    if(n==1)
    {
        return false;
    }
    if(n==2 || n==3)
    {
        return true;
    }
    if(n%2==0 || n%3==0)
    {
        return false;
    }
    for(int i=5;i*i<=n;i+=6)
    {
        if(n%i==0 || n % (i+2) ==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cout<<"enter the value of n \n";
    cin>>n;
    int cnt=0;
    for(int i=2;i*i<=n;i++)
    {
        int res=check_prime(i);
        if(res==true)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

So, if we are given a value that is equals to N=10.

Then in that case, we will be having only 2 numbers which have 3 divisors and those numbers are 4 and 9.

Divisors of 4 are 1,2,4.
Divisors of 9 are 1,3,9.

Lets understand an approach:-
We will keep one variable named as count which will keep the count of numbers between 1 to N that is having exactly 3 divisors.

Initially count will be equals to 0.

We just need to find the prime number between 2 to N and check that if their perfect square is less than or equals to N or not.If yes then we will increment the count.

So, lets do a dry run to understand the approach more clearly:-

N=10.

count=0.

We will start a loop from 2 to <=N.

Iteration 1:-

I=2.

Now, we will check if i * i <= N or not.so, 2 * 2 = 4 is <= 10.so we will go inside loop and check if I=2 is prime or not. Yes i=2 is prime number so, we will increment the value of count by 1.

count=1.

Iteration 2:-

I=3

Now, we will check if i * i <= N or not.so, 3 * 3 = 9 is <= 10.so we will go inside loop and check if I=3 is prime or not. Yes I=3 is prime so we will increment the value of count by 1.

count=2.

Iteration 3:-

I=4

Now, we will check if i * i <= N or not.so, 4 * 4 = 16 is not <= 10 .so we will not go inside that loop and we will just print the value of count.

So the value of count was 2 in iteration 2 and we didn't go inside the loop In iteration 3 so,the value of count=2 will be printed and we can see that we have only 2 numbers between 2 to 10 who have exactly 3 divisors.

 