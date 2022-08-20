#define __LIBRARY__
#include <stdio.h>
#define __NR_iam 72
#define __NR_whoami 73
#include <unistd.h>
_syscall1(int,iam,char*,name)
_syscall2(int,whoami,char*,name,int,size)
int main() {
	char name[20] = "owenwtwu";
	char s[20];
	iam(name);
	whoami(s,20);
	printf("I am:%s\n",s);
	return 0;
}
