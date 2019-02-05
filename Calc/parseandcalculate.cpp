/*
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "calc.h"

/*   If you want to add more constants, increment 'maxsym', and      */
/* add the symbol at the end of 'initsym'.                           */
/* Also, make sure MAXNAME is adequately dimensioned.                */
/*   If you want to add more operations, increment 'maxsym', 'maxf', */
/* and 'twonums' for each, depending on arguments it requires.       */

double pi = 3.141592653589793;
double c_light = 2.99792458e8; /* speed of light in m/s */
double h = 6.6260755e-34;      /* Planck's constant in J/s */
double Na = 6.0221367e23;      /* Avogadro's number, 1/mol */
                               /*double k_b= 1.380658e-23;                   Boltzman's constant, J/K */
                               /*double Faraday= 9.6485309e4;               Faraday's constant, C/mol */
                               /*double electric= 1.60217733e-19;                 Elementary charge C */
                               /*double m_e= 9.1093897e-31;                         Electron mass, kg */
                               /*double m_p= 1.6726231e-27;                           Proton mass, kg */
                               /* Ref: phys. const. from B.W. Petley, Sci. Prog. (Oxford), 1989, 73, 231. */


/* if you change the number of symbols, change the limit in calling pgms */
#define MAXNUM  100
#define MAXNAME  25

char *name[MAXNAME];

void initsym();
double funcs(int i, double y, double x);


#ifdef __cplusplus
extern "C"
#endif
double runcalcs(int argc, char ** argv)
   {
      /* initialize symbols for functions */
      initsym();

      int k = 0;
      /* up to twonums, only operate on one value */
      int twonums = 13;
      /* up to maxf, operate on two values */
      int maxf = 19;
      /* up to maxsym, assign a numerical constant value */
      int maxsym = 23;
      int i, top, prev, whatisit[MAXNUM];

      char c;

      double value[MAXNUM];
      double result, y, x;

      /* now make the remaining arguments into an array of numbers and actions */
      for (i = 1; i < argc; i++) {
         c = argv[i][0];
         k = 0;

         /* is it a number? */
         char *endpt;
         if ((c >= '0' && c <= '9') || (c == '.')) {
            whatisit[i] = 0;
            value[i] = strtod(argv[i], &endpt);
         }
         else if ((c == '-') && argv[i][1] != '\0') {
            whatisit[i] = 0;
            value[i] = strtod(argv[i], &endpt);
         }
         else {
            /* Some kind of loop to match values */
            while (k < maxsym && (strcmp(argv[i], name[k]) != 0)) k++;
            whatisit[i] = k;
            if (k >= maxf && k < maxsym) {
               if (k == 19) value[i] = pi;
               else if (k == 20) value[i] = c_light;
               else if (k == 21) value[i] = h;
               else if (k == 22) value[i] = Na;
               whatisit[i] = 0;
            }
         }
         if (k > 0 && k < maxf) {
            /* one value is needed, y */
            top = i - 1;
            while (whatisit[top] != 0 && top > 0) top--;
            y = value[top];
            whatisit[top] = -1;
            if (k > twonums) {
               /* if k>twonums, two values are needed, x and y */
               prev = top - 1;
               while (whatisit[prev] != 0 && prev > 0) prev--;
               x = value[prev];
               whatisit[prev] = -1;
            }
            result = funcs(k, y, x);
            value[i] = result;
            whatisit[i] = 0;
         }
         else if (k == maxsym) {
            printf("Unknown? %s\n", argv[i]);
         }
         /* printf("iteration %d, %d, %d, %.9g, %.9g, %.9g, %s\n",
         i, k, whatisit[i], value[i], y, x, argv[i]); */
      }

      return(result);
   }

   void fcn_list() {
      printf("  -  +  /  x\n");
      printf(" log   ln    invlog  invln  sin  cos  tan\n");
      printf(" atan  asin  acos    sqrt   sq   y^z  inv\n");
      printf(" Physical constants: pi  c(m/s)  h(J-s)  Na\n");
   }

   void initsym()
   {
      /* if you change the number of symbols, change the limit in calling pgms */
      /*
      strcpy(name[ 1] , "log");
      strcpy(name[ 2] , "ln");
      strcpy(name[ 3] , "invlog");
      strcpy(name[ 4] , "invln");
      strcpy(name[ 5] , "sin");
      strcpy(name[ 6] , "cos");
      strcpy(name[ 7] , "tan");
      strcpy(name[ 8] , "asin");
      strcpy(name[ 9] , "acos");
      strcpy(name[10] , "atan");
      strcpy(name[11] , "sqrt");
      strcpy(name[12] , "sq");
      strcpy(name[13] , "inv");
      strcpy(name[14] , "-");
      strcpy(name[15] , "+");
      strcpy(name[16] , "/");
      strcpy(name[17] , "x");
      strcpy(name[18] , "y^z");
      // numerical constants
      strcpy(name[19] , "pi");
      strcpy(name[20] , "c");
      strcpy(name[21] , "h");
      strcpy(name[22] , "Na");
      */

      name[0] = "";
      name[1] = "log";
      name[2] = "ln";
      name[3] = "invlog";
      name[4] = "invln";
      name[5] = "sin";
      name[6] = "cos";
      name[7] = "tan";
      name[8] = "asin";
      name[9] = "acos";
      name[10] = "atan";
      name[11] = "sqrt";
      name[12] = "sq";
      name[13] = "inv";
      name[14] = "-";
      name[15] = "+";
      name[16] = "/";
      name[17] = "x";
      name[18] = "y^z";
      /* numerical constants */
      name[19] = "pi";
      name[20] = "c";
      name[21] = "h";
      name[22] = "Na";
   }

   double funcs(int i, double y, double x)
   {
      double f = 0.0;

      switch (i) {
         /* here to twonums, operate on one value. */
      case 1:
         f = log10(y);
         break;
      case 2:
         f = log(y);
         break;
      case 3:
         f = pow(10.0, y);
         break;
      case 4:
         f = exp(y);
         break;
      case 5:
         f = sin(y);
         break;
      case 6:
         f = cos(y);
         break;
      case 7:
         f = tan(y);
         break;
      case 8:
         f = asin(y);
         break;
      case 9:
         f = acos(y);
         break;
      case 10:
         f = atan(y);
         break;
      case 11:
         f = sqrt(y);
         break;
      case 12:
         /* f = pow(x,2); */
         f = y*y;
         break;
      case 13:
         f = 1.0 / y;
         break;
         /* here to maxf, operate on two values */
      case 14:
         f = x - y;
         break;
      case 15:
         f = y + x;
         break;
      case 16:
         f = x / y;
         break;
      case 17:
         f = y*x;
         break;
      case 18:
         f = pow(x, y);
      }
      return(f);
   }
