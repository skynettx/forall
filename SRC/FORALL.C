#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char fname[260];
char incmd[260];
char fline[260];
char outcmd[780];

int main(int argc, char* argv[])
{
	int i;
	FILE* f;

	if (argc < 3)
	{
		printf("\n"
			"\n"
			"USAGE:  %s filename command\n"
			"\n"
			" Where 'filename' is the name of a file containing the\n"
			" list of files to be operated on, and 'command' is a\n"
			" DOS command that will operate on those files.\n"
			"\n", argv[0]);

		return 0;
	}

	strcpy(fname, argv[1]);

	f = fopen(fname, "r");

	if (!f)
	{
		printf("cannot open file\n");
		return 0;
	}

	for (i = 2; i < argc; i++)
	{
		strcat(incmd, argv[i]);
		strcat(incmd, " ");
	}

	incmd[strlen(incmd) - 1] = '\0';

	while (fgets(fline, sizeof(fline), f))
	{
		sprintf(outcmd, "%s %s", incmd, fline);
		outcmd[strcspn(outcmd, "\n")] = '\0';
		printf("%s\n", outcmd);
		system(outcmd);
	}

	fclose(f);

	printf("\n"
		"\n"
		"Copyright(C) 2023 skynettx\n"
		"\n"
		"This program is free software; you can redistribute it and /or modify\n"
		"it under the terms of the GNU General Public License as published by\n"
		"the Free Software Foundation; either version 2 of the License, or\n"
		"(at your option) any later version.\n"
		"\n");

	return 0;
}