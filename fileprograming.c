#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILENAME_LEN 100
#define MAX_BUFFER_SIZE 1024

int countWords(FILE *file);
void findAndCountOccurrences();
void readFromFile();
void writeToFile();
int countWordsInFile();
void countCharsInFile();
int countCharacters(FILE *file);
int countVowels(FILE *file);
void openBrowserToResources();
void readCreatorInfoFromFile();
int countConsonants(FILE *file);
void countConsonantsInFile();
void copyFile(const char *sourceFilename, const char *destinationFilename);
/**
 * Counts the number of words in a file.
 * 
 * @param file The file to count words from.
 * @return The number of words in the file.
 */
int countWords(FILE *file) {
    int count = 0;
    int inWord = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
    }

    return count;
}

/**
 * Finds and counts the occurrences of a specific character or word in a file.
 * 
 * @param file The file to search in.
 */
void findAndCountOccurrences()
{
    char searchStr[MAX_BUFFER_SIZE];
    char filename[MAX_FILENAME_LEN];
    FILE *file;

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Enter the character or word to find: ");
    scanf(" %s", searchStr);

    int searchLen = strlen(searchStr);
    int occurrence = 0;

    char buffer[MAX_BUFFER_SIZE];

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL)
    {
        char *word = strtok(buffer, " ");
        while (word != NULL)
        {
            if (strcmp(word, searchStr) == 0)
            {
                occurrence++;
            }
            word = strtok(NULL, " ");
        }
    }

    printf("Occurrences of '%s': %d\n", searchStr, occurrence);

    fclose(file);
}

/**
 * Reads and prints the contents of a file.
 */
void readFromFile() {
    char filename[MAX_FILENAME_LEN];
    printf("Enter the filename to read: ");
    scanf("%99s", filename);  // Limit input to 99 characters

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file '%s'. Make sure it exists.\n", filename);
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

/**
 * Writes user input to a file.
 */
void writeToFile() {
    char filename[MAX_FILENAME_LEN];
    printf("Enter the filename to write: ");
    scanf("%99s", filename);

    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }

    printf("Enter the text to write (Ctrl+D to end):\n");
    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, MAX_BUFFER_SIZE, stdin) != NULL) {
        fputs(buffer, file);
    }

    fclose(file);
    printf("File written successfully.\n");
}

/**
 * Counts the number of words in a file.
 * 
 * @return The number of words in the file.
 */
int countWordsInFile() {
    char filename[MAX_FILENAME_LEN];
    printf("Enter the filename to count words: ");
    scanf("%99s", filename);  // Limit input to 99 characters

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file '%s'. Make sure it exists.\n", filename);
        return -1;
    }

    int wordCount = countWords(file);
    printf("Number of words in the file: %d\n", wordCount);

    fclose(file);
    return wordCount;
}

/**
 * Counts the number of characters in a file.
 */
void countCharsInFile() {
    char filename[MAX_FILENAME_LEN];
    printf("Enter the filename to count characters: ");
    scanf("%99s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file '%s'. Make sure it exists.\n", filename);
        return;
    }

    int charCount = countCharacters(file);
    printf("Number of characters in the file: %d\n", charCount);

    fclose(file);
}

/**
 * Counts the number of characters in a file.
 * 
 * @param file The file to count characters from.
 * @return The number of characters in the file.
 */
int countCharacters(FILE *file) {
    int count = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        count++;
    }

    return count;
}

/**
 * Counts the number of vowels in a file.
 * 
 * @param file The file to count vowels from.
 * @return The number of vowels in the file.
 */
int countVowels(FILE *file) {
    int count = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count++;
        }
    }

    return count;
}

/**
 * Counts the number of vowels in a file.
 */
void countVowelsInFile() {
    char filename[MAX_FILENAME_LEN];
    printf("Enter the filename to count vowels: ");
    scanf("%99s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file '%s'. Make sure it exists.\n", filename);
        return;
    }

    int vowelCount = countVowels(file);
    printf("Number of vowels in the file: %d\n", vowelCount);

    fclose(file);
}


int countConsonants(FILE *file) {
    int count = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' &&
                ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U') {
                count++;
            }
        }
    }

    return count;
}

void countConsonantsInFile() {
    char filename[MAX_FILENAME_LEN];
    printf("Enter the filename to count consonants: ");
    scanf("%99s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file '%s'. Make sure it exists.\n", filename);
        return;
    }

    int consonantCount = countConsonants(file);
    printf("Number of consonants in the file: %d\n", consonantCount);

    fclose(file);
}

/**
 * Opens the browser to multiple resources.
 */
void openBrowserToResources() {
    printf("Storing resources in a file...\n");

    // Open the file for writing
    FILE *file = fopen("file_programming_resources.txt", "w");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }

    // Write the resource information to the file
    fprintf(file, "1. Open Source: https://opensource.com/article/19/12/programming-resources\n");
    fprintf(file, "2. MIT CommKit: https://mitcommlab.mit.edu/broad/commkit/file-structure/\n");
    fprintf(file, "3. Codecademy Communities: https://www.codecademy.com/resources/blog/programming-resources/\n");
    fprintf(file, "4. CS Dojo YouTube Channel: https://www.youtube.com/c/CSDojo\n");
    fprintf(file, "5. Codecademy: https://www.codecademy.com/\n");

    // Close the file
    fclose(file);

    printf("Resources stored in the file 'file_programming_resources.txt'.\n");
}

void readCreatorInfoFromFile() {
    printf("Reading creator's info from file...\n");

    // Open the file for reading
    FILE *file = fopen("creator_info.txt", "r");
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return;
    }

    // Read the creator's info from the file
    char name[100];
    char email[100];
    char github[100];
    char linkedin[100];

    fscanf(file, "Name: %[^\n]\n", name);
    fscanf(file, "E-mail: %[^\n]\n", email);
    fscanf(file, "Github: %[^\n]\n", github);
    fscanf(file, "LinkedIn: %[^\n]\n", linkedin);

    // Close the file
    fclose(file);

    // Print the creator's info
    printf("Creator's Info:\n");
    printf("Name: %s\n", name);
    printf("E-mail: %s\n", email);
    printf("Github: %s\n", github);
    printf("LinkedIn: %s\n", linkedin);
}


void copyFile(const char *sourceFilename, const char *destinationFilename) {
    FILE *sourceFile = fopen(sourceFilename, "r");
    if (sourceFile == NULL) {
        printf("Error opening the source file '%s'. Make sure it exists.\n", sourceFilename);
        return;
    }

    FILE *destinationFile = fopen(destinationFilename, "a");
    if (destinationFile == NULL) {
        printf("Error opening the destination file '%s'.\n", destinationFilename);
        fclose(sourceFile);
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    printf("Contents of '%s' copied and appended to '%s' successfully.\n", sourceFilename, destinationFilename);
}

void copyFileContents() {
    char sourceFilename[MAX_FILENAME_LEN];
    printf("Enter the source filename: ");
    scanf("%99s", sourceFilename);

    char destinationFilename[MAX_FILENAME_LEN];
    printf("Enter the destination filename: ");
    scanf("%99s", destinationFilename);

    copyFile(sourceFilename, destinationFilename);
}



int main() {
    int choice;
    int scanfResult;

    do {
        printf("\nFile Programming Menu\n");
        printf("1. Read from a file\n");
        printf("2. Write to a file\n");
        printf("3. Count words in a file\n");
        printf("4. Count characters in a file\n");
        printf("5. Count vowels in a file\n");
        printf("6. Count consonants in a file\n");
        printf("7. Find and count occurrences in a file\n");
        printf("8. Copy file contents\n");
        printf("9. Open browser to multiple resources\n");
        printf("10. Exit\n");
        printf("11. Wanna know about me?\n");
        printf("Enter your choice: ");

        scanfResult = scanf("%d", &choice);

        if (scanfResult == EOF) {
            break;
        }

        switch (choice) {
            case 1:
                readFromFile();
                break;
            case 2:
                writeToFile();
                break;
            case 3:
                countWordsInFile();
                break;
            case 4:
                countCharsInFile();
                break;
            case 5:
                countVowelsInFile();
                break;
            case 6:
                countConsonantsInFile();
                break;
            case 7:
                findAndCountOccurrences();
                break;
            case 8:
                copyFileContents();
                break;
            case 9:
                openBrowserToResources();
                break;
            case 10:
                printf("Exiting...\n");
                exit(0);
                break;
            case 11:
                readCreatorInfoFromFile();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 8);

    return 0;
}


