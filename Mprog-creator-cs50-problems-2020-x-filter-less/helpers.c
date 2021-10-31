#include "helpers.h"
#include <math.h> 
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
        int red=image[i][j].rgbtRed;
        int blue=image[i][j].rgbtBlue;
        int green=image[i][j].rgbtGreen;
        float average = (round(red) + round(blue) + round(green)) / 3;
        average = round(average);
        image[i][j].rgbtRed = average;
        image[i][j].rgbtBlue = average;
        image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
        int red=image[i][j].rgbtRed;
        int blue=image[i][j].rgbtBlue;
        int green=image[i][j].rgbtGreen;
        int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
        int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
        int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);
        if (sepiaRed>255)
        {
            image[i][j].rgbtRed=255;
        }
        else
        {
            image[i][j].rgbtRed=sepiaRed;
        }
          if (sepiaGreen>255)
        {
            image[i][j].rgbtGreen=255;
        }
        else
        {
            image[i][j].rgbtGreen=sepiaGreen;
        }
          if (sepiaBlue>255)
        {
            image[i][j].rgbtBlue=255;
        }
        else
        {
            image[i][j].rgbtBlue=sepiaBlue;
        }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     for (int i=0;i<height;i++)
    {
        for (int j=0;j<(width/2);j++)
        {
     RGBTRIPLE temp= image[i][j];
     image[i][j] = image[i][width - (j + 1)];
     image[i][width - (j + 1)] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int Rsum;
    int Bsum;
    int Gsum;
    float Counter;
    RGBTRIPLE temp[height][width];
    for (int i=0;i<width;i++)
    {
        for (int j=0;j<height;j++)
        {
            Rsum=0;
            Bsum=0;
            Gsum=0;
            Counter=0.00;
            
            
            for (int k=-1;k<2;k++)
            {
                if (j+k<0||j+k>height-1)
                {
                    continue;
                }
            
            for (int h=-1;h<2;h++)
            {
                if (i+h<0 || i+h>width-1)
                {
                    continue;
                }
            Rsum+=image[k+j][h+i].rgbtRed;
            Bsum+=image[k+j][h+i].rgbtBlue;
            Gsum+=image[k+j][h+i].rgbtGreen;
            Counter++;
            }
            }
         
            temp[j][i].rgbtRed=round(Rsum/Counter);
            temp[j][i].rgbtBlue=round(Bsum/Counter);
            temp[j][i].rgbtGreen=round(Gsum/Counter);
        }
    }
      for (int i=0;i<width;i++)
        {
        for (int j=0;j<height;j++)
        {
     image[j][i].rgbtRed=temp[j][i].rgbtRed;
     image[j][i].rgbtBlue=temp[j][i].rgbtBlue;
     image[j][i].rgbtGreen=temp[j][i].rgbtGreen;

        }
    }
  
}