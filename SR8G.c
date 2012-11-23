#include <stdio.h>
#include <limits.h>
#include <math.h>
#define BASE 5

long int BASEto10(long int a);
long int toBASE(long int a10,long int *z);

int main(void) {
 long int x, y,z=0,t;
 int ch=0;
 char op;
 printf("Enter expression: ");
 scanf("%ld%c%ld", &x,&op,&y);
 x=BASEto10(x);
 y=BASEto10(y);
 if (op=='+')
 {
   t=x+y;
 }
 if (op=='-')
 {
   t=x-y;
 }
 if (op=='*')
 {
   t=x*y;
 }
 if (op=='^')
 {
   t=pow(x,y);
 }
 ch=toBASE(t,&z);
 if (ch==0)
  printf("Result: %ld\n", z);
 else
 printf("Result:ERROR: Limits overflow\n");
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

long int toBASE(long int a10,long int *z)
{
 int k=1;
 if ((a10>=-4687499) && (a10<=4687499))
 {
 while (a10)
 {
  *z += k*(a10%BASE);
  k *= 10;
  a10 /= BASE;
 }
 return 0;
 }
 else
 return 1;
}
