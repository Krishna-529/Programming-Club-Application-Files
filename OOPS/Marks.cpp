#include <bits/stdc++.h> 

using namespace std; 

  

class Marksheet 

{ 

    private: 

        int marks; 

    public: 

        Marksheet(){}; 

        int getMarks()   

        { 

            return marks; 

        } 

        void setMarks(int marks) 

        { 

            this->marks = marks; 

        } 

}; 

  

class Students 

{ 

    private: 

        int marks; 

    public: 

        Students(int i, Marksheet obj) 

        { 

            marks = obj.getMarks(); 

        }; 

        int getMarks()   

        { 

            return marks; 

        } 

}; 

  

int main() 

{ 

    Marksheet marks_obj[126]; 

    for(int i=0; i<126; i++)    marks_obj[i].setMarks(50); //We assign 50 marks to each students. 

     

    cout << "Enter your role.\n1.\t1 - For Teacher\n2\t2 - For Student\n"; 

    int x;  cin >> x; 

    if(x==1) 

    { 

        cout << "Enter the roll number for which you want to change marks.\t"; 

        int i; cin >> i; 

        i--; 

        cout << "The curent score is:\t" << marks_obj[i].getMarks() << endl; 

        cout << "Enter the marks you want to set.\t"; 

        int marks; cin >> marks; 

        marks_obj[i].setMarks(marks); 

        cout << "The score has been change to " << marks_obj[i].getMarks(); 

    } 

    else 

    { 

        cout << "Enter your roll number.\t"; 

        int i;  cin >> i; 

        i--; 

        cout << "Your score is :\t" << Students(i, marks_obj[i]).getMarks() << endl; 

    } 

     

    return 0; 

}