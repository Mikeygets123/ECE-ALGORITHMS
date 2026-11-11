// DO NOT forget to add the prototypes for your ASort, BSort, and other functions below!


#include <string>
#include <unistd.h>
#define MAXSIZE	 2100000

using namespace std;

void	printmenu();
void	printarray(long data[], long size);
int		readfile(string infilename, long data[]);
int		writefile(long data[], long size, string outfilename);
void	swap(long& x, long& y);
void    heapsort(long data[], long n);
void    moveDown(long data[], int first, int last);
void    quicksort(long data[], int n);
void    quicksort(long data[], int first, int last);
void    Shellsort(long data[], int n);
void    bubblesort(long data[], int n);
void    mergesort(long data[], int first, int last);
void    merge(long data[], int first, int last);
