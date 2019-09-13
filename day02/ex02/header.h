#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_player {
  int   score;
  char  *name;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void quickSort(struct s_player **players);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_player **genRandomPlayers(int n);
struct s_player *createRandomPlayer(char *name);
void printPlayers(struct s_player **players);

/*--------------------------------
  &  your own other function
  --------------------------------*/
int 	findSize(struct s_player **players);
int		partition(struct s_player **players, int low, int high);
void	sortPlayers(struct s_player **players, int low, int high);

#endif
