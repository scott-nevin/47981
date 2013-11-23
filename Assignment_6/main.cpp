/*  Scott Nevin
    November 27, 2013
    Assignment 6
 */

//Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//No GLobal Constants or variables

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem0();
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();



//Begin Execution Here!!!
int main(){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 0:    problem0();break;
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        case 7:    problem7();break;
        case 8:    problem8();break;
        case 9:    problem9();break;
        default:   def(inN);}
    }while(inN>=0&&inN<=9);
    return 0;
}

void Menu(){
    cout<<"Menu for Assignment 5"<<endl;
    cout<<"Type 0 for Gaddis 7th Edition Chapter 7 problem 1"<<endl;
    cout<<"Type 1 for Gaddis 7th Edition Chapter 7 problem 2"<<endl;
    cout<<"Type 2 for Gaddis 7th Edition Chapter 7 problem 3"<<endl;
    cout<<"Type 3 for Gaddis 7th Edition Chapter 7 problem 4"<<endl;
    cout<<"Type 4 for Gaddis 7th Edition Chapter 7 problem 5"<<endl;
    cout<<"Type 5 for Gaddis 7th Edition Chapter 7 problem 6"<<endl;
    cout<<"Type 6 for Gaddis 7th Edition Chapter 7 problem 7"<<endl;
    cout<<"Type 7 for Gaddis 7th Edition Chapter 7 problem 8"<<endl;
    cout<<"Type 8 for Gaddis 7th Edition Chapter 7 problem 9"<<endl;
    cout<<"Type 9 for Gaddis 7th Edition Chapter 7 problem 10"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem0(){

    //Function Prototypes
    void filArry(int [],int);
    void prntAry(int [],int,int);
    void swap1(int &,int &);
    void sortPos(int [],int,int);
    void markSort(int [],int);

    //Declare Variables
       const int SIZE=9;
        int array[SIZE];

       //prompt user for array
        for (int i=1;i<11;i++){
            cout<<"Input value "<<i<<endl;
            cin>>array[i-1];
        }

       //Print Array
       prntAry(array,SIZE,10);
       cout<<endl;

       //Sort the array
        markSort(array,SIZE);

        //Display results
        cout<<"The largest number in the array is "<<array[9]<<endl;
        cout<<"The smallest number in the array is "<<array[0]<<endl;

       //Exit Stage Right
}
   void markSort(int a[],int n){
         for(int i=0;i<n-1;i++){
                sortPos(a,n,i);
        }
   }

   void sortPos(int a[],int n,int pos){
        if(pos>n-1)return;
        for(int i=pos+1;i<n;i++){
                if(a[pos]>a[i])swap1(a[pos],a[i]);
         }
   }

   void copy(int a[],int b[],int n){
        for(int i=0;i<n;i++){
                b[i]=a[i];
        }
   }

   void swap1(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
   }

   void prntAry(int a[],int n,int perLine){
         for(int i=0;i<n;i++){
                cout<<a[i]<<" ";
                if(i%perLine==(perLine-1))cout<<endl;
        }
        cout<<endl;
   }

   void filArry(int a[],int n){
         for(int i=0;i<n;i++){
                a[i]=rand()%900+100;
        }
   }

void problem1(){


}

void problem2(){

}

void problem3(){

}

void problem4(){

}

void problem5(){

}

void problem6(){

}

void problem7(){

}

void problem8(){

}

void problem9(){

}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}



