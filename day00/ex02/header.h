#ifndef HEADER_H
# define HEADER_H

# include <string.h>

/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_art {
	char *name;
	int price;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/

int searchPrice(struct s_art **arts, int n, char *name);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

struct s_art **getArts(int *n);
int 	findSize(struct s_art **arts);


/*--------------------------------
  &  your own other function
  --------------------------------*/

#endif
