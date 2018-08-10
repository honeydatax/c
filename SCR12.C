#include <dos.h>
#include <conio.h>


void screen(char x,int color);
void setcolor(int color);

int main(void){
int n;
long l;
long ll=640L*480L/8L;
char far *s;
s=(char far *) 0xa0000000;
screen(0x12,4);
setcolor(1);
for (l=0;l<ll;l++)
{
*(s+(l))=64;
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