// First negative number in every window of size K

// Video : https://www.youtube.com/watch?v=uUXXEgK2Jh8&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=4

// Reference : https://www.geeksforgeeks.org/first-negative-integer-every-window-size-k/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {-8, 2, 3, -6, 10,11,12,-34,14,-1,12};

    int n=11;//length of array
    int k = 3;//size of window
    
    //if no negative number in a window then print 0

    int i=0;
    int j=0;

    queue<int> negative_numbers;//to store queue of -ve numbers

    while(j<n)
    {
        if(arr[j]<0)
        negative_numbers.push(arr[j]);//storing all the -ve numbers in the queue

        if((j-i+1)<k)
        {
            j++;
        }
        else if((j-i+1)==k)
        {
            if(negative_numbers.empty())
            {
                cout<<"0 ";
            }
            else 
            {
                cout<<negative_numbers.front()<<" ";
                //while changing the window we should check if the first element of prev window is present at front of queue
                //if yes then remove else don't
                if(arr[i]==negative_numbers.front())
                {
                    negative_numbers.pop();
                }
            }
            i++;
            j++;
        }
    }
    
}