#include<iostream>

int sum(int* a, int len){
    int ans = 0;
    for (int i = 0; i < len; i++){
        ans += a[i];
    }

    return ans
}

int main(){
    // pointer types are closely tied
    // to arrays
    int x;
    int* p;
    int* q = p+1;

    int num = 5;

    // &variable -> take the addr of variable
    // type of addr_of_num is of (int-start or int-pointer)
    int* addr_of_num = &num;


    // this is getting the value stored at the addr_of_num value
    cout <<  "number via pointer" << *addr_of_num << endl;
    
    int arr[10];
    /* Here, the variable "arr" is really a pointer 
     * to the integer array[0]
     */


}
