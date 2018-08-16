#include <dos.h>
#include <conio.h>


void screen(char x,int color);
void setcolor(int color);
void putpix(int x,int y,char color);
void setbrush(int brush);
void hline(int x,int y,int x1,int y1,int color);
void print(char *text,int color);
void debugs(int n,int color);


int main(void){
int n;
long l;
int nn;

screen(0x12,4);
//nn=480/2;
n=8;
for (n=0;n<479;n++){
nn=n ;
 hline(320-n,nn,320+n,nn,1);
}
 n=getch();
 return 0;
}

void screen(char x,int color){
union REGS regs;
int n;
long l;
long ll=640L*480L/8L;
char far *s;
s=(char far *) 0xa0000000;

regs.h.ah = 0;
regs.h.al = x;
int86(0x10, &regs, &regs);
n=0x0100*color+2;
outpw (0x03c4,n);
for (l=0;l<ll;l++)
{
*(s+(l))=255;
}
}

void setcolor(int color){
int n;
n=0x0100*color+2;
outpw (0x03c4,n);

}

void putpix(int x,int y,char color){
union REGS regs;

regs.h.ah = 0xc;
regs.h.al =color;
regs.h.bh =0;
regs.x.cx =x;
regs.x.dx =y;
int86(0x10, &regs, &regs);

}

void setbrush(int brush){
int n;
n=0x0100*brush+3;
outpw (0x03ce,n);
}

void hline(int x,int y,int x1,int y1,int color){
int yy;
int xx;
int xxx;
int xxx1;
int xxa;
int xxb;
int xxc;
int axx;
int bxx;
int n;
long l;
long ll;
char far *s;
char bits;
// bits scroller left rigth bits of end and start of the horizontal line
unsigned char lshiftr[]={128,192,224,240,248,252,254,255};
// bits scroller left rigth bits of end and start of the horizontal line
unsigned char rshiftr[]={1,3,7,15,31,63,127,255};
char u[]={1,2,4,8,16,32,64};
//pointer to far address position of video a000h
s=(char far *) 0xa0000000;



//check if the line is out side screen
if (x>639)x=639;
if (x1>639)x1=639;
if (x<0)x=0;
if (x1<0)x1=0;

if (y>479)y=479;
if (y1>639)y1=479;
if (y<0)y=0;
if (y1<0)y1=0;


// screen a0000:0000h into 640/8*480  is the black color to change mem
// from a0000:0000h into a000:ffffh into 4 blocks of memory diferent
// the blue block of memory the green block memory  the red block memory
// and the intensity block memory give the all 4 bits mix color 0x0 into 0xf

//x the start of a line
//divide x by 8 every byte have 8 bits 1 bit is 1 pixel on horizontal bytes
xx=x/8;

//x1 the tail of a line
//divide x by 8 every byte have 8 bits 1 bit is 1 pixel on horizontal bytes
xxx=(x1+1)/8;


//every line have 80 bytes X 8 bits=640 bits=1 line
yy=y*80;


//find the number of bits from the diference of x1 into x
xxx1=x1-x;


//if is only one line draw the line if not error ignore code
if (y1==y && x1>=x){
// find if x is a 8 multiple divide by 8 of start of line
axx=xx*8;
// find if x1 is a 8 multiple divide by 8 of tail of line
bxx=xxx*8;

xxa=xx;
xxb=xxx;


//check if the line starts on half way byte
if (axx != x)xxa=xx+1;
//check if the line tail on half way
xxb=xxx-1;



xxc=xxb-xxa;


//check if have compleat 8 bits pixels if have draw it only the compleat 8 bits are draw for now
if (xxc>0) {
//  delete the old color mask by write 4 masks bit color into 0 to byte
bits=0;
//set a mask to replace the intire byte of 0 value
setbrush(0);
//set color to all 4 mask bits to delete all negative colors
setcolor(15);

if (xxc>79)xxc=79;

ll=xxc+1;


// delete all the old colors of complite byte
for (n=0;n<2;n++){
for (l=0;l<ll;l++){
*(s+(yy+l+xxa))=bits;
}

//fill now the entire byte 2 part n for
setcolor(color);
bits=255;
}

}


//check if  is the begin  of broken line start
if (axx != x){
xxc=x-axx;
//and byte brushs
setbrush(8);
//delete the old color start of a broken byte line
for (n=0;n<4;n++){
setcolor(u[n]);
//delete old color byte

*(s+(yy+xx))=(char)lshiftr[xxc];
}
//or byte brushs
setbrush(16);
//set the color
setcolor(color);
//write the firt byte of the broken line
*(s+(yy+xx))=(char)rshiftr[xxc];

}

//check if  is the tail  of broken line tail byte

if (bxx != x1+1){
xxc=(x1-bxx);
//and byte brushs
setbrush(8);
//delete the old color tail of a broken byte line
for (n=0;n<4;n++){
setcolor(u[n]);
//delete old color byte
*(s+(yy+xxx))=(char)~lshiftr[xxc];
}
//or byte brushs
setbrush(16);
//set the color
setcolor(color);
//write the last  byte of the broken line
*(s+(yy+xxx))=(char)~rshiftr[xxc];

}


}

//leave the replace byte brush mask to others functions
setbrush(0);
}



void print(char *text,int color){
int n;
int nn;
union REGS regs;
nn=0;
for (n=0;n<513;n++)
{
regs.h.ah = 0xe;
regs.h.al =text[n];
regs.h.bh =0;
regs.h.bl =color;
if (regs.h.al>6) int86(0x10, &regs, &regs);
if (text[n]<7) n=32000;

}
}

void debugs(int n,int color){
char c1[80]="00000000000000000000000000000\0\0\0\0\0";
char c2[80];
sprintf(c1,"%d|\0",n);
print(c1,color);

}