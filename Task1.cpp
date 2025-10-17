#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

class CgpaCalculator{
    public:
    
    vector<int> subjectmarks;
    vector<int> creditHours;
    vector<char> G;
    int number;
    CgpaCalculator(int number){
        this->number=number;
        subjectmarks.resize(number);
        creditHours.resize(number);
        G.resize(number);
    }
    void EnterGrade(){

        for(int i=0;i<number;i++){
            char grade;
            int gtn;
           do{ cout<<"Enter subject "<<(i+1)<<" grade: ";
            cin>>grade;
            cout<<"Enter credit hours for subject "<<i+1<<": ";
            cin>>creditHours[i];
            gtn=gradeToNumber(grade);
            subjectmarks[i]=gtn; 
            if(gtn==-1){
                cout<<"invalid grade! try again:\n";
            }
             G[i]=grade;
            }while(subjectmarks[i]==-1);

        }  
    }
    int gradeToNumber(char grade){
        if(grade=='A'|| grade=='a')
        return 10;

         else if(grade=='B'|| grade=='b')
        return 9;

         else if(grade=='C'|| grade=='c')
        return 8;

         else if(grade=='D'|| grade=='d')
        return 7;

         else if(grade=='E'|| grade=='e')
        return 6;

         else if(grade=='F'|| grade=='f')
        return 5;
         else if(grade=='g'|| grade=='G')
        return 4;
         else if(grade=='h'|| grade=='H')
        return 3;
         else if(grade=='i'|| grade=='I')
        return 2;
         else if(grade=='j'|| grade=='J')
        return 1;
        else return -1;  
    }

    double calculation(){
        int totalMarks=0;
        int totalcredit=0;
        for(int i=0;i<number;i++){
            totalcredit += creditHours[i];
            totalMarks += subjectmarks[i] * creditHours[i];
        }
        if(totalcredit==0) return 0;
        return (double)totalMarks/totalcredit;
    }
    
   void showGrade(){
    cout<<"The grades you have entered:\n";
    for(int i=0;i<number;i++){
        cout<<"Grade of "<<i+1<<" subject is "<<G[i]<<"\n";
    }

   }

    ~CgpaCalculator(){}

};

int main(){
    int numberOfCourses;
    try{
        cout<<"Enter number of courses:";
        cin>>numberOfCourses;
        if(numberOfCourses<=0){
            string s= "Number of courses can not be "+ to_string(numberOfCourses);
            throw s;
        }
        CgpaCalculator cgpaC(numberOfCourses);
        cgpaC.EnterGrade();
        double cgpa=cgpaC.calculation();
        cout<<fixed<<setprecision(2);
        cgpaC.showGrade();
        cout<<"\nYour CGPA is : "<< cgpa;
    }
    catch(string str){
        cout<<str<<endl;
    }

    
    return 0;
}


