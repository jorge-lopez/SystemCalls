#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main (int argc, char **argv)
{
	
	if( strcmp(argv[1], "copy") == 0)
	{
		int source = open(argv[2],O_RDONLY);
		int destiny = open(argv[3], O_CREAT | O_WRONLY );
		
		if( source > -1 )
		{
			char buffer;
			int i;
			while((i= read(source,&buffer,1)) != 0)		
				write(destiny,&buffer,1);			
		}
	}

	else if(strcmp(argv[1], "move") == 0)
	{        
		int i = link(argv[2], argv[3]);
		if ( i > -1)
		{
			unlink(argv[2]);
		}

	}

	 else if(strcmp(argv[1], "remove") == 0)
        {
		unlink(argv[2]);
        }



	return 0;
}
