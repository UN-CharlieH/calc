#include <stdio.h>
#include <string.h>
#include "calc.h"

/* cc -O calc.c -lm -o calc                        (Compile command) */


int main(int argc, char *argv[])
{
   int i;
   double result;

   /* First, check for flags */
   for (i = 0; i < argc; i++) {
      if (strcmp(argv[i], "-h") == 0 ||
         strcmp(argv[i], "-?") == 0)
      {
         fcn_list();
         return 0;
      }
   }


   result = runcalcs(argc, argv);
   printf("%.12g\n", result);

   return result;
}

