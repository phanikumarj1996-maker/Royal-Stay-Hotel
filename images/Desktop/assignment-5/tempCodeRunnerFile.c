// # Traversing an array
// #include <stdio.h>
// int main(){
//     int arr[] = {1, 2, 3, 4, 5};
//     int n = 5;

//     for(int i = 0; i < n; i++){
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// # Insertion in Array
// #include <stdio.h>
// int main(){
//     int arr[100] = {1, 2, 3, 4, 5};
//     int n = 5, pos = 2, value = 10;

//     for(int i = n; i > pos; i--){
//         arr[i] = arr[i-1];
//     }
//     arr[pos] = value;
//     n++;

//     for(int i = 0; i < n; i++)
//         printf("%d ", arr[i]);
//     return 0;
// }


// # Deletion in Array
#include <stdio.h>
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5, pos = 2;

    for(int i = pos; i < n-1; i++){
        arr[i] = arr[i+1];
    }
    n--;

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
