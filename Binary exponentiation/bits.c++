#include <bits/stdc++.h> 
using namespace std; 

vector<int> bin;      // Declaring a global vector so that it can be returned as reference to int main() 

vector<int> decimal_to_binary_Reverse(int n) 
{ 
    while(n != 0) 
    { 
        bin.push_back(n%2); 
        n/=2; 
    } 
    return bin;	// Returns the vector of the binary representation in the reverse order. 
} 

int main() 
{ 
    long long int a, n;  cin >> a >> n;	// Takes input a and n. 

    vector<int> bin = decimal_to_binary_Reverse(n);	// Storing the binary vector to a vector. 

    long long int x = 1; 

    for(auto binary: bin) 
    { 
        // Multiply the number with ‘a’ when the binary value at the index is 1.  
        if(binary == 1) x = (x*1LL*a);	 
        a = (a*1LL*a);	// Squaring the number multiple times so that th e power is of the form 2^m; 
    } 
    cout << x; 

    return 0; 
} 