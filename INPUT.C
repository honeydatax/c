
#include <conio.h>

int main(void)
{
char buffer[83];
char *p;
buffer[0] = 12;
textcolor(1);
textbackground(4);

clrscr();

textcolor(4);
textbackground(1);

window(10,10,40,11);
clrscr();

cprintf("Name:");
p = cgets(buffer);
cprintf("\r\n");
cprintf("%s",p);
return 0;
}

