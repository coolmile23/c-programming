#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0

#define NOT_BLANK 1
#define BLANK 0
#define ITEM 10

int main(int argc, char **argv)
{
	double wc = 0;
	double lc = 0;
	double cc = 0;
	int counter[ITEM];
	int flag = OUT_WORD;
	int blank_flag = NOT_BLANK;
	char c;
	char word_length = 0;

	while ((c = getchar()) != EOF) {
		cc ++;

		if (c == ' ') {
			if (blank_flag == NOT_BLANK) {
				printf("\\b");
			}
			blank_flag = BLANK;
		} else {
			if (c == '\t') {
				printf("\\t");
			} else {
				putchar(c);
			}
			blank_flag = NOT_BLANK;
		}

		if (c == '\t' || c == ' ' || c == '\n') {
			putchar('\n');
			if (c == '\n') {
				lc++;
			}
			flag = OUT_WORD;
		} else if (flag == OUT_WORD) {
			flag = IN_WORD;
			word_length++;
			wc++;
		}
	}

	printf("%.0lf %.0lf %.0lf\n", lc, wc, cc);
	printf("word length: %d\n", word_length);

	return 0;
}
