//Maximum of all sub-arrays of size k

//video :  https://www.youtube.com/watch?v=xFJXtB5vSmM&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=6

//reference : https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};

    int n=10; //size of array
    int  k = 3; //window size

    int i=0;//start of window
    int j=0;//end of window

    deque<int> curr_max;//doubly ended queue to store max element candidate

    while(j<n)
    {
        while(!curr_max.empty() && curr_max.back()<arr[j])
        curr_max.pop_back();
        
        curr_max.push_back(arr[j]);

        if((j-i+1)<k)
        {
            j++;
        }
        else if((j-i+1)==k)
        {
            cout<<curr_max.front()<<" ";

            if(curr_max.front()==arr[i])//if the current max is equal to the front element of the old window them remove it
            curr_max.pop_front();
            i++;
            j++;
        }
    }


}