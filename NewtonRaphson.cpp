#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;

double f(double x){            //define your function here
//return x*x - 3.*x + 2.;      //func-1(uncomment to use)
return x - 2.*cos(x);          //func-2 (comment out if not used)
}

double df(double x){           //define the derivative of your function here
//return 2.*x - 3.;            //derivative of func-1 (uncomment to use)
return 1. + 2.*sin(x);         //derivative of func-2 (cooment out if not used)
}

double setGuess(){             //function to set initial guess value
  double guess;
  cout<<"Enter again the initial guess : "<<endl;
  cin>>guess;
  return guess;
}

void NewtonRaphson(double x0, double eps, int N){                                                //function for NewtonRaphson method
  ofstream File;
  File.open("Data2.txt");        //File named "Data.txt" created
  int Flag = 0;                 //Flag to mark converge
  int Response = 0;             //variable to store response from user
  do{
    int count = 1;              //counter initialised
    double Di = x0 - f(x0)/df(x0);             //Error
    double Df;
    double x, y;                //y = x_(i+1)
    x = x0;                     //setting the initial parameter as xi
    File<<"Initial guess = "<<x0<<setw(20)<<"Accuracy : "<<eps<<setw(20)<<"Max iterations = "<<N<<endl;
  do {
    Df = Di;
    y = x - (f(x)/df(x));
    Df = abs(y - x);
    File<<"No. of iterations : "<<count<<setw(20)<<"xi = "<<x<<setw(20)<<"x_(i+1) = "<<y<<endl;   //writing the values to File "Data.txt"
    if(Df < eps && abs(f(y)) < eps){
      cout<<"Root after "<<count<<" interations is  : "<<y<<endl;
      File<<"Root after "<<count<<" interations is  : "<<y<<endl;
      Flag = 1;                  //convergence is marked by Flag
      break;
    }
    count += 1;
    x = y;

 } while(count <= N && Df < Di);  //while condition
 if(Flag == 0){                   //Steps to performance is convergence is not there
   cout<<"Error : Root does not converge "<<endl;
   File<<"Error : Root does not converge "<<endl;
   cout<<"Do you want to continue the program ? (0 - Abort, 1 - Continue) :";
   cin>>Response;                 //Response from user to continue the program
   if(Response == 0) break;
   x0 = setGuess();
 }
}while (Flag == 0);

File.close();
}


int main(){
int N = 1000;                     //Max no of iterations
double eps = 1e-06;               //accuracy
double x0 = 1.8;                  //initial guess value
cout<<"Enter the maximum number of iterations : ";
cin>>N;

cout<<"Enter the accuracy of the root : ";
cin>>eps;

cout<<"Enter the initial guess value : ";
cin>>x0;

NewtonRaphson(x0, eps, N);   //calling the N-R function for root finding

return 0;
}
