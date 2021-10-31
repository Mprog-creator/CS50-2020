#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
int main(int argc, char *argv[])
{
typedef uint8_t BYTE;
int counter=0;
BYTE buffer[512];
bool check=false;
FILE* file = fopen(argv[1], "r");
FILE* output;
if (argc!=2)
{
    printf("Usage: ./recover image");
    return 1;
}
if (file==NULL)
{
    printf("File does not exist\n");
    return 1;
}
 while (fread(buffer,512,1,file)!=0)
 {
     if (buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]& 0xe0)==0xe0)
     {
         if (check==true)
         {
         fclose(output);
         }
         else
         {
        check=true;
         }
      
        char name[8];
        sprintf(name,"%03i.jpg",counter);
        output=fopen(name,"a");
         counter++;
     }
  
     
     if (check==true)
     {
         fwrite(&buffer,512,1,output);
     }
 }

fclose(output);
fclose(file);
return 0;

}
