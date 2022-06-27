// https://www.youtube.com/watch?v=EHCGAZBbB88&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=1

// Maximum Subarray sum of a given size k

//Reference : https://www.geeksforgeeks.org/find-maximum-minimum-sum-subarray-size-k/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //This is method taught by Aditya Verma (Better method in terms of window visualisation)
    int arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20};

    int k = 4;//window size
    int n=9;//size of array

    /*
    If (i) is pointing to the start of window and (j) is pointing to the end then,
    the   (j-i+1) is the size of the window
    */

   int i=0,j=0; //first both ptrs are pointing in the beginning

   int current_sum=0,max_sum=INT_MIN;

   while(j<n)
   {
        current_sum+=arr[j];
        if((j-i+1)<k)
        {
            j++;
        }
        else if(j-i+1==k)
        {
            max_sum=max(max_sum,current_sum);
            current_sum-=arr[i];
            i++,j++;
        }
   }
   cout<<"Max subarray sum of size k is : "<<max(max_sum,current_sum);
}