/*
Write a function in C that takes an array of integers (int arr[]), a pointer to its length (indicating the current number of
valid elements in the array), a maximum size (indicating the maximum capacity of the array), an integer value to insert,
and an index at which to insert it.
The function should insert the given value at the specified index by shifting all the values from that index onwards
one position to the right (i.e., shift right), provided there is enough space (i.e., current length < maximum size). The
new element should be placed at the specified index. For example, if the array is {5, 8, 3, 7} (length 4, max size 6), and
the value 10 is to be inserted at index 2, the result should be {5, 8, 10, 3, 7} with length updated to 5.
If the index is out of bounds (i.e., less than 0 or greater than the current length), or if the array is already full, the
function should leave the array unchanged.
The function does not return anything.
*/

#include <stdio.h>

void insertAtIdx(int arr[], int* length, int maxSize, int insert, int index);

int main() {

	return 1;
}
/*
createArrayOfInts takes an integer array, a pointer to the current length of the array, and the max size the array,
and an interger to insert, alongside an int representing the index to insert it it.

curr: length: 7; maxSize: 11
for i = 6; i >= 3; i-- 
insert 6 and arr[3]
 0  1  2  3  4  5  6  7    8    9    10
[0, 1, 2, 3, 4, 5, 6, spc, spc, spc, spc]
[0, 1, 2, 6, 3, 4, 5, 6,   spc, spc, spc]

*/
void insertAtIdx(int arr[], int* length, int maxSize, int insert, int index) {

	if ( (arr != NULL) && (length != NULL) && ((*length) >= 0) && (maxSize > (*length)) && (index >= 0) && (index >= (*length)) ) {
		for(int i = ((*length) - 1); i >= index; i--) {
			arr[i+1] =  arr[i];
			if (i == index) {
				arr[i] = insert;
				(*length)++;
				break;
			}
		}
	}
	
	return;
}
