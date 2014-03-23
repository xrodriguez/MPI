#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

double max(double a, double b){
        if(a>=b) return a;
            else return b;

}
double miabs(double a, double b){
    double c;
    c=a-b;
    if(c>=0) return c;
    else return -1.0*c;
}


main(){
   double A[4][4]={{2,-1,0,0},
                    {-1,2,-1,0},
                    {0,-1,2,-1},
                    {0,0,-1,2},
    };
    double b[4]={19,19,-3,-12};
    double sm=1.0,w=1.5,s1,su,xi;
    double x[4]={0,0,0,0};
    int i,j,n=4,k;
    double t1,t2;
/*
    for(i=0;i<n;i++)
        u[0][i]=exp(i)-cos(i);
    for(i=0;i<n;i++)
        u[i][0]=cos(i)-exp(i);
    for(i=0;i<n;i++)
        u[4][i]=(exp(i)*cos(4))-exp(4)*cos(i);
    for(i=0;i<n;i++)
        u[i][4]=exp(4)*cos(i)-exp(i)*cos(4);
 */   
    k=9;
    while(sm>0.0000001){
        s1=0.0;
        sm=0.0;
        for(i=0;i<n;i++){
            su=b[i];
            for(j=0;j<=i-1;j++)
                su=su-A[i][j]*x[j];
            for(j=i+1;j<n;j++)
                su=su-A[i][j]*x[j];
            xi=(1-w)*x[i]+w*su/A[i][i];
            sm=max(miabs(x[i],xi),sm);
            x[i]=xi;
            s1=max(s1,miabs(x[i],0));
            printf("%f  ",x[i]);
        }
        printf("\n");
        printf("\n");
        sm=sm/s1;
    }
}

