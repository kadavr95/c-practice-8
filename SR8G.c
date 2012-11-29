#include <stdio.h>

int input(long double *a,long double *b);
int idb(long int number,int base,long int *result);
int fdb(long double number,int base,long double *result);
int ibd(long int number,int base,long int *result);
int fbd(long double number,int base,long double *result);
int output(long double c);

int main(void)
{
  long double a,b,c;
  int check=1;
  while (1)
  {
  input(&a,&b);
  output(c);
  }
}

int input(long double *a,long double *b)
{
  long double aa,bb,cc;
  char oper;
  printf("Taskset 8. Yaskovich Dmitry T01-01c\n");
  printf("Enter expression you want to calculate\n");
  scanf("%ld %c %ld %ld", &aa, &oper, &bb, &cc);
  *a=aa;
  *b=bb;
}

int output(long double c)
{
  printf("Result: %ld\n",c);
  printf("Dimini Inc.\n");
  printf("For progressive future\n");
  printf("(c)2009-2012\n");
}




/*
	#include <stdio.h>
    #include <limits.h>
    #define BASE 5

    long int BASEto10(long int a);
    long int toBASE(long int a10,long int *a);

    int main(void) {
     long int x, y, a=0;
     int ch=0;
	 printf("Enter number and base of it(5 or 10): ");
	 scanf("%ld %d", &x, &ch);
     if (ch==10)
     {
       y = toBASE(x, &a);
       if (y==0)
    	 printf("%ld base 10 to base 5: a=%ld\n",x, a);
       else
    	 printf("%ld base 10 to base 5: ERROR: Limits overflow",x, a);
     }
     else
     {
       y=BASEto10(x);
	   printf("%ld base 5 to base 10: a=%ld\n",x, y);
     }
     fflush(stdin);
     getchar();
     return 0;
    }
    long int BASEto10(long int a) {
     int k=1;
     long int a10=0;
     while (a) {
      a10 += k*(a%10);
      k *= BASE;
      a /= 10;
     }
     return a10;
    }

    long int toBASE(long int a10,long int *a)
    {
     int k=1;
     if ((a10>=-4687499) && (a10<=4687499))
     {
     while (a10)
     {
      *a += k*(a10%BASE);
      k *= 10;
      a10 /= BASE;
     }
     return 0;
     }
     else
     return 1;
	}

*/
