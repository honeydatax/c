#include <dos.h>


void screen(char x,char color);
void psets(long x,long  y,char color);

int main(void){
screen(0x13,4);
psets(160,100,1);
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