#include <bits/stdc++.h> 

using namespace std; 

  

long long int matrix[4];	      //  Declaring a global array for the matrix so that it can be returned as argument. 

vector<int> bin;	// Declaring a global vector  

  

long long int* matrix_multiplication(long long int m1[], long long int m2[]) 

{ 

    long long int a1 = m1[0];	// a(1,1) of the first matrix 

    long long int b1 = m1[1];	// a(1,2) of the first matrix 

    long long int c1 = m1[2];	// a(2,1) of the first matrix 

    long long int d1 = m1[3];	// a(2,2) of the first matrix 

     

    long long int a2 = m2[0];	// a(1,1) of the second matrix 

    long long int b2 = m2[1];	// a(1,2) of the second matrix 

    long long int c2 = m2[2];	// a(2,1) of the second matrix 

    long long int d2 = m2[3];	// a(2,2) of the second matrix 

     

// Matrix multiplication... 

    matrix[0] = a1*1LL*a2 + b1*1LL*c2; 

    matrix[1] = a1*1LL*b2 + b1*1LL*d2; 

    matrix[2] = a2*1LL*c1 + c2*1LL*d1; 

    matrix[3] = b2*1LL*c1 + d1*1LL*d2; 

     

    return matrix;	// Returns the address pointer of the array matrix 

} 

  

vector<int> decimal_to_binary_Reverse(int n)		// Same as the binary exponentiation. 

{ 

    while(n!=0) 

    { 

        bin.push_back(n%2); 

        n/=2; 

    } 

    return bin; 

} 

  

int main() 

{ 

    int n;  cin >> n; 

    if(n == 1 || n == 2) 

    { 

        cout << 1; 

        return 0; 

    } 

     

    long long matr[4] = {1, 1, 1, 0};	//  The fibonacci matrix 

    vector <int> bin = decimal_to_binary_Reverse(n-2); 

     

    long long int mat[4] = {1, 0, 0, 1};	// Identity matrix. 

    long long int *m;	// Pointer declaration 

     

    for(auto binary: bin)	 

    { 

        if(binary == 1) 

        { 

            m = matrix_multiplication(mat, matr);	// Storing the returned address in the pointer 

            for(int i=0; i<4; i++) mat[i] = m[i];	       // storing the array in a separate array to avoid pointer overwrite 

        } 

        m = matrix_multiplication(matr, matr); 

        for(int i=0; i<4; i++) matr[i] = m[i]; 

    } 

     

// The n’th fibonacci number is (mat(1, 1)*1 + mat(1, 2)*1) 

    cout << mat[0]+mat[1]; 


    return 0; 

} 