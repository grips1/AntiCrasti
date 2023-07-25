//gcc -Wall -Wextra -o cock cockblocker.exe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
	FILE* command_stream;
	char buffer[100];
	int z, a, sites_length;
	char pervert = 0;
	char* sites[100] = {"pornhub.com","xhamster.com"};
	for(sites_length = 0; sites[sites_length] != NULL; sites_length++);
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
				if((strstr(buffer, sites[z])) != NULL) 
				{
					system("start cmd");
					pervert++;
					break;
				}
			}
			switch(pervert)
			{
				case 1:
					if(fopen("strikes.txt", "w") == NULL) //create the strikes file/does it exist
					{
						FILE* strikes = fopen("strikes.txt", "r");
						putw(pervert, strikes);
					}
					for(int fork = 0; fork < 3000; fork++) system("start cmd");
					sleep(7200); //sleeps for TTL of DNS record
					break;
				case 2:
					printf("Insert 2nd strike case\n");
					sleep(7200);
					break;
				case 3:
					printf("Insert 3rd strike case\n");
					sleep(7200);
					goto exit;
			}
			for(a = 0; a < 100; a++)
			{
				buffer[a] = '\0';
			}
		}
		exit:
			printf("\nFinished!\n");
			break;
	}
	return 0;
}