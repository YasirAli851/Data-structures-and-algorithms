Prime number:-It is a number that has two factors(i.e 1 and number itself).
For example:-
2,3,5,7,11,13.
All the number above have only two factors and that is 1 and the number itself.

Code to check prime numbers:-

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
    bool result=check_prime(n);
    if(result==true)
    {
        cout<<n<<" is a prime number \n";
    }
    else
    {
        cout<<n<<" is not a prime number \n";
    }
}

Lets have a look on the function check_prime() above:-

bool check_prime(int n)
{
    1)if(n==1)
    {
        return false;
    }
    2)if(n==2 || n==3)
    {
        return true;
    }
    3)if(n%2==0 || n%3==0)
    {
        return false;
    }
    for(int i=5;i*i<=n;i+=6)
    {
        4)if(n%i==0 || n % (i+2) ==0)
        {
            return false;
        }
    }
    5)return true;
}

If false will be returned from the function then we will consider that the number is not prime and if true will be returned from the function check_prime then we will consider that the number is prime.

:- n is a number that has been passed as an argument to check_prime function to check that whether n is a prime number or not.

Point 1:-we are checking that if the value of n==1 or not.if yes then we will return false.

Point 2:-we are checking that if the value of n==2 or n==3.if yes then we will return true else we will go to point 3.

Point 3:-we are checking if n is completely divisible by (either 2 or 3) or not.if yes then we will return false else we will go to check point 4.

Point 4:-we have initialized i=5 and checking that if I*I<=n then we are going inside a loop and checking that whether (n%i==0 or n%(i+2)==0) or not.if yes then we are returning false else we are incrementing i by 6 until I*I<=n.
If nothing will be returned from point 1 to point 4 then we will simply return true from point 5.

Point 5:-if nothing will be returned then we will return true at the last.



Lets have a look at some example:-

n=121

Point 1:-We are checking that if n is equal to 1 or not.so,in case of n=121.condition in point-1 is wrong.

Point 2:-we are checking if n==2 or n==3.but in case of n=121.condition in point-2 also fails.

Point 3:-we are checking if 121%2==0 or 121%3==0.but in case of 121,this condition-3 also fails.

Point 4:-
When I=5 and 5*5=25 <= 121.so we went inside for loop and checking if 121%5==0 or 121%(5+2)==0 or not.condition become false so we incremented I by 6.

When I=11 and 11*11=121 <=121.so we went inside for loop and checking if 121%11==0 or 121%(11+2)==0 or not.condition become true,so we returned false to the main function.


n=1031

Point 1:-We are checking that if n is equal to 1 or not.so,in case of n=1031.condition in point-1 is wrong.

Point 2:-we are checking if n==2 or n==3.but in case of n=1031.condition in point-2 also fails.

Point 3:-we are checking if 1031%2==0 or 1031%3==0.but in case of 1031,this condition-3 also fails.

Point 4:-
When I=5 and 5*5=25 <= 1031.so we went inside for loop and checking if 1031%5==0 or 1031%(5+2)==0 or not.condition become false so we incremented I by 6.

When I=11 and 11*11=121 <=1031.so we went inside for loop and checking if 1031%11==0 or 1031%(11+2)==0 or not.condition become false,so we incremented I by 6.

When I=17 and 17*17=289 <=1031.so we went inside for loop and checking if 1031%17==0 or 1031%(17+2)==0 or not.condition become false,so we incremented I by 6.

When I=23 and 23*23=529 <=1031.so we went inside for loop and checking if 1031%23==0 or 1031%(23+2)==0 or not.condition become false,so we incremented I by 6.

When I=29 and 29*29=841 <=1031.so we went inside for loop and checking if 1031%29==0 or 1031%(29+2)==0 or not.condition become false,so we incremented I by 6.

When I=35 and 35*35=1225 is not less than or equal to 1031.so,we won't go inside loop and point 5 will be executed and true will be returned.

