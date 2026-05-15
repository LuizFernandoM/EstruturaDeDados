#include <algorithm>
#include <stdio.h>
void mergesort(int arr[], int inicio, int fim) {
    if (fim - inicio < 1) {
        int meio = (inicio + fim) / 2;
        mergesort(arr, inicio, meio);
        mergesort(arr, meio, fim);
        merge(arr, inicio, meio, fim);
    }
}
void merge(int arr[], int inicio, int meio, int fim) {
    int leftSize = (fim - inicio) + 1;
    int rightSize = (fim - meio);
    for (int k=0; k<leftSize; k++) {

    }

}



int main() {

}