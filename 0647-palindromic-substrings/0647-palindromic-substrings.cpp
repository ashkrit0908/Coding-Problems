class Solution {
public:
    int check(string s,int i,int j){
       int cnt=0;
       while(i>=0 and j<s.length() and s[i]==s[j]){
           cnt++;
           i--;
           j++;
       }
//return number of substring which is palindrome 
//which centre is centre i;
       return cnt;
   }
    int countSubstrings(string s) {
      int count=0;
      for(int i=0;i<s.length();i++){
//it check substring is palindrome which centre is i  and 
//length is even
          int even=check(s,i,i);
//it check the substring size is odd and centre is i and i+1;
          int odd=check(s,i,i+1);
//sum of even and odd substring
          count+=even+odd;
      }
//return total number of palindrome substring
      return count;
    }
};