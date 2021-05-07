#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
	FILE *fp;
	char ch;
	char fh = ' ';
	int charcount = 0;
	int wordcount = 0;

	if (argc != 3) {
		printf("请使用格式: %s 文件名", argv[0]);
		exit(0);
	}
	if ((fp = fopen(argv[2], "r")) == NULL) {
		printf("文件不能打开\n");
		exit(0);
	}

	while ((ch = getc(fp)) != EOF) {
		charcount++;
		if ((ch >= 33 && ch <= 43) || (ch >= 45 && ch <= 126) && ((fh == ' ') || (fh == ','))) 
		{
			wordcount++;
		}
		fh = ch;
	}

	if (strcmp(argv[1], "-c") == 0) {
		printf("字符数:%d\n", charcount);
	} else if (strcmp(argv[1], "-w") == 0) {
		printf("单词数:%d\n", wordcount);
	}
	fclose(fp);
}
