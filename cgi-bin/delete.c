#include <stdio.h>
#include <string.h>
#include <ctype.h>

void urldecode2(char *dst, const char *src)
{
        char a, b;
        while (*src) {
                if ((*src == '%') &&
                    ((a = src[1]) && (b = src[2])) &&
                    (isxdigit(a) && isxdigit(b))) {
                        if (a >= 'a')
                                a -= 'A'-'a';
                        if (a >= 'A')
                                a -= ('A' - 10);
                        else
                                a -= '0';
                        if (b >= 'a')
                                b -= 'A'-'a';
                        if (b >= 'A')
                                b -= ('A' - 10);
                        else
                                b -= '0';
                        *dst++ = 16*a+b;
                        src+=3;
                } else {
                        *dst++ = *src++;
                }
        }
        *dst++ = '\0';
}

int main()
{
	char qs[1000], *pch, *pch2, path[100];
	
	urldecode2(qs, getenv("QUERY_STRING"));
	printf("Content-type: text/html\n\n");
	
	pch = strtok (qs ,"&");
	while (pch != NULL && strstr(pch, "name") != pch)
	{
		pch = strtok (NULL, "&");
	}
	
	pch2 = strtok(pch, "=");
	pch2 = strtok(NULL, "=");
	
	if (strstr(pch2, "..") || strstr(pch2, "/"))
	{
		printf("Fara hackeri pe aici!!!");
		printf("<br /><a href='..'>Go back</a>");
		return;
	}
	
	
	//printf("%s", pch2);
	
	sprintf(path, "../uploads/%s", pch2); 
	
	//printf("%s", path);
	
	if( remove( path) != 0 )
		printf( "Error deleting %s", path);
	else
	{
		puts( "File successfully deleted" );
		printf("<br /><a href='..'>Go back</a>");
	}
	
	return 0;
}
