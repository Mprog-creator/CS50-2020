#include <stdio.h>
#include <cs50.h>
#include <string.h>

int Lcounter=0;
int Wcounter=1;
int Scounter=0;
float average(int Count,int Wordcount);

int main(void)
{
    string s= get_string("Text: ");
    int length=strlen(s);
     for (int i = 0; i < length; i++)
    {
       if (s[i]>=65 && s[i]<=90)
       {
       Lcounter++;
       }
       else if (s[i]>=97 && s[i]<=122)
       {
       Lcounter++;
       }
       if (s[i]==32)
       {
       Wcounter++;
       }
     if (s[i]==33 || s[i]==46 || s[i]==63 )
    {
        Scounter++;
    }

}
float L= average(Lcounter,Wcounter);
float S= average(Scounter,Wcounter);
float index = (0.0588 * L)- (0.296 * S) - 15.8;

    if (index < 1)
    {
      printf("Before Grade 1\n");
    }
    else if (index>16)
    {
    printf("Grade 16+\n");
    }
    else
    {
    printf("Grade %.0f\n",index);
    }

}


float average(int Count,int Wordcount)
{
return ((float) Count/(float) Wordcount)*100;
}