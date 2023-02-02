Question:-Write a program to check if a number is palindrome or not.

N=1221
Output:-YES

N=123
Output:-NO

My code with solution.

bool isPalindrome(int n)
{
    int s=n; //storing the initial value of n.
    int rev=0; //we will store the reverse of the number in it.
    while(n>0) //we will keep stroring the reverse value of n until n is //more than 0.
    {
        //suppose the value of n is 363
        int c=n%10; //this will give the last index.
        rev=rev*10+c; 

        //our rev is 0 initially.so
        //iteration 1:-we have got the last value as c=3 (363%10)
        //so,rev=rev*10+c (0=0*10+3)=3.(rev=3)
        //now n=n/10 will remove the last digit from the n.
        //so,n is now 36.

        //iteration 2:-we have got the last value as c=6 (36%10)
        //so,rev=rev*10+c (3=3*10+6)=36.(rev=36)
        //now n=n/10 will remove the last digit from the n.
        //so,n is now 3.

        //iteration 3:-we have got the last value as c=3 (3%10)
        //so,rev=rev*10+c (36=36*10+3)=363.(rev=363)
        //now n=n/10 will remove the last digit from the n.
        //so,n is now 0.

        // after that we will come out of this loop

        n=n/10;
    }
    if(rev==s) //as we have stored the initial value of n in s,so,we will //compare the value of rev with s.if s==rev then we will return //true.else return false.
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve() 
{
    int n;
    cin>>n;
    if(isPalindrome(n)) //if the function returns true then we will go //inside this condition and print YES.
    {
        cout<<"YES"<<endl;
    }
    else//if the function returns false then we will go inside this      // condition and print NO.
    {
        cout<<"NO"<<endl;
    }
}  





