//Program Libraries
#include <cstdlib>
#include <math.h>
#include <iostream>
using namespace std;
//Global Variables
double x[6],u[6],pl,sum1;
int f[6],pd,i,j,penf,t;
//Header
void SelectionSort(double  *pinakas, int *parallhlos, int size);
//Begin of main
int main(int argc, char *argv[])
{
    for(t=0;t<=5;t++)
    {
//pd?                    
while ((pd!=500)&&(pd!=700)&&(pd!=900))
      {printf("Please insert the power demand(pd)in MW from the system \n500,700 or 900MW are your options:");
       scanf("%d", &pd);}
//Initialize L amd U arrays
int L[]={10,10,35,35,130,125};
int U[]={125,150,225,210,325,315};
//Randomization of f array
srand ( time(NULL) );
f[0]= rand() % 125 + 10;
f[1]= rand() % 150 + 10;
f[2]= rand() % 225 + 35;
f[3]= rand() % 210 + 35;
f[4]= rand() % 325 + 130;
f[5]= rand() % 315 + 125;
//Initialize B array
float B[6][6] = {
{1.40,0.17,0.15,0.19,0.26,0.22},
{0.17,0.60,0.13,0.16,0.15,0.20},
{0.15,0.13,0.65,0.17,0.24,0.19},
{0.19,0.16,0.17,0.71,0.30,0.25},
{0.26,0.15,0.24,0.30,0.69,0.32},
{0.22,0.20,0.19,0.25,0.32,0.85}
};
//Calculation of pl
sum1=0;
for (i=0;i<=5;i++)
    {for (j=0;j<=5;j++)
         {sum1=sum1+B[i][j]*f[i]*f[j];}}
         
pl=sum1;
//Print pl
printf("pl=");
printf("%f",pl);
//Initialize a,b,c,d,e,g arrays 
double a[]={0.15247,0.10587,0.02803,0.03546,0.02111,0.01799};
double b[]={38.53973,46.15916,40.3965,38.30553,36.32782,38.27041};
double c[]={756.79886,451.32513,1049.9977,1243.5311,1658.569,1356.6592};
double d[]={0.00419,0.00419,0.00683,0.00683,0.00461,0.00461};
double e[]={0.32767,0.32767,-0.54551,-0.54551,-0.51116,-0.51116};
double g[]={13.85932,13.85932,40.2669,40.2669,42.89553,42.89553};
//Calculation of Fcost  
double Fcost=0;   
       for (i=0;i<=5;i++)
       {Fcost=Fcost+(a[i]*pow(f[i],2)+b[i]*f[i]+c[i]);}
//Calculation of Ecost    
double Ecost=0;
       for(i=0;i<=5;i++)
       {Ecost=Ecost+(d[i]*pow(f[i],2)+e[i]*f[i]+g[i]);}
//Calculation of u array
for (i=0;i<=5;i++)
    {u[i]=(a[i]*pow(U[i],2)+b[i]*U[i]+c[i])/(d[i]*pow(U[i],2)+e[i]*U[i]+g[i]);}
//We call the SelectionSort function for u,U arrays of size=6       
SelectionSort(u,U,6);
//Calculation of penalty factor
penf=0;
while (penf<pd)
{penf=penf+U[i];}
//Calculation of x array
for (i=0;i<=5;i++)
    {x[i]=(a[i]*pow(f[i],2)+b[i]*f[i]+c[i])+penf*(d[i]*pow(f[i],2)+e[i]*f[i]+g[i]);}
      system("PAUSE");
//Print Fcost,Ecost
printf("FC=");
printf("%f\n",Fcost);
printf("EC=");    
printf("%f\n",Ecost);
}
       system("PAUSE");
       return EXIT_SUCCESS;
}
//end of main
//SelectionSort function
void SelectionSort(double  *pinakas, int *parallhlos, int size)
{
      int i, j, first, temp2; 
      double temp;
      for (i= size - 1; i > 0; i--)
     {
           first = 0;                 
           for (j=1; j<=i; j++)   
          {
                 if (pinakas[j] > pinakas[first])
                 first = j;
  }
         temp2 = parallhlos[first];
         temp = pinakas[first];   
         pinakas[first] = pinakas[i];
	     parallhlos[first] = parallhlos[i];
	     parallhlos[i] = temp2;
         pinakas[i] = temp; }
     return;
}


