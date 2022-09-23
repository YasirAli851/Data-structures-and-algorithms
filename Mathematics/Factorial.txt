What is a factorial?
A factorial of N(a number) is the multiplication of of all the numbers from N to 1.
For example:-
N=5.
So,factorial of 5 = 5*4*3*2*1 = 120.

Code:-

Iterative approach:-

#include <iostream>
using namespace std;
int main() {
    int N; //this will store the number to check for the factorial.
    int result=1; //we will store the result of the factorial in it.
    cin>>N;
    for(int i=N;i>=1;i--) //This loop will start from N and will go upto 1.
    {
        result=result*i;  //we will multiply the value of "i" with the result. 
    }
    cout<<result<<endl; //printing the result (factorial).
    return 0;


    //Let's look at the working of the program:-
	/*
   N=5.
   iteration 1:-
   result = 1.
   i=5.

   so,1*5=5.
   result = 5.

   iteration 2:-
   result = 5.
   i=4.

   so,5*4 = 20.
   result = 20.

   iteration 3:-
   result = 20.
   i=3.

   so,20*3 = 60.
   result = 60.

   iteration 4:-
   result = 60.
   i=2.

   so,60*2 = 120.
   result = 120.

   iteration 5:-

   result=120.
   i=1.

   so,120*1 = 120.
   result = 120.

   so,as our N was 5,we had total five iteration. so.after fifth iteration,we got out from our loop.and printed the result = 120.
   */
    
}

Recursive approach:-

long long unsigned int fact(int n)
{
    if(n==0)
    {
        return n+1;
    }
    else
    {
        return n * fact(n-1);
    }

	

}
Int main() 
{
    int n;
    cin>>n;
    long long unsigned int result=fact(n);
    cout<<"factorial of "<<n<<" is "<<result<<endl;
}  



Now lets consider the above code and look the working of recursive function:-

long long unsigned int fact(int n)
{
    if(n==0)
    {
        return n+1;
    }
    else
    {
        return n * fact(n-1);
    }

    //lets consider the value of n is 5.
	
    stack 1:- So,when we do 5 * fact(n-1) then, n will be waiting to be multiplied with the value of fact(4).
    	
    now,after decrementing above,the value of n has became 4.

    Stack 2:- Now,4 * fact(n-1),then n will be waiting to be multiplied with the value of fact(3).

    Now,after decrementing above, the value of n has became 3.

    Stack 3:- Now,3 * fact(n-1),then n will be waiting to be multiplied with the value of fact(2).

    Now,after decrementing above, the value of n has became 2.

    stack 4:- Now,2 * fact(n-1),then n will be waiting to be multiplied with the value of fact(1).
	
    Now,after decrementing above, the value of n has became 1.

    stack 5:- Now,1 * fact(n-1),then n will be waiting to be multiplied with the value of fact(0).
    
    Now,after decrementing above, the value of n has became 0.
	
    Here,we can see in our program, when our n==0 we are returning n+1 i.e 0+1 = 1 = fact(0),so returing 1.

    In 5th stack, we can see that our n has became 0.so:- 1 * fact(0)= 1 * 1 => 1.
    
    This 1 from above will be returned to stack 4 that means fact(1)=1.so, 2 * fact(1)= 2 * 1 =2.

    Then again this 2 from above will be returned to stack 3 that means fact(2)=2 .so, 3 * fact(2) = 3 * 2 = 6.

    Then again this 6 from above will be returned to stack 2 that means fact(3)=6 .so, 4 * fact(3) = 4 * 6 = 24.
   
    Then again this 24 from above will be returned to stack 1 that means fact(4)=24 .so, 5 * fact(4) = 5 * 24 = 120.

    Now,we have reached back to stack 1,then final value that means 5 * fact(4) = 120 will be returned to main function. 



   
   LETS LOOK AT THE CODE OF THE MAIN FUNCTION:-

    int n;  
    cin>>n; //ASKING THE USER TO ENTER THE NUMBER TO CHECK THEIR FACTORIAL .
    long long unsigned int result=fact(n);  // CALLING FACT FUNCTION AND PASSING N TO IT AND WHATEVER WILL BE RETURNED FROM THAT FUNCTION,THAT WILL BE STORED IN RESULT.

    cout<<"factorial of "<<n<<" is "<<result<<endl;  //PRINTING THE RESULT I.E FACTORIAL OF N.

}
