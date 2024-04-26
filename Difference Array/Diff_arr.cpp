#include <bits/stdc++.h> 

using namespace std; 

  

int main() 

{ 

    // Taking inputs. 

    cout << "Enter 'n' and 'q'.\n"; 

    int n, q;  cin >> n >> q;   // Taking n in input. 

     

    cout << "Enter the marks.\n"; 

    int arr[n]; 

    for(int i=0; i<n; i++)  cin >> arr[i];  // Taking array of marks in input. 

     

    int diff_arr[n];    // Declaring difference array. 

    diff_arr[0] = arr[0]; 

    for(int i=1; i<n; i++)  diff_arr[i] = arr[i]-arr[i-1];  // Assigning the difference of values as the elements in the array. 

  

    // Taking querries. 

    while(q--) 

    { 

        int l, r, x; 

        cout << "Enter the leftmost and rightmost roll numbers to change marks and the value of x(the increase in marks) in format\nl\tr\tx\n"; 

        cin >> l >> r >> x; 

        l--; r--; 

        diff_arr[l] += x;    

        if(r != n-1)    diff_arr[r+1] -= x;     // To avoid the change in the later elements and also to avoid accessing the location outside the array. 

    } 

     

    // Final output. 

    arr[0] = diff_arr[0];    

    cout << "The final marks are:\n"<<arr[0] << endl; 

     

    for(int i=1; i<n; i++) 

    { 

        arr[i] = arr[i-1]+diff_arr[i];  // Taking the prefix sum of differential array. 

        cout << arr[i] << endl; 

    } 

     

    return 0; 

}