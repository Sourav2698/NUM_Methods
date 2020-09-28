#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;

double f(double x){	//define your function here
return exp(-2.*x);
}

int main(){
double eps = 1e-8;	//a small number to determine accuracy
int N = 1000;		//max number of iterations
double x = 0.8;		//set initial guess x0
double y = f(x);	//y = x_{i+1} = f(x_{i})
int count = 0;          //to count the number of iterations


ofstream myfile;
myfile.open("OutputValue.txt");		//A file named "OutputValue.txt" is created with 3 columns: No. of iterations , x , f(x) 



myfile<<"No. of iterations"<<setw(20)<<"   x   "<<setw(20)<<"    f(x)  "<<endl;  //writing the column names into the file
myfile<<"-----------------"<<setw(20)<<"-------"<<setw(20)<<"----------"<<endl;



for(int i = 0; i<= N; i++){
myfile<<setw(6)<<i<<setw(31)<<x<<setw(19)<<f(x)<<endl; //writing the values to the file "OutputValue.txt"
	x = y;
	y = f(x);


if(abs(y - x) < eps){
myfile<<"The required root after "<<i<<" iterations is : "<<f(x)<<endl;	//writing the root into the file 
cout<<"The required root after "<<i<<" iterations is : "<<f(x)<<endl;   //printing out the root 
break;
}


if(i == N) cout<<"No root found : Maximum iteration reached"<<endl;     //if the root is not found, prints out the message
}

return 0;
}
