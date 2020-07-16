#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val, double ave, int x);
extern double var_online(double val, double ave, double square_ave, int x);

int main(void)
{
    double val,ave,ave1=0,var1=0,heikin=0,bunsan=0,square_ave=0;
    int x;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);

        ave1 = ave_online(val,ave,x);
        var1 = var_online(val,ave,square_ave,x);
        heikin = ave1;
        bunsan = x*val/(x-1);
        square_ave = ave_online(val*val,square_ave,x);
        x = x+1;
        ave = ave1;

    }
    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    printf("sample mean：%f\n",ave1);
    printf("sample variance :%f\n",var1);
    printf("population mean(estimated) : %f\n",heikin);
    printf("population variance(estimated) : %f\n",bunsan);

    return 0;


}

double ave_online(double val,double ave,int x)
{
    double a;
     a = ((x-1)*ave/x) + val/x;
     return a;
    
}
double var_online(double val,double ave,double square_ave,int x)
{
    double b;
    b = (((x-1)*square_ave/x) + val*val/x) - pow(((x-1)*ave/x) + val/x,2);
    return b;
}
