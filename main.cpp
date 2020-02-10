// GroceryItem Implementation file
// Brian Lucero
// CS131
// part 0
// spring 2020 - started on 2/3/2020

#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <functional>
#include <stdio.h>


// Program requirements from pdf :
// 1. Read a grocery item from standard input (std::cin) until end of file.
//     For each item read:
//     a. Store the grocery item in a dynamically allocated object
//     b. Store the pointer to the grocery item in a standard vector

// 2. After you have reached the end of file, write the grocery items
//    to standard output (std::cout), in reverse order.

// 3. Be sure to release the dynamically allocated objects before exiting the program

// ============== N O T E S ===================================================
// 1. How to read until end of file : general idea :
        // std::string line;
        // while (std::getline(std::cin, line))
        // {
        //     std::cout << line << std::endl;
        // }

// 2. considering using FOPEN / FCLOSE functions :
// a. r+ : read/update: Open a file for update (both for input and output). The file must exist.
// b. w+ : write/update: Create an empty file and open it for update (both for input and output).
//         If a file with the same name already exists its contents
//         are discarded and the file is treated as a new empty file.
// c. r : read: Open file for input operations. The file must exist.
// d. w. : write: Create an empty file for output operations.
//         If a file with the same name already exists, its contents are discarded
//         and the file is treated as a new empty file.
// ============================================================================

int main() {

// opens given input file
  FILE * pFile;
   int c;
   int n = 0;
   pFile=fopen ("sample_input.txt","r");
   if (pFile==NULL) perror ("Error opening file");
   else
   {
     do {
       c = getc (pFile);
       if (c == '$') n++;
     } while (c != EOF);
     fclose (pFile);
     printf ("File contains %d$.\n",n);
   }

   
  /* fopen example */
  // make sure to close your files
  FILE * poFile;
 poFile = fopen ("sample_input.txt","r");
 if (poFile!=NULL)
 {
   fputs ("solution to the main() problem",poFile);
   fclose (poFile);
 }

  return 0;
}
