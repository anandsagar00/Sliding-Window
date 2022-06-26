
// https://www.youtube.com/watch?v=EHCGAZBbB88&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=1

// Maximum Subarray sum of a given size k

//Reference : https://www.geeksforgeeks.org/find-maximum-minimum-sum-subarray-size-k/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;
    int n=9;

    int sum=0;
    int max_sum=-1;

    //summing up till the first window
    for(int i=0;i<k;i++)
    sum+=arr[i];

    if(sum>max_sum)
    max_sum=sum;

    for(int i=k;i<n;i++)
    {
        sum=sum+arr[i];//adding the new element
        sum=sum-arr[i-k];//removing the first element

        if(sum>max_sum)
        max_sum=sum;
    }

    cout<<"Max subarray sum of size "<<k<<" is : "<<max_sum<<endl;
    
}
