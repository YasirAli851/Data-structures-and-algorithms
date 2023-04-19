/*
Given the first 2 terms A and B of a Geometric Series. The task is to find the Nth term of the series.
Input:
A = 2 
B = 3
N = 1
Output: 2
Explanation: The first term is already
given in the input as 2

Input:
A = 1
B = 2
N = 5
Output: 16
Explanation: Common ratio = 2,
Hence second term is 1*(2)(5-1) = 24 = 16 .
*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int A,B,N;
    cout<<"enter the value of A "<<endl;
    cin>>A;
    cout<<"enter the value of B "<<endl;
    cin>>B;
    cout<<"enter the value of N"<<endl;
    cin>>N;

    double r = (double)B/A;
    auto result=A*(pow(r,N-1));
    cout<<floor(result)<<endl;
}

// In the question above,we are asked to return the geometric progression term where we are given the value
// of first two terms A AND B and the value of N(To find the Nth term).

// so,in order to find the Nth term,following are the steps:-
// 1)find the ratio first.
// Ratio can be found by doing B/A.
// 2)Then calculating power of ratio with respect to N-1.
// power can be found by doing pow(ratio,N-1) and i have stored the value of it inside variable result.
// 3)Then multiplying the value of A with the value of pow(ratio,N-1).
// multiplication can be done by doing A*pow(ratio,N-1).