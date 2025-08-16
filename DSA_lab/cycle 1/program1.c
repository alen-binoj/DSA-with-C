#include <stdio.h>
void rotateleftbyone(int arr[],int n){
    int temp = arr[0];
    for (int i=0;i<n-1;i++){
        arr[i]= arr[i+1];
    }
    arr[n-1]=temp;
}
void rotaterightbyone(int arr[],int n){
    int temp=arr[n-1];
    for (int i=n-1;i>0;i--){
        arr[i] = arr[i-1];
    }
    arr[0]=temp;
}
int main(){
    printf("Enter the number of elements in the array: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("enter %d element:", i+1);
        scanf("%d", &arr[i]);
    }
    printf("Enter number of rotations:");
    int r;
    scanf("%d", &r);
    r=r%n;
    char direction;
    printf("Enter direction of rotation (l for left, r for right): ");
    scanf(" %c", &direction);
    if (direction == 'l') {
        for (int i = 0; i < r; i++) {
            rotateleftbyone(arr, n);
        }
    } else if (direction == 'r') {
        for (int i = 0; i < r; i++) {
            rotaterightbyone(arr, n);
        }
    } else {
        printf("Invalid direction! Use 'l' for left or 'r' for right.\n");
        return 1;
    }
for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;

}