/*      Scott Nevin
 *      December 12th, 2013
 *      Purpose: Final exam 
 *      CSC-5 47981
 */

//Library includes Here!!!
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
using namespace std;

//Global Constants Here!!!

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Final"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
    
        //function prototypes
        int reverse(int);
    
        //Declare variables
    unsigned int number;
    unsigned short num;

    //Prompt user for number to convert
    cout<<"Please enter a number to be reversed."<<endl;
    cout<<"The number must be no larger than 53556."<<endl;
    cin>>number;

    while(number>53556){
        cout<<"Unable to reverse, enter a number lower than 53556 and larger than 0"<<endl;
        cin>>number;
    }
    
    //make number an unsigned short
    num = number;

    //Call reverse function
    cout<<"Reverse:   "<<reverse(num)<<endl;

}


int reverse ( int num){

    //declare reverse variable
    int digit, revrs = 0;

    //while the number is greater than 0 then keep looping
            while(num > 0){



                //get the last digit from right to left

                digit = num % 10;

                //trim the last digit

                num /= 10;



                //create the rever number with each digit

                revrs = revrs * 10 + digit;
            }



            //	return the number
            return revrs;
}

void problem2(){
    
        //Get the system time
        unsigned seed = time(0);

    //seed random number generator
    srand(seed);

    //Declare variables
   int num, user, count=0;
   bool guess = false;

   //create number
   num = 1 + rand() % 500;

   //Prompt user for input
   cout<<"Guess the number between 1 and 500"<<endl;
   cout<<"You have 9 guesses"<<endl;

   //initiate loop for guessing
   while(guess==false&&count<9){

       //Prompt user for guess
       cout<<"Input guess: ";
       cin>>user;
       count++;

       if(user==num){
           cout<<"Correct!"<<endl;
           guess = true;
       }
       else
           cout<<"Incorrect, try again"<<endl;

       if(user>num){
           cout<<"Guess was too high"<<endl;
       }
       if(user<num){
           cout<<"Guess was too low"<<endl;
       }
   }

   if(count==9){
       cout<<"Out of guesses"<<endl;
   }

   cout<<"game over"<<endl;


}

void problem3(){
    
        //function prototypes
    void filEven(vector<int> &,int);
    void filOdd(vector<int> &,int);
    void prntAry(vector<int> &,int, int);
        
        //Declare array size variable
        int SIZE;
        //Prompt for array size
        cout<<"Input array size"<<endl;
        cin>>SIZE;

        //Declare Variables and initialize the
        //random number seed
        vector<int> aryEven(SIZE), aryOdd(SIZE);
        srand(static_cast<unsigned int>(time(0)));
        int perLine;

        //Fill the even Array
        filEven(aryEven,SIZE);

        //Fill the odd array
        filOdd(aryOdd, SIZE);

        //prompt for number of columns
        cout<<"How many columns should be output?"<<endl;
        cin>>perLine;

        //Print even Array
        prntAry(aryEven,SIZE,perLine);
        cout<<endl;

        //Print odd Array
        prntAry(aryOdd,SIZE, perLine);
        
    }

    void prntAry(vector<int> &a,int n, int perLine){

          for(int i=0;i<n;i++){
                 cout<<setw(2)<<a[i]<<" ";
                 if(i%perLine==(perLine-1))cout<<endl;
         }
         cout<<endl;
    }

    void filEven(vector<int> &a,int n){

        int temp;

          for(int i=0;i<n;i++){
                 temp = 1 + rand() % 99;

                 if(temp % 2 == 0){
                     a[i]=temp;
                 }
                 else
                     i--;
         }
    }

    void filOdd(vector<int> &a,int n){

        int temp;

          for(int i=0;i<n;i++){
                 temp = 1 + rand() % 99;

                 if(temp % 2 == 0){
                     i--;
                 }
                 else
                     a[i]=temp;
         }
}

void problem4(){
        
    //function prototypes
    void nums(int &, int &, int &, int &, int &);

    //Declare variables
    int num1=0, num2=0, num3=0, num4=0, num5=0, i;

    //seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    //initiate random number loop
    for(i=0;i<10000;i++){

        //call random number
        //and incrementer loop
        nums(num1, num2, num3, num4, num5);
    }

    //output results
    cout<<"Generation results:"<<endl;

    cout<<"9   occurred "<<num1<<" times"<<endl;
    cout<<"51  occurred "<<num2<<" times"<<endl;
    cout<<"78  occurred "<<num3<<" times"<<endl;
    cout<<"181 occurred "<<num4<<" times"<<endl;
    cout<<"251 occurred "<<num5<<" times"<<endl;

}

void nums(int &num1, int &num2, int &num3, int &num4, int &num5){

    int temp, num;
    short int rndseq[]={9,51,78,181,251};

    temp = rand() % 5;
    num = rndseq[temp];
    
    cout<<num<<endl;

    if(num==9){
        num1++;
    }
    else if(num==51){
        num2++;
    }
    else if(num==78){
        num3++;
    }
    else if(num==181){
        num4++;
    }
    else if(num==251){
        num5++;
    }
    cout<<endl;

}

void problem5(){
        cout<<"In problem # 5"<<endl<<endl;
}

void problem6(){
    
    //function prototypes
    int input();
        //Declare Variables and initialize the
    //random number seed
    int array[5][6];
    srand(static_cast<unsigned int>(time(0)));
    int row=0, col=0, tot=0;

    //Fill array
    for(int i=0; i<5; i++){

            for(int j=0; j<6; j++){

                array[i][j] = input();
       }
     }

    //Print array without totals
    for(int i=0; i<5; i++){

            for(int j=0; j<6; j++){

                cout<<setw(7)<<array[i][j];
       }
            cout<<endl;
   }

    cout<<endl<<endl;

    //print array with totals
    for(int i=0; i<5; i++){

            for(int j=0; j<6; j++){

                cout<<setw(7)<<array[i][j];
                row+=array[i][j];
       }
            cout<<setw(7)<<row<<endl;
   }

    //sum columns and display
    for(int j=0; j<6; j++){

        for (int i=0; i<5; i++){

            col+=array[i][j];
        }
        cout<<setw(7)<<col;
        tot += col;
    }
    cout<<setw(7)<<tot<<endl;

}

int input(){
    int num;
    num = 1 + rand() % 150;
    return num;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

