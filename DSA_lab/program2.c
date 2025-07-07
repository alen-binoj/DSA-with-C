#include <stdio.h>
int mean(int arr[],int n){
    int sum=0;
    for(i=0;i<n;i++){
        sum+=arr[i];
    }
    int mean=sum/n;
    return mean;
}
int median(int arr[],int n){
    //sorting first
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
    }
    arr[j+1]=key;
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
    for(i=0;i<n;i++){
        int count=0;
        for(j=0;j<n;j++){
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