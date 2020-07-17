#include <stdio.h>
#include <unistd.h>

int main(void) {
	char buff[FILENAME_MAX];
	getcwd(buff, FILENAME_MAX);
	printf("%s\n", buff);
	return 0;
}
