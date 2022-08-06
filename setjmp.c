#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

//jmp_buf envbuf;//#include <setjmp.h>  int setjmp( jmp_buf envbuf );

void b(jmp_buf envbuf)
{
	printf("I am func\n");
	longjmp(envbuf,5);
}
void a(jmp_buf envbuf)
{
	printf("before b(),I am func\n");
	b(envbuf);
	printf("after b(),I am func\n");
}
int main()
{
	int i;
	jmp_buf envbuf;
	i = setjmp(envbuf);
	if (0 == i)
	{
		a(envbuf);
	}
}
