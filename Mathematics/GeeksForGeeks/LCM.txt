LCM(Least common multiple):-Least common multiple is first as well as a smallest number that is divisible by two numbers.
For example:-
a=4,b=6.

Multiple of 4 and 6 are 12,24,36 and so on............
But least common multiple of a=4 and b=6 will be 12 as it is the smallest common multiple.


a=12,b=15.

Multiple of 12 and 15 are 60,120 and so on............
But least common multiple of a=12 and b=15 will be 60 as it is the smallest common multiple.

Assumptions:-

A1)When we have 2 numbers and if any of them will divide another number completely then the maximum number between those two numbers will be considered as LCM.

For example:
1)a=10,b=20:- here b=20 is completely divisible by a=10 so, maximum number between them(i.e b=20) will be considered as lcm.

2)a=48,b=8:- here a=48 is completely divisible by b=8 so, maximum number between them(i.e a=48) will be considered as lcm.


A2)When we have 2 numbers and if both of them are prime then their multiplication will be considered as LCM of those two numbers.

For example:
1)a=3,b=7:- here both of them are prime and their multiplication(ie. a=3 * b=7 = 21) will be considered as the LCM of a=3,b=7.

2)a=3,b=11:- here both of them are prime and their multiplication(ie. a=3 * b=11 = 33) will be considered as the LCM of a=3,b=11.


NAIVE APPROACH:-

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a,b;
    cout<<"enter the value in a "<<endl;
    cin>>a;
    cout<<"enter the value in b "<<endl;
    cin>>b;
    int s=max(a,b);
    while(true)
    {
        if(s%a==0 && s%b==0)
        {
            break;
        }
        else
        {
            s++;
        }
    }
    cout<<"lcm of "<<a<<" and "<<b<<" is "<<s<<endl;
}

Let's understand the above code:-

1)int s=max(a,b);
    2)while(true)
    {
        3)if(s%a==0 && s%b==0)
        {
		break;
        }
        else
        {
            4)s++;
        }
    }

Let's discuss point 1:-we have initialised the maximum value between among a and b in an integer s.The reason behind that is the lcm of two numbers can either be equals to maximum of two numbers or more than maximum of two numbers.

Now,in point 2:-we have initialized one while loop until our (s%a!=0 && s%b!=0) and incrementing s by 1.

In point 3):-we are just checking that whether our s%a==0 && s%b==0 or not.if yes then we are breaking from the loop but if no, then we are executing point 4.

In point 4:-we are incrementing s++ until we reach the condition where s%a==0 && s%b==0.

Lets have a look on how this approach will look like during running time:-

a=4,b=6.
s=max(a=4,b=6),so the value of s will be equal to 6 as 6 is maximum.

Iteration 1:-

We will check that if 6%4==0 && 6%6==0 then will break from the loop, else we will increment the value of s by 1.
So,s will be equal to 7.

Iteration 2:

We will check that if 7%4==0 && 7%6==0 then will break from the loop, else we will increment the value of s by 1.
So,s will be equal to 8.

Iteration 3:

We will check that if 8%4==0 && 8%6==0 then will break from the loop, else we will increment the value of s by 1.
So,s will be equal to 9.

Iteration 4:

We will check that if 9%4==0 && 9%6==0 then will break from the loop, else we will increment the value of s by 1.
So,s will be equal to 10.

Iteration 5:

We will check that if 10%4==0 && 10%6==0 then will break from the loop, else we will increment the value of s by 1.
So,s will be equal to 11.

Iteration 6:

We will check that if 11%4==0 && 11%6==0 then will break from the loop, else we will increment the value of s by 1.
So,s will be equal to 12.

Iteration 7:

We will check that if 12%4==0 && 12%6==0 then will break from the loop, else we will increment the value of s by 1.

But here, our condition(12%4==0 && 12%6==0) is satisfied so we will break from the loop and after breaking from the loop we can we see that the value of our s was 12.


So, we will just print the lcm of a=4 and b=6 is s=12.



EFFECIENT SOLUTION:-

#include<iostream>
#include<math.h>
using namespace std;
int gCd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gCd(b,a%b);
    }
}
int main()
{
    int a,b;
    cout<<"enter the value in a "<<endl;
    cin>>a;
    cout<<"enter the value in b "<<endl;
    cin>>b;
    int s=gCd(a,b);
    int lcm=(a*b)/s;
    cout<<"lcm of "<<a<<" and "<<b<<" is "<<lcm<<endl;
}

We have a formulla called a*b=gcd(a,b) * lcm(a,b).

By this formulla we can obtain lcm as lcm(a, b) = (a*b)/gcd(a, b).

So, in the above code:-
Let's consider we have given the value of a=4,and b=6 then the gCd function will return the greatest common divisor of a=4,b=6.
So, the greatest common divisor of a=4 b=6 will be 2<=gcd. And after that we are dividing the value of (a=4 * b=6)=24 with the gcd of (4,6).
So, 24/2 will be equals to 12 and 12 is our LCM.


 
