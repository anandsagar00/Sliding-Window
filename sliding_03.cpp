//count occurences of Anagram of a given string into another string

//video link : https://www.youtube.com/watch?v=MW4lJ8Y0xXk&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=5

//reference : https://www.geeksforgeeks.org/count-occurrences-of-anagrams/#:~:text=Given%20a%20word%20and%20a,hence%20the%20count%20is%203.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string text = "forxxorfxdofr";
    string word = "for";

    unordered_map<char,int> letter_count_in_word;//to store the count of each characters in word
    unordered_map<char,int> letter_count_in_text;//to store the count of each character in sliding window of size of length equal to word

    int n=text.length();//store the length of text
    int l=word.length();//to store the length of word , (This also will be equal to the length of window)
    int k=l;

    //this loop counts the freq of each char in word
    for(int i=0;i<l;i++)
    letter_count_in_word[word[i]]++;

    int i=0,j=0;

    int count=0;

    while(j<n)
    {
        letter_count_in_text[text[j]]++;
        if((j-i+1)<k)
        {
            j++;
        }
        else
        {
            int flag=0;//flag to denote anagram not present in the window
            auto it=letter_count_in_word.begin();
            for(;it!=letter_count_in_word.end();it++)
            {
                if((it->second)!=letter_count_in_text[(it->first)])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            count++;
            letter_count_in_text[text[i]]--;
            i++;
            j++;
        }
    }

    cout<<"Total anagrams of "<<word<<" present in "<<text<<" are : "<<count<<endl;

}