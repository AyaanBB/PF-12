// Online C compiler to run C program online
#include <stdio.h>

void Length(char *str)
{
    int len = 0;
    
    while(str[len] != '\0'){
      len++;
    }
    printf("%d", len);
    printf("\n");
}

void Reverse(char *str)
{
    int len = 0;
    
    while(str[len] != '\0'){
      len++;
    }
    for(int i=len-1;i>=0;i--)
    {
        printf("%c", *(str + i));
    }
    printf("\n");
}

void Concatenate(char *str,char *str1)
{
    int len = 0;
    
    while(str[len] != '\0'){
      len++;
    }
    int len1 = 0;
    
    while(str1[len1] != '\0'){
      len1++;
    }
    
    for(int i = 0;i<len;i++)
    {
        printf("%c", *(str + i));
    }
    
    for(int i=0;i<len1;i++)
    {
        printf("%c", *(str1 + i));
    }
}

int main() {

  char str[20] = "Deez";
  char str1[20] = " Nuts";    
    Length(str);
    Reverse(str);
    Concatenate(str,str1);

    return 0;
}