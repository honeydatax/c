#include <dos.h>
#include <conio.h>


void screen(char x,int color);
void setcolor(int color);
void putpix(int x,int y,char color);
void setbrush(int brush);
void hline(int x,int y,int x1,int y1,int color);

int main(void){
int n;
long l;

screen(0x12,4);

for (n=0;n<479;n=n+20){

 hline(0,n,639,n,1);
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
outpw (0x03c4,n);

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
char lshiftr[]={128,192,224,240,248,252,254,255};
char rshiftr[]={1,3,7,15,31,63,127,255};


s=(char far *) 0xa0000000;


if (x>639)x=639;
if (x1>639)x1=639;
if (x<0)x=0;
if (x1<0)x1=0;

if (y>479)y=479;
if (y1>639)y1=479;
if (y<0)y=0;
if (y1<0)y1=0;

xx=x/8;
xxx=(x1+1)/8;
yy=y*80;


xxx1=x1-x;

if (y1==y && x1>=x){
axx=xx*8;
bxx=xxx*8;

xxa=xx;
xxb=xxx;
if (axx != x)xxa=xx+1;
if (bxx != x1)xxb=xxx-1;

xxc=xxb-xxa;

if (xxc>0) {
bits=0;
setbrush(0);
setcolor(15);
ll=xxc+1;
for (n=0;n<2;n++){
for (l=0;l<ll;l++){
*(s+(yy+l))=bits;
}
setcolor(color);
bits=255;
}
}

if (axx != x){
xxc=x-axx;
setbrush(8);
setcolor(15);
*(s+(yy+xx))=lshiftr[xxc];
setbrush(16);
setcolor(color);
*(s+(yy+xx))=rshiftr[xxc];

}
if (bxx != x1){
xxc=8-x1-bxx;
setbrush(8);
setcolor(15);
*(s+(yy+xxx))=rshiftr[xxc];
setbrush(16);
setcolor(color);
*(s+(yy+xxx))=lshiftr[xxc];

}


}

setbrush(0);
}