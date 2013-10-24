#include <stdio.h>

#include <dirent.h>

int main()
{
	DIR *dir;
	struct dirent *ent;
	
	printf("Content-type: text/html\n\n");
	
	if ((dir = opendir ("../uploads")) != NULL) {
	  /* print all the files and directories within directory */
	  while ((ent = readdir (dir)) != NULL) {
		if (ent->d_type == DT_REG)
			printf ("<div style='float:left;padding:5px'>"
				"<label align='center'>%s</label><br />"
				"<a href='../uploads/%s'>"
					"<img src='../uploads/%s' style='max-width:450px;max-height:250px'>"
				"</a><br/>"
				"<a href='delete.cgi?name=%s'>Delete</a>"
				"</div>\n", ent->d_name, ent->d_name, ent->d_name, ent->d_name);
	  }
	  closedir (dir);
	  
	  printf("<div style='clear:both'></div><br /><a href='..'>Go back</a>");
	  
	} else {
	  printf("could not open directory");
	  perror ("");
	  return -1;
	}

	return 0;
}
