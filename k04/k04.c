#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct date
{
    int id;
    int sex;
    double height;
};

int main(void)
{
    char fname[FILENAME_MAX];
    char buf[256];
    FILE*fp;

    int i=0,ID,num=100;;
    struct date a[14];


    printf("input the filename of sample heights ? :");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] ='\0';
    printf("the filename of sample heights : %s\n",fname);
    

    fp = fopen(fname,"r");
    if(fp==NULL)
    {
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL)
    {
        sscanf(buf,"%d,%lf",&a[i-1].sex,&a[i-1].height);
        i++;
    }
    
    if(fclose(fp) == EOF)
    {
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("input the filename of sample ID ? : ");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';


    fp = fopen(fname,"r");
    if(fp==NULL)
    {
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    i=0;

    while(fgets(buf,sizeof(buf),fp) != NULL)
    {
        sscanf(buf,"%d",&a[i].id);
        i++;
    }

    if(fclose(fp) == EOF)
    {
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

     printf("Which ID's date do you want ? : ");
     scanf("%d",&ID);

     for(i=0;i<=14;i++)
     
         if(ID==a[i].id)
         {
             num = i;
         }
     
    
    printf("---\n");
    if(num != 100)
    {
        printf("ID : %d\n",a[num].id);

    if(a[num].sex==2)
    {
        printf("gender : Female\n");
    }
    else
    {
        printf("gender : Male\n");
    }
    printf("height : %4.1lf\n",a[num].height);
    }
    else
    {
        printf("No data\n");
    }
    return 0;
    
    
}

