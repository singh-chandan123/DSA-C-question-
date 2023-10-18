#include <bits/stdc++.h> 
string longestPalinSubstring(string &str)
{
    int startind=0;//start index
    int longlen=1;//their is always one length
    int n=str.length();
for(int i=0;i<n;i++){
    //even case
    int lowind=i;
    int highind=i+1;
    while(lowind>=0&&highind<n&&str[lowind]==str[highind]){
        //update length
        if(highind-lowind+1>longlen){
           startind=lowind;
          
          longlen=highind-lowind+1;
        }
lowind--;
highind++;
    } 
    //oddcase
       lowind=i-1;
     highind=i+1;
    while(lowind>=0&&highind<n&&str[lowind]==str[highind]){
        //update length
        if(highind-lowind+1>longlen){
           startind=lowind;
          
          longlen=highind-lowind+1;
        }
lowind--;
highind++;
    }
}
return str.substr(startind,longlen);
}