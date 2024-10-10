 
#include <iostream> 
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;

class sortation { //Patrick
public:
	void Bubble_sort(int A[], int n);
	void selection(int A[], int n);
	void swap(int& i, int& j); 
private:
	int temp;
	int steps = 0;
};

//this function just shuffles the array 


//sorts to ascending order. 
void sortation::Bubble_sort(int A[], int n) {
    steps = 0;
	bool flag = false;
	steps++; //bool declare
	steps+=3;//int it, it < n && !flag = false
	for (int it = 0; it < n && !flag; it++) {
	    steps+=3; // = true, it++, flag = true
		flag = true; // Resets flag parameter
		steps+=2; //i, < n = false
		for (int i = 0; i < n - it - 1; i++) {
		    steps+=2; // = true, i++
		    steps++; //if else
			if (A[i] > A[i + 1]) {
				swap(A[i], A[i + 1]); // Swaps
				steps+=3; //swap
				flag = false;
				++steps; // Counts the number of steps for bubble sort
			}
		}

	}/*
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}*/
	cout << "\nNum of steps: " << steps << endl;
}


void sortation::selection(int A[], int n) {
    steps = 0;
    steps+=2; //iter = 0, < n -1 = false
	for (int iter = 0; iter < n - 1; iter++) {
	    steps+=3;//< n-1 = true, iter++, Largest
		int Largest = iter;
	    steps+=2; //i, i < n = false
		for (int i = iter + 1; i < n; i++) {
		    steps+=2; // = true, i++
		    steps++; // if else
			if (A[i] < A[Largest]) {
				Largest = i;
				++steps; //Largest
				swap(A[iter], A[Largest]);
				++steps;
			}
		}
	};/*
	for (int iter = 0; iter < n; iter++) {
		cout << A[iter] << ' '; 
	}*/
	cout << "\nNum of steps: " << steps << endl;;

};


void sortation::swap(int& i, int& j) { 
	int temp = i;
	i = j; 
	j = temp; 
}


void Insert(int A[], int n); //Bailey

void Heapity(int A[], int i, int n, int& s); //Bailey
void Swap(int& a, int& b);
void HeapSort(int A[], int n);


void Insert(int A[], int n)
{
	int steps = 0;
	steps++;
	steps++; //i , comparing when n-1 = false 
	for (int i = 1; i <= n - 1; i++) {
		steps += 2; //n-1 = true, i++
		int tmp = A[i];
		int j = i - 1;
		steps += 2; //tmp, j
        steps++; //loop cond. #1
		while (j >= 0 && tmp < A[j]) {
			steps++; //loop cond. #2
			A[j + 1] = A[j];
			steps++; //ask if J+1 counts as a step; otherwise A[i]
			j--;
			steps++;
		}
		A[j + 1] = tmp;
		steps++; //ask if J+1 counts as a step; otherwise A[j+1]
	}
	
	cout << " Steps: " << steps << endl;
     // if printing both sorts
	//steps += 2; //i & i < n = false
	/*
	for (int i = 0; i < n; i++) {
		//steps+=2; //i < n = true & i++
		cout << A[i] << ' ';
		
	}*/
	
}

void HeapSort(int A[], int n) 
{   //BuildHeap
	int steps = 0;
	steps++; //int i
	steps++; // i >= 0 = false
	//cout << "steps: ~ " << steps << endl;
	for (int i = n / 2 - 1; i >= 0; i--) {
		steps+=2;//i >= 0 = true, i--
		Heapity(A, i, n, steps); // will be counted in func
	    //cout << "steps: ~ " << steps << endl
	}
	//cout << "steps: ~ " << steps << endl; 
	//heap sort
	steps+=2; //int i, false
	for (int i = n - 1; i >= 0; i--)
	{   steps+=2; //true, i--
		Swap(A[0], A[i]);
		steps+=3; //swap func
		Heapity(A, 0, i, steps);
	}
	
	cout << " # of Steps: " << steps << endl;
}

void Heapity(int A[], int i, int n, int& s) //declare steps here
{   //cout << "steps: " << s << endl;
	int steps = s;
	int large = i;
	int l_child = 2 * i + 1;
	int r_child = 2 * i + 2;
	steps += 4; //int declaration
	steps++; //1st cond.
	//cout << "steps: ` " <<steps << endl;
	if (l_child < n && A[l_child] > A[large]) {
		steps += 2; //if 2nd cond. is true, large = 
		large = l_child;
	}
	steps++; //1st cond.
	if (r_child < n && A[r_child] > A[large]) {
		steps += 2; //2nd cond, large = 
		large = r_child;
	}
	steps++;// cond
	if (i != large) {
		Swap(A[i], A[large]); 
		steps += 3;// swap func
		steps++; //calling
		Heapity(A, large, n, steps);
	}
	s = steps;
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}





// Merge two sorted subarrays A[begin..mid] and A[mid+1..end]
int Merge(int A[], int begin, int mid, int end, int& steps) {
    int i, j, k;
    int n1 = mid - begin + 1; // length of left sub[]
    int n2 = end - mid; // length of right sub[]
    int L[n1], R[n2]; // temporary arrays to hold left/right sub[]
    steps+=7;
    steps+=2;
    // Copy data to temp. arrays L[] and R[]
    for (i = 0; i < n1; i++){
      steps+=2;
        L[i] = A[begin + i];
        steps++;
    }
  steps+=2;
    for (j = 0; j < n2; j++){
      steps+=2;
        R[j] = A[mid + 1 + j];
        steps++;
    }

    // Merge the two temporary arrays back into A[begin..end]
    i = 0; // left sub[]
    j = 0; // right sub[]
    k = begin; // initial index for merged sub[]
  steps+=3;
    while (i < n1 && j < n2) { // while both subarrays have elements
        steps++; // increment the step counter for each comparison
        if (L[i] <= R[j]) { // if left element is smaller or equal
            A[k] = L[i]; // copy it to merged array
            i++; // move to next element in left subarray
            steps++;
        }
        else { // otherwise, right element is smaller
            A[k] = R[j]; // copy it to merged array
            j++; // move to next element in right subarray
            steps++;
        }
        k++; // move to next element in merged array
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
        steps+=3; // increment the step counter for each element moved
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
        steps+=3; // increment the step counter for each element moved
    }
    return steps; // return the total number of steps
}

// Merge sort algorithm to sort array A[begin..end]
int MergeSort(int A[], int begin, int end, int& steps) {
    if (begin < end) {
        int mid = (begin + end) / 2;

        MergeSort(A, begin, mid, steps);
        MergeSort(A, mid + 1, end, steps);

        steps += Merge(A, begin, mid, end, steps);
    }

    return steps;
}


// function to partition the array into two parts
// and return the index of the pivot element
int partition(int A[], int start, int end, int& steps) {
   int pivot = A[end]; // select the last element as pivot
    int P = start; // initialize partition index as start
      //steps+=2;
      //steps+=2;
    for (int i = start; i < end; i++) {
        steps+=2;
        if (A[i] <= pivot) {
            // swap A[i] and A[pIndex]
            int temp = A[i];
            A[i] = A[P];
            A[P] = temp;
            P++;
            //steps+=3;
            steps++;
        }
        steps++;
    }
    // swap A[pIndex] and A[end]
    int temp = A[P];
    A[P] = A[end];
    A[end] = temp;
    steps++;
    //steps+=3;
    return P; // return the partition index
}

void QuickSort(int A[], int start, int end, int& steps) {
    if (start < end) {
        steps++;
        int P = partition(A, start, end, steps); // partition the array
        QuickSort(A, start, P - 1, steps); // recursively sort the left subarray
        QuickSort(A, P + 1, end, steps); // recursively sort the right subarray
    }
}








void shuffle_array(int arr[], int n)
{
    
    // To obtain a time-based seed
    unsigned seed = 0;
    //srand ( time(NULL) );
    // Shuffling our array... default_random_engine(seed)
    shuffle(arr, arr + n, default_random_engine(seed));
 
    // Printing our array
   /* for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;*/
}


int main()
{   //must have 8 different arrays with the same data
  const int n = 100;
  int arr1[n]; //Bubble
	int arr2[n]; //Selection
	int arr3[n]; //Insertion
	int arr4[n]; //Heap
	int arr5[n]; //Merge
	int arr6[n]; //Quick


//initializations of sorted reverse instance
    cout << "Original " << n << endl;
    //cout << "here" << endl;
    
    //int j = n;
    for(int i = 0; i < n; i++){
        //cout << "here" << endl;
        arr1[i] = i+1; //j
        arr2[i] = i+1; //j
        arr3[i] = i+1; //j
        arr4[i] = i+1; //j
        arr5[i] = i+1; //j
        arr6[i] = i+1; //j
        //j--;
        //cout << arr1[i] << ' ';
    }
    
    /*//srand((unsigned)time(NULL)); 
    srand(time(0));
    shuffle_array(arr1, n);
    shuffle_array(arr2, n);
    shuffle_array(arr3, n);
    shuffle_array(arr4, n);
    shuffle_array(arr5, n);
    shuffle_array(arr6, n);
    */

    
    //cout << "actual" << endl;
    //for(int i = 0; i < n; i++ ){
      //  cout << arr1[i]<< ' ';
    //}
  
  //Bubble
    cout << "Bubble Sort" << endl;
    sortation P;
    long before1 = clock();
    P.Bubble_sort(arr1, n);
    long after1 = clock();
    double elapsed = (double)(after1-before1)/CLOCKS_PER_SEC;
     cout << "Bubble CPU Time: " << elapsed << endl;
  cout  << endl;
  
     //Selection
  cout << "Selection Sort" << endl;
    long before2 = clock();
    P.selection(arr2, n);
    long after2 = clock();
    double elapsed2 = (double)(after2-before2)/CLOCKS_PER_SEC;
     cout << "Selection CPU Time: " << elapsed2 << endl;
     cout  << endl;

  //Insertion
  cout << "Insertion Sort" << endl;
     long before3 = clock();
    Insert(arr3, n);
    long after3 = clock();
     double elapsed3 = (double)(after3-before3)/CLOCKS_PER_SEC;
     cout << "Insert CPU Time: " << elapsed3 << endl;
    cout  << endl;

  //Heap
  cout << "Heap Sort" << endl;
    long before4 = clock();
    HeapSort(arr4, n);
    long after4 = clock();
    double elapsed4 = (double)(after4-before4)/CLOCKS_PER_SEC;
    cout << "Heap CPU Time: " << elapsed4 << endl;
    cout  << endl;
  
  //Merge
  cout << "Merge Sort" << endl;
  int steps = 0;
    long before5 = clock();
    for (int i = 0; i < n; i++) {
        int* arr = new int[arr5[i]];
        // calc # of steps taken
        
        MergeSort(arr, 0, arr5[i] - 1, steps);
    //cout << "n = " << arr6[i] << ", steps = " << steps << endl;
      
        delete[] arr;
    }
    cout << steps << endl;
    long after5 = clock();
    double elapsed5 = (double)(after5-before5)/CLOCKS_PER_SEC;
    cout << "Merge CPU Time: " << elapsed5 << endl;
    cout << endl;

    //Quick
    cout << "Quick Sort" << endl;
    long before6 = clock();
    steps = 0;
    for (int i = 0; i < n; i++) {
      
        int* arr = new int[arr6[i]];
        // fill array with random numbers
        //for (int j = 0; j < A[i]; j++) {
            //arr[j] = rand();
        //}
        // calc # of steps taken
        
        QuickSort(arr, 0, arr6[i] - 1, steps);
        //cout << "n = " << arr6[i] << ", steps = " << steps << endl;
        delete[] arr;
    }
    cout << steps << endl;
    long after6 = clock();
    double elapsed6 = (double)(after6-before6)/CLOCKS_PER_SEC;
    cout << "Quick CPU Time: " << elapsed6 << endl;
   

	return 0;

}
