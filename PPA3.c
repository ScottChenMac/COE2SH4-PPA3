#include <stdio.h>
#include "MacUILib.h"
#include "myStringLib.h"   // This is your first custom C library

// [TODO] Import the required library for rand() and srand()
// [TODO] Import the required library for accessing the current time - for seeding random number generation





// PREPROCESSOR DIRECTIVE CONSTANTS
// ================================
// For program-wide constants, define them here using #define.  Add as seen needed.

// [COPY AND PASTE FROM PPA2] Copy your additional preprocessor constants from PPA2 and paste them below


// [TODO] Then, define more constants here as seen needed.





// GLOBAL VARIABLES
// ================================

int exitFlag; // Program Exiting Flag

// [COPY AND PASTE FROM PPA2] Copy your additional global from PPA2 and paste them below

// [TODO] Declare More Global Variables as seen needed.

// [TODO] Declare Global Pointers as seen needed / instructed in the manual.








// FUNCTION PROTOTYPES
// ================================
// Declare function prototypes here, so that we can organize the function implementation after the main function for code readability.

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

// [TODO] In PPA3, you will need to implement this function to generate random items on the game board
//        to set the stage for the Scavenger Hunter game.
void GenerateItems(struct objPos list[], int listSize, const char* str, int strSize);





// MAIN PROGRAM
// ===============================
int main(void)
{

    Initialize();

    while(!exitFlag)  
    {
        GetInput();

        RunLogic();

        DrawScreen();

        LoopDelay();
    }

    CleanUp();

}




// INITIALIZATION ROUTINE
// ===============================
void Initialize(void)
{
    MacUILib_init();

    MacUILib_clearScreen();

    // [COPY AND PASTE FROM PPA2] Copy your initialization routine from PPA2 and paste them below

    
    // [TODO] Initialize any global variables as required.
    exitFlag = 0;  // 0 - do not exit, non-zero - exit the program

    
    // [TODO] Allocated heap memory for on-demand variables as required.  Initialize them as required.

    // [TODO] Seed the random integer generation function with current time.

    // [TODO] Generate the initial random items on the game board at the start of the game.

    
}




// INPUT COLLECTION ROUTINE
// ===============================
void GetInput(void)
{

    // Asynchronous Input - non blocking character read-in
    
    // [COPY AND PASTE FROM PPA2] Copy your input collection routine from PPA2 and paste them below

    // [TODO] Though optional for PPA3, you may insert any additional logic for input processing.

   
}




// MAIN LOGIC ROUTINE
// ===============================
void RunLogic(void)
{
    // [COPY AND PASTE FROM PPA2] Copy your main logic routine from PPA2 and paste them below

    // [TODO]   Implement the Object Collision logic here
    //
    //      Simple Collision Algorithm
    //      1. Go through all items on board and check their (x,y) against the player object x and y.
    //      2. If a match is found, use the ASCII symbol of the collided character, and 
    //         find all the occurrences of this ASCII symbol in the Goal String
    //      3. For every occurrence, reveal its ASCII character at the corresponding location in the
    //         Collected String
    //      4. Then, determine whether the game winning condition is met.

    // [TODO]   Implement Game Winning Check logic here
    //
    //      Game Winning Check Algorithm
    //      1. Check if the contents of the Collected String exactly matches that of the Goal String.
    //         YOU MUST USE YOUR OWN my_strcmp() function from Lab 3.
    //      2. If matched, end the game.
    //      3. Otherwise, discard the current items on the game board, and 
    //         generate a new set of random items on the board.  Game continues.
    
}



// DRAW ROUTINE
// ===============================
void DrawScreen(void)
{
       
    // [COPY AND PASTE FROM PPA2] Copy your draw logic routine from PPA2 and paste them below

    // [TODO]   Insert somewhere in the draw routine to draw the randomly generated items on the board.

    // [TODO]   Display the "Mystery String" contents at the bottom of the game board
    //          To help players keep track of their game progress.
    
    
    
}



// DELAY ROUTINE
// ===============================
void LoopDelay(void)
{
    MacUILib_Delay(100000); // 0.1s delay
}





// TEAR-DOWN ROUTINE
// ===============================
void CleanUp(void)
{
    // [TODO]   To prevent memory leak, free() any allocated heap memory here
    //          Based on the PPA3 requirements, you need to at least deallocate one heap variable here.

    // Insert any additional end-game actions here.
    

    MacUILib_uninit();
}




// The Item Generation Routine
////////////////////////////////////
void GenerateItems(struct objPos list[], int listSize, const char* str, int strSize)
{
    // This is possibly one of the most conceptually challenging function in all PPAs
    // Once you've mastered this one, you are ready to take on the 2SH4 course project!

    // Random Non-Repeating Item Generation Algorithm
    ////////////////////////////////////////////////////

    // Setup - Bit Vector
    //  - Set up an int array with the number of elements equal to the x-size of the game board, initialized all to zero
    //  - Set up another int array with the size equal to the y-size of the game board, again initialize to zero.
    //  - Set up yet another integer array with the size matching the Goal String.
    //      such that every character in the Goal String has a corresponding bit vector index. 

    //  General Idea:
    //    When a random integer has been generated, use it as an index to access the bit vector
    //    If the value at the index in the bit vector is zero, it means this recent random integer has not been generated before.
    //      Accept this random integer, and change the value at the index to non-zero.
    //    If the value at the index in the bit vector is non-zero, it means this random number has been generated before.
    //      Reject this random integer, and generate another one.

    //  Random Coordinate Generation (not ideal):
    //  - Generate non-repeating x coordinate values using its bit vector
    //  - Generate non-repeating y coordinate values using its bit vector
    //  - Also want to make sure that player position is not in the generate range!!

    //  Random Character Symbol Generation:
    //  - Generate random integer index, then determine whether the character at this index has been used (using it bit vector)
    //  - If character has not been used, accept the character at this index.
    //    Otherwise, reject this index, and regenerate another random integer.

    //  Output
    //  - Write the random x-y coordinates and their corresponding characters into the objStr array
    

    //  Above and Beyond: 
    //  - What would you do if we want not only the characters from the Goal String to be generated,
    //    but also other unrelated ASCII characters?

}
