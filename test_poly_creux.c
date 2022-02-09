#include <stdio.h>
#include <stdlib.h>

#include "poly_creux.h"


int main (int argc, char **argv)
{
  p_polyf_t p1, p2 ;
  
  if (argc != 3)
    {
      fprintf (stderr, "deux paramètres (polynomes,fichiers) sont à passer \n") ;
      exit (-1) ;
    }
      
  p1 = lire_polynome_float (argv [1]) ;
  p2 = lire_polynome_float (argv [2]) ;

  ecrire_polynome_float (p1) ;
  ecrire_polynome_float (p2) ;

  printf("p5(2) = %f\n", eval_polynome(p1, 2));
  printf("p6(3) = %f\n", eval_polynome(p2, 3));

}
