//c0ckbl0cker.c
//gcc -Wall -Wextra -o cock cockblocker.exe

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	FILE* command_stream;
	char buffer[100];
	int z, a, sites_length;
	//format's 4 spaces, [site]\n
	char* sites[100] = {"pornhub.com", "www.pornhub.com", "xhamster.com"};
	for(sites_length = 0; sites[sites_length] != NULL; sites_length++)
	{
			printf("Sites length = %d\n", sites_length);
	} 
	printf("Sites length = %d\n", sites_length);
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
			for(z = 0; z != sites_length; z++)
			{
				if((strstr(buffer, sites[z])) != NULL ) 
				{
					//enter upon detection logic
					system("start cmd");
					break;
				}
			}
			for(a = 0; a < 100; a++)
			{
				buffer[a] = '\0';
			}
		}
		printf("\nFinished!\n");
		break;
	}
	return 0;
}
