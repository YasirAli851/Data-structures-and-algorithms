Q:-Write a program to find the gcd or Highest common factor of two numbers.

//Approach 1:-Using iteration.

#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int a,b;
    cin>>a>>b;
    int result=min(a,b);
    while(result > 0)
    {
        if(a%result==0 && b%result==0)
        {
            break;
        }
        result--;
    }
    cout<<result<<endl;
    return 0;
}

//so,lets have a look at this first approach
So,step 1:-
We have initialized a variable called result with minimum value of a and b.
Note:we are considering a smallest number and decrementing it because any number bigger than both the numbers will never divide both number.
For example:-
95 and 200,so,we will initialise result with 95 because the number either 95 or less than 95 can divide both 95 and 200 and the number 
More than 95 may divide 200 but cannot 95.

So,lets take an example:-

a=10,b=15
So,our result will be equals to 10 as 10 is minimum between 10 and 15.
Now,we have initialized a loop and running it until result > 0 or we will break from the loop if both numbers will be divisible by result.

Now,result=10.
Iteration 1:
Result=10
a%10==0 && b%10!=0,so we will decrement result by 1,so,the value of our result now is 9.

Iteration 2:
result=9
a%9!=0 && b%9!=0,so we will decrement result by 1,so,the value of our result now is 8.
 
Iteration 3:
result=8
a%8!=0 && b%8!=0,so we will decrement result by 1,so,the value of our result now is 7.

Iteration 4:
result=7
a%7!=0 && b%7!=0,so we will decrement result by 1,so,the value of our result now is 6.

Iteration 5:
result=6
a%6!=0 && b%6!=0,so we will decrement result by 1,so,the value of our result now is 5.

Iteration 6:
result=5
a%5==0 && b%5==0,so we will break from the loop and print result as 5 as 10 and 15 both are divisible by 5 and 5 is also the highest common factor of 10 and 15.

--------------------------------------------------x--------------------------------x--------------------------------------------

//Using Euclidean algorithm:-

void solve() 
{
   int a,b;
   cin>>a>>b;
   while(a!=b)
   {
       if(a>b)
       {
        a=a-b;
       }
       else
       {
        b=b-a;
       }
   }
   cout<<a<<endl;

}

//This is euclidean method that is more efficient than the above one.

Let's consider a=15,b=10
We will create one loop and keep checking that until and unless a is not equals to b then we will keep going inside the loop.
So,iteration 1:
a=15 and b=10,so a is greatest so , we will decrement b from a.That means,15=15-10 that means a is equals to 5.
 
Now,value of a=5 and value of b=10.

Iteration 2:
a=5 and b=10,so b is greatest so , we will decrement a from b.That means,10=10-5 that means b is equals to 5.
 
Now,value of a=5 and value of b=5.

So,both are equal to each other so, we will break from the loop and print a that is 5 as 15 and 10 both are divisible by 5 and 5 is also the highest common factor of 15 and 10.

-----------------------------------------x----------------------------------------------x------------------------------

//using recursion

int greatest_common_div(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return greatest_common_div(b,a%b);
    }
}
void solve() 
{
   int a,b;
   cin>>a>>b;
   int ans=greatest_common_div(a,b);
   cout<<"gcd of "<<a<<" and "<<b<<" is "<<ans<<endl;

}



//let's look at the working of this recursive approach to find the gcd of two numbers.

Now , consider that our first number (a=16) and second number (b=20).
Lets consider the name of our function is greatest_common_div(a , b).

Recursive calls are shown below:-

greatest_common_div(16 , 20).

First call:-

b!=0,so,we will return greatest_common_div(b,a%b).

greatest_common_div(20 <= b,16 <= 16%20).
a=20,b=16 
because it is assigned as per the position of parameters.

Second call:-
a=20,b=16
b!=0,so,we will return greatest_common_div(b,a%b).

greatest_common_div(16 <= b,4 <= 20%16).
a=16,b=4. 
because it is assigned as per the position of parameters.

Third call:-
a=16,b=4
b!=0,so,we will return greatest_common_div(b,a%b).

greatest_common_div(4 <= b, 0 <=16%4).
a=4,b=0. 
because it is assigned as per the position of parameters.

Fourth call:-
a=4,b=0.

So, we will simply return a that is 4 because our b has became 0.
