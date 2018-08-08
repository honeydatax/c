#include <conio.h>
#include <dos.h>

void print(int x,int y,char c);
void beep();

int main(void)
{
char c=' ';
char cc='o';
int x=1;
int y=1;
int xx=1;
int yy=1;
int xx1=1;
int xx2=-1;
int yy1=1;
int yy2=-1;
textcolor(1);
textbackground(4);

clrscr();
_setcursortype(_NOCURSOR);
do{
print(x,y,c);
x=x+xx;
y=y+yy;

if (x>79){
x=79;
xx=xx2;
beep();
}

if (x<1){
x=1;
xx=xx1;
beep();
}

if (y>24){
y=24;
yy=yy2;
beep();
}

if (y<1){
y=1;
yy=yy1;
beep();
}

print(x,y,cc);
delay(700);
}
while (!kbhit());

_setcursortype(_NORMALCURSOR);
return 0;
}

void print(int x,int y,char c){
gotoxy(x,y);
cprintf("%c",c);
}

void beep()
{
   sound(600);
   delay(700);
   nosound();
}
