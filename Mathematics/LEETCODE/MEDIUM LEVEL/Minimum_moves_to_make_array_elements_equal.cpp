Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.In one move, you can increment n - 1 elements of the array by 1.

Example 1:-Input: nums = [1,2,3]
Output: 3
Explanation: Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4].

Example 2:-Input: nums = [1,1,1]
Output: 0

Approach:-

step 1:-we will sort the array first.
Step 1:-We will try to find the minimum element from the array and store it in a variable 'm'.
step 2:-After step 1,we will do the substraction between 'm' and and all the array elements and store the sum of absolute differences inside a variable sum.

class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m=nums[0];
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=abs(m-nums[i]);
        }
        return sum;
        
    }
};


lets do the dry run:-
suppose we have an array [2,1,3].
so lets look at the first step that we are going to do:-
step 1:-we have sorted the array and after sorting we have 1 as first element in the array and i have stored that 1 in a variable called "m".
step 2:-we will find the absolute difference between "m" and all the elements of the array and store the sum of absolute differences in a variable called "sum".


so,lets look at each iteration:-
array=[2,1,3].
after sorting,array=[1,2,3]
m=array[0],so m=1.
sum=0.

iteration 1:-
i=0
m=1,so absolute difference between m=1 and array[0]=1 is (1-1)=0.
sum=sum+abs(m-array[0]).
0=0+0.
sum=0.

iteration 2:-
i=1
m=1,so absolute difference between m=1 and array[1]=2 is (1-2)=1.
sum=sum+abs(m-array[1]).
0=0+1.
sum=1.

iteration 3:-
i=2
m=1,so absolute difference between m=1 and array[2]=3 is (1-3)=2.
sum=sum+abs(m-array[2]).
1=1+2
sum=3.

so,as the size of our array was 3,so we have iterated from 0 to 2 and after that we have moved out of loop and the final value of sum is the minimum number of moves required to make all the array elements equal,i.e 3.

