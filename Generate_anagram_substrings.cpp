/*
Generate Anagram Substrings

You are given a lowercase alphabet string s. Return all substrings in s where there is another substring in s at a different location that is an anagram. Return the list sorted in lexicographic order.

Constraints

    1 ≤ n ≤ 100 where n is the length of s

Example 1
Input

s = "aba"

Output

["a", "a", "ab", "ba"]

Explanation

We have "a" and "a" which are anagrams. Also, "ab" and "ba" are anagrams.
*/

//code goes here

vector<string> solve(string s) {

//for storing count of given substring
   map<vector<int>,int> m1;
   int i,j;
   //for storing corresponding substring to given vector(this can suffice no need to use previous(by checking size of m1[vx].size() instead of cn inside line 23 for loop) but used here)
   map<vector<int>,vector<string>> m2;
   //for generating all substrings
   for(i=0;i<s.length();i++)
   {
       vector<int> v1(26,0);
       string st="";
       for(j=i;j<s.length();j++)
       {
           st+=s[j];
          v1[s[j]-'a']+=1;
          m2[v1].push_back(st);
          m1[v1]+=1;
       }
   }
vector<string> strq;//list for getting all anagramic substrings
   for(auto x: m1)
   {
       vector<int> vx=x.first;
       int cn=x.second;//count of substring with that anagram
       
       if(cn>1)//as if cn==1 thrn only one exist which does'nt fulfill angram condition
       {
           while(cn--){
           string str=m2[vx].back();//getting substring from back of vector
           strq.push_back(str);//pushing substr to out returning list
           m2[vx].pop_back();//popping back from vector
           }
       }

   }

sort(strq.begin(),strq.end());//sorting for lexicographical list

return strq;

}
