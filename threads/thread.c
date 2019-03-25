#include "./thread.h"

struct thread_param {
	FILE *fichier;
	int startchar;
	int nchar;
	int result[26];
};

void* count_letters(void* arg)
{
    // take arguments
    struct thread_param* tp = (struct thread_param*) arg;

    // inialize result array and set position in file
    memset(tp->result, 0, sizeof(tp->result));
    fseek(tp->fichier, tp->startchar, SEEK_SET);

    // read part of the file
    // https://rosettacode.org/wiki/Letter_frequency#C
    for (int i=0; i < tp->nchar; i++)
    {
	    char ch = fgetc(tp->fichier);
	    if (ch == EOF) break;

	    if ('a' <= ch && ch <= 'z')
		    tp->result[ch-'a']++;
	    else if ('A' <= ch && ch <= 'Z')
		    tp->result[ch-'A']++;
    }

    pthread_exit(NULL);
}
