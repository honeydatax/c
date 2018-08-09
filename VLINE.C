#include <dos.h>
#include <conio.h>

void screen(char x,char color);
void psets(long x,long  y,char color);
void hline(long x,long  y,long x1,long  y1,char color);
void vline(long x,long  y,long x1,long  y1,char color);

int main(void){
int n;
screen(0x13,4);
for (n=0;n<319;n=n+10){
if (n<199)hline(0,n,319,n,1);
vline(n,0,n,199,1);
}
 n=getch();
 return 0;
}

void screen(char x,char color){
union REGS regs;
long l;
long ll=320L*200L;
char far *s;
s=(char far *) 0xa0000000;

regs.h.ah = 0;
regs.h.al = x;
int86(0x10, &regs, &regs);
for (l=0;l<ll;l++)
{
*(s+(l))=color;
}
}

void psets(long x,long  y,char color){
long l=y*320+x;
char far *s;
s=(char far *) 0xa0000000;
*(s+(l))=color;
}




void hline(long x,long  y,long x1,long  y1,char color){
long l;
long l1;
long ll;
char far *s;

if (x>319)x=319;
if (x<0)x=0;

if (y>199)y=199;
if (y<0)y=0;

if (x1>319)x1=319;
if (x1<0)x1=0;

if (y1>199)y1=199;
if (y1<0)y1=0;

if (x<=x1 && y1==y) {

s=(char far *) 0xa0000000;

l=y*320l+x;
ll=x1-x;




for (l1=0;l1<ll;l1++)
{
*(s+(l+l1))=color;
}
}

}


void vline(long x,long  y,long x1,long  y1,char color){
long l;
long l1;
long ll;
long l2;
char far *s;

if (x>319)x=319;
if (x<0)x=0;

if (y>199)y=199;
if (y<0)y=0;

if (x1>319)x1=319;
if (x1<0)x1=0;

if (y1>199)y1=199;
if (y1<0)y1=0;

if (y<=y1 && x1==x) {

s=(char far *) 0xa0000000;

l=y*320l+x;
ll=y1-y;



l2=0;
for (l1=0;l1<ll;l1++)
{
*(s+(l+l2))=color;
l2=l2+320;
}
}

}