#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 10
#define MAX_DESC_LEN 100
#define MAX_CODE_LEN 50

// Function to check if a description already exists in the list
int isDuplicateDescription(char descriptions[MAX_PRODUCTS][MAX_DESC_LEN], int count, const char* description) {
    for (int i = 0; i < count; i++) {
        if (strcmp(descriptions[i], description) == 0) {
            return 1; // Duplicate found
        }
    }
    return 0; // No duplicate
}

int main() {
    char productCodes[MAX_PRODUCTS][MAX_CODE_LEN];
    char productDescriptions[MAX_PRODUCTS][MAX_DESC_LEN];
    int productIDs[MAX_PRODUCTS];
    int productCount = 0;

    char searchKeyword[MAX_DESC_LEN];
    char combinedCodes[MAX_PRODUCTS * MAX_CODE_LEN] = "";

    printf("Enter the number of products (max %d): ", MAX_PRODUCTS);
    scanf("%d", &productCount);
    
    // Input product codes and descriptions
    for (int i = 0; i < productCount; i++) {
        char code[MAX_CODE_LEN];
        char description[MAX_DESC_LEN];
        
        printf("Enter product code (Code%d): ", i+1);
        scanf("%s", code);
        
        // Extracting ID from the product code (assuming ID is at the end of the string)
        int id = atoi(code + strlen(code) - 3); // Extract last 3 digits as ID
        productIDs[i] = id;
        
        printf("Enter product description (Desc%d): ", i+1);
        scanf(" %[^\n]", description); // To allow spaces in description
        
        // Check for duplicate descriptions
        if (isDuplicateDescription(productDescriptions, i, description)) {
            printf("Duplicate description! Enter a new description.\n");
            i--; // Decrement counter to re-enter the product
            continue;
        }
        
        strcpy(productCodes[i], code);
        strcpy(productDescriptions[i], description);
        
        // Concatenate all product codes into a single string
        if (i > 0) {
            strcat(combinedCodes, ", "); // Add a separator between codes
        }
        strcat(combinedCodes, code);
    }
    
    // Print out all products and their IDs
    printf("\nProduct Information:\n");
    for (int i = 0; i < productCount; i++) {
        printf("Product Code: %s, Product ID: %d, Description: %s\n", 
               productCodes[i], productIDs[i], productDescriptions[i]);
    }
    
    // Join all product codes into one string and print it
    printf("\nAll Product Codes: %s\n", combinedCodes);
    
    // Search for a keyword in the descriptions
    printf("\nEnter a keyword to search for in product descriptions: ");
    scanf(" %[^\n]", searchKeyword);
    
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strstr(productDescriptions[i], searchKeyword) != NULL) {
            printf("Keyword '%s' found in description of product code: %s\n", 
                   searchKeyword, productCodes[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Keyword '%s' not found in any product descriptions.\n", searchKeyword);
    }
    
    // Reverse and check for palindrome
    printf("\nChecking for palindrome product codes:\n");
    for (int i = 0; i < productCount; i++) {
        char reversedCode[MAX_CODE_LEN];
        strcpy(reversedCode, productCodes[i]);
        strrev(reversedCode); // Reverse the product code
        
        if (strcmp(productCodes[i], reversedCode) == 0) {
            printf("Product code '%s' is a palindrome.\n", productCodes[i]);
        } else {
            printf("Product code '%s' is not a palindrome.\n", productCodes[i]);
        }
    }

    return 0;
}
