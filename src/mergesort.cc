#include "myheaders.h"


// Mergesort - recursively divides input array until we get sub-arrays of size 1

void	mergesort(long data[], long first, long last) {

			if (first < last) {  // i.e. array is of size 2 or larger

				long	mid;
				
				mid = (first + last)/2;
				
				mergesort(data, first, mid);
				mergesort(data, mid+1, last);
				
				merge(data, first, last);

			}
	
			return;
}



// Merge - merges left and right sub-arrays of the input array, in order

void	merge(long d[], long first, long last) {

		long	mid, i1, i2, i3;
		long	tmp[last-first+1];

		mid = (first + last)/2;
		i1 = 0;				// start index of tmp[]
		i2 = first;			// start index of left sub-array of d[]
		i3 = mid + 1;		// start index of right sub-array of d[]

		// while both left and right sub-arrays have elements ..
		while ((i2 <= mid) && (i3 <=last)) {
			
			if (d[i2] < d[i3])  tmp[i1++] = d[i2++];
			else				tmp[i1++] = d[i3++];
		}
		// After loop finishes, one of the sub-arrays will be empty. Therefore,
		//  we must copy the remaining sub-array elements into tmp[].

		// while right sub-array is empty, but the left one isn't ..
		while (i2 <= mid)	   tmp[i1++] = d[i2++];

		// while left sub-array is empty, but the right one isn't ..
		while (i3 <= last)	   tmp[i1++] = d[i3++];

		// Now, copy back the contents of tmp[] into d[]
		for (i1 = 0; i1 < (last-first+1); ++i1)	 d[first+i1] = tmp[i1];
	
		return;
}