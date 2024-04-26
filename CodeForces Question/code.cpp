#include <bits/stdc++.h> 

   using namespace std; 

     

   string int_to_string(string s) 

   { 

       string s2=""; 

       int x=0, i=0; 

       while(i<s.length()) 

       { 

           x = (x*10 + (s[i]-'0')); 

           i++; 

       } 

       int num = x; 

       while(num != 0) 

       { 

           if(num % 26 == 0) 

           { 

               s2.append("Z"); 

               num -= 26; 

               num /= 26; 

           } 

           else  

           { 

               string str = ""; 

               str += char((num%26)+64); 

               s2.append(str); 

               num /= 26; 

               str = ""; 

           } 

       } 

       reverse(s2.begin(), s2.end()); 

       return s2; 

   } 

     

   void convert_XSupperior_to_YSuperior(string s) 

   { 

       int x=0, i=0; 

       while(s[i]>=65) 

       { 

           x = (x*26 + (s[i]-64)); 

           i++; 

       } 

       int y=0; 

       while(i<s.length()) 

       { 

           y = (y*10 + (s[i]-'0')); 

           i++; 

       } 

       cout << "R" << y << "C" << x << endl; 

   } 

     

   int main() 

   { 

       int t;  cin >> t; 

       while(t--) 

       { 

           string s;   cin >> s; 

           int col_start, type; 

           if(s[0] == 'R') 

           { 

               bool num_check = false; 

               int i=1; 

               for(; i<s.length(); i++) 

               { 

                   if(num_check == false && s[i] - '0' <= 9)   num_check = true; 

                   else if(num_check == true && s[i] == 'C')    

                   { 

                       break; 

                   } 

               } 

               if(i==s.length()) 

               { 

                   convert_XSupperior_to_YSuperior(s); 

               } 

               else 

               { 

                   string s_Y = s.substr(1, i-1); 

                   string s_X = s.substr(i+1, s.length()-i); 

                   cout << int_to_string(s_X) << s_Y << endl; 

               } 

           } 

           else 

           { 

               convert_XSupperior_to_YSuperior(s); 

           } 

       } 

   } 