#include <cs50.h>
#include <stdio.h>

int main(void)
{
    
long Number=0;
long Number1=0;
long Number2=0;
long Number3=0;
long Input=0;
long Counter=0;
long AlternateCounter=0;
long AlternateCounter2=0;
long Digit=0;
long Remainder=0;
long Sum=0;
long finaldigit=0;

 
 do
 Number=get_long("Number:");
 while (Number<=0);
Number1=Number/10;
Number2=Number;
Number3=Number;
  do
 {
  Digit=(Number1%10)*2;
  if(Digit>=10)
  {
  Remainder= Digit%10;
  Digit=Digit/10;
  Digit= Digit%10 + Remainder;
  }
  
  AlternateCounter=AlternateCounter+Digit;
  Number1=Number1/100;
 } while (Number1>0);
 
 do
 {
  Digit=Number%10;
  AlternateCounter2=AlternateCounter2+Digit;
  Number=Number/100;
 } while (Number>0);
 long sum= AlternateCounter+AlternateCounter2;
do
{
    Number2=Number2/10;
    Counter++;
}while (Number2>0);
if (Counter>16 || Counter<13 || Counter==14 || sum%10!=0)
{
    printf("INVALID\n");
}
if (sum%10==0)
{
if (Counter==15)
{
if ((Number3/10000000000000)==34  )
{
    printf("AMEX\n");
}
else if ((Number3/10000000000000)==37)
{
    printf("AMEX\n");
}
else
{
    printf("INVALID\n");
 
}
}
if (Counter==16)
{
if ((Number3/100000000000000)==51  )
{
    printf("MASTERCARD\n");
}
else if ((Number3/100000000000000)==52)
{
    printf("MASTERCARD\n");
}
else if ((Number3/100000000000000)==53)
{
    printf("MASTERCARD\n");
}
else if ((Number3/100000000000000)==54)
{
    printf("MASTERCARD\n");
}
else if ((Number3/100000000000000)==55)
{
    printf("MASTERCARD\n");
}
else if ((Number3/1000000000000000)==4)
{
    printf("VISA\n");
}
else
{
    printf("INVALID\n");
 
}

}
if (Counter==13)
{
if ((Number3/1000000000000)==4  )
{
    printf("VISA\n");
}

else
{
    printf("INVALID\n");
 
}
}
}
}

