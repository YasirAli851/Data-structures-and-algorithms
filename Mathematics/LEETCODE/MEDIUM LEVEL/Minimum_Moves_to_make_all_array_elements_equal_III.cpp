You are given an array nums consisting of positive integers.

You are also given an integer array queries of size m. For the ith query, you want to make all of the elements of nums equal to queries[i]. You can perform the following operation on the array any number of times:

Increase or decrease an element of the array by 1.
Return an array answer of size m where answer[i] is the minimum number of operations to make all elements of nums equal to queries[i].

Note that after each query the array is reset to its original state.

Example 1:-
Input: nums = [3,1,6,8], queries = [1,5]
Output: [14,10]
Explanation: For the first query we can do the following operations:
- Decrease nums[0] 2 times, so that nums = [1,1,6,8].
- Decrease nums[2] 5 times, so that nums = [1,1,1,8].
- Decrease nums[3] 7 times, so that nums = [1,1,1,1].
So the total number of operations for the first query is 2 + 5 + 7 = 14.
For the second query we can do the following operations:
- Increase nums[0] 2 times, so that nums = [5,1,6,8].
- Increase nums[1] 4 times, so that nums = [5,5,6,8].
- Decrease nums[2] 1 time, so that nums = [5,5,5,8].
- Decrease nums[3] 3 times, so that nums = [5,5,5,5].
So the total number of operations for the second query is 2 + 4 + 1 + 3 = 10.

Example 2:-
Input: nums = [2,9,6,3], queries = [10]
Output: [20]
Explanation: We can increase each value in the array to 10. 
The total number of operations will be 8 + 1 + 4 + 7 = 20.

Note:-My approach will be based on binary search,prefix sum and suffix sum.So,before going through my approach,plz have an idea of prefix sum,suffix sum,upper bound,lower bound and binary search.

So,lets have a look at my approach:-

step 1:-I will sort the vector,and then store the size of the vector inside a variable named "n".

step 2:-after step 1,i will create three vectors,1st vector will be having name as prefix_sum of size (n + 1) and 2nd vector will be having name as suffix_sum of size (n + 1) and 3rd vector will be having name as ans.

step 3:-After step 2,we will fill the prefix_sum vector(0 at index 0) and rest according to the nums vector and we will fill the suffix_sum vector (0 at index n) and rest according to the nums vector.

step 4:-we will iterate through the query vector and obtain the lower bound of queries[i] on vector nums.
so,for every lower bound of queries[i], we will store the index of value of lower bound in a variable position.

step 5:-now,after finding position from step 4,we will check the number of elements present at the left of position index,and as well as check the number of element present at the right of position index including position index.

step 6:-after performing step 5,we will multiply the queries[i] with the count of the numbers present at the left of the position index and after that we will substract with the value that is present at prefix_sum[position] and store the result in a variable res1.Again i will multiply the queries[i] with the count of the numbers present at the right side of position index including position index and after that i will substract with the value that is present at the suffix_sum[position] and store the result in a variable res2. and then we will do the addition of both res1 and res2 and that addition will be the minimum moves to make all the array elements equal to that queries[i].Step 4 step 5 and step 6 will be done for all the values that is present inside queries vector.and we will store the value of minimum moves inside a vector called ans.

lets have a look at my code:-

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<long long>ans;
        vector<long long>prefix_sum(nums.size() + 1);
        vector<long long>suffix_sum(nums.size() + 1);
        for(int i=1;i<=nums.size();i++)
        {
            prefix_sum[i]=prefix_sum[i - 1]+nums[i - 1];
        }
        for(int i=nums.size() - 1;i>=0;i--)
        {
            suffix_sum[i]=suffix_sum[i + 1]+nums[i];
        }
        for(int i=0;i<queries.size();i++)
        {
            long long pos=lower_bound(nums.begin(),nums.end(),queries[i])-nums.begin();
            long long answer=pos*queries[i] - prefix_sum[pos] + suffix_sum[pos] - (nums.size()-pos) * queries[i];
            ans.push_back(answer);
        }
        return ans;
    }
};

Lets do the dry run of an example:-

nums=[3,1,6,8] queries=[1,5]

step 1:-

nums=[1,3,6,8], n=nums.size() i.e=n=4.

step 2:-

prefix_sum=[] and suffix_sum=[]  and ans=[].

step 3:-

prefix_sum=[0,1,4,10,18] and suffix_sum=[18,15,14,8,0].

step 4:-

when i=0.
    queries[i]=1.
    so,lower bound of 1 in vector nums is at index 0.so,0 will be stored inside variable named position.
    position=0.

    step 5:-
    so,there are 0 elements in nums towards left side of index(0) named position.
    so,0 * queries[i]=i.e 0*1=0 =  val1.

    now,there are 4 elements in nums towards right side of index(0) including index 0.
    so,4 * queries[i]=i.e 4*1=4 =  val2.

    step 6:-

    so,we will look at the element that is present at index position i.e 0 of prefix_sum.so value at  prefix_sum[0]=0.

    so prefix_sum[0] - val1 = 0-0 = 0.
    so,we will store this 0 in a variable res1.
    res1=0.

    again,we will look at the element that is present at index position i.e 0 of suffix_sum.so value at  suffix_sum[0]=18.

    so , suffix_sum[0] - val2 = 18-4 = 14.
    so,we will store this 14 in a variable res2.
    res2=14.

    addition of res1 + res2 = 0 + 14 = 14.so,14 is the minimum moves required to make all the array elements equal to queries[0]=1.now,we will push back this 14 inside a vector called ans.

    ans=[14,]

when i=1.
    queries[i]=5.
    so,lower bound of 5 in vector nums is at index 2.so,2 will be stored inside variable named position.
    position=2.

    step 5:-
    so,there are 2 elements in nums towards left side of index(2) named position.
    so,2 * queries[i]=i.e 2*5 = 10 =  val1.

    now,there are 2 elements in nums towards right side of index(2) including index 2.
    so,2 * queries[i]=i.e 2*5 = 10 =  val2.

    step 6:-

    so,we will look at the element that is present at index position i.e 2 of prefix_sum.so value at  prefix_sum[2]=4.

    so prefix_sum[2] - val1 = 4-10 = 6.
    so,we will store this 6 in a variable res1.
    res1=6.

    again,we will look at the element that is present at index position i.e 2 of suffix_sum.so value at  suffix_sum[2]=14.

    so , suffix_sum[2] - val2 = 14-10 = 4.
    so,we will store this 4 in a variable res2.
    res2=4.

    addition of res1 + res2 = 6 + 4 = 10.so,10 is the minimum moves required to make all the array elements equal to queries[1]=5.now,we will push back this 10 inside a vector called ans.

    ans=[14,10]

    after that we will return this vector ans because size of vector queries was 2.so we have iterated from 0 to 1.

    Note:-the implementation of above steps is there in the form of code.Step 4 5 and 6 are done on loop number 3.


