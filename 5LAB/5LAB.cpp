#include <iostream>
#include <locale.h>
//#include "output.h"
#pragma warning(disable : 4996)
#define FILE_NAME_LENGHT 15

typedef struct {
    char town[20];
    int day;
    float temp;
    float wet;
}data;

int sizeCount(FILE* file)
{
    int counter = 1;
    while (!feof(file))
    {
        if (fgetc(file) == '\n')
            counter++;
    }
    fseek(file, 0, SEEK_SET);
    return counter;
}

data* fileInput(char* fileName, int* fileSize)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("File doesn't exist! ");
        return NULL;
    }
    *fileSize = sizeCount(file);
    data* out = (data*)calloc(*fileSize, sizeof(data));
    //data* out = (data*)calloc(301, 32);
    for (data* i = out; i < out+sizeof(data)*(*fileSize); i+= sizeof(data))
    {
        if (fscanf(file, "%s %i %f %f", 
            &(i->town),
            &(i->day),
            &(i->temp),
            &(i->wet)) != 4)
        {
            printf("Invalid file format %i \n", fscanf(file, "%s %i %f %f",///
                &(i->town),
                &(i->day),
                &(i->temp),
                &(i->wet)));
            free(out);
            fclose(file);
            return NULL;
        }
    }
    printf("Reading file OK\n");
    fclose(file);
    return out;
}

void print(data* arr, int size)
{
    for (data* i = arr; i < arr + sizeof(data) * size; i += sizeof(data))
        printf("%10s %2i %2.2f %2.2f\n",
            (i->town),
            (i->day),
            (i->temp),
            (i->wet));
        
}

int main()
{
     setlocale(LC_ALL, "Russian");
    char* fileName = (char*)calloc(FILE_NAME_LENGHT, sizeof(char));
    int* size = (int*)calloc(1,sizeof(int));
    printf("Enter file name: ");
    scanf("%s", fileName);
    //getRandFile(fileName);
    data* mass = fileInput(fileName, size);
    if (mass == NULL)
        while (mass == NULL)
        {
            printf("Please try again\n");
            scanf("%s", fileName);
            mass = fileInput(fileName, size);
        }
    print(mass, *size);
}
