#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

void usage()
{
	fprintf(stderr, "usage : ./regex_sample [regular expression] [target string]\n\n");
	exit(1);
}

int main(int argc, char *argv[])
{
	int rv;
	regex_t re;
	char *re_str, *target_str;
	char errbuf[256];

	if (argc != 3) usage();

	re_str     = argv[1];
	target_str = argv[2];

	rv = regcomp(&re, re_str, REG_EXTENDED | REG_NOSUB);
	if (rv != 0) {
		regerror(rv, &re, errbuf, 256);
		fprintf(stderr, "recomp() error : %s\n", errbuf);
		regfree(&re);
		return -1;
	}

	printf("regexec() : re=%s, target_str=%s, ", re_str, target_str);

	rv = regexec(&re, target_str, 0, NULL, 0);
	if (rv != 0) {
		printf("match=false\n");
	}
	else {
		printf("match=true\n");
	}
	
	regfree(&re);
	
	return 0;
}
