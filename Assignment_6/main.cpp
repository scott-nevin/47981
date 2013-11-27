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
#include <string>
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

    //function prototypes
    int High(int[], int);
    int Low(int[], int);

    //Declare Variables
        const int SIZE=9;
         int array[SIZE];
         int high, low;

        //prompt user for array
         for (int i=1;i<11;i++){
             cout<<"Input value "<<i<<endl;
             cin>>array[i-1];
         }

        //determine highest and lowest
         high = High(array, SIZE);
         low = Low(array, SIZE);

         //Display results
         cout<<"The largest number in the array is "<<array[high]<<endl;
         cout<<"The smallest number in the array is "<<array[low]<<endl;

        //Exit Stage Right

}

    int High(int array[], int SIZE){

        int highIndx = 0;

        for (int pos = 1; pos < SIZE; pos++){

            if (array[pos] > array[highIndx])
                highIndx = pos;
        }
        return highIndx;

    }
    int Low(int array[], int SIZE){

        int lowIndx = 0;

        for (int pos = 1; pos < SIZE; pos++){

            if (array[pos] < array[lowIndx])
                lowIndx = pos;
        }
        return lowIndx;
}

void problem1(){

    //function prototypes
    void getSales(string[], int[], int);
    int getTotal(int[], int);
    int findHigh(int[], int);
    int findLow(int[], int);

    //Declare Variables
        const int TYPES=5;
         int high, low, total;

         //Array of salsa names
         string names[TYPES] = {"Mild", "Hot", "Sweet", "Medium", "Zesty"};

         //Array of sales
         int sales[TYPES];

         //Get number of jars sold
         getSales(names, sales, TYPES);

         //Get total sales and highest/lowest sales
         total = getTotal(sales, TYPES);
         high = findHigh(sales, TYPES);
         low = findLow(sales, TYPES);

         //Display sales report header
         cout<<endl<<endl;
         cout<<"     Salsa Sales Report \n\n";
         cout<<"Name                Jars Sold \n";
         cout<<"_____________________________ \n";

         //Display name and jars sold
         for (int type = 0; type < TYPES; type++){

             cout<<setw(6)<<names[type]<<setw(21)<<sales[type]<<endl;
         }

         //Display total sales and high/low
         cout<<"\nTotal Sales:"<<setw(15)<<total<<endl<<endl;
         cout<<"High Seller: "<<names[high]<<endl;
         cout<<"Low Seller : "<<names[low]<<endl<<endl<<endl;


        //Exit Stage Right
    }

    void getSales(string names[], int sales[], int size){

        for (int type = 0; type < size; type++){

            //Get number of jars sold
            cout<<"How many jars of "<<names[type]<<" salsa were sold last month?"<<endl;
            cin>>sales[type];

            //validate input
            while (sales[type] < 0){

                cout<<"Jars sold must be 0 or more. Please re-enter: ";
                cin>>sales[type];
            }
        }
    }

    int getTotal(int array[], int size){

        int total = 0;

        for (int pos = 0; pos < size; pos++)
            total += array[pos];

        return total;
    }

    int findHigh(int array[], int SIZE){

        int highIndx = 0;

        for (int pos = 1; pos < SIZE; pos++){

            if (array[pos] > array[highIndx])
                highIndx = pos;
        }
        return highIndx;

    }
    int findLow(int array[], int SIZE){

        int lowIndx = 0;

        for (int pos = 1; pos < SIZE; pos++){

            if (array[pos] < array[lowIndx])
                lowIndx = pos;
        }
        return lowIndx;
}

void problem2(){

    void getRain(string[], int[], int);
    int Total(int[], int);
    int Avg(int[], int);
    int highRain(int[], int);
    int lowRain(int[], int);

    //Declare Variables
        const int MONTH=12;
         int high, low, total, avg;

         //Array of salsa names
         string names[MONTH] = {"January", "February", "March", "April", "May",
         "June", "July", "August","September", "October", "November", "December"};

         //Array of rainfall
         int rain[MONTH];

         //Get number of jars sold
         getRain(names, rain, MONTH);

         //Get total rainfall, average rainfall and highest/lowest rainfall
         total = Total(rain, MONTH);
         avg = Avg(rain, MONTH);
         high = highRain(rain, MONTH);
         low = lowRain(rain, MONTH);

         //Display sales report header
         cout<<endl<<endl;
         cout<<"          Rainfall Report \n\n";
         cout<<"   Month                Rainfall (inches) \n";
         cout<<"______________________________________ \n";

         //Display name and jars sold
         for (int type = 0; type < MONTH; type++){

             cout<<setw(10)<<names[type]<<setw(24)<<rain[type]<<endl;
         }

         //Display total sales and high/low
         cout<<"\nTotal Rainfall:"<<setw(19)<<total<<endl;
         cout<<"Average rainfall per month: "<<setw(6)<<avg<<endl;
         cout<<"Highest rainfall month: "<<names[high]<<endl;
         cout<<"Lowest rainfall month  : "<<names[low]<<endl;


        //Exit Stage Right
    }

    void getRain(string names[], int rain[], int size){

        for (int type = 0; type < size; type++){

            //Get amount of rain
            cout<<"How many inches of rain were there in "<<names[type]<<"?"<<endl;
            cin>>rain[type];

            //validate input
            while (rain[type] < 0){

                cout<<"Rainfall must be 0 or more. Please re-enter: ";
                cin>>rain[type];
            }
        }
    }

    int Total(int array[], int size){

        int total = 0;

        for (int pos = 0; pos < size; pos++)
            total += array[pos];

        return total;
    }

    int Avg(int array[], int size){

        int total = 0;
        int avg;

        for (int pos = 0; pos < size; pos++){
            total += array[pos];
        }
        avg = total / 12;

        return avg;
    }

    int highRain(int array[], int SIZE){

        int highIndx = 0;

        for (int pos = 1; pos < SIZE; pos++){

            if (array[pos] > array[highIndx])
                highIndx = pos;
        }
        return highIndx;

    }
    int lowRain(int array[], int SIZE){

        int lowIndx = 0;

        for (int pos = 1; pos < SIZE; pos++){

            if (array[pos] < array[lowIndx])
                lowIndx = pos;
        }
        return lowIndx;
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



