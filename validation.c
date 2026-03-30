#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

int validation_name(const char *name) 
{
    for (int i = 0; name[i] != '\0'; i++) 
    {
        if (!isalpha(name[i]) && name[i] != ' ') 
        {
            return 0; // invalid
        }
    }
    return 1; // valid
}

int validation_phone_no(const char *num, AddressBook *addressBook)
{
    // Check if length is exactly 10
    if (strlen(num) != 10)
    {
        return 0; // Invalid length
    }

    // Check if all characters are digits
    for (int i = 0; num[i] != '\0'; i++)
    {
        if (!isdigit(num[i]))
        {
            return 0; // Contains non-digit
        }
    }

    // Check uniqueness in address book
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(num, addressBook->contacts[i].phone) == 0)
        {
            return 0; // Duplicate found
        }
    }

    return 1; // Valid and unique
}
int validation_email(const char *email, AddressBook *addressBook)
{
    int len = strlen(email);

    // Check for uppercase letters
    for (int i = 0; email[i] != '\0'; i++)
    {
        if (isupper((unsigned char)email[i]))
        {
            printf("Email contains uppercase letters. Only lowercase letters are allowed.\n");
            return 0;
        }
    }

    // Check if '@' is present and not at the start
    const char *at = strchr(email, '@');
    if (!at)
    {
        printf("Email must contain '@'\n");
        return 0;
    }
    if (at == email)
    {
        printf("Email must contain characters before '@'\n");
        return 0;
    }

    // Check if it ends with ".com"
    if (len < 5 || strcmp(email + len - 4, ".com") != 0)
    {
        const char *dotcom = strstr(email, ".com");
        if (dotcom)
            printf("'.com' is present but not at the end\n");
        else
            printf("Email is missing '.com'\n");
        return 0;
    }

    // Check if email is unique in address book
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(email, addressBook->contacts[i].email) == 0)
        {
            printf("Email already exists in the address book.\n");
            return 0;
        }
    }

    return 1; // Email is valid and unique
}

