Q:Write a program to find the number of zeroes present in the factorial of N.

Let's consider an example:-

N=4.
So,factorial of 4 is 24.
So,no zeroes are there is 24,so our answer will be 0.

N=5.
So,factorial of 5 is 120.
So,1 zero is there in 120,so our answer will be 1.


Lets see the implementation of this in C++.

void solve() 
{
    int n;
    cin>>n;
    int result=0;
    for(int i=5;i<=n;i=i*5)
    {
        result=result+(n/i);
     
    }
    cout<<result<<endl;
}  


        Lets do the dry run:-

	   //Suppose we have given the value of n as 251
	   //iteration 1 :-
	   //I=5 and 5<=251,so we will go inside that loop.
	   //0=0+(251/5)
	   //0=0+50
        //Result=50.

        //After this, i is being multiplied by 5,so,value of i right now is=5*5=25.
	   
	   //iteration 2 :-
        //i=25 and 25<=251,so we will go inside that loop
        //50=50+(251/25)
        //50=50+10
	   //result=60

	   //After this, i is being multiplied by 5,so,value of i right now is=25*5=125.
	
	   //iteration 3:-
	
        //i=125 and 125<=251, so we will go inside that loop
	   
	   //60=60+(251/125)
        //60=60+2
	   //result=62.
	  
	   //After this, i is being multiplied by 5,so,value of i right now is=125*5=625.
	   
        //625 <= 251 ?No,so,we won't go inside the loop and our final result is = 62.That means if we do the factorial of 251,then
        //Total 62 zeroes will be there in the factorial of 251.


       //-----------------------------x-------------------------------------x----------------------------x----------------------

	   //Suppose we have given the value of n as 5
	   //iteration 1 :-
	   //I=5 and 5<=5,so we will go inside that loop.
	   //0=0+(5/5)
	   //0=0+1
        //Result=1.

        //After this, i is being multiplied by 5,so,value of i right now is=5*5=25.
	   
	   //iteration 2 :-
        //I=25 and 25<=5,no,25 is not less than or equal to 5,so we will not go inside that loop
	   
        //our final result is = 1,That means if we do the factorial of 5,then,Total 1 zero will be there in the factorial of 5 as
	   //factorial of 5 is 120 so,1 zero is there in 120.