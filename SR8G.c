#include <stdio.h>//подключение библиотек ввода/вывода и математических вычислений
#include <math.h>
#define LIMIT 2144444444//определение предела допустимых чисел

long int sum(long int x,long int y,long int *z);//прототипы функций
long int subtract(long int x,long int y,long int *z);
long int multiply(long int x,long int y,long int *z);
long int power(long int x,long int y,long int *z);

int main(void)//главная функция
{
 long int x, y,z=0,r=0,u,uu=0;//определение переменных
 int ch=0;
 char op;
 printf("Enter expression: ");//вывод запроса и считывание значений
 scanf("%ld%c%ld", &x,&op,&y);
 if ((abs(x)<=LIMIT)&&(abs(y)<=LIMIT))//числа в пределах?
 {
  if (op=='+')//используемые функции сами по себе
   ch=sum(x,y,&z);
  if (op=='-')
   ch=subtract(x,y,&z);
  if (op=='*')
   ch=multiply(x,y,&z);
  if (op=='^')
   ch=power(x,y,&z);
  if (ch==1)//вычисления в пределах?
   printf("Z: %ld\n", z);//вывод результата какой-то функции
  else
   printf("Result:ERROR: Limits overflow\n");//вывод ошибки
  z=0;
  ch=1;
  ch*=subtract(y,x,&z);//минус в скобках
  u=z;
  z=0;
  ch*=power(u,2,&z);//скобки в квадрате
  u=z;
  ch*=power(y,3,&uu);//число в кубе
  z=0;
  ch*=subtract(uu,(u),&z);//число минус скобки
  u=z;
  z=0;
  ch*=sum(u,x,&z);//итог
  if (ch==1)//вычисления в пределах
   printf("Result: %ld\n", z);//вывод результата
  else
   printf("Result:ERROR: Limits overflow\n");//вывод ошибки
 }
 else
  printf("Result:ERROR: Limits overflow\n");//вывод ошибки
 fflush(stdin);//ожидание нажатия клавиши Enter
 getchar();
 return 0;
}

long int sum(long int x,long int y,long int *z)//сложение
{
 int i,t1=1,t2=1,xs=1,ys=1;//определение переменных
 long int xx[22],yy[22],zz[22],chk;
 long int w,v,xt,yt;
 if (x<0)//сохранение знаков
  xs=-1;
 if (y<0)
  ys=-1;
 for (i = 0; i <=20 ; i++)//заполнение массивов нулями
 {
  xx[i]=0;
  yy[i]=0;
  zz[i]=0;
 }
 if ((xs*ys)==1)//числа одного знака
 {
  chk=0;//проверка вычислений в пределах
  subtract(LIMIT,abs(x),&chk);
  if (chk<abs(y))
  {
   t1=0 ;
  }
  for (i = 1; i <= 20; i++)//разбивка чисел на символы
  {
   xx[i]=abs(x%10);
   x=x/10;
   yy[i]=abs(y%10);
   y=y/10;
  }
  for (i = 1; i <= 20; i++)//вычисление результата в массиве
  {
   zz[i]=xx[i]+yy[i]+zz[i];
   if (zz[i]>=5)//проверка выхода из системы счисления
   {
	zz[i]=zz[i]-5;
	zz[i+1]++;
   }
  }
  for (i = 1; i <= 20; i++)//перевод из массива в число
   *z=*z+zz[i]*pow(10,i-1);
  if ((xs<0)&&(ys<0))//корректировка знака
   *z=*z*(-1);
 }
 else//числа разных знаков
 {
  xt=x;
  yt=y;
  if (abs(x)>=abs(y))//первое больше по модулю
  {
   x=abs(x);
   y=abs(y);
   for (i = 1; i <= 20; i++)//разбивка чисел на символы
   {
	xx[i]=x%10;
	x=x/10;
	yy[i]=y%10;
	y=y/10;
   }
   for (i = 1; i <= 20; i++)//вычисление результата в массиве
   {
	zz[i]=zz[i]+xx[i]-yy[i];
	if (zz[i]<0)//проверка нехватки числа в своём разряде
	{
	 zz[i]=zz[i]+5;
	 zz[i+1]--;
	}
   }
   for (i = 1; i <= 20; i++)//перевод из массива в число
	*z=*z+zz[i]*pow(10,i-1);
  }
  else//второе больше по модулю
  {
   x=abs(x);
   y=abs(y);
   for (i = 1; i <= 20; i++)//разбивка чисел на символы
   {
	xx[i]=x%10;
	x=x/10;
	yy[i]=y%10;
	y=y/10;
   }
   for (i = 1; i <= 20; i++)//вычисление результата в массиве
   {
	zz[i]=zz[i]+yy[i]-xx[i];
	if (zz[i]<0)//проверка нехватки числа в своём разряде
	{
	 zz[i]=zz[i]+5;
	 zz[i+1]--;
	}
   }
   for (i = 1; i <= 20; i++)//перевод из массива в число
	*z=*z+zz[i]*pow(10,i-1);
   *z=*z*(-1);//корректировка знака
  }
  if ((xt<0)&&(yt>=0))
   *z=*z*(-1);//корректировка знака
 }
 return t1*t2;//возврат ошибок
}

long int subtract(long int x,long int y,long int *z)//вычитание
{
 long int ztmp=*z;//определение переменных
 int t1=1;
 y=-y;//смена знака второй переменной
 t1=t1*sum(x,y,&ztmp);//вызов сложения
 *z=ztmp;//результат
 return t1;//возврат ошибок
}

long int multiply(long int x,long int y,long int *z)//умножение
{
 int t1=1,t2=1,xs=1,ys=1;//определение переменных
 long int ztmp=*z,zres=*z,yrs=abs(y);
 if (x<0)//сохраняем знаки переменных
  xs=-1;
 if (y<0)
  ys=-1;
 x=abs(x);//берём модули
 y=abs(y);
 while (y>1)//сложение пока подходит множитель
 {
  ztmp=zres;
  zres=0;
  t1=t1*sum(ztmp,x,&zres);//вызов сложения
  y=yrs;
  yrs=0;
  t2=t2*sum(y,-1,&yrs);//уменьшение множителя
 }
 if ((xs*ys)==-1)//корректировка знака
  zres=-1*zres;
 *z=zres;//результат
 return t1*t2;//возврат ошибок
}

long int power(long int x,long int y,long int *z)//степень
{
 int t1=1,t2=1,xs=1,ys=1;//определение переменных
 long int ztmp=x,zres=x,yrs=(y-1);
 while (y>1)//умножение пока подходит степень
 {
  ztmp=zres;
  zres=0;
  t1=t1*multiply(ztmp,x,&zres);//вызов умножения
  y=yrs;
  yrs=0;
  t2=t2*sum(y,-1,&yrs);//уменьшение степени
 }
 *z=zres;//результата
 return t1*t2;//возврат ошибок
}
