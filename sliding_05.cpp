// Variable size sliding window

// Largest subarray of given sum K

// video : https://www.youtube.com/watch?v=cyu_nuW5utA&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=7

// reference : https://www.geeksforgeeks.org/longest-sub-array-sum-k/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4, 1, 1, 1, 2, 3, 5};
    int k = 5; // SUM

    int n = 7;//length of array

    int i=0;//starting of window
    int j=0;//ending of window

    int sum=0; // to store the sum of current window

    int max_window_size=-1; // this will store the maxium window size if the sum of that window is equal to k

    while(j<n)
    {
        sum+=arr[j];

        if(sum<k)
        {
            j++;
        }
        else if(sum==k)
        {
            max_window_size=max(max_window_size,(j-i+1));//storing the window_size 
            j++;
        }
        else if(sum>k)
        {
            while(sum>k)
            {
                sum-=arr[i];
                i++;
            }
            j++;
        }
    }
    cout<<"Max window size of sum equal to "<<k<<" is : "<<max_window_size<<endl;
}