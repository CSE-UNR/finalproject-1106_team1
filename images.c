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
void LoadImage(int image[MAXROWS][MAXCOLS]);
void DisplayImage(int image[][MAXCOLS], int* rows, int* cols);
void EditImage(int image[][MAXCOLS], int rows, int cols);

// MENU 2 Function prototypes
void CropImage(int image[][MAXCOLS], int rows, int cols);
void DimImage(int image[][MAXCOLS], int rows, int cols, int adjustment);
void BrightImage(int image[][MAXCOLS], int rows, int cols, int adjustment);
void RotateImage(int image[][MAXCOLS], int rows, int cols);

int main() {
    int choice;
    int ImageWidth = 0, ImageHeight = 0; 
    int image[MAXROWS][MAXCOLS];

    do {
        printf("***ERINSTAGRAM***\n");
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
                printf("\n");
                break;
            case 2:
                DisplayImage(image, &ImageHeight, &ImageWidth);
                printf("\n");
                break;
            case 3:
            	EditImage(image, ImageHeight, ImageWidth);
            	printf("\n");
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
        
        fscanf(file, "\n"); 
    }

    fclose(file);
    printf("\nImage successfully loaded!\n");
}

void DisplayImage(int image[][MAXCOLS], int* rows, int* cols) {
    
    char mapping[] = {' ','.','o','O','0'};

   
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
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
        printf("\nChoose from one of the options above: ");
        scanf("%d", &EditChoice);
        
         switch (EditChoice) {
            case 1:
                CropImage(image, rows, cols);
                break;
            case 2:
                DimImage(image, rows, cols, -1);
                break;
            case 3:
                BrightImage(image, rows, cols, 1);
                break;
            case 4:
                RotateImage(image, rows, cols);
                break;
            case 0:
                return;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (EditChoice != 0);
    
 printf("Exiting EditImage function.\n"); 
 
}
   


void CropImage(int image[][MAXCOLS], int rows, int cols){
	int userCol1, userCol2, userRow1, userRow2;
	char tempArray[rows][cols];
    char mapping[] = {' ','.','o','O','0'};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value = image[i][j] - '0'; 
            image[1][1] = '1';
            image[2][1] = '1';
            image[1][21] = '1';
            image[1][20] = '2';
            image[12][1] = '1';
            image[12][2] = '2';
            printf("%c", mapping[value]);
        }
        printf("\n");
    }
	printf("The image you want to crop is 12 x 21.\n");
	printf("The row and column values start in the upper lefthand corner.\n");

	printf("Which column do you want to be the new left side?");
	scanf("%d", &userCol1);
	  for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           image[i][j] = tempArray[i][userCol1];
        }
    }
	printf("Which column do you want to be the right left side?");
	scanf("%d", &userCol2); 

	if(userCol2 == userCol1){
		printf("Invalid column value. Choose a value between 1 and 11:");
		scanf("%d", &userCol2);
	}
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           image[i][j] = tempArray[i][userCol2];
        }
    }
	printf("Which row do you want to be the new top?");
	scanf("%d", &userRow1);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           image[i][j] = tempArray[userRow1][j];
        }
    }
	printf("Which row do you want to be the new bottom?");
	scanf("%d", &userRow2);
  
	if(userRow2 == userRow1){
		printf("Invalid row value. Choose a value between 1 and 20:");
		scanf("%d", &userRow2);
	}
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value = image[i][j] - '0'; 
            printf("%c", mapping[value]);
        }
        printf("\n");
    }
    

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
    char choice;
    printf("Would you like to save the file? (y/n) ");
    scanf(" %c", &choice);
    
    if(choice == 'y') {
    
    	char filename[100];
    	printf("What do you want to name the image file? (include the extension) ");
   	 scanf("%s", filename);

    	FILE *file = fopen(filename, "w");
   	 if (file == NULL) {
        	printf("Could not find an image with that filename.\n");
        	return;
        	
    	} else {
    		 for (int i = 0; i < rows; i++) {
        	    for (int j = 0; j < cols; j++) {
           	 	 int original_pixel = image[i][j] - '0';
			 int dimmed_pixel = original_pixel + adjustment;
			 if (dimmed_pixel < 0) {
                	 dimmed_pixel = 0;
            		} else if (dimmed_pixel > 4) {
                	dimmed_pixel = 4;
            			}
            			fprintf(file, "%c", mapping[dimmed_pixel]);
        		}
        		fprintf(file, "\n");
   	       }	
    	
    		printf("Image successfully loaded!\n");
    		fclose(file);
    	}
    }
    	
    if(choice == 'n') {
    
     return;
     
    }
}



void BrightImage(int image[][MAXCOLS], int rows, int cols, int adjustment){

    char mapping[] = {' ', '.', 'o', 'O', '0'};
    
 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int original_pixel = image[i][j] - '0';
            int bright_pixel = original_pixel + adjustment;

            if (bright_pixel < 0) { 
                bright_pixel = 0; 
            } else if (bright_pixel > 4 ) {	
               	bright_pixel = 4;
               
            }
		
            printf("%c", mapping[bright_pixel]);
        }
        printf("\n"); 
        
    }
    char choice;
    printf("Would you like to save the file? (y/n) ");
    scanf(" %c", &choice);
    
    if(choice == 'y') {
    
    	char filename[100];
    	printf("What do you want to name the image file? (include the extension) ");
   	 scanf("%s", filename);

    	FILE *file = fopen(filename, "w");
   	 if (file == NULL) {
        	printf("Could not find an image with that filename.\n");
        	return;
        	
    	} else {
    	
    		
    		for (int i = 0; i < rows; i++) {
        		for (int j = 0; j < cols; j++) {
            		     int original_pixel = image[i][j] - '0';
           		     int bright_pixel = original_pixel + adjustment;
            			if (bright_pixel < 0) {
                		bright_pixel = 0;
                
            			} else if (bright_pixel > 4 ) {
            			bright_pixel = 4;
               
            			}

            			fprintf(file, "%c", mapping[bright_pixel]);
        		}
        		fprintf(file, "\n"); 
    		}
    		printf("Image successfully loaded!\n");
    		fclose(file);
    	}
    }
    	
    if(choice == 'n') {
    return;
     
    }
}

   


void RotateImage(int image[][MAXCOLS], int rows, int cols){
	char matrix[cols][rows];
	char mapping[] = {' ','.','o','O','0'};

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            int value = image[j][i] - '0'; 
            matrix[i][j]=mapping[value];
        }
    }
	
	for(int r=0; r<cols; r++){
		for(int c=rows-1; c>=0; c--){
			printf("%c", matrix[r][c]);
		}
		printf("\n");
	}
    char choice;
    printf("Would you like to save the file? (y/n) ");
    scanf(" %c", &choice);
    
    if(choice == 'y') {
    
    	char filename[100];
    	printf("What do you want to name the image file? (include the extension) ");
   	 scanf("%s", filename);

    	FILE *file = fopen(filename, "w");
   	 if (file == NULL) {
        	printf("Could not find an image with that filename.\n");
        	return;
        	
    	} else {
    	
    		 
            for(int r=0; r<cols; r++){
                for(int c=rows-1; c>=0; c--){
                    fprintf(file, "%c", matrix[r][c]);
                }
                printf("\n");
            }
    		printf("Image successfully loaded!\n");
    		fclose(file);
    	}
    }
    	
    if(choice == 'n') {
    
     return;
     
    }
}


