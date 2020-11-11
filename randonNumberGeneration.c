

#include <stdio.h>
#include <math.h>
#include "lcgrand.h"  /* Header file for random-number generator. */

FILE *exponential, *uniform1,  *uniform2, *pareto_f;

float expon(float mean) ;
float uniform(int a,int b);
float pareto(float a, float k);

int main(void)
{
    int i = 0;
    float
          Beta = 2.0,
          sum_e = 0.0, sum_u1 = 0.0, sum_u2 = 0.0, sum_p = 0.0,
          rand_e, rand_u1,  rand_u2, rand_p ,
          average_e, average_u1,  average_u2, average_p ,
          max_e = 0, max_u1 = 0, max_u2 = 0, max_p = 0,
          min_e = 100, min_u1 = 100, min_u2 = 100, min_p = 100;

    int loop = 1000;

    exponential = fopen("C:/Users/akeem/Desktop/M.SC PHOTONICS INTEGRATED CIRCUIT SENSORS AND NETWORK SSSA/NS/Assignment/exponential.txt","w");
    uniform1    = fopen("C:/Users/akeem/Desktop/M.SC PHOTONICS INTEGRATED CIRCUIT SENSORS AND NETWORK SSSA/NS/Assignment/uniform1.txt","w");
    uniform2    = fopen("C:/Users/akeem/Desktop/M.SC PHOTONICS INTEGRATED CIRCUIT SENSORS AND NETWORK SSSA/NS/Assignment/uniform2.txt","w");
    pareto_f    = fopen("C:/Users/akeem/Desktop/M.SC PHOTONICS INTEGRATED CIRCUIT SENSORS AND NETWORK SSSA/NS/Assignment/pareto_f.txt","w");


    while(i++ <= loop)
    {
        rand_e = expon(Beta);
        max_e = (max_e < rand_e) ? rand_e : max_e;
        min_e = (min_e > rand_e) ? rand_e : min_e;
        sum_e += rand_e;
        fprintf(exponential,"%f\n",rand_e);


        rand_u1 = uniform(0,1);
        max_u1 = (max_u1 < rand_u1) ? rand_u1 : max_u1;
        min_u1 = (min_u1 > rand_u1) ? rand_u1 : min_u1;
        sum_u1 += rand_u1;
        fprintf(uniform1,"%f\n",rand_u1);

        rand_u2 = uniform(4,10);
        max_u2 = (max_u2 < rand_u2) ? rand_u2 : max_u2;
        min_u2 = (min_u2 > rand_u2) ? rand_u2 : min_u2;
        sum_u2 += rand_u2;
        fprintf(uniform2,"%f\n",rand_u2);

        rand_p = pareto(4,2);
        max_p = (max_p < rand_p) ? rand_p : max_p;
        min_p = (min_p > rand_p) ? rand_p : min_p;
        sum_p += rand_p;
        fprintf(pareto_f,"%f\n",rand_p);
    }
    average_e = sum_e / loop;
    average_u1 = sum_u1 / loop;
    average_u2 = sum_u2 / loop;
    average_p = sum_p / loop;

    fprintf(exponential,"\n\n%f\n%f\n%f\n",min_e,max_e,average_e);
    fprintf(uniform1,"\n\n%f\n%f\n%f\n",min_u1,max_u1,average_u1);
    fprintf(uniform2,"\n\n%f\n%f\n%f\n",min_u2,max_u2,average_u2);
    fprintf(pareto_f,"\n\n%f\n%f\n%f\n",min_p,max_p,average_p);

    fclose(exponential);
    fclose(uniform1);
    fclose(uniform2);
    fclose(pareto_f);

    //printf("sum = %f and average = %f, minimum = %f and maximum = %f",sum,average,min,max);
}

float expon(float mean)  /* Exponential variate generation function. */
{
    /* Return an exponential random variate with mean "mean". */
    return -mean * log(lcgrand(2));
}

float uniform(int a,int b)
{
    return (float)(a + (b-a)*lcgrand(2));
}

float pareto(float a, float k)
{
    return (k /(pow((1-lcgrand(2)),(1.0/a))));
}

