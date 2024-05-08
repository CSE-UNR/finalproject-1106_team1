// 1106-Team1: Ashton Hayes & Yadira Ayala

// Final Group Project

// Goal:
// 1. Familiarize us with coding collaboratively
// 2. Familiarize us with 2D Arrays
// 3. Provide us with continued practice using everything!

// Due Date: 5/7/2024

#include <stdio.h>

#define MAXROWS 12
#define MAXCOLS 21

// Function prototypes
void LoadImage(int image[][MAXCOLS]);
void DisplayImage(int rows, int cols, int image[][MAXCOLS]);
void EditImage(int rows, int cols, int image[][MAXCOLS]);


// MENU 2 Function prototypes
void CropImage();
void DimImage(int rows, int cols, int adjust, int image[][MAXCOLS]);
void BrightImage(int rows, int cols, int adjust, int image[][MAXCOLS]);
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
        printf("Choose from one of the options above: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                LoadImage(image);
                ImageWidth = MAXCOLS;
                ImageHeight = MAXROWS;
                break;
            case 2:
                DisplayImage(ImageHeight, ImageWidth, image);
                break;
            case 3:
            	EditImage(ImageHeight, ImageWidth, image);
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

    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Could not find an image with that filename.\n");
        return;
    }

    char temp = 0;
    int row = 0, col = 0;
    while (fscanf(fptr, "%c", &temp) == 1 && row < MAXROWS) {
        if (temp == '\n') {
            row++;
            col = 0;
        } else if (temp != ' ') { 
            if (col < MAXCOLS) {
                image[row][col] = temp - '0'; 
                col++;
            }
        }
    }

    fclose(fptr);
    printf("Image successfully loaded!\n");
}

void DisplayImage(int rows, int cols, int image[][MAXCOLS]) {
    if (rows == 0 || cols == 0) {
        printf("Sorry, no image to display\n");
        return;
    }

    char pixels[] = {' ', '.', 'o', 'O', '0'};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value = image[i][j]; // Original pixel value
            printf("%c", pixels[value]);
        }
        printf("\n");
    }
}


void EditImage(int rows, int cols, int image[][MAXCOLS]) {
	if (rows == 0 || cols == 0) {
        printf("Sorry, no image to edit\n");
        return;
    }

     int EditChoice;

// MENU 2
 do{
        printf("\n***EDITING***\n");
        printf("1: Crop image\n");
        printf("2: Dim image\n");
        printf("3: Brighten image\n");
        printf("4: Rotate image\n");
        printf("0: Return to main menu\n");
        printf("Choose from one of the options above: ");
        scanf("%d", &EditChoice);
        
         switch (EditChoice) {
            case 1:
                CropImage();
                break;
            case 2:
                DimImage(rows, cols, -1, image);
                break;
            case 3:
                BrightImage(rows, cols, +1, image);
                break;
            case 4:
                RotateImage();
                break;
            case 0:
                
                return;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (EditChoice != 0);
 printf("Exiting EditImage function.\n"); // Print statement indicating the function exit
}
   


void CropImage() {
    }
    

void DimImage(int rows, int cols, int adjust, int image[][MAXCOLS]) {
    char pixels[] = {' ', '.', 'o', 'O', ' '};

   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int og_pixel = image[i][j];
            int dimmed_pixel = og_pixel + adjust;

            if (dimmed_pixel < 0) {
                dimmed_pixel = 0;
            } else if (dimmed_pixel > 4) {
                dimmed_pixel = 4;
            }

            
            printf("%c", pixels[dimmed_pixel]);
        }
        printf("\n"); 
    }
}

void BrightImage(int rows, int cols, int adjust, int image[][MAXCOLS]) {
    char pixels[] = {' ', '.', 'o', 'O', '0'};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int original_pixel = image[i][j];
            int brightened_pixel = original_pixel + adjust;

            if (brightened_pixel < 0) {
                brightened_pixel = 0;
            } else if (brightened_pixel > 4) {
                brightened_pixel = 4;
            }

            printf("%c", pixels[brightened_pixel]);
        }
        printf("\n");
    }
}


void RotateImage(){
}

void SaveImage() {

}

