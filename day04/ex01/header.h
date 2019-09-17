#ifndef HEADER_H
# define HEADER_H

# include <string.h>

/*--------------------------------
  !! required structure
  --------------------------------*/


/*--------------------------------
  :) function you must implement
  --------------------------------*/
char *getAnd(char *a, char *b);
char *getOr(char *a, char *b);
int toInt(char *bits);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
int checkBinary(char *str);

/*--------------------------------
  &  your own other function
  --------------------------------*/
char *getNeg(char *a);

#endif