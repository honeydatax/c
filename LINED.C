#include <dos.h>
#include <conio.h>

void screen(char x,char color);
void psets(long x,long  y,char color);
void hline(long x,long  y,long x1,long  y1,char color);
void vline(long x,long  y,long x1,long  y1,char color);
void linedown(long x,long  y,long x1,long  y1,char color);

int main(void){
int n;
screen(0x13,4);

for (n=0;n<310;n=n+60){
linedown(0,0,n,180,1);
linedown(0,0,n,60,1);
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

void linedown(long x,long  y,long x1,long  y1,char color){
long l;
long l1;
long ll;
long l2;
long l3;
long l4;
long ld;
long la;
long ld1;
long ld2;
long la1;
long la2;

char far *s;

if (x>319)x=319;
if (x<0)x=0;

if (y>199)y=199;
if (y<0)y=0;

if (x1>319)x1=319;
if (x1<0)x1=0;

if (y1>199)y1=199;
if (y1<0)y1=0;

if (y<=y1 && x<=x1) {

s=(char far *) 0xa0000000;

l=y*320l+x;
l3=y1-y;
ll=x1-x;

la1=1000;
la2=1000;


if (ll>l3){
la2=l3*1000/ll;
la=ll;
}


if (ll<l3){
la1=ll*1000/l3;
la=l3;
}

ld1=0;
ld2=0;
l2=0;
for (l1=0;l1<la;l1++)
{
*(s+(l2))=color;
ld2=ld2+la2;
ld1=ld1+la1;
if (ld2>999){
ld2=ld2-1000;
l2=l2+320;
}
if (ld1>999){
ld1=ld1-1000;
l2++;
}

}
}

}