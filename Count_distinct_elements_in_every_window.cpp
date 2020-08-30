/*
Count distinct elements in every window

Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.

Example 2:

Input:
N = 3, K = 2
A[] = {4,1,1}
Output: 2 1

Your Task:
Your task is to complete the function countDistinct() which takes the array A[], the size of the array(N) and the window size(K) as inputs and returns an array containing the count of distinct elements in every contiguous window of size K in the array A[].

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= K <= 105
1 <= A[i] <= 105 , for each valid i
*/
//code goes here
#include <bits/stdc++.h>
using namespace std;

vector <int> countDistinct(int[], int, int);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        vector <int> result = countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


vector <int> countDistinct (int a[], int n, int k)
{
    //code here.
    int i;
    vector<int> distinct;
int first=0;
unordered_map<int,int> hm;
for(i=0;i<k;i++)
{
    hm[a[i]]+=1;
    if(hm[a[i]]==1)
    {
          first+=1;
    }
}
distinct.push_back(first);
int fw=first;
int fi=0;
int wi=k-1;

    while(wi!=n-1)
    {
        if(hm[a[fi]]==1)
        {
            fw-=1;

        }
         hm[a[fi]]-=1;
        if(hm[a[wi+1]]==0)
        {
            fw+=1;

        }
        if(wi+1<n)
        hm[a[wi+1]]+=1;
        distinct.push_back(fw);
        fi++;
       // cout<<distinct[fi]<<' ';
        wi++;
    }
    
    return distinct;
}
