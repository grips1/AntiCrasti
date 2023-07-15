//c0ckbl0cker.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	FILE* command_stream;
	char buffer[100];
	if((command_stream = popen("ipconfig /displaydns", "rt")) == NULL) 
	{
		printf("Failed to create FILE stream!\n");
		return -1;
	}
	while(1)
	{
		for(int i = 0; i < 500; i++)
		{
			fgets(buffer, 100, command_stream); //need to clean buffer of spaces if I want to compare...
			puts(buffer);
			if(strcmp(buffer, "    pornhub.com\n") == 0)
			{
				//enter detection logic
				system("shutdown /s /t 1000");
				break;
			}
			else
				i =+ 4
			for(int a = 0; a < 100; a++)
			{
				buffer[a] = 0;
			}
		}
	}
	return 0;
}
