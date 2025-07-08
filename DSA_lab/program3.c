#include <stdio.h>
void intersection(int arr1[],int arr2[],int arr[],int n1,int n2){
    int n3=0;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(arr1[i]==arr2[j]){
                for(int k=0;k<n3;k++){
                    if(arr[k]==arr1[i]){
                        break; // if already present, skip
                    }
                    else{
                        arr[n3]=arr1[i]; // add to intersection
                        n3++;
                        break; // exit inner loop after adding
                    }
                }
            }
        }
    }   
}


int main(){
    int arr1[]={1,2,3,4};
    int arr2[]={3,4,5};
    int arr3[10]; // array to store intersection
    intersection(arr1, arr2, arr3, 4, 3);
    printf("Intersection of the two arrays: ");
    for(int i=0;i<10;i++){
         
        printf("%d ", arr3[i]);
    }
}
