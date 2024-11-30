 #include <stdio.h>

void Reverse(int *a, int n) {
    for (int i =n - 1;i >= 0; i--) {
        printf("%d ", *(a+i));
    }
    printf("\n");
}

int main() {
    int n;
    
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("Reversed array: ");
    Reverse(a, n);

    return 0;
}
