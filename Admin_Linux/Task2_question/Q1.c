#include<stdio.h>

int binary_search(int *arr ,int size ,int target){
	
	int start = 0 ; 
	int end = size - 1 ;
	int mid ;
	while(end >= start){
	mid = (start + end )/2;
	if(arr[mid] == target)
		return target;
	else if(arr[mid] < target){
		start = mid+1;
		}
	else
		end = mid - 1 ;

	}
	return -1 ;
}

int main(void){
	int arr[] = {1,2,3,4,5};
	int result = binary_search(arr,5,3);
	printf("%d",result);

	return 0;


}
