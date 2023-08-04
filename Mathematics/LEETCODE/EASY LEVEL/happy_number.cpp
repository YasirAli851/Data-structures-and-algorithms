Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:-

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:-

Input: n = 2
Output: false

Mainly we have to focus on the condtions where we are supposed to stop and return either true or false.

condition 1:-When we will get 1 after doing the operation listed above then we will stop and return true. 
condition 2:-when we dont get 1 but found the previously occured number again then we will stop and return false.

lets look at the approach:-

step 1:-we will create an empty set.

step 2:-we will do the sum of all the of digit's' squares and put it in the set.

step 3:-cond1:-we will check if the sum of all the digit's' square is equals to 1 then we will return true but cond2:- if the sum od digit's' squares matches with the existing values that is present inside the set then we will return false.if both the condition doesn't' satisfies then we will update the value of "n" with the sum of digit's' squares and we will keep iterating while loop until both the conditions are not satisfied.

lets have a look at the code:-

lass Solution {
public:
    bool isHappy(int n) {
        set<int>st;
        while(true)
        {
            int val=0;
            while(n>0)
            {
                int rem=n%10;
                val+=rem * rem;
                n=n/10;
            }
            if(val==1)
            {
                return true;
            }
            else
            {
                for(auto a:st)
                {
                    if(a==val)
                    {
                        return false;
                    }
                }
                n=val;
                st.insert(val);
            }
        }
    }
};

let's' do the dry run of the code with an example:-

example 1:-
n=19;
val=0

loop runs for first time for the value of n = 19.

9=9*9 = 81
val+=81.
val=81

loop runs for second time for the value of n = 19.
1=1*1 = 1
val+=1
val=82

we will check if val==1 or not,so val is not equals to 1 so,we will go to next conditoon where we will check if 82 is present in the set or not,so,82 is not present on the set so this condition is also not satisfied,so we will do n=val and insert 82 on the set.

st=[82]

loop runs for first time for the value of n = 82.
val=0

2=2*2 = 4
val+=4.
val=4.

loop runs for second time for the value of n = 82.
8=8*8 = 64
val+=64
val=68

we will check if val==1 or not,so val is not equals to 1 so,we will go to next conditoon where we will check if 68 is present in the set or not,so,68 is not present on the set so this condition is also not satisfied,so we will do n=val and insert 68 on the set.

st=[82,68].

loop runs for first time for the value of n = 68.
val=0

8=8*8 = 64
val+=64.
val=64.

loop runs for second time for the value of n = 68.
6=6*6 = 36
val+=36
val=100

we will check if val==1 or not,so val is not equals to 1 so,we will go to next conditoon where we will check if 100 is present in the set or not,so,100 is not present on the set so this condition is also not satisfied,so we will do n=val and insert 100 on the set.

st=[82,68,100]

loop runs for first time for the value of n = 100.
val=0

0=0*0 = 0
val+=0.
val=0.

loop runs for second time for the value of n = 100.
0=0*0 = 0
val+=0 
val=0

loop runs for third time for the value of n = 100.
1=1*1 = 1
val+=1
val=1

here condition 1 is satisfied where val==1, so we will return true.No need to check condition 2.

Example 2:-
n=4;
val=0

loop runs for first time for the value of n = 4.

4=4*4 = 16
val+=16.
val=16

we will check if val==1 or not,so val is not equals to 1 so,we will go to next conditoon where we will check if 16 is present in the set or not,so,16 is not present on the set so this condition is also not satisfied,so we will do n=val and insert 16 on the set.
st=[16]

loop runs for first time for the value of n = 16.

6=6*6 = 36
val+=36.
val=36

loop runs for second time for the value of n = 16.
1=1*1 = 1
val+=1
val=37

we will check if val==1 or not,so val is not equals to 1 so,we will go to next conditoon where we will check if 37 is present in the set or not,so,37 is not present on the set so this condition is also not satisfied,so we will do n=val and insert 37 on the set.
st=[16,37]


loop runs for first time for the value of n = 37.

7=7*7 = 49
val+=49.
val=49.

loop runs for second time for the value of n = 37.
3=3*3 = 9
val+=9
val=58

we will check if val==1 or not,so val is not equals to 1 so,we will go to next conditoon where we will check if 58 is present in the set or not,so,58 is not present on the set so this condition is also not satisfied,so we will do n=val and insert 58 on the set.
st=[16,37,58]

loop runs for first time for the value of n = 58.

8=8*8 = 64
val+=64.
val=64

loop runs for second time for the value of n = 58.
5=5*5 = 25
val+=25
val=89

we will check if val==1 or not,so val is not equals to 1 so,we will go to next conditoon where we will check if 89 is present in the set or not,so,89 is not present on the set so this condition is also not satisfied,so we will do n=val and insert 89 on the set.
st=[16,37,58,89]

loop runs for first time for the value of n = 89.

9=9*9 = 81
val+=81.
val=81

loop runs for second time for the value of n = 89.
8=8*8 = 64
val+=64
val=145

we will check if val==1 or not,so val is not equals to 1 so,we will go to next conditoon where we will check if 145 is present in the set or not,so,145 is not present on the set so this condition is also not satisfied,so we will do n=val and insert 145 on the set.
st=[16,37,58,89,145]

loop runs for first time for the value of n = 145.

5=5*5= 25
val+=25.
val=25

loop runs for second time for the value of n = 145.
4=4*4 = 16
val+=16
val=41

loop runs third second time for the value of n = 145.
1=1*1 = 1
val+=1
val=42

we will check if val==1 or not,so val is not equals to 1 so,we will go to next conditoon where we will check if 42 is present in the set or not,so,42 is not present on the set so this condition is also not satisfied,so we will do n=val and insert 42 on the set.
st=[16,37,58,89,145,42]

loop runs for first time for the value of n = 42.
2=2*2 = 4
val+=4
val=4

loop runs for second time for the value of n = 42.
4=4*4 = 16
val+=16
val=20

we will check if val==1 or not,so val is not equals to 1 so,we will go to next conditoon where we will check if 20 is present in the set or not,so,20 is not present on the set so this condition is also not satisfied,so we will do n=val and insert 20 on the set.
st=[16,37,58,89,145,42,20]


loop runs for first time for the value of n = 20.
0=0*0 = 0
val+=0
val=0

loop runs for second time for the value of n = 20.
2=2*2 = 4
val+=4
val=4

we will check if val==1 or not,so val is not equals to 1 so,we will go to next conditoon where we will check if 4 is present in the set or not,so,4 is not present on the set so this condition is also not satisfied,so we will do n=val and insert 4 on the set.
st=[16,37,58,89,145,42,20,4].

loop runs for first time for the value of n = 4.
4=4*4=16
val+=16
val=16

we will check if val==1 or not,so val is not equals to 1 so,we will go to next conditoon where we will check if 16 is present in the set or not,so,16 is present on the set so this condition is satisfied,so we will return false.






