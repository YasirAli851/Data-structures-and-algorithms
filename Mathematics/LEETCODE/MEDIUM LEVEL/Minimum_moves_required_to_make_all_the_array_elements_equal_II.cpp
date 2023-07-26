Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.

Example 1:-
Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

Example 2:-
Input: nums = [1,10,2,9]
Output: 16

Note:-if we have a condition that we can either increase or decrease an element in each iteration then we will simply follow the below approach. 

so,lets look at the approach:-

step 1:-we will sort the array.

step 2:-after sorting the array we will pick the middle element from the array.So,we will create a variable "md" in which we will store the value that is at the middle of the array.We will get the middle value by doing (array[array.size()/2])

step 3:-we will find the absolute difference between "md" and all the elements of the array and store the sum of absolute differences in a variable called "ans".

Lets have a look on the code:-

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int md=nums[nums.size()/2];
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=abs(md-nums[i]);
        }
        return ans;

    }
};

lets do the dry run of an example:-

step 1:-Sorting the array.

array=[1,10,2,9].
after sorting the array.
array=[1,2,9,10].

step 2:-finding the middle element.

The value of array.size() = 4.
so,array.size()/2=2.
md=array[array.size()/2].
md=array[2].
md=9.

step 3:-finding and adding the absolute difference in ans.

ans=0

iteration 1:-
i=0.
md=9
ans=ans+abs(md-array[0]).
0=0+8.
ans=8.

iteration 2:-
i=1.
md=9
ans=ans+abs(9-array[1]).
8=8+7.
ans=15.

iteration 3:-
i=2.
md=9
ans=ans+abs(9-array[2]).
15=15+0.
ans=15.

iteration 4:-
i=3.
ans=ans+abs(9-array[3]).
15=15+1.
ans=16.

so,as the size of our array was 4,so we have iterated from 0 to 3 and after that we have moved out of loop and the final value of ans is the minimum number of moves required to make all the array elements equal,i.e 16.






