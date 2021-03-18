#include <iostream>

using namespace std;

void display_array(int array[]){
    for(int i=0; i<10; i++){    //iterate through the array and print out each item
        cout << array[i] << " ";
    }
    cout << endl;
}

int binary_search(int array[], int first, int last, int search){
    int mid;

    if(last >= first){
        mid = (first+last)/2;   //find middle by dividing the smallest and largest index number by two
        if(array[mid] == search){   //if array equals search then
            return mid+1;   //return mid+1 (because mid will be one index lower)
        }
        else if(array[mid] < search){   //if array is less than the search number
            return binary_search(array, mid+1, last, search);   //adjust the lower index and try again
        } 
        else{ // if array is more than the search number
            return binary_search(array, first, mid-1, search);  //adjust the upper index and try again
        }
    }

    return -1;  //if the number isn't found then return -1
}

void bubble_sort(int array[], int n){
    int swapper;

    if(n != 1){
        for(int i=0; i<n-1; i++){   //iterate through array
            if(array[i] > array[i+1]){  //compare index and index+1
                swapper = array[i];
                array[i] = array[i+1];  //swap the integers around
                array[i+1] = swapper;
            }
        }
    }
    else{   //return if n=1 since we've gone through all we need to
        return;
    }
    bubble_sort(array, n-1);
}

int main(){
    int unordered_array[] = {5, 3, 1, 2, 4, 7, 6, 9, 8, 10};
    int found;

    display_array(unordered_array);
    bubble_sort(unordered_array, 10);
    display_array(unordered_array);
    found = binary_search(unordered_array, 0, 10, 4);

    cout << "4 was found at index " << found << endl;

    return -1;
}