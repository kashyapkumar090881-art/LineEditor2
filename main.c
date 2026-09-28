#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char document[MAX_LINES][MAX_LENGTH];
int lineCount = 0;


/* Function to insert a line */
void insertLine()
{
    int lineNumber;
    char text[MAX_LENGTH];

    if (lineCount >= MAX_LINES)
    {
        printf("Document is full.\n");
        return;
    }

    printf("Enter line number to insert (1-%d): ", lineCount + 1);
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > lineCount + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);

    text[strcspn(text, "\n")] = '\0';

    /* Shift lines downward */
    for (int i = lineCount; i >= lineNumber; i--)
    {
        strcpy(document[i], document[i - 1]);
    }

    /* Insert new line */
    strcpy(document[lineNumber - 1], text);

    lineCount++;

    printf("Line inserted successfully.\n");
}


/* Function to delete a line */
void deleteLine()
{
    int lineNumber;

    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("Enter line number to delete: ");
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    /* Shift lines upward */
    for (int i = lineNumber - 1; i < lineCount - 1; i++)
    {
        strcpy(document[i], document[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}


/* Function to display document */
void displayDocument()
{
    if (lineCount == 0)
    {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\n========== DOCUMENT ==========\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%d: %s\n", i + 1, document[i]);
    }

    printf("==============================\n");
}


/* Function to save document */
void saveFile()
{
    FILE *file;
    
    file = fopen("document.txt", "w");

    if (file == NULL)
    {
        printf("Unable to save file.\n");
        return;
    }

    for (int i = 0; i < lineCount; i++)
    {
        fprintf(file, "%s\n", document[i]);
    }

    fclose(file);

    printf("Document saved successfully.\n");
}


/* Function to load document */
void loadFile()
{
    FILE *file;

    file = fopen("document.txt", "r");

    if (file == NULL)
    {
        printf("No saved document found.\n");
        return;
    }

    lineCount = 0;

    while (lineCount < MAX_LINES &&
           fgets(document[lineCount], MAX_LENGTH, file) != NULL)
    {
        document[lineCount][strcspn(document[lineCount], "\n")] = '\0';
        lineCount++;
    }

    fclose(file);

    printf("Document loaded successfully.\n");
}


/* Main function */
int main()
{
    int choice;

    printf("====================================\n");
    printf("       SIMPLE LINE EDITOR\n");
    printf("====================================\n");

    while (1)
    {
        printf("\n");
        printf("1. Insert Line\n");
        printf("2. Delete Line\n");
        printf("3. Display Document\n");
        printf("4. Save Document\n");
        printf("5. Load Document\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                insertLine();
                break;

            case 2:
                deleteLine();
                break;

            case 3:
                displayDocument();
                break;

            case 4:
                saveFile();
                break;

            case 5:
                loadFile();
                break;

            case 6:
                printf("Exiting editor...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}