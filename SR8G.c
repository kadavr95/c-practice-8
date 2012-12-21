#include <stdio.h>
#include <limits.h>
#include <math.h>
#define BASE 5
#define LIMIT 2144444444

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
 if ((abs(x)<=LIMIT)&&(abs(y)<=LIMIT))
 {
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
 ch*=subtract(y,x,&z);
 u=z;
 z=0;
 ch*=power(u,2,&z);
 u=z;
 ch*=power(y,3,&uu);
 z=0;
 ch*=subtract(uu,(u),&z);
 //ch*=(power(y,3,&z),(-(u)),&z);
 u=z;
 z=0;
 ch*=sum(u,x,&z);
 printf("Result: %ld\n", z);
 }
 else
 printf("Result:ERROR: Limits overflow\n");
 fflush(stdin);
 getchar();
 return 0;
}

long int sum(long int x,long int y,long int *z)
{
int i,t1=1,t2=1,xs=1,ys=1;
long int xx[22],yy[22],zz[22];
long int w,v,xt,yt;
if (x<0) {
  xs=-1;
}
if (y<0) {
  ys=-1;
}
for (i = 0; i <=20 ; i++) {
  xx[i]=0;
  yy[i]=0;
  zz[i]=0;
}
if ((xs*ys)==1) {
for (i = 1; i <= 20; i++) {
	 xx[i]=abs(x%10);
	 x=x/10;
	 yy[i]=abs(y%10);
	 y=y/10;
	 }
	 for (i = 1; i <= 20; i++) {

		 zz[i]=xx[i]+yy[i]+zz[i];
	 if (zz[i]>=5) {
	  zz[i]=zz[i]-5;
	  zz[i+1]++;
	 }
	 }
	 for (i = 1; i <= 20; i++) {
	  *z=*z+zz[i]*pow(10,i-1);
	 }
	 if (z>LIMIT) {
	   t1=0 ;
	 }
 // if ((x>=0)&&(y>=0)) {

 // }
  if ((xs<0)&&(ys<0)) {
	*z=*z*(-1);
  }
}
else
{
 xt=x;
 yt=y;
   if (abs(x)>=abs(y)) {
	x=abs(x);
	y=abs(y);
	for (i = 1; i <= 20; i++) {
	 xx[i]=x%10;
	 x=x/10;
	 yy[i]=y%10;
	 y=y/10;
	 }
	 for (i = 1; i <= 20; i++) {

		 zz[i]=zz[i]+xx[i]-yy[i];
	 if (zz[i]<0) {
	  zz[i]=zz[i]+5;
	  zz[i+1]--;
	 }
	 }
	 for (i = 1; i <= 20; i++) {
	  *z=*z+zz[i]*pow(10,i-1);
	 }
	 if (z>LIMIT) {
	   t1=0 ;
	 }
   }
	else
	{
	x=abs(x);
	y=abs(y);
	for (i = 1; i <= 20; i++) {
	 xx[i]=x%10;
	 x=x/10;
	 yy[i]=y%10;
	 y=y/10;
	 }
	 for (i = 1; i <= 20; i++) {

		 zz[i]=zz[i]+yy[i]-xx[i];
	 if (zz[i]<0) {
	  zz[i]=zz[i]+5;
	  zz[i+1]--;
	 }
	 }
	 for (i = 1; i <= 20; i++) {
	  *z=*z+zz[i]*pow(10,i-1);
	 }
	 if (z>LIMIT) {
	   t1=0 ;
	 }
	 *z=*z*(-1);
	}
   if ((xt<0)&&(yt>=0)) {
	*z=*z*(-1);
  }
}
  //x=BASEto10(x);
 // y=BASEto10(y);
 /* if (y>0)
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
//  t2=toBASE(w,&v);
  *z=v; */
  return t1*t2;
}
long int subtract(long int x,long int y,long int *z)
{
 long int ztmp;
 int t1=1;
 ztmp=*z;
 y=-y;
 t1=sum(x,y,&ztmp);
 *z=ztmp;
 return t1;
}
long int multiply(long int x,long int y,long int *z)
{
int t1=1,t2=1,xs=1,ys=1;
long int ztmp,zres,yrs;
if (x<0) {
  xs=-1;
}
if (y<0) {
  ys=-1;
}
x=abs(x);
y=abs(y);
ztmp=*z;
zres=*z;
yrs=y;
 while (y>0)
 {
 ztmp=zres;
 zres=0;
 t1=sum(ztmp,x,&zres);
 y=yrs;
 yrs=0;
 t2=sum(y,-1,&yrs);
 }
 if ((xs*ys)==-1) {
  ztmp=-1;
 }
 *z=ztmp;
return t1*t2;
/*int t1=1,t2=1;
long int w,v;
  //x=BASEto10(x);
 // y=BASEto10(y);
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
 // t2=toBASE(w,&v);
  *z=v;
  return t1*t2; */
}
long int power(long int x,long int y,long int *z)
{
int t1=1,t2=1,xs=1,ys=1;
long int ztmp,zres,yrs;
if (x<0) {
  xs=-1;
}
if (y<0) {
  ys=-1;
}
x=abs(x);
y=abs(y);
ztmp=1;
zres=1;
yrs=y;
 while (y>0)
 {
 ztmp=zres;
 zres=0;
 t1=multiply(ztmp,x,&zres);
 y=yrs;
 yrs=0;
 t2=sum(y,-1,&yrs);
 }
 //if ((xs*ys)==-1) {
 // ztmp=-1;
 //}
 *z=ztmp;
return t1*t2;
/*int t1=1,t2=1;
long int w,v;
 // x=BASEto10(x);
 // y=BASEto10(y);
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
 // t2=toBASE(w,&v);
  *z=v;
  return t1*t2;   */
}


