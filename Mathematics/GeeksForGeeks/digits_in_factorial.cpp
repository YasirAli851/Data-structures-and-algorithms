Digits in factorial:-In this question, we are asked to find the number of digits in the factorial of a number N.

For an example:-
N=5.
So, factorial of 5 is 120.
So, there are 3 digits(1,2,0) are present in the factorial of 5.

Lets have a look on the code:

#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter the value of n"<<endl;
	cin>>n;
	
	double ans=0;

	for(int i=1;i<=n;i++)
	{
		ans+=log10(i);
	}
	
	cout<<"number of digits in the factorial "<<n<<" is "<<floor(ans+1)<<endl;
}

Lets understand the code:-

So,our ans=0 initially.

n=5;
We are going inside for loop:-

Iteration 1:-

i=1.

So,log of i=1 with base 10 (log10(1)) is 0.

ans = ans + log10(1).
0 = 0 + 0.

ans=0.

Iteration 2:-

I=2.

So,log of i=2 with base 10 (log10(2)) is 0.30103.

ans = ans + log10(2).

0 = 0 + 0.30103.

ans=0.30103.

Iteration 3:-

I=3.

So,log of i=3 with base 10 (log10(3)) is 0.477121.

ans = ans + log10(3).

0.30103 = 0.30103 + 0.477121.

ans=0.778151.

I=4.

So,log of i=4 with base 10 (log10(4)) is 0.60206.

ans = ans + log10(4).

0.778151 = 0.778151 + 0.60206.

ans=1.380211.

I=5.

So,log of i=5 with base 10 (log10(5)) is 0.69897.

ans = ans + log10(5).

1.380211 = 1.380211 + 0.69897.

ans=2.079181.


So, if i do ans+1,that means 2.079181 + 1 = 3.079181 and floor value of 3.079181 is 3.
So, our answer is 3 and number of digits in the factorial of 5 is 3.
