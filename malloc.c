 // Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Write C code here
    int n = 5;
    
    int *a = (int*)malloc(n * sizeof(int));
    
    if(a == NULL)
    {
        printf("Fail");
        return 1;
    }
    
    int sum = 0;
    
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }

    printf("%d", sum);
    
    a = (int*)realloc(a,2*n * sizeof(int));
    
    for(int i = 0;i<2*n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    printf("%d", sum);
    
    free(a);
    return 0;
}