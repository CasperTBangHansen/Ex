/*
    Input xPos/yPos: Takes an (x,y)-coordinate as starting position
    Input *here: Struct value that takes the initial coordinates
    Input *there: Struct value that updates with every move the player makes
*/
#include "ControlSystem.h"
#include "Ships.h"
#include "Drawing.h"

#define ESC 0x1B
#define SPACE 0x20
#define ENT 0x0D


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
uint8_t UserInput(){

char buttonPress = uart_get_char(); // Defining the variable as the button the player has pressed

if (buttonPress == '\0'){ // Necessary to make the function not accept null values. Makes it run faster/smoother
    return 0;
}
// 1 - 4 are for the WASD controls
if(buttonPress != '\0' && buttonPress == 'w' ){
    return 1;
}
if(buttonPress != '\0' && buttonPress == 'a'){
    return 2;
}
if(buttonPress != '\0' && buttonPress == 's'){
    return 3;
}
if(buttonPress != '\0' && buttonPress == 'd'){
    return 4;
}
// Spacebar
if(buttonPress !='\0' && buttonPress == 0x20){
    return 5;
}
// Enter
if(buttonPress !='\0' && buttonPress == 0x0D){
    return 6;
}
 /*   switch (buttonPress){
        case 'w':{
            return 1;
            break;
        }
        case 'a':{
            return 2;
            break;
        }
        case 's':{
            return 3;
            break;
        }
        case 'd':{
            return 4;
            break;
        }
        case 0x20:{
            return 5;
            break;
        }
        case 0x0D:{
            return 6;
            break;
        }
        default:
            return '\0';
    }*/
uart_clear();
}


void Controller(int8_t moveDir, struct playerPos *there){
uint16_t xPos = (*there).xPosition; // Updates the value of the x-coordinate
uint8_t yPos = (*there).yPosition; // Updates the value of the y-coordinate
    if (yPos > 0){ // Prevents the player from going off screen
        if (moveDir == 1){
            yPos--;
        }
    }
    if (xPos > 0){ // Prevents the player from going off screen
        if (moveDir == 2){
            xPos--;
        }
    }
    if (yPos < 66){ // Prevents the player from going off screen
        if (moveDir == 3){
            yPos++;
        }
    }
    if (yPos < 271){ // Prevents the player from going off screen
        if (moveDir == 4){
            xPos++;
            }
    }
    if (moveDir == 0){
        return moveDir;
    }
    if (moveDir == '\0'){
        return moveDir;
    }
there->xPosition = xPos;
there->yPosition = yPos;
}
