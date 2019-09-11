#ifndef HEADER_H
# define HEADER_H
# define AL 256
# define PRIME 101

# include <string.h>

/*--------------------------------
  !! required structure
  --------------------------------*/


/*--------------------------------
  :) function you must implement
  --------------------------------*/

int howManyJesus(char *bible, char *jesus);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

char *readFile(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/
int findPow(int len);
int findHash(char *str, int len);

#endif
