/*
Check whether a given String 'S' is a palindrome using recursion.


Return true or false.


Note:
You don’t need to print anything. Just implement the given function.
Example:
Input: s = "racecar"
Output: true
Explanation: "racecar" is a palindrome.
Input Format:
The first and only line of the input contains string S.
Output format:
Return a boolean value True or False.
Sample Input 1:
abbba
Sample Output 1:
true
Explanation Of Sample Input 1 :
“abbba” is a palindrome
Sample Input 2:
abcd
Sample Output 2:
false
Explanation Of Sample Input 2 :
“abcd” is not a palindrome.
Constraints:
0 <= |S| <= 10^6
where |S| represents the length of string S.
*/

# include<bits/stdc++.h>
bool helper(int s,char input[],int e){
    //base case if one element present
    if(s>=e){
        return true;
    }
//small work one case check baki recursion
if(input[s]==input[e]){
    // s++;
    // e--;
   bool ans= helper(s+1,input,e-1);
   return ans;
}
 else {
  return false;
}
}
bool checkPalindrome(char input[]) {
int s=0;
int n=strlen(input);
int e=n-1;
return helper(s,input,e);
}


