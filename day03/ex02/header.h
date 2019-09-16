#ifndef HEADER_H
# define HEADER_H

# include <string.h>
# include <stdlib.h>
/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	char	*name;
	struct s_node **children;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_node *getTreeOfLife(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/
struct s_node *lowestCommonAncestor(struct s_node *root, char *firstSpecies, char *secondSpecies);
int findSpecies(struct s_node *root, char *species);

#endif
  