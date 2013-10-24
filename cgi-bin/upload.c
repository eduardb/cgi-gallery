#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
	char boundary[100], content_disposition[1000], content_type[100];
	char line[1000];
	char *p, *q;
	char filename[256], path[256];
	FILE *f;
	printf("Content-type: text/html\n\n");
  
	fgets(boundary, 100, stdin);
  
	fgets(content_disposition, 1000, stdin); 
  
	fgets(content_type, 1000, stdin);

	if (!strstr(content_type, "image"))
	{
		printf("Puteti urca doar imagini! <a href='..'>Go back</a>");
		return;
	}
  
 	fgets(line, 1000, stdin); // asta e linie in gol

	p = strtok(content_disposition, ";");

	while (p!= NULL && strstr(p, "filename") != p+1)
	{
		p = strtok(NULL, ";");
	}

	q = strtok(p + 1, "=");
	q = strtok(NULL, "=");

	memset(filename, 0, sizeof(filename));

	strcpy(filename, q + 1);

	filename[strlen(filename) - 3] = 0;
	  
	sprintf(path, "../uploads/%s", filename);

	f = fopen(path, "wb");
 
	while (fread(line, 1, 100, stdin) > 0)
	{
		fwrite(line, 1, 100, f);
	}
  
	printf("Gata! <a href='gallery.cgi'>Mergeti la galerie</a>");

	return 0;
}
