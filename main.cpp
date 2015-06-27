//Steve Cirelli
//Rungge-Kutta
#include <iostream.h>
#include <iomanip.h> //included for persition
#include <fstream.h> //included for file I/O

void main()
{
	long double FNF(long double, long double);
	
	fstream out_file; //creates variable for a file
	long double x1=1,h=0,x0=0,y0=0,k=0,k1=0,k2=0,k3=0,k4=0;
	long double x=0,y=0; //initial x y
	int n=0; //number of steps
	
	out_file.open("c:\\windows\\desktop\\rungekut.txt",ios::out);//opens a file for output
	
	cout <<"y= ? ";
	cin >> y;
	
	cout <<"\nx= ? ";
	cin >> x;
	
	cout <<"\nn= ? ";
	cin >> n;

	h= (x1-x)/n; //step size

	for(int i=1; i<=n; i++)
	{
		x0=x;
		y0=y;
		
		k1= FNF(x,y); //call function
		
		x= x0 + h/2;
		y = y0+ h*k1/2;
		
		k2= FNF(x,y);   //call function
		
		y= y0 + h*k2/2;
		
		k3 = FNF(x,y);  //call function

		x= x0+h;
		y= y0+ h*k3;
		
		k4= FNF(x,y); //call function
		
		k= (k1 + 2*k2 + 2*k3 + k4)/6;
		y = y0 + h*k;
		
		cout.precision(10);
		out_file.precision(10);
		cout << "\nx= " << x << " y= " << y << " "; //output
		out_file << "\nx= " << x << " y= " << y << " "; //output to a file for printing
	}
	
	out_file.close();//closes out put file

	char hold;
	cout <<'\n';
	cin >> hold;

	return;
}


long double FNF(long double x, long double y)
{
	return 4/(1+(x*x)); //define function f
}


/* 1. 10 subintervals
   2. 10 subintervals
   3. 10 subintervals

  dy/dx= y, y(0)=1
Output:
x= 0.1 y= 1.105170833 
x= 0.2 y= 1.221402571 
x= 0.3 y= 1.349858497 
x= 0.4 y= 1.49182424 
x= 0.5 y= 1.648720639 
x= 0.6 y= 1.822117962 
x= 0.7 y= 2.013751627 
x= 0.8 y= 2.225539563 
x= 0.9 y= 2.459601414 
x= 1   y= 2.718279744 

dy/dx 1/x, y(1)=0
Output:
x= 1.9 y= -0.05129329735 
x= 1.8 y= -0.1053605225 
x= 1.7 y= -0.1625189414 
x= 1.6 y= -0.22314357 
x= 1.5 y= -0.2876821005 
x= 1.4 y= -0.356674985 
x= 1.3 y= -0.4307829758 
x= 1.2 y= -0.5108257108 
x= 1.1 y= -0.5978371294 
x= 1   y= -0.6931473747 

dy/dx 4/(1+x^2), y(0)=0
Output:
x= 0.1 y= 0.3986749298 
x= 0.2 y= 0.7895827906 
x= 0.3 y= 1.165827826 
x= 0.4 y= 1.522026129 
x= 0.5 y= 1.854590949 
x= 0.6 y= 2.161678375 
x= 0.7 y= 2.442904098 
x= 0.8 y= 2.698963901 
x= 0.9 y= 2.931260459 
x= 1   y= 3.141592653 
*/