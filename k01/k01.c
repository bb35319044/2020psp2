#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val, double ave, int x);
extern double var_online(double val, double ave, double square_ave, int x);

int main(void)
{
    double val,ave,ave_val,var_val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int x=1;

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

        ave = ave_online()
    }
    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    printf("平均：%f\n",ave_val);
    printf("分散は%f\n",var_val);

    return 0;


}

double ave_online(double val)
{
    int x=1;
    x++;
    ave=(1/x)*((x-1)*ave+val);
    return(ave);
}
double var_online(double val)
{
    int x=1;
    x++;
    double bnsan,ave2,ave,var2;
    bnsan=(((x-1)/x)*ave2+(1/__FLT32X_DECIMAL_DIG__)*pow(val,2))-pow((((x-1)/x))*ave+(1/x)*val,2);
    ave2=(1/x)*((x-1)*ave2+pow(val,2));
    ave=(1/x)*((x-1)*ave+val);
    var2=(x/(x-1))*bnsan;
    return(bnsan);
}
