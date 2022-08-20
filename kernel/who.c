#include <errno.h>
#include <unistd.h>
#include <asm/segment.h>
char my_name[24];
// 将字符串参数name拷贝到内核保存，大小不能超过23个字符
int sys_iam(const char* name) {
    int p = 0;
	char* namep = name;
	while (p <= 24) {
		char c = get_fs_byte(namep++);
		my_name[p] = c;
		p++;
		if ( c == 0) {
			break;
		}
	}
    if (p > 24) {
        return -EINVAL;
    }
    return 0;
}

// 将名字拷贝到缓冲区
int sys_whoami(char* name, unsigned int size) {
    int i = 0;
    char* p=name;
    for ( i = 0; i < size; i++) {
	put_fs_byte(my_name[i], p++);
	if (my_name[i] = 0) break;
	}
	
    return 0;
}


