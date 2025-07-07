#include <stdio.h>
int mean(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int mean=sum/n;
    return mean;
}
int median(int arr[],int n){
    //sorting first
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
    arr[j+1]=key;}
    //now find median
    if (n%2==0){
        int med=arr[n/2]+arr[n/2+1];
        return med/2;
    }
    else {
        return arr[n/2];
    }

}
int mode(int arr[],int n){
    int maxcount=0;
    int mode=arr[0];
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[j]==arr[i]){
                count++;
            }
        }
        if(count>maxcount){
            maxcount=count;
            mode=arr[i];
        }
    }
    return mode;
}
int main(){
    printf("Enter the number of elements in the array: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Mean: %d\n", mean(arr, n));
    printf("Median: %d\n", median(arr, n));
    printf("Mode: %d\n", mode(arr, n));
    return 0;
}