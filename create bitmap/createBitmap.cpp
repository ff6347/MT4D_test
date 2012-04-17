// found here http://www.tutorials.de/c-c/346115-c-bitmap-erstellen.html
#include <iostream>
#include <fstream>
// #include <windows.h>
 
using namespace std; 


struct BITMAPFILEHEADER { //BitMap File Header structure
unsigned short bfType; 
unsigned long bfSize;
unsigned short bfReserved1;
unsigned short bfReserved2;
unsigned long bfOffBits;
};
 
struct BITMAPINFOHEADER { //BitMap Info Header structure
unsigned long biSize;
unsigned long biWidth;
unsigned long biHeight;
unsigned short biPlanes;
unsigned short biBitCount;
unsigned long biCompression;
unsigned long biSizeImage;
unsigned long biXPelsPerMeter;
unsigned long biYPelsPerMeter;
unsigned long biClrUsed;
unsigned long biClrImportant;
};
 
int main(){

BITMAPFILEHEADER fileheader; //Fileheader
BITMAPINFOHEADER infoheader;//...

 
//Infoheader Einstellungen
 
infoheader.biSize = sizeof(BITMAPINFOHEADER);
infoheader.biWidth = 10;
infoheader.biHeight = 10;
infoheader.biPlanes = 1;
infoheader.biBitCount = 24;
infoheader.biCompression = 0;
infoheader.biSizeImage =   infoheader.biWidth * infoheader.biHeight;
infoheader.biXPelsPerMeter = 2400;
infoheader.biYPelsPerMeter = 2400;
infoheader.biClrUsed = 0;
infoheader.biClrImportant = 0;
 
// Fileheader Einstellungen
fileheader.bfType = 19778;
fileheader.bfSize = sizeof(BITMAPFILEHEADER);
fileheader.bfReserved1 = 0;
fileheader.bfReserved2 = 0;
fileheader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

 
/////////Daten schreiben///////////////
ifstream::pos_type size; 
ofstream myfile ("testbmp.bmp",ios::out | ios::binary); //Ofstream erstelllen mit Namen : myfile
 
myfile.write ((char*) &fileheader, sizeof(fileheader)); 
myfile.write ((char*) &infoheader, sizeof(infoheader));
for(int u=0;u< 10 ;u++)
{
    for(int o=0;o<10;o++)
    {
         for(int z= 0;z<3;z++)
        {
        myfile.put(rand() % 256);
        }

    	// if(u == 0 && o == 0)
     //    {myfile.put( 1);
     //    }else{
     //    myfile.put( 0);

     //    }
    }
}
 
 
myfile.close();
 
 
}