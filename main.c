#include <stdio.h>
#include "Params.h"

/*Give a histagram for input image*/
void histagram(unsigned char image_in[Y_SIZE][X_SIZE],long hist[256])
{
    int i,j,n;
    for(i=0;i<Y_SIZE;i++)
    {
        for(j=0;j<X_SIZE;j++)
        {
            n = image_in[i][j];
            hist[n]++;
        }
    }
}

void threshold(unsigned char image_in[Y_SIZE][X_SIZE],unsigned char image_out[Y_SIZE][X_SIZE],int threshold, int mode)
{
	int i,j;

	for(i=0;i<Y_SIZE;i++){
        for(j=0;j<X_SIZE;j++){
            switch(mode){
                case 2:
                    if((int)image_in <= threshold)
                        image_out[i][j] = HIGH;
                    else
                        image_out[i][j] = LOW;
                        break;
                default:
                    if((int)image_in >= threshold)
                        image_out[i][j] = HIGH;
                    else
                        image_out[i][j] = LOW;
                        break;
            }
        }
	}
}

void histprint(long hist[256],char *buf)
{
    int i,j,k;
    float p,q,max;
    int posi,m;

    posi=0;
    p=X_SIZE*Y_SIZE;
    max=0;
    for(i=0;i<256;i++)
    {
        if(hist[i]>max)
            max = hist[i];
    }
    for(i=0;i<256;i++)
    {
        q=(float)hist[i]/p*100.0;
        m=sprintf(&buf[posi],"%3d:%5.1f\%",i,q);
        posi+=m;
        k=(float)hist[i]/max*60.0;
        for(j=0;j<k;j++)
        {
            m=sprintf(&buf[posi],"*");
            posi+=m;
        }
        m=sprintf(&buf[posi],"\n");
        posi+=m;
    }
}

int main()
{

}
