// 1106-Team1: Ashton Hayes & Yadira Ayala

// Final Group Project

// Goal:
// 1. Familiarize us with coding collaboratively
// 2. Familiarize us with 2D Arrays
// 3. Provide us with continued practice using everything!

// Due Date: 5/7/2024

#include <stdio.h>

// MENU 1 Function prototypes
void LoadImage();
void DisplayImage();
void EditImage();

// MENU 2 Function prototypes
void CropImage();
void DimImage();
void BrightImage();
void RotateImage();
void SaveImage();

// Global variables
int image[500][500]; // Ms.Erin constraint: suggested max image size of [500] x [500] pixels (2D Array)
int ImageWidth, ImageHeight;

// Main Function
int main() {

    int choice;

// MENU 1 with options

    do {
        printf("\n***ERINSTAGRAM***\n");
        printf("1: Load image\n");
        printf("2: Display image\n");
        printf("3: Edit the current image\n");
        printf("0: Exit\n");
        printf("Choose from one of the options above: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                LoadImage();
                break;
            case 2:
                DisplayImage();
                break;
            case 3:
                EditImage();
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

// MENU 1 - choice '1': Load an image
void LoadImage() {

    char filename[100];
    printf("What is the name of the image file? ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not find an image with that filename.\n");
        return;
    }

    fscanf(file, "%d %d", &ImageWidth, &ImageHeight);

    for (int i = 0; i < ImageHeight; i++) {
    
        for (int j = 0; j < ImageWidth; j++) {
        
            fscanf(file, "%d", &image[i][j]);
        }
    }

    fclose(file);
    
}

// MENU 1 - choice '2': Display an image
void DisplayImage() {

    for (int i = 0; i < ImageHeight; i++) {
    
        for (int j = 0; j < ImageWidth; j++) {
        
            printf("%c", image[i][j] >= 128 ? '#' : ' ');
        }
        
        printf("\n");
        
    }
}

// MENU 1 - choice '3': Edit the image (Crop, Brighten, Dim, or Rotate)
void EditImage() {

 int EditChoice;

// MENU 2
        printf("\n***EDITING***\n");
        printf("1: Crop image\n");
        printf("2: Dim image\n");
        printf("3: Brighten image\n");
        printf("4: Rotate image\n");
        printf("0: Return to main menu\n");
        printf("Choose from one of the options above: ");
        
         switch (EditChoice) {
            case 1:
                CropImage();
                break;
            case 2:
                BrightImage();
                break;
            case 3:
                DimImage();
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

    return 0;
	}
   
}

void CropImage() {
     // case 1
    // Implement cropping logic
}

void DimImage() {
     // case 2
    // Implement dimming logic
}

void BrightImage() {
     // case 3
    // Implement dimming logic
}

void RotateImage() {
     // case 4
    // Implement rotating logic
}

void SaveImage() {
    // case 0
    // Implement saving logic
}

