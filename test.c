#include <stdio.h>

#define MAXROWS 12
#define MAXCOLS 21

// Function prototypes
void LoadImage(int image[MAXROWS][MAXCOLS]);
void DisplayImage(int image[][MAXCOLS], int rows, int cols);

// Global variable
int image[MAXROWS][MAXCOLS]; // Image data

int main() {
    int choice;
    int ImageWidth = 0, ImageHeight = 0; 

    do {
        printf("\n***ERINSTAGRAM***\n");
        printf("1: Load image\n");
        printf("2: Display image\n");
        printf("0: Exit\n");
        printf("Choose from one of the options above: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                LoadImage(image);
                ImageWidth = MAXCOLS;
                ImageHeight = MAXROWS;
                break;
            case 2:
                DisplayImage(image, ImageHeight, ImageWidth);
                break;
            case 0:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 0);

    return 0;

}
void LoadImage(int image[MAXROWS][MAXCOLS]) {
    char filename[100];
    printf("What is the name of the image file? ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not find an image with that filename.\n");
        return;
    }

    char temp;
    for (int i = 0; i < MAXROWS; i++) {
        for (int j = 0; j < MAXCOLS; j++) {
            if (fscanf(file, " %c", &temp) != 1) {
                printf("Error reading image data.\n");
                fclose(file);
                return;
            }
            image[i][j] = temp;
        }
        fscanf(file, "\n"); // Consume the newline character
    }

    fclose(file);
    printf("Image successfully loaded!\n");
}
void DisplayImage(int image[][MAXCOLS], int rows, int cols) {
    
    char mapping[] = {' ','.','o','O','0'};

   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value = image[i][j] - '0'; 
            printf("%c", mapping[value]);
        }
        printf("\n");
    }
}

