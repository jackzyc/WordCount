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
		printf("��ʹ�ø�ʽ: %s �ļ���", argv[0]);
		exit(0);
	}
	if ((fp = fopen(argv[2], "r")) == NULL) {
		printf("�ļ����ܴ�\n");
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
		printf("�ַ���:%d\n", charcount);
	} else if (strcmp(argv[1], "-w") == 0) {
		printf("������:%d\n", wordcount);
	}
	fclose(fp);
}
