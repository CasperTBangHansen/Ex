/*
    Input xPos/yPos: Takes an (x,y)-coordinate as starting position
    Input *here: Struct value that takes the initial coordinates
    Input *there: Struct value that updates with every move the player makes
*/
#include "ControlSystem.h"

#define ESC 0x1B
#define SPACE 0x20


// Function from the assignments that lets us jump to whereever on the prompt
void gotoxy(uint16_t x, uint8_t y){
        printf("%c[%u;%u%c",ESC,y,x,0x48);
}

//Clears terminal
void clearscr() {
        printf("%c[%d%c",ESC,2,0x4A);
}


// Initializing the position
void InitPosition(uint16_t x, uint8_t y, struct playerPos *here){
    here->xPosition = x; // Initializes the x-coordinate
    here->yPosition = y; // Initializes the y-coordinate
}

void clreol() {
        printf("%c[%c",ESC,0x4B);
}


// Main function that moves the player around
void userInput(struct playerPos *there){ // We want to remove that this input is necessary (Only possible with global variable?)<------------------------------------------
char buttonPress; // Adds a variable to use for registering the pressed button
uint16_t xPos = (*there).xPosition; // Updates the value of the x-coordinate
uint8_t yPos = (*there).yPosition; // Updates the value of the y-coordinate
buttonPress = uart_get_char(); // Defining the variable as the button the player has pressed
if (buttonPress == '\0'){ // Necessary to make the function not accept null values. Makes it run faster/smoother
    return buttonPress;
}
if(buttonPress != '\0' && buttonPress == 'w' ){ // If and only if the pressed button is "w", the players moves up
    if (yPos > 0){ // Prevents the player from going off screen
        gotoxy(xPos,yPos);
        printf(" ");
        yPos--;
        gotoxy(xPos,yPos);
        printf("O");
    }
}
if(buttonPress != '\0' && buttonPress == 'a'){ // If and only if the pressed button is "a", the players moves left
    if (xPos > 0){ // Prevents the player from going off screen
        gotoxy(xPos,yPos);
        printf(" ");
        xPos--;
        gotoxy(xPos,yPos);
        printf("O");
    }
}
if(buttonPress != '\0' && buttonPress == 's'){ // If and only if the pressed button is "s", the players moves down
    if (yPos < 66){ // Prevents the player from going off screen
        gotoxy(xPos,yPos);
        printf(" ");
        yPos++;
        gotoxy(xPos,yPos);
        printf("O");

    }
}
if(buttonPress != '\0' && buttonPress == 'd'){ // If and only if the pressed button is "d", the players moves right
    if (yPos < 271){ // Prevents the player from going off screen
        gotoxy(xPos,yPos);
        printf(" ");
        xPos++;
        gotoxy(xPos,yPos);
        printf("O");
    }
}
if(buttonPress !='\0' && buttonPress == 0x20){ // If and only if the space bar is pressed, "YEEEEEEET!" is printed. This is going to be assigned as the shoot button
    gotoxy(xPos,yPos);
    printf("YEEEEEEET!");
    gotoxy(xPos,yPos);
}
there->xPosition = xPos;
there->yPosition = yPos;
uart_clear();
}

