#include <stdio.h>
#include <stdlib.h>
#include "contactList.h"
#include <string.h>
#include <ctype.h>

// IF IT'S EASIER, YOU NEED NOT BE OVERLY GENERAL/FLEXIBLE
// BUT CAN ASSUME THESE LIMITS
#define MAXCONTACTS 30 /* max # of contacts */
#define MAXPHONES 10 /* max # of phone numbers for each contact */

#define PHONE_NUMBER_MAX_LENGTH 12
// INCLUDE YOUR OWN "HELPER" ROUTINES AS YOU SEE FIT

//contact (Big): Includes contact nameand phone number.
struct contactNode *head2=NULL;
//struct node2 *head2=(nodeContact *)malloc(sizeof(nodePhoneNum));

// contactNumNode = Contact Number (Small):
struct contactNumNode
{
    char contactNumber[PHONE_NUMBER_MAX_LENGTH];
    struct contactNumNode *next;  //Create variable called "next" as a pointer to point toward structure node 1.
} nodePhoneNum;  //Name of variable that has structure of node 1.

//Linked list needs to store 2 main things: Data of itself and Next(Address of the next linked list).
// structure is like a variable BUT can store many types of variables(information) inside.
// HOW is Linked List conencted to Strucutre?
// ANS: We need to use structure to reate a linked list.
struct contactNode
{   //Another linked list(structure) inside structure.
    struct contactNumNode *head1; //Create a variable called head1 as a pointer that points to the structure of node 1.
//    struct node1 head1=(nodePhoneNum *)malloc(sizeof(nodePhoneNum));
    
    char contactName[150]; // Number of alphabets of a person's name.
    
    struct contactNode *next;
    
}nodeContact;

// 2 variable(information) that is being stored:
// 1.) Data of itself.
// 2.) next is the second type but just happen to be a "pointer" which stores address of the next linked list that is conencted to this linked list.
// 3.) head2 is OUTSIDE of the structure BUT is a pointer that MUST points to the structure.



// Function: ListAllContacts
void ListAllContacts()
{
    struct contactNode *tempHead2;
    struct contactNumNode *tempHead1;
    tempHead2 = head2;
    tempHead1 = head2->head1;

    
    while(tempHead2 != NULL)
    {
        printf("Name: %s\n", tempHead2->contactName);
        
        if(tempHead1 != NULL)
        {
            printf("Phone(s):");
            
            while(tempHead1 != NULL)
            {
                printf(" %s", tempHead1->contactNumber);
                tempHead1 = tempHead1 ->next;
            }
            printf("\n");
        }
        tempHead2 = tempHead2->next;
        
        if(tempHead1 == NULL && tempHead2 == NULL)
        {
            break;
        }
        
        tempHead1 = tempHead2->head1;
        
    }
    ////Also work ////
//    while((tempHead->next) != NULL)
//    {
//        printf("Name: %s\n", tempHead->contactName);
//    
//        tempHead = tempHead->next;
//    }
//    printf("Name: %s\n", tempHead->contactName);
}

//Function: sortFront
int sortFront(char oldArr[50], char newArr[50])
{
    int maxString=0;
    // Find: The maximum number of alphabet of the shorter string.
        if(strlen(oldArr) < strlen(newArr))
        {
            maxString = strlen(oldArr);
        }
        else
            maxString = strlen(newArr);
            
            
    for(int i=0; i< maxString; i++)
    {
        if(oldArr[i] > newArr[i])
        {
//            printf("Old alphabet greater than New");
            return 1;
        }
        else if(oldArr[i] < newArr[i])
        {
//            printf("New alphabet greater than Old");
            return -1;
        }
    }
    return 0;
}

int sortMiddle(char middleArr[50], char backArr[50])
{
    int maxString = 0;
    // Find: The maximum number of alphabet of the shorter string.
        if((strlen(middleArr) < strlen(backArr)))
            maxString = strlen(middleArr);
            
        else //if((strlen(backArr) < strlen(frontArr)) && (strlen(backArr) < strlen(middleArr)))
            maxString = strlen(backArr);
            
            
    for(int i=0; i<maxString; i++)
    {
        if(middleArr[i] < backArr[i])
        {
            return 1;
        }
        else if(middleArr[i] > backArr[i])
        {
            return -1;
        }
    }
    return 0;
}



//Function: addContactName

// NOTE: strName is the string in contactList that is a "Name".
void addContactName(char strName[50]) //Adding an item to the end of the list.
{
int count=0;
//    void push(node_t * head, int val)
    
    //Create a new pointer call "current" that points to the same pointer of head2.
    // WHY? Because head2 is a pointer, changing it's value will change its address
    // of head2 that are used anywhere is this file. Therefore, we create another pointer
    // that is essentailly a copy of head2 pointer but chanign this pointer will not affect affect head2.
    
    /////////1.)/////////
    struct contactNode *current;
    current = head2;
    
    struct contactNode *tempFirst;
    struct contactNode *tempLast;
    tempFirst = head2;
    tempLast = head2->next;
    
    // Add to front.
    if(sortFront(current -> contactName, strName) ==1) // !=1 Means to put the new,later string in front of the intiial string.
    {
//      printf("\nCheckpoint1\n");
        struct contactNode *temp; //Declare pointer temp, pointing to structure of contactnode.
        temp=head2;
        
        head2 = (struct contactNode *) malloc(sizeof(struct contactNode));
        
        strcpy(head2->contactName, strName); // If the new string (strName) has alphabet less than the old string,
                                             // Then add the new string to the new head2 of new link list that is placed before the old link list.
        head2->next= temp; //set next of the new head2 to point to the initial head2.
        return ;
    }
    
    
    while((sortMiddle(strName, tempLast->contactName) ==-1) && tempLast->next !=NULL)
    {
        tempFirst = tempFirst->next;
        tempLast = tempLast->next;
    }
    
    ////////2.)/////////
    
    if((tempLast != NULL) && sortMiddle(strName, tempLast->contactName) ==1)
    {
//        printf("\nCheckpoint2\n");
        current = (struct contactNode *) malloc(sizeof(struct contactNode));
        
        tempFirst->next = current;
        
        strcpy(current->contactName, strName);
        
        current->next = tempLast;
    }
    
    //////////3.)////////////
    
    else //Add to back.
    {
//        printf("\nCheckpoint3\n");
        while (current->next != NULL)
        {   //current->next means "next" of current head, which is head2.
            current = current->next; // Shifting "Head", where the head is called "current".
            //Current is equal to "next" of the current itself. In which "next is pointing to the address
            //of the next structure that is linked to the initial structure.
        }
        // WHEN: current-> next == NULL
        // Meaning: When "next" of the current "current" is poitning to NO other linked list / pointing to NULL.
        // THEN: We create a new linked list using malloc and assigns it's address to the pointer current->next.
        // current->next is the "next" pointer that is of the head called "current".
        // KEY NOTE: Header is a ...???
        /* now we can add a new variable */
        current->next = (struct contactNode *) malloc(sizeof(struct contactNode));  // Connected linked list together/
        
    //  current->next->contactName = contactName; } CANNOT use EQUAL sign because this is a string.
        
        strcpy(current->next->contactName, strName); //strcpy(destination, source)
        
        current->next->next = NULL;
    }
    
}



// Function: addContactNum
void addContactNum(char storeContactName[50], char strNum[50])
{
    int count=0;

    struct contactNode *tempHead2;
    tempHead2 = head2;
    
    struct contactNumNode *tempHead1;
    tempHead1 = tempHead2->head1; //Because tempHead2 changes. //tempHead1 is a spare that store head1.
    // Declare temHead1 as a pointer to store address of tempHead2->head1.
    
    while (tempHead2 != NULL)
        {   
            if(sortFront(storeContactName, tempHead2->contactName) == 0)
            {
                break;
            }
            tempHead2 = tempHead2->next; // Shifting "Head", where the head is called "current".
        }

        if(tempHead2 != NULL)
        {
            tempHead1 = tempHead2->head1; //Let tempHead1 point to the newest tempHead2.
            
            while(tempHead1 !=NULL)
            {
                count++;
                tempHead1 = tempHead1->next;
            }
            tempHead1 = tempHead2->head1;
        }      

        if(tempHead2 != NULL && count <= MAXPHONES)
        {
            if(tempHead1 == NULL) //tempHead1 is inside tempHead2 that is changing.
             {
                   tempHead2->head1 = (struct contactNumNode *) malloc(sizeof(struct contactNumNode));  //Create New linked list.
        
             // *tempHead1 = (struct contactNumNode *) malloc(sizeof(struct contactNumNode));
              // tempHead1 = (struct contactNumNode *) malloc(sizeof(struct contactNumNode)); = Assign new address to tempHead1, BUT tempHead1 is NOT in structure.
               strcpy(tempHead2->head1->contactNumber, strNum); //strcpy(destination, source)
            
                tempHead2->head1->next = NULL;
             }
            else
            {
               struct contactNumNode *temp;
               temp = tempHead2->head1;
               tempHead2->head1 = (struct contactNumNode *) malloc(sizeof(struct contactNumNode));
        
                  strcpy(tempHead2->head1->contactNumber, strNum); // If the new string (strName) has alphabet less than the old string,
                                                        // Then add the new string to the new head2 of new link list that is placed before the old link list.
                  tempHead2->head1->next= temp; //set next of the new head2 to point to the initial head2.
              }
        }

}



/*
 * convertInputToDataStructure
 * Takes the information in contactList.h and puts it into a data
 * structure of your choosing, however: 1 mark of the lab will be
 * for using structs with pointers in your solution.
 * You might also want to consider the outputs from the program
 * (see the menu printed in printMenu) since some structures will
 * make this easier than others.
 */
void convertInputToDataStructure() {
    // YOUR CODE HERE
    
    char storeContactName[50];
    if(head2 == NULL) //head2 is NULL because it does not have any structure to point too yet.
    {
        head2 = (struct contactNode *) malloc(sizeof(struct contactNode)); //Return address of memory that we booked to head2.
        
        strcpy(head2->contactName, contactList[0]); //Since we know that the 1st string in the ContactList is a Name, we can therefore store the 1st string in contactList(which is a name) into contactName.
        
        strcpy(storeContactName, contactList[0]);
        head2 -> next = NULL; //Assigned next as NULL because this is the first structure.
    }
    
//    ListAllContacts();
    
    int maxSize = sizeof(contactList)/8; //Array 1 entry have size 8.
    
    for(int i=1; i< maxSize; i++)
    {
        char str[50]; //Declare str 1D array.
        
        strcpy(str, contactList[i]); //strcpy(destination, source) where we want to copy the source into the destination.
        //"Each individual" string that are listed in contactList[i] is being copied to str for every i.
        // Process:
        // 1.) For i=0 --> contactList[0], str = contactList[0] = Johnny Chen.
        // 2.) CHECK/ SORT: Check and Sort if the 1st letter of the string is an alphabet or a number.
        // 3.) If it is an "Alphabet", then it means that this string is a "Name". Therefore, pass this individual string of a single index in contactList[index] to the function AddContactName.
        // 4.) If it is an NOT an Alphabet, then it means that this string is a "Phone Number". Therefore, pass this individual string of a single index in contactList[index] to the function AddContactNum.
        // 5.) Repeat STEP 1,2,3,4 for every "i", that is the index in the contactList[i], i.e. for every string(Name and Phone Number) in the contactList.
        
        
        //Check if the first letter of each string is an alphabet or not.
        // IF: 1st Letter of String is an "Alphabet"--> This string is a name --> Add this string to addContactName function.
        // IF: 2nd Letter of String is an "NOT an Alphabet"--> This string is a phone number --> Add this string to addContactNum function.
        if(isalpha(str[0]) !=0)
        {
//            printf("%s\n", str);
            addContactName(str); //Function addContact: Adds contact Name.
//            ListAllContacts();
//            printf("\n--------------------------------------------\n");
            strcpy(storeContactName, str);
        }
        
        else
        {
            addContactNum(storeContactName,str); // Function addContactNum: Adds contact number.
            //ListAllContacts();
        }
    }

}



/*
 * printMenu - Prints out the user menu
 */
void printMenu() {
   printf("\n\nEnter a command by number\n");
   printf("1. List all contacts in alphabetical order\n");
   printf("2. Print phone(s) for a contact\n");
   printf("3. Find duplicate entries\n");
   printf("4. Delete contact\n");
   printf("5. Exit the program\n");
   printf("Your input: ");
}

//eliminate trailing \n
char* rtrim(char* str)
{
   int i;
   for (i = strlen(str) - 1; i >= 0 && str[i] == '\n'; i--)
      str[i] = '\0';
   return str;
}

// Function: PrintContact

// 1.) User input name
// 2.) Print contact number of the inputted name.
// 3.) Similar to addPhone Number.
// Find name that matches first. Then print the phone number in that name.

void PrintContact()
{
    printf("Enter name: ");
    
    char userChoice[100];
    char* s = fgets(userChoice, sizeof(userChoice), stdin);
    if (!s)
    {
        printf("Wrong input\n");
    }
    s = rtrim(s); /* eliminate trailing \n */
    //printf("selection = %s\n", s);
    //printf("%s\n", s); Print to Check that the same name as that of user's input is printed out.

    struct contactNode *current;
    current = head2;
    
    struct contactNode *tempHead2;
    tempHead2 = head2;
    
    struct contactNumNode *tempHead1;
    tempHead1 = tempHead2->head1; //Because tempHead2 changes. //tempHead1 is a spare that store head1.
    // Declare temHead1 as a pointer to store address of tempHead2->head1.


    while (tempHead2 != NULL)
    {   
        if(sortFront(s, tempHead2->contactName) == 0) //Check same name.
        {
            printf("Name: %s\n", s);
            printf("Phone(s): ");
            while(tempHead1 != NULL)
            {
                printf("%s", tempHead1->contactNumber);
                tempHead1 = tempHead1 -> next;
            }
            printf("\n");
            return;
        }
            
            tempHead2 = tempHead2->next; // Shifting "Head", where the head is called "current".
            if(tempHead2 == NULL)
            {
                break;
            }
            // Alternative Method//
//            if(tempHead2 !=NULL)
//            {
//                tempHead1 = tempHead2->head1;
//            }

            tempHead1 = tempHead2->head1;
    }

    printf("Contact not found\n");
    
}



/*
 * DeleteContact deletes a contact from the list
 * The user must enter the name of the contact to delete
 * 
 */

// 1.) User input name
// 2.) Print contact number of the inputted name.
// Similar to addPhone Number.
// Find name that matches first. Then change next of previous link to the next link. Then free.
void DeleteContact() {
//    // YOUR CODE HERE

printf("Enter name: ");
    
    char userChoice[100];
    char* s = fgets(userChoice, sizeof(userChoice), stdin);
    if (!s)
    {
        printf("Wrong input\n");
    }
    s = rtrim(s); /* eliminate trailing \n */
    //printf("selection = %s\n", s);
    //printf("%s\n", s); Print to Check that the same name as that of user's input is printed out.
    
    //////////////////////////////////////////////////////
    struct contactNode *current;
    current = head2;
    
    struct contactNode *tempHead3;
    tempHead3 = head2;
    
    struct contactNode *tempHead2;
    tempHead2 = head2;
    
    struct contactNumNode *tempHead1;
    tempHead1 = tempHead2->head1;
    
    int count=0;
    while (tempHead2 != NULL)
        {   
            if(sortFront(s, tempHead2->contactName) == 0)
            {
                //Delete Front
                if(count==0) //switch this line with if(sortFront(s, tempHead2->contactName) == 0).
                {
//                  printf("Checkpoint1\n");
                    tempHead3 = head2->next;
                    free(head2);
                    head2 = tempHead3;
                    break;
                }
            }
            
            if(tempHead2->next != NULL)
            {
                if(sortFront(s, tempHead2->next->contactName) == 0) //Check same name.
                {
                
                    //Delete Last
                    if(tempHead2->next->next==NULL)
                    {
//                        printf("Checkpoint2\n");
                        free(tempHead2->next);
                        tempHead2->next = NULL; //CANNOT USE == (COMPARE) | MUST USE "=" assignment.
                        break;
                    }
                    
                    //Delete Middle
                    else //When tempHead2->next->next !=NULL
                    {
//                      printf("Checkpoint3\n");
                        tempHead3 = tempHead2->next->next;
                        
                        free(tempHead2->next);
                        
                        tempHead2->next = tempHead3;
                        break;
                        
//                        tempHead3->next == NULL; // WRONG. NOT TRUE THAT tempHead3->next has to be NULL.
                    }
                    
                    
                }
            }
            
            tempHead2 = tempHead2->next;
            count++;
        }
        
//        if(sortFront(s, current->contactName) != 0)
        if(tempHead2 ==NULL)
        {
            printf("Contact not found");
        }
    
}



//
//
///*
// * findDuplicates finds the names of contacts with 
// * a phone number in common
// */
//


// 1.) Find repeated name.
// 2.) Print only repeated name.
void FindDuplicates() {
//    
//    // YOUR CODE HERE
    
    struct contactNode *current2;
    current2 = head2;
    
    struct contactNumNode *current1;
    current1 = current2->head1;
    
    //////
    struct contactNode *tempHead2;
    tempHead2 = head2->next;
    
    struct contactNumNode *tempHead1; //next and head1 is  Pointer which stores "Address". | head1 is a pointer that keeps the address of first contact number linkedlist. |  Next is a pointer that keeps address of the next structure.
    tempHead1 = tempHead2->next->head1; //tempHead1 is a pointer that points to the address of head1.
    // KEY: tempHead1 DOES NOT point to tempHead2.
    // tempHead1 DOES NOT store the address of tempHead2, BUT store the address of head1 that happens to be INSIDE tempHead2 in this case.
    // THIS MEANS THAT: Change/shift/increment head2 to head->next or example, THEN: tempHead1 WILL NOT be changed/shifted/incremeented as well since it stores the address of the old head1 NOT the new head1 that resides inside the new tempHead2.
    //STEPS:
    // 1.) Let header2 point to 1st Linked List. (current2 = head2) /
    // 2.) Let tempHead2 point to the next linked list. (tempHead2 = head2->next) /
    // 3.) Access the 1st contact number of head1 of 1st Contact AND COMPARE WITH 1st contact number of head1 of 2nd Contact.
    // 4.1) IF tempHead1->Contact number > 1 : THEN increment to NEXT contact number. (CHECK USING NULL)
    // 4.2) IF tempHead1->Contact number = 1 : THEN increment to NEXT contact name. (tempHead2->next)
    // .
    // .
    // .
    // 5.) IF NO duplicated Contact Number is found after reaching the last Contact Name.
    //     : THEN CHECK IF 1st Contact Name Have >1 contact number or not
    // 5.1) IF: 1st Contact Name Have >1 contact number : THEN Iterate to next contact number
    // 5.2) ELSE (IF: 1st Contact Name Have =1 contact number) THEN printf("NO duplicate contact").
    
    
    // Use current2 != NULL instead of current2 -> contactName != NULL because the second one will have an error if current2 does not exist.
    while(current2 != NULL) // While Contact Name != NULL //current2 -> contactName != NULL means nothing is insidde contactName.
    {
        struct contactNumNode *current1;
        current1 = current2->head1;
        while(current1 != NULL) // While Contact Number != NULL
        {
            
            struct contactNode *tempHead2;
            tempHead2 = current2->next; //tempHead2 must always be the next linked list of the present linked list.
            
            
            while(tempHead2 != NULL)
            { 
                struct contactNumNode *tempHead1; //next and head1 is  Pointer which stores "Address". | head1 is a pointer that keeps the address of first contact number linkedlist. |  Next is a pointer that keeps address of the next structure.
                tempHead1 = tempHead2->head1;
                while(tempHead1 != NULL)
                {
                    if(sortFront(current1-> contactNumber, tempHead1->contactNumber) == 0)
                    {
                        printf("%s and %s have a phone number in common\n", current2->contactName, tempHead2->contactName);
                    }
                    tempHead1 = tempHead1->next;
                }
                tempHead2 = tempHead2->next;
            }
            
            current1 = current1 -> next;
        }
        current2 = current2->next;
//      current1 = current2 -> head1;
    }
    
    
    
    
    
    
    
    
    
    
    
//    printf("Checkpoint 1\n");
//    while(tempHead2 != NULL)
//    {
//        if(sortFront(current1-> contactNumber, tempHead1) == 0)
//        {
//            printf("Checkpoint 2\n");
//            printf("%s and %s have a phone number in common", current2->contactName, tempHead2->contactName);
//        
//        }
//    
//        else
//        {
//            while(tempHead1->next != NULL)
//            {
//                printf("Checkpoint 3\n");
//                tempHead1 = tempHead1->next;
//            }
//        
//            while(tempHead1->next == NULL) //IF tempHead1->next == NULL -> Increment to next ContactName.
//            {
//                printf("Checkpoint 4\n");
//                tempHead2 = tempHead2-> next;
//                tempHead1 = tempHead2 -> head1; //ERROR: tempHead1 = tempHead2 -> tempHead1 because tempHead1 is the initial one. BUT the tempHead2 is being shifted and it is now the NEW tempHead1 that is inside new tempHead2.
//                
//            }
//        }
//    }
    
}


//char *strncpy(char *dest, const char *src, size_t n)
//{
//    
//}


int main()
{
    
//    printf(" %d\n", strlen(contactList));
   // first move data from contactList.h to a data structure
   convertInputToDataStructure();
   
//   for(int i=0; i<24; i++)
//   {
//       if(isalpha(contactList[i]) !=0)
//       {
//           printf("String Character\n");
//       }
//       
//       else if(isdigit(contactList[i] !=0))
//       {
//           printf("Number\n");
//       }
//   }  
//    printf("%d\n", isalpha());
   
   
   char notDone = 1;
   while (notDone) {
      printMenu();
      char userChoice[100];
      char* s = fgets(userChoice, sizeof(userChoice), stdin);
      if (!s)
      {
         printf("Wrong input\n");
         continue;
      }
      s = rtrim(s); /* eliminate trailing \n */
      //printf("selection = %s\n", s);
      int userSelection = atoi(s);

      switch (userSelection) {
         case 1: ListAllContacts(); break;
         case 2: PrintContact(); break;
         case 3: FindDuplicates(); break;
         case 4: DeleteContact(); break;
         case 5: notDone = 0; break;
         default: printf("Bad command...\n"); break;
         }
     
   }
//   int i=0;

//   printf("%d", ((head2->contactName[i+1])));
   
   // PUT ANY POST_RUN CODE HERE

   return 0;
}