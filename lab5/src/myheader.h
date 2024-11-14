#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <string>
#include <unistd.h>
#define MAXSIZE	 2100000

using namespace std;

void	printmenu();
void	printarray(long data[], long size);
int		readfile(string infilename, long d1[], long d2[]);
int		writefile(long data[], long size, string outfilename);
void	swap(long& x, long& y);
void 	bubblesort(long data[], int size);
void    mergesort(long data[], int firstIndex, int lastIndex);



#endif /* MYHEADER_H_ */
