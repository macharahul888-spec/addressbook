#include <stdio.h>
#include "contact.h"
#include "file.h"
#include <stdlib.h>

int main() {
    int choice;
    AddressBook addressBook;//struct name & struct variable
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5: 
                     printf("----display the MENU----\n");
                     printf("1.Sort by name\n");
                     printf("2.Sort by phone\n");
                     printf("3.Sort by email id\n");
                     printf("4.Normal Method\n");

                     int sortChoice;
                     printf("Enter the option\n");
                     scanf("%d",&sortChoice);
                listContacts(&addressBook, sortChoice);
                 
                break;
            case 6:
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                exit(0);
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);
    
       return 0;
}
