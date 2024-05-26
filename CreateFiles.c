#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char fileName[256];
    char directory[256];
    char fileType[10];
    int numFiles;

    printf("\nEnter the directory path where files should be created: ");
    fgets(directory, sizeof(directory), stdin);
    directory[strcspn(directory, "\n")] = '\0';

    printf("\nEnter the base name of the file (e.g., myfile): ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName, "\n")] = '\0';

    printf("\nEnter the type of file (e.g., txt, csv): ");
    fgets(fileType, sizeof(fileType), stdin);
    fileType[strcspn(fileType, "\n")] = '\0';

    printf("\nEnter the number of files to create: ");
    scanf("%d", &numFiles);
    getchar();
    printf("\n");

    for (int i = 1; i <= numFiles; i++) 
    {
        char filePath[512];
        sprintf(filePath, "%s\\%s_%d.%s", directory, fileName, i, fileType);

        FILE *file = fopen(filePath, "w");
        if (file == NULL) 
        {
            perror("Error creating file");
            return 1;
        }

        printf("File created successfully at: %s\n", filePath);

        fclose(file);
    }

    return 0;
}
