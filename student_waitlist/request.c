//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "request.h"
#include "readline.h"

void update(struct request *list)
{
	//TEMPORARY NODE THAT WILL BE USED TO SEARCH THE LIST
	struct request *temp = list;
	
	//NODE THAT WILL STORE USER INPUT
	struct request *link_list = malloc(sizeof(struct request));					
	
	//USER INPUT	
	printf("Enter Class room: ");
	read_line(link_list->classroom,ROOM_LEN);
	printf("\nEnter child first name: ");
        read_line(link_list->first, NAME_LEN);
        printf("\nEnter child last name: ");
        read_line(link_list->last, NAME_LEN);
		
	//CHECKING IF STUDENT IS ALREADY ON WAITING LIST
	do{
		if(strcmp(temp->classroom,link_list->classroom) == 0 &&
			strcmp(temp->first,link_list->first) ==0 && 
			strcmp(temp->last,link_list->last)==0)
		{
			printf("\n%s  %s found on the list for classroom %s.", link_list->first, link_list->last, link_list->classroom);
			//DELETING THE NODE THE USER INPUTED IF DATA ALREADY IN LINK LIST
			free(link_list);
			
			//UPDATING CLASS ROOM
			printf("\nEnter new class room: ");
        		read_line(temp->classroom,ROOM_LEN);				
			
			//EXITING
			return;
		}//end if	
		
		//MOVING TEMP ONE NODE OVER
		temp = temp->next;
		
		//IF AT END OF LIST AND STUDENT MATCH IS NOT FOUND WILL PRINT MESSAGE
		if(temp == NULL)
			printf("\n%s %s was not found on the list for %s classroom.", link_list->first, link_list->last, link_list->classroom);
	
	}while(temp != NULL);//end while
	
	
}

void printList(struct request *list)
{
 	 //SETS P EQUAL TO LIST	       
        struct request *p = list;
	
        //PRINTING LIST CONTENTS
        printf("Classroom         First Name      Last Name       Contact Phone Number\n");
        while(p != NULL){
                printf("%-10s         %-10s       %-10s       %-10s \n", p->classroom, p->first, p->last, p->phone);
                p=p->next;
        }

}


void clearList(struct request *list)
{
	//TEMPORARY NODE THAT WILL BE USED TO GO THROUGH THE LIST 
       struct request *temp;
       while(list != NULL)
        {
		//SETS TEMP EQUAL TO TEMP               
                temp = list;
                //MOVES LIST TO NEXT NODE
                list = list->next;
                //DELETES TEMP IF TEMP IS NOT NULL
                if(temp != NULL)
                        free(temp);
        }//end while



}


struct request *append_to_list(struct request *list)
{
        struct request *link_list, *temp;
	
	//SETS TEMP EQUAL TO TEMP	
	if(list == NULL){
                link_list = malloc(sizeof(struct request));

		//USER INPUT
                printf("Enter Class room: ");
                read_line(link_list->classroom,ROOM_LEN);
                printf("\nEnter child first name: ");
                read_line(link_list->first, NAME_LEN);
                printf("\nEnter child last name: ");
                read_line(link_list->last, NAME_LEN);
                printf("\nEnter contact phone number: ");
                read_line(link_list->phone, PHONE_LEN);


		//LINK->NEXT SET TO NULL
           	link_list->next = NULL;
		//MAKING LINK_LIST FIRST NODE
                list = link_list;
		//RETURNING NEW LINK LIST
                return link_list;
        }
	
	else{
		//TEMPORARY NODE THAT WILL BE USED TO SEARCH THE LIST
                temp = list;
		struct request *curr, *prev,*swap;
		
		//ALLOCATING MEMORY FOR NODE
                link_list = malloc(sizeof(struct request));

		//USER INPUT
                printf("Enter Class room: ");
                read_line(link_list->classroom,ROOM_LEN);
                printf("\nEnter child first name: ");
                read_line(link_list->first, NAME_LEN);
                printf("\nEnter child last name: ");
                read_line(link_list->last, NAME_LEN);
	
		//CHECKING IF STUDENT IS ALREADY ON WAITING LIST
                do{
                        if(strcmp(temp->classroom,link_list->classroom) == 0 &&
                                strcmp(temp->first,link_list->first) ==0 &&
                                strcmp(temp->last,link_list->last)==0)
                        {
                                printf("\n%s  %s is already on the list for classroom %s,please use update(u) to change information",
                                        link_list->first, link_list->last, link_list->classroom);
				//EXITING IF USER ALREADY IN LIST
                                free(link_list);
                                return list;
                        }//end if

                        temp = temp->next;

                }while(temp != NULL);
		
		//USER INPUT
		printf("\nEnter contact phone number: ");
		read_line(link_list->phone, PHONE_LEN);
		
		//SORTING THEN INSERTING
		
		//For loop that goes through the list until new node classroom is less than curr
		for(curr = list, prev = NULL; curr != NULL && strcmp(link_list->classroom, curr->classroom)>0; prev = curr, curr=curr->next);
		
		//CHECKING FOR LAST NAME
		for(; curr != NULL && strcmp(link_list->last, curr->last)>0 && strcmp(link_list->classroom, curr->classroom)==0; prev = curr, curr= curr->next);
		
		//APPENDING TO LIST
		if(prev == NULL)
		{
			link_list->next = curr;
			return link_list;
		}//END IF
		else
			link_list->next = curr;
		{	prev->next = link_list;
			return list;
		}//end else
	
		//CASE 3: APPEND TO END IF NEW NODE IS GREATER THAN ALL ELEMENTS
		if(prev == NULL)
		{
			list->next = link_list;
			link_list->next=NULL;
			return list;
		}		
		else{
			prev->next = link_list;
			link_list->next = NULL;
			return list;
		}//end if prev


	}//end else

        return NULL;

}

struct request *delete_from_list(struct request *list)
{	
	//WILL STORE THE REQUEST 
	struct request *node=malloc(sizeof(struct request)); 
	//WILL GO THROUGH LOOP
	struct request *prev, *curr;
	
	//GETTING REQUEST INFORMATION
	printf("Enter classroom name: \n");
	read_line(node->classroom,ROOM_LEN);
	printf("Enter student's first name: \n");
        read_line(node->first,NAME_LEN);
	printf("Enter student's last name: \n");
        read_line(node->last,NAME_LEN);

	//FOR LOOP TO DELETE REQUEST
	for(curr = list, prev = NULL; curr != NULL; prev = curr, curr = curr->next)
	{
		//COMPARING CURRENT NODE WITH THE REQUEST USER HAS MADE
		if(strcmp(curr->classroom, node->classroom)==0 && 
			strcmp(curr->first, node->first)==0 &&
			strcmp(curr->classroom, node->classroom)==0)
		{	
			//IF CURR IS THE FIRST NODE 
			if(prev == NULL)
			{
				list = list->next;
				printf("\n %s %s was deleted from the list.", node->first, node->last);
				free(curr);

				return list;
			}//end if
			else
			{	
				prev->next = curr->next;
				free(curr);
				return list;//returning list because we are not changing the head node 
			}//end else
		}//end if
	}//end for 

	//STUDENT NOT FOUND ON LIST
	printf("The student was not found on list");
	return list;	
}//end request
