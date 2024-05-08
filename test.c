// 1106-Team1: Ashton Hayes & Yadira Ayala

// Final Group Project

// Goal:
// 1. Familiarize us with coding collaboratively
// 2. Familiarize us with 2D Arrays
// 3. Provide us with continued practice using everything!

// Due Date: 5/7/2024

#include <stdio.h>

#define MAXROWS 50
#define MAXCOLS 50

// Function prototypes
void LoadImage(int image[MAXROWS][MAXCOLS]);
void DisplayImage(int image[][MAXCOLS], int rows, int cols);
void EditImage(int image[][MAXCOLS], int rows, int cols, int ImageHeight, int ImageWidth);

// MENU 2 Function prototypes
void CropImage(int *rows, int *cols, int image[][MAXCOLS]);

void DimImage(int image[][MAXCOLS], int rows, int cols, int adjustment);
void BrightImage(int image[][MAXCOLS], int rows, int cols, int adjustment);
void RotateImage();
void SaveImage();

// Global variable
int image[MAXROWS][MAXCOLS]; // Image data

int main() {
    int choice;
    int ImageWidth = 0, ImageHeight = 0; 

    do {
        printf("\n***ERINSTAGRAM***\n");
        printf("1: Load image\n");
        printf("2: Display image\n");
        printf("3: Edit image\n");
        printf("0: Exit\n");
        printf("\nChoose from one of the options above: ");
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
            case 3:
            	EditImage(image, ImageHeight, ImageWidth, MAXROWS, MAXCOLS);
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
void EditImage(int image[][MAXCOLS], int rows, int cols, int ImageHeight, int ImageWidth);
     int EditChoice;

// MENU 2
 do{
        printf("\n***EDITING***\n");
        printf("1: Crop image\n");
        printf("2: Dim image\n");
        printf("3: Brighten image\n");
        printf("4: Rotate image\n");
        printf("0: Return to main menu\n");
        printf("\nChoose from one of the options above: ");
        scanf("%d", &EditChoice);
        
         switch (EditChoice) {
            case 1:
                CropImage(ImageHeight, ImageWidth, image);
                break;
            case 2:
                DimImage(image, rows, cols, -1);
                break;
            case 3:
                BrightImage(image, rows, cols, +1);
                break;
            case 4:
                RotateImage();
                break;
            case 0:
                printf("Would you like to save the file? (y/n)\n");
                return;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (EditChoice != 0);
 printf("Exiting EditImage function.\n"); 
}
   
}

void CropImage(int *rows, int *cols, int image[][MAXCOLS]) {
    // Display the image
    printf("\n");
    DisplayImage(image, *rows, *cols);
    printf("\n");

    // Get user input for new dimensions
    int new_cols, new_rows;
    printf("The image you want to crop is %d x %d.\n", *rows, *cols);
    printf("The row and column values start in the upper lefthand corner.\n\n");
    printf("Which column do you want to be the new left side? ");
    scanf("%d", &new_cols);
    printf("Which column do you want to be the new right side? ");
    scanf("%d", &(*cols));  // Update the number of columns
    printf("Which row do you want to be the new top? ");
    scanf("%d", &new_rows);
    printf("Which row do you want to be the new bottom? ");
    scanf("%d", &(*rows));  // Update the number of rows

    // Crop the image
    int cropped_image[MAXROWS][MAXCOLS];
    for (int i = new_rows; i < *rows; i++) {
        for (int j = new_cols; j < *cols; j++) {
            cropped_image[i - new_rows][j - new_cols] = image[i][j];
        }
    }

    // Update the original image with the cropped image
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            image[i][j] = cropped_image[i][j];
        }
    }

    
    *rows -= new_rows;
    *cols -= new_cols;

 
    printf("\nCropped image:\n");
    DisplayImage(image, *rows, *cols);
}
    
    

void DimImage(int image[][MAXCOLS], int rows, int cols, int adjustment) {
    char mapping[] = {' ', '.', 'o', 'O', ' '};

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            
            int original_pixel = image[i][j] - '0';

           
            int dimmed_pixel = original_pixel + adjustment;

            
            if (dimmed_pixel < 0) {
                dimmed_pixel = 0;
            } else if (dimmed_pixel > 4) {
                dimmed_pixel = 4;
            }

            
            printf("%c", mapping[dimmed_pixel]);
        }
        printf("\n"); 
    }
}

void BrightImage(int image[][MAXCOLS], int rows, int cols, int adjustment) {
    char mapping[] = {' ', '.', 'o', 'O', '0'};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int original_pixel = image[i][j] - '0';
            int brightened_pixel = original_pixel + adjustment;

            if (brightened_pixel < 0) {
                brightened_pixel = 0;
            } else if (brightened_pixel > 4) {
                brightened_pixel = 4;
            }

            printf("%c", mapping[brightened_pixel]);
        }
        printf("\n");
    }
}
   


void RotateImage(){
}

void SaveImage() {
}

