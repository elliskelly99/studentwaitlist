/*
 * Summary: This program manages a daycare waitlist by using a linked list to store data of the child classroom,first and last name,
 * and contact phone number. The user must first enter the operation code that will allow them to add to the list, update a book, 
 * and p to print all the request in the list.
*/
#include <stdio.h>
#include "request.h"

int main(void)
{ 
  char code;
  
  struct request *wait_list = NULL;  

  //Program Summary
  printf("------------------------------Program Summary-------------------------------");
  printf("\nThis program manages a daycare waitlist.\nImplemented using, C, a linked list  is used to store students data."
  " first and last name, and contact phone number.");
  printf("\n----------------------------------------------------------------------------");
  
  printf("\nOperation Code: \na:for appending to the list \nd:for deleting from the list \nu:for updating a book"
          "\np:for printing the list \nq:for quit.");


  for (;;) {
    printf("\n----------------------------------------------------------------------------");

    printf("\nEnter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': wait_list = append_to_list(wait_list);
                break;
      case 'd': wait_list = delete_from_list(wait_list);
		break;
      case 'u': update(wait_list);
                break;
      case 'p': printList(wait_list);
                break;
      case 'q': clearList(wait_list);
                return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

