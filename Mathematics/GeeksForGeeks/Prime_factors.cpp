Prime factors:-prime factors are all the numbers from 2 to < n that are prime as well as divides a number n.
Suppose the value of n=15.
So, the factor of n=15 are 3,5.
But,if we talk about prime factors then only 3 and 5 will be considered as prime factors because we are excluding 1 and n=15.So,only 3 and 5 are left and both of them are prime number.

Code:-

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<=1)
    {
        cout<<1<<endl;
    }
    while(n%2==0)
    {
        cout<<2<<" ";
        n=n/2;
    }
    while(n%3==0)
    {
        cout<<3<<" ";
        n=n/3;
    }
    for(int i=5;i*i<=n;i+=6)
    {
        while(n%i==0)
        {
            cout<<i<<" ";
            n=n/i;
        }
        while(n%(i+2)==0)
        {
            cout<<(i+2)<<" ";
            n=n/(i+2);
        }
    }
    if(n>3)
    {
        cout<<n<<endl;
    }

}

Lets have a look on the code:-

    P1)if(n<=1)
    {
        cout<<1<<endl;
    }
    p2)while(n%2==0)
    {
        cout<<2<<" ";
        n=n/2;
    }
    P3)while(n%3==0)
    {
        cout<<3<<" ";
        n=n/3;
    }
    P4)for(int i=5;i*i<=n;i+=6)
    {
        P4-1)while(n%i==0)
        {
            cout<<i<<" ";
            n=n/i;
        }
        P4-2)while(n%(i+2)==0)
        {
            cout<<(i+2)<<" ";
            n=n/(i+2);
        }
    }
    P5)if(n>3)
    {
        cout<<n<<endl;
    }


Let's discuss all the points:

P1:-in p1,we are just checking that if n<=1 then we are simply printing 1.
P2:-in p2,we are just printing all the factors of n that is equals to 2.
P3:-in p3,we are just printing all the factors of n that is equals to 3.
P4:-in p4,we are assigning the value of i as 5 and check that whether i*i <= n(value of n after passing all the points above(I.e p1,p2,p3).if i*I<=n then we will go inside that for loop and again at point p4-1 we are checking and printing for all the factor of n that is equals to i and after that we are executing point p4-2 and we are checking and printing all the factors of n that is equals to i+2 and we are incrementing i with 6.this for loop will run until i*i<=n.in case i*i is not less than to equals to n then we will break from that for loop and execute point p5.

P5:-we will check if the remaining value of n is > 3 or not.one thing to note here is we are checking with n > 3 because we have already handled with 2 and 3 above(i.e point p2,p3).so,if the value of n will be more than 3 then we will simply print n.

Lets take an example:-
The value of n=10350.

P1:-so,n=10350 is not <= 1.so,we won't go inside that if.

P2:-so,we will go inside that while loop until n is divisible by 2 and we are dividing the value of n by 2 in every iteration.
Iteration 1:- 
n=10350.
10350%2==0,so,we will go in that while loop and print 2,and then do 10350/2,so the value of n will become 5175.

Iteration 2:-
n=5175.
5175%2!=0.so,we will not go inside that while loop.so we will directly jump to point P3.

P3:-so,we will go inside that while loop until n is divisible by 3 and we are dividing the value of n by 3 in every iteration.

n=5175.

Iteration 1:-
n=5175.
5175%3==0,so,we will go inside that while loop and print 3 and then do 5175/3,so the value of n will become 1725.

Iteration 2:-
n=1725.
1725%3==0,so,we will go inside that while loop and print 3 and then do 1725/3,so the value of n will become 575.

Iteration 3:-
n=575.
575%3 != 0,so,we wont go inside that while loop.and then directly move to point p4.

P4:-so,in this point we will be using for loop and initialise i=5.
Iteration 1 of p4:
I=5.
n=575.
So,i=5,so we will check if I*I<=n.I.e 5*5<=575?yes.so we will go inside that for loop.

Now,in point p4-1,we will go inside while loop and print the value of i until n%i==0 and we will do n/i in every iteration.

So,1st iteration of while loop(p4-1):-
I=5.
n=575.
575%5==0 so,we will print 5 and then do 575/5,so the value of n become 115.

2nd iteration of while loop:-
I=5.
n=115.
115%5==0 so,We will print 5 and then do 115/5,so the value of n become 23.

3rd iteration of while loop.
I=5.
n=23.
23%5!=0,so,we won't go inside that loop and move to point p4-2.

Now,in point p4-2,we will go inside while loop and print i+2 until n%i+2==0 and we will do n/i+2 in every iteration.
Iteration 1 of while loop(p4-2):-
I+2=7.
n=23.

23%7!=0.
Sow will not go inside that while loop of p4-2.so,the i will be incremented by 6.
So,loop of p4 will again be executed with value of I=11.

So, we will check if 11*11=121 <= 23?no.so we will come out of for loop and move to point P5.

P5:-In this point we will check that whether n>3 or not?yes.n=23 is > 3,so,we will print n(i.e 23).

So,2 3 3 5 5 23 will be the prime factors of 10350.