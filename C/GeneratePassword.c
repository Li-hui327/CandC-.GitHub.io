#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

char pwdcont[]="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
 
char* GeneratePassword(int pwd_size)
{
	int i; 
	int random;
	char *Password = (char *)malloc(pwd_size + 1);
	
	srand((unsigned)time(NULL));
	for(i = 0;i < pwd_size;i++)
	{
        random = rand()%(strlen(pwdcont));
		*(Password + i) = pwdcont[random]; 
	}
	
	*(Password + i)= '\0'; 
	return Password;	
} 

int main()
{
    int random;
    char *Password;
	srand((unsigned)time(NULL));
    
	for(int i=0;i<10;i++)
	{
		Sleep(100);
        random=rand()%(58)+6;//密码的长度范围 （6-63） 
        printf("random = %d\n",random);
		Password = GeneratePassword(random); 
		printf("Password = %s\n",Password);
	}
	free(Password);
    system ("pause");
	return 0;
} 
