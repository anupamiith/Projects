#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
int main()
{ 
    float a[100][100], b[100], x[100], y[100];
    int n ,m ,i ,j, flag=0,sum=0 ;
    cout << "Enter size of array(Square matrix) : ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << "Enter the values of (" << i << ", " << j<< "):";
            cin >> a[i][j];
        }
    }
    cout<<endl;
    for (i = 1; i <= n; i++)           // checking diagonally dominant matrix or not
    {
    	sum=0;
        for (j = 1; j <= n; j++)
        {
        	if(i != j)
        	{
        		sum = sum + abs(a[i][j]);
			}
	    }
	    if(abs(a[i][i]) < sum)
	    {
	    	flag=1;
		}
    }
    if(flag == 0)
    {
    	cout<<"It is a diagonally dominant matrix"<<endl;
    	
    	cout << "\nEnter the Value of B matrix\n";
        for (i = 1; i <= n; i++)
    	{
          cout << "Enter the values of (" << i << ", 1):";
          cin >> b[i];
        }
        cout << "\nEnter initial values of x\n";
        for (i = 1; i <= n; i++)
        {
        	cout << "Enter the value of (x"<<i<<"):";
        	cin >> x[i];
    	}
    	cout << "\nEnter the no. of iteration : ";
    	cin >> m;    	
    	clock_t startTime = clock();    	
    	while (m > 0)
    	{
        	for (i = 1; i <= n; i++)//to run the loop for each element of x matrix
        	{
            	y[i] = (b[i] / a[i][i]); // to calculate initial value of x[i]
            	for (j = 1; j <= n; j++)  // to run the loop for calculating x[i]
            	{
               	 	if (j == i)         
                 	continue;
                	y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);//  calculating x[i] using other x[j] values
                	x[i] = y[i];                                // setting x[i] value to the calculated value for using in next calculation
                }
          	cout<<"x"<< i << " = "<<fixed<<y[i]<<"     "; // printing values // printing values
        	}
        	cout << "\n";
        	m--;          // decreasing the number of iteration
    	} 
    	clock_t endTime = clock();
    	cout<<"execution time was "<<(double)(endTime-startTime)/CLOCKS_PER_SEC <<" sec";
	}
    else
    cout<<"It is not a diagonally dominant matrix"<<endl;
return 0;
} 
