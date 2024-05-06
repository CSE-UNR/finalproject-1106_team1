#include <stdio.h>

#define MAXROWS 12
#define MAXCOLS 21

// Function prototypes
void LoadImage(int image[MAXROWS][MAXCOLS]);
void DisplayImage(int image[][MAXCOLS], int rows, int cols);
void EditImage(int image[][MAXCOLS], int rows, int cols);

// MENU 2 Function prototypes
void CropImage();
void DimImage(int image[][MAXCOLS], int rows, int cols, int adjustment);
void BrightImage();
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
                DisplayImage(image, ImageHeight, ImageWidth);
                break;
            case 3:
            	EditImage(image, ImageHeight, ImageWidth);
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
void EditImage(int image[][MAXCOLS], int rows, int cols) {
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
                DimImage(image, rows, cols, -1);
                break;
            case 3:
                BrightImage();
                break;
            case 4:
                RotateImage();
                break;
            case 0:
                printf("\nWould you like to save the file? (y/n)\n");
                return;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (EditChoice != 0);
 printf("Exiting EditImage function.\n"); 
}
   


void CropImage() {
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

void BrightImage() {
   
}

void RotateImage(){
}
