#include "myheaders.h"
void bubblesort(T data[], int n) {
	for (int i = 0; i < n-1; i++)
		for (int j = n-1; j > i; --j)
			if (data[j] < data[j-1])
				swap(data[j],data[j-1]);
}

