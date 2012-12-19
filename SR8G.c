#include <stdio.h>
#include <limits.h>
#include <math.h>
#define BASE 5
#define LIMIT 2144444444

//long int BASEto10(long int a);
//long int toBASE(long int a10,long int *z);
long int sum(long int x,long int y,long int *z);
long int subtract(long int x,long int y,long int *z);
long int multiply(long int x,long int y,long int *z);
long int power(long int x,long int y,long int *z);

int main(void) {
 long int x, y,z=0,r=0,u,uu=0;
 int ch=0;
 char op;
 printf("Enter expression: ");
 scanf("%ld%c%ld", &x,&op,&y);
 if (op=='+')
 {
   ch=sum(x,y,&z);
 }
 if (op=='-')
 {
   //y*=-1;
   ch=subtract(x,y,&z);
 }
 if (op=='*')
 {
   ch=multiply(x,y,&z);
 }
 if (op=='^')
 {
   ch=power(x,y,&z);
 }
 if (ch==1)
  printf("Z: %ld\n", z);
 else
 printf("Result:ERROR: Limits overflow\n");
 z=0;
 ch=1;
 //r=sum(sum(power(y,3,&z),-(power(sum(y,-x,&z),2,&z)),&z),x,&z) ;
 ch*=sum(y,-x,&z);
 u=z;
 z=0;
 ch*=power(u,2,&z);
 u=z;
 ch*=power(y,3,&uu);
 z=0;
 ch*=sum(uu,(-u),&z);
 //ch*=(power(y,3,&z),(-(u)),&z);
 u=z;
 z=0;
 ch*=sum(u,x,&z);
 printf("Result: %ld\n", z);
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
 return 1;
 }
 else
 return 0;
}
long int sum(long int x,long int y,long int *z)
{
int t1=1,t2=1;
long int w,v;
  x=BASEto10(x);
  y=BASEto10(y);
  if (y>0)
  {
   if ((LONG_MAX-y)>x)
   {
	 w=x+y;
   }
   else
	 t1=0;
  }
  else
  if ((LONG_MIN-y)<x)
   {
	 w=x+y;
   }
   else
	 t1=0;
  v=*z;
  t2=toBASE(w,&v);
  *z=v;
  return t1*t2;
}
long int subtract(long int x,long int y,long int *z)
{

}
long int multiply(long int x,long int y,long int *z)
{
int t1=1,t2=1;
long int w,v;
  x=BASEto10(x);
  y=BASEto10(y);
  if (((y>0)&&(x>0))||((y<0)&&(x<0)))
  {
   if ((LONG_MAX/y)>x)
   {
	 w=x*y;
   }
   else
	 t1=0;
  }
  else
  if ((LONG_MIN/y)<x)
   {
	 w=x*y;
   }
   else
	 t1=0;
  v=*z;
  t2=toBASE(w,&v);
  *z=v;
  return t1*t2;
}
long int power(long int x,long int y,long int *z)
{
int t1=1,t2=1;
long int w,v;
  x=BASEto10(x);
  y=BASEto10(y);
  if ((x<0) &&(y%2==1))
  {
   if ((-pow(LONG_MAX,1.0/y)<x))
   {
	 w=pow(x,y);
   }
   else
	 t1=0;
  }
  else
  if (pow(LONG_MAX,1.0/y)>x)
   {
	 w=pow(x,y);
   }
   else
	 t1=0;
  v=*z;
  t2=toBASE(w,&v);
  *z=v;
  return t1*t2;
}


