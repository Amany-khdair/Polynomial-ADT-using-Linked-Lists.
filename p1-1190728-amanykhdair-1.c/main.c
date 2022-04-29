//1190728 amany khdair
#include <stdio.h>//This is useful for getting the input from the user(Keyboard) and output result text to the screen.
#include <stdlib.h>//includes functions involving memory allocation, process control, conversions and others.
#include <ctype.h>//header file of the C Standard Library declares several functions that are useful for testing and mapping characters
#include <conio.h>// is a C header file used mostly by MS-DOS compilers to provide console input/output.
#include <math.h>//declares a set of functions to compute common mathematical operations and transformations:
#include <string.h>//Functions declared in string.

#define MAX 100 //instead of writing 100 in each function we define this step

typedef struct N* POINT;//pointer

struct N
{
    int COE;//coefficient of type INT
    int POW;//power of type INT
    POINT next;
};

typedef POINT LT;
typedef POINT PLACEMENT;

void PTF(FILE *, LT);//PRINT TO FILE
int RPFF (LT L,short n, char ASD[100]); //READ POLY FROM FILE
void RL(char []);//to release line
void IN (LT, int, int);//INSERT
void PL (LT);//PRINT LIST
void DL (LT);//DELETE LIST
void EST (LT);//TO ELIMINATE THE SIMILAR TERMS
PLACEMENT FP (LT, PLACEMENT);//TO FIND THE PREVIOUS
int GV (char *, short *);//TO GET THE VALUE
LT ADDITION (LT, LT);
LT SUBTRACT (LT, LT);
LT MULTIPLY (LT, LT);
double SUB (LT, double);
int SIGN (char *, short);
char NC (char *, short);//THE NEXT CHARACTER
char PC (char *, short);//THE PREVIOUS CHARACTER
int POWER (char *, short);
short IOPC (char *, short);//INDEX OF PREVIOUS CHARACTER
short IONC (char *, short);//INDEX OF NEXT CHARACTER
int EOT (char *, short);//FUNCTION TO THE END OF TERMS
int INTEGER (double);
void DO (LT, LT, int);//TO LET THE PROGRAM DO THE OPERATIONS
int HS();//TO LET THE PROGRAM KNOW WHAT THE USER WANT TO SUBSTITUTE FIRST
void RFF();//THIS FUNCTION WILL READ THE EQUATIONS FROM THE FILE

int INDEX = 0;// the start index of the array linked list
LT equations[MAX]; // to store polynomials in

int main()
{
    system("color c0");//THIS STATEMENT ISNT USEFUL AT ALL ITS JUST FOR THE DESIGN :)
    LT L1 = (LT) malloc(sizeof(struct N));//to book a place for the placement or in other word the position in the memory to let it add to the node
    L1 -> next = NULL;
    LT L2 = (LT) malloc(sizeof(struct N));//to book a place for the placement or in other word the position in the memory to let it add to the node
    L2 -> next = NULL;
    char CHOISE;
    char CHAR1;
    char CHAR2;
    do //THESE STATEMENTS WILL APPER IN THE BEGINING OF THE PROGRAM
    {
        printf("\t\t________________________________**************************________________________________\n");
        printf(" \t\t\t\t\t\t\tTHE LIST\n");
        printf("\t\t\t\t\t   1)Read polynomials from the file\n");
        printf("\t\t\t\t\t   2)Find the sum\n");
        printf("\t\t\t\t\t   3)Find the difference\n");
        printf("\t\t\t\t\t   4)Find the product\n");
        printf("\t\t\t\t\t   5)Exit from the program\n");
        printf("please insert number 1 first to let the program works very well.. thanks\n");
        printf("\t\t________________________________**************************________________________________\n");
        CHOISE = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console.

        switch (CHOISE) //because we have a lot of choices I used this function
        {

        case '1'://if the user clicked on 1 then the program will print to the user all the equations in the file from function RFF (read from file)
            system("cls");//This function is used to run system command prompt commands and here (cls) is a command to clear the output screen
            RFF();//call up method RFF(read from file)
            system("cls");//This function is used to run system command prompt commands and here (cls) is a command to clear the output screen
            break;

        case '2'://here if the user clicked on 2 then the system will print to the user the equations he want to sum
            system("cls");//This function is used to run system/ command prompt commands and here cls is a command to clear the output screen
            printf(" Choose which equations to sum: \n");
            for(int i = 0; i < INDEX ; i ++)//this for loop method will help to let the user choose which equation want
            {
                printf("%d : ", i+1);//to get the next equation
                PL(equations[i]);
            }
            printf("\nfirst: ");//this statement will appear to the user to let him write the first equation he want to operate on it
            CHAR1 = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
            if((CHAR1-'0') < 1 && (CHAR1-'0') >= INDEX)//char -0 transfer the char into integer so it check if the user entered it in the right way or not
            {
                printf("\nIts a wrong entry, could you please enter the number again or just press Amany to back :) ... ");
                CHAR1 = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
                if(CHAR1 == 'Amany')
                    break;//The break statement ends the loop immediately when it is encountered.
            }
            printf("\nsecond: ");//this statement will appear to the user to let him write the second equation he want to operate on it
            CHAR2 = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
            printf("\n");
            if((CHAR2-'0') < 1 && (CHAR2-'0') > INDEX)//char - 0 transfer the char into integer so it check if the user entered it in the right way or not
            {
                printf("\nWrong entry, please enter the number again or press Amany to back: ");
                CHAR2 = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
                if(CHAR2 == 'Amany')
                    break;//The break statement ends the loop immediately when it is encountered.
            }
            DO(equations[(CHAR1-'0') - 1], equations[(CHAR2-'0') - 1],1);//transfer it
            system("cls");//This function is used to run system/ command prompt commands and here cls is a command to clear the output screen
            break;//The break statement ends the loop immediately when it is encountered.

        case '3':
            system("cls");//This function is used to run system/ command prompt commands and here cls is a command to clear the output screen
            printf(" Choose which equations to sum: \n");
            for(int i = 0; i < INDEX ; i ++)//this for loop method will help to let the user choose which equation want
            {
                printf("%d : ", i+1);//to get the next equation
                PL(equations[i]);
            }
            printf("\nfirst: ");//this statement will appear to the user to let him write the first equation he want to operate on it
            CHAR1 = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
            if((CHAR1-'0') < 1 && (CHAR1-'0') >= INDEX)//char -0 transfer the char into integer so it check if the user entered it in the right way or not
            {
                printf("\nWrong entry, please enter the number again or press Amany to back: ");
                CHAR1 = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
                if(CHAR1 == 'Amany')
                    break;//The break statement ends the loop immediately when it is encountered.
            }
            printf("\nsecond: ");//this statement will appear to the user to let him write the second equation he want to operate on it
            CHAR2 = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
            printf("\n");
            if((CHAR2-'0') < 1 && (CHAR2-'0') > INDEX)//char -0 transfer the char into integer so it check if the user entered it in the right way or not
            {
                printf("\nWrong entry, please enter the number again or press Amany to back: ");
                CHAR2 = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
                if(CHAR2 == 'Amany')
                    break;//The break statement ends the loop immediately when it is encountered.
            }
            DO(equations[(CHAR1-'0') - 1], equations[(CHAR2-'0') - 1], HS());//transfer it
            system("cls");//This function is used to run system/ command prompt commands and here cls is a command to clear the output screen
            break;//The break statement ends the loop immediately when it is encountered.

        case '4':
            system("cls");//This function is used to run system/ command prompt commands and here cls is a command to clear the output screen
            printf(" Choose which equations to sum: \n");
            for(int i = 0; i < INDEX ; i ++)//this for loop method will help to let the user choose which equation want
            {
                printf("%d : ", i+1);//to get the next equation
                PL(equations[i]);
            }
            printf("\nfirst: ");//this statement will appear to the user to let him write the first equation he want to operate on it
            CHAR1 = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
            if((CHAR1-'0') < 1 && (CHAR1-'0') >= INDEX)
            {
                printf("\nWrong entry, please enter the number again or press Amany to back: ");
                CHAR1 = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
                if(CHAR1 == 'Amany')
                    break;//The break statement ends the loop immediately when it is encountered.
            }
            printf("\nsecond: ");//this statement will appear to the user to let him write the second equation he want to operate on it
            CHAR2 = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
            printf("\n");
            if((CHAR2-'0') < 1 && (CHAR2-'0') > INDEX)//char -0 transfer the char into integer so it check if the user entered it in the right way or not
            {
                printf("\nWrong entry, please enter the number again or press Amany to back: ");
                CHAR2 = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
                if(CHAR2 == 'Amany')
                    break;//The break statement ends the loop immediately when it is encountered.
            }
            DO(equations[(CHAR1-'0') - 1], equations[(CHAR2-'0') - 1], 4);//transfer it
            system("cls");//This function is used to run system/ command prompt commands and here cls is a command to clear the output screen
            break;//The break statement ends the loop immediately when it is encountered.

        default://here if the user did not choose any of the above number the following statement will appear..
            system("cls");//This function is used to run system/ command prompt commands and here cls is a command to clear the output screen
            printf("\t\t OPS! no such CHOISE! Could you please enter your choice again :\n\n");
            continue;
        }

    }
    while (CHOISE != '5'); //if the user did not chose 5

    system("cls");//This function is used to run system/ command prompt commands and here cls is a command to clear the output screen

    for(int i  = 0 ; i < INDEX ; i++)
    {
        DL(equations[i]);//call up function delete list (DL)
        free(equations[i]);//deallocates the memory previously allocated by a call to malloc
    }

    return 0;
}

void RL(char ASD[100]) // release line function to remove the new line from the last of the string
{
    for(int i = 0 ; i < 100 ; i ++)//check if the number of char is less than 100
    {
        if(ASD[i] == '\n')
        {
            ASD[i] = '\0';//it is equal null
            return;
        }
    }
}
void RFF()//this function will read the equations that you already inserted it in the file
{
    FILE * in = fopen("equations.txt", "r");// opens the equations file to read
    char ASD[100];// to store each line from the file
    while(fgets(ASD, 100, in)) // reading the file line by line using the fgets
    {
        if(INDEX == MAX)// check if it reached the maximum number of polynomials
        {
            printf("you reached the maximum number of equations :)! \npress any key to get back to the menu\n");
            getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
            return;
        }
        RL(ASD);// To remove the new line from the last of the string
        equations[INDEX] = (LT) malloc(sizeof(struct N));//to book a place for the placement or in other word the position in the memory to let it add to the node or just initializing the node
        equations[INDEX] -> next = NULL;
        if(RPFF(equations[INDEX], 100, ASD))           // check if a valid polynomial and stores it in the list
        {
            printf("[%d]: ", INDEX);
            PL(equations[INDEX]);
            INDEX++;      // this index or this operation means that it will reach to the last size(( number of polynomials in the array ))
        }
    }
    printf("good!, you inserted the Data successfully, press any key to get back to the menu\n");
    getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
}


int HS() // this function will ask the user how he/she want to substitute? f1 - f2 or f2 - f1, and return the choice
{
    printf("1)Find f1(x) - f2(x)\n");
    printf("2)Find f2(x) - f1(x)\n");
    printf("3)return to main menu\n\n");//get back to the main menu

    char CHOISE = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console

    while(!((CHOISE=='1')||(CHOISE=='2')||(CHOISE=='3'))) //if the user did not choose any of the above options then print the warning statement and then show the last 3 statements again
    {
        system("cls");//This function is used to run system/ command prompt commands and here cls is a command to clear the output screen
        printf("sorry but No such CHOISE! I already told you to Enter one of the choices that appear in front of you :(, chose again please:\n\n");
        printf("1)Find f1(x) - f2(x)\n");
        printf("2)Find f2(x) - f1(x)\n");
        printf("3)return to main menu\n\n");//get back to the main menu

        CHOISE = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
    }

    if (CHOISE == '1')
        return 2;

    else if (CHOISE == '2')
        return 3;

    else if (CHOISE == '3')
    {
        system("cls");//This function is used to run system/ command prompt commands and here cls is a command to clear the output screen
        return 0;
    }
    return 0;
}

void DO (LT L1, LT L2, int op)  // this function will make the specified operation on the given lists, print the result, and ask the user to enter a value for x to find g(x)
{

    if (op == 0)
    {
        system("cls");//This function is used to run system/ command prompt commands and here cls is a command to clear the output screen
        return;
    }

    if ( (L1 -> next == NULL) || (L2 -> next == NULL) ) //if L1 was empty in other word if the user did not insert an equation then...
    {
        printf("OPS! an Error occurred! if you want to do an operation on two functions, Please enter the value of those functions ^_^\n\n");
        printf("press any key to get back to the menu\n");
        getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
        system("cls");//This function is used to run system/ command prompt commands and here cls is a command to clear the output screen
        return;
    }

    printf("f1(x) = ");
    PL(L1);//print list for the first equation
    printf("f2(x) = ");
    PL(L2);//print list for the second equation
    printf("\n");

    LT result;//steps to print the result

    if (op == 1) //if the operation was 1 then it will add the first function to the other..
    {
        result = ADDITION(L1,L2);//add the first to the second
        printf("g(x) = f1(x) + f2(x) = ");
        PL(result);//show the result
    }

    else if (op == 2) //if the operation was 2 then it will substitute the first function from the second then...
    {
        result = SUBTRACT(L1,L2);//sub the first from the second
        printf("g(x) = f1(x) - f2(x) = ");
        PL(result);//show the result
    }

    else if (op == 3) //if the operation was 3 then it will substitute the second function from the first then...
    {
        result = SUBTRACT(L2,L1);//sub the second from the first
        printf("g(x) = f2(x) - f1(x) = ");
        PL(result);//show the result
    }

    else if (op == 4) //if the operation was 4 then it will multiplies the first function to the other then..
    {
        result = MULTIPLY(L1,L2);//mul the first to the second
        printf("g(x) = f1(x) * f2(x) = ");
        PL(result);//show the result
    }

    printf("\n");//new line
    printf("1)enter a value for x to find g(x)\n");//if the user wants to found the value of g(X) then he/she should enter the value of x
    printf("2)store the output in the output.txt file\n");//to store the results in the output file
    printf("3)return to main menu\n\n");//get back to the main menu

    char CHOISE = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console

    while( !( (CHOISE == '1')||(CHOISE == '2')||(CHOISE == '3')) ) //if the user did not choose any of the above options then print the warning statement and then show the last 3 statements again
    {
        system("cls");//This function is used to run system/ command prompt commands and here cls is a command to clear the output screen
        printf("sorry but No such CHOISE! I already told you to Enter one of the choices that appear in front of you :(, chose again please:\n\n");
        printf("1)enter a value for x to find g(x)\n");//if the user wants to found the value of g(X) then he/she should enter the value of x
        printf("2)store the result in the output.txt file\n");//to store the results in the output file
        printf("3)return to main menu\n\n");//get back to the main menu

        CHOISE = getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console
    }

    if (CHOISE == '1') //if the user chose 1
    {

        system("cls");//This function is used to run system command prompt commands and here cls is a command to clear the output screen
        printf("\n\n");//to make a new line
        printf("g(x) = ");//to prepare what the value of g(x)
        PL(result);//& here is the result
        printf("\n\n");//new line

        double x;//a value of type double
        printf("hello again :), enter the value you want of x please:\n");
        scanf("%lf",&x);//of type float

        if (INTEGER(x))//this is the function who will allow the user to enter the value of x
            printf("\nf(%d) = %d\n",(int)x,(int)SUB(result,x));
        else
            printf("\nf(%.2f) = %.2f\n",x,SUB(result,x));
    }
    else if (CHOISE == '2') //if the user chose 2
    {
        FILE *output = fopen("output.txt", "a");
        if(op == 1)//if the user chose the addition operation then
        {
            fprintf(output, "g(x) = f1(x) + f2(x) \n");// print the whole addition equation
            fprintf(output, "f1(x) = ");//to print the value of F1
            PTF(output, L1);//print to file the value of L1
            fprintf(output, "\nf2(x) = ");//to print the value of F2
            PTF(output, L2);//print to file the value of L1
            fprintf(output, "\ng(x) = ");//print the result of addition
            PTF(output, result);//print from file the result
            fprintf(output, "\n______________________________************************______________________________\n\n");//just for design :)
        }
        else if (op == 2)//if the user chose the subtracter operation then
        {
            fprintf(output, "g(x) = f1(x) - f2(x) \n");//to print the whole subtracter equation
            fprintf(output, "f1(x) = ");//to print the value of F1
            PTF(output, L1);//print to file the value of L1
            fprintf(output, "\nf2(x) = ");//to print the value of F2
            PTF(output, L2);//print to file the value of L2
            fprintf(output, "\ng(x) = ");//print the result of subtracter
            PTF(output, result);//print from file the result
            fprintf(output, "\n______________________________************************______________________________\n\n");//just for design :)
        }
        else if (op == 3)//if the user chose the subtracter operation but the other operation then
        {
            fprintf(output, "g(x) = f2(x) - f1(x) \n");//to print the whole subtracter equation
            fprintf(output, "f1(x) = ");//to print the value of F1
            PTF(output, L1);//print to file the value of L1
            fprintf(output, "\nf2(x) = ");//to print the value of F2
            PTF(output, L2);//print to file the value of L2
            fprintf(output, "\ng(x) = ");//print the result of subtracter
            PTF(output, result);//print from file the result
            fprintf(output, "\n______________________________************************______________________________\n\n");
        }
        else if (op == 4)//if the user chose the multiply operation then
        {
            fprintf(output, "g(x) = f1(x) * f2(x) \n");//to print the whole multiply equation
            fprintf(output, "f1(x) = ");//to print the value of F1
            PTF(output, L1);//print to file the value of L1
            fprintf(output, "\nf2(x) = ");//to print the value of F2
            PTF(output, L2);//print to file the value of L2
            fprintf(output, "\ng(x) = ");//print the result of multiply
            PTF(output, result);//print from file the result
            fprintf(output, "\n______________________________************************______________________________\n\n");
        }
        return;
    }
    else if( CHOISE == '3')
    {
        system("cls");//This function is used to run system/ command prompt commands and here cls is a command to clear the output screen
        return;
    }

    printf("\n");
    printf("press any key to get back to the menu\n");
    getch();//getch means pauses the Output Console until a key is pressed and The entered character does not show up on the console

    system("cls");//This function is used to run system/ command prompt commands and here cls is a command to clear the output screen

    DL(result);
    free(result);//this function is to free the memory
}

int RPFF (LT L,short n, char ASD[100])  // this function will read the polynomials from the file, insert its term to the list L in sorted due to larger power, eliminate similar terms in the polynomial and return 1 for success
{
    char *poly = (char *) malloc(n * sizeof(char));//pass each line from the file to this function and analyse it to a polynomial
    strcpy(poly, ASD);//function copies the string pointed by source to the destination
    short i = 0;
    int co = 1;
    int pow = 0;
    int POWERF = 0;

    if (   (poly[0] == '\0')  ||  (  (poly[0] == ' ')&&(NC(poly, 0) == '\0')  )   ) //this will read the polynomial as a string and start take letter by letter then store it
    {
        printf(":) OPS! an Error occurred! there is nothing here, You didn't enter anything please be care full!\n");
        free(poly);//free the memory
        return 0;// if the polynomial is incorrect, then return 0
    }

    while ( (i != n - 1) && (poly[i] != '\0') )//check if the string empty or not
    {

        if (poly[i] == 'X')//if the user entered x capital then
        {
            printf("Error! Please use small x only!the capital latter is not allowed here sorry..\n");
            free(poly);
            return 0;// if the polynomial is incorrect, then return 0
        }

        if ( (poly[i] == '+')||(poly[i] == '-')||(poly[i] == '*'))// this statement making exception for cases like (x +  ) ,(x +++ 5)
        {

            if ( (poly[i] == '+')||(poly[i] == '-') )//if it was positive or negative then it goes to the next character as shown in the second if
            {
                if ( (NC(poly, i) == '+')||(NC(poly, i) == '-'))//next character
                {

                    short j = IONC(poly, i);//this is the index of next character

                    if ((NC(poly, j) == '+')||(NC(poly, j) == '-'))//the next of the next
                    {
                        printf("OPS! an Error occurred! You can't use more than one sign!\n");
                        free(poly);//free the memory
                        return 0;// if the polynomial is incorrect, then return 0
                    }
                }
            }

            if (NC(poly,i)=='\0')//if it is empty or equal null then..
            {
                printf("OPS! an Error occurred! Binary Operation must have two operators!\n");
                free(poly);//free the memory
                return 0;// if the polynomial is incorrect, then return 0
            }
        }

        if (poly[i]=='*')// this function is making exceptions for cases like x * x or x * a
        {

            if (( isdigit(PC(poly, i))&&isdigit(NC(poly, i)))||(isdigit(PC(poly, i))&&(NC(poly, i)=='x')))
            {
                short j = IOPC(poly, i);     // next of next
                if ( (j != -1) && POWER(poly, j))
                {
                    printf("OPS! an Error occurred! You can't use * expect between a coefficient and x or between two numbers (coefficient for some x)!\n");
                    free(poly);//free the memory
                    return 0;// if the polynomial is incorrect, then return 0
                }
            }

            else if ( isdigit(PC(poly, i)) )// MEANS that (a * -x) or (b * +x) are valid
            {
                if ( (NC(poly, i) == '+') || (NC(poly, i) == '-') )//negative or positive poth of them are valid
                {
                    // this means dont do any thing, this is valid
                }
            }

            else
            {
                printf("OPS! an error occurred! You can't use * for the power!\n");
                free(poly);//free the memory
                return 0;// if the polynomial is incorrect, then return 0
            }
        }

        else if (poly[i] == 'x')//for x
            pow = 1;

        else if (poly[i] == '^')//for the power
        {

            if ( (PC(poly, i) == 'x') && (NC(poly, i) == '+') )//this is a special case for ax^+b about how it will work
            {

                short j = IONC(poly, i);// index of +

                j++;// increment j by 1 so that we find previousChar in next step

                while(isdigit(poly[j]))//next,,, the char after (+) is a number
                    j++;// increment j by 1 so that we find previousChar in next step

                j--;//The -- operator works in a similar way to the ++ operator except -- decreases the value by 1 so that we find nextChar in next step

                if ( !isdigit(NC(poly, j)) )// next of next ,,, if the char after (+) is not a number
                {
                    printf("OPS! an error occurred! Wrong use of power! You can only use it in this form ax^n\n");
                    free(poly);//free the memory
                    return 0;// if the polynomial is incorrect, then return 0
                }
            }

            else if ( (PC(poly, i) == 'x') && (NC(poly, i) == '-') )
            {
                printf("OPS! an error occurred! You can't use a negative power in a polynomial! didnt you earn this?\n");
                free(poly);//free the memory
                return 0;// if the polynomial is incorrect, then return 0
            }

            else if  ( ( PC(poly, i) != 'x' ) || !isdigit( NC(poly, i) ) )//it must be in the form x^n
            {
                printf("OPS! an error occurred! You can only use the power in this form ax^n\n");
                free(poly);//free the memory
                return 0;// if the polynomial is incorrect, then return 0
            }

            else if ( isdigit(NC(poly, i)) )// next char ,,,in x^n then n must be the end of this term not like x^6x
            {
                short j = IONC(poly, i);//the index of next character

                if (!EOT(poly, j))//if the FUNCTION was not END OF TERMS then
                {
                    printf("OPS! an error occurred! The power must be only a single number!\n");
                    free(poly);//free memory
                    return 0;// if the polynomial is incorrect, then return 0
                }
            }
            POWERF = 1;//power found equal 1
        }

        else if (isdigit(poly[i]))// this function is to be very sure that it is a number
        {
            if (PC(poly, i)=='x')//this function check the previous character
            {
                printf("OPS! an error occurred! The coefficient must be before x\n");
                free(poly);//free memory
                return 0;//if the polynomial is incorrect, then return 0
            }

            if (!POWERF)
            {
                co *= GV(poly, &i);//This function would return the coefficient and increment I to meet the index of the first character after the coefficient, with (*=) keeping the sign.
                i--;//The -- operator works in a similar way to the ++ operator except -- decreases the value by 1 so that we find nextChar in next step
                if ( isdigit(NC(poly, i)) )// here i is the index of the last digit in the coefficient, so we just need to check nextChar to make sure that we don't have two consecutive numbers without operator
                {
                    printf("OPS! an error occurred!  Missed operator or something!its not valid a space between two numbers :) \n");
                    free(poly);//free memory
                    return 0;// if the polynomial is incorrect, then return 0
                }
            }
            else
            {
                pow = GV(poly, &i);
                POWERF = 0;//power found equal 0
                i--;//The -- operator works in a similar way to the ++ operator except -- decreases the value by 1 so that we find nextChar in next step
            }
        }

        else if ((poly[i] != '+')&&(poly[i] !='-')&&(poly[i] !=' '))//if the user insert sth else not like what suppose to insert then
        {
            printf("OPS! an error occurred! this is an invalid input %c\n",poly[i]);
            free(poly);//free memory
            return 0;// if the polynomial is incorrect, then return 0
        }


        if ((((poly[i]=='-')||(poly[i]=='+'))&&(!SIGN(poly, i)))||(poly[i+1] == '\0'))//if the poly was negative or positive and not sign or empty
        {
            IN(L,co,pow);
            co = 1;//coefficient equal 1
            pow = 0;//power equal 0
        }

        if (poly[i]=='-')//if it was negative then
        {
            if (!POWERF)
                co *= -1;
        }
        i++;// increment i by 1 so that we find previousChar in next step
    }

    if (i == n - 1)//this means that if the polynomial was long then
    {
        printf("Error! This is too long polynomial!\n");
        free(poly);//free memory
        return 0;// if the polynomial is incorrect, then return 0
    }

    free(poly);//free memory
    EST(L);//call the eliminate Similar Term to get the final answer

    return 1;//return 1 for success
}

int GV (char *poly, short *i)// This function would read any number either was coefficient or power and then return it
{
    int value;//The index of the first character after the number read will be (i) after this function is run.

    short j = *i;
    while (isdigit(poly[*i]))
        (*i)++;// increment *i by 1 so that we find previousChar in next step.

    char c = poly[*i];// this statements means that save the char at index (i)

    poly[*i] = '\0';// ('\0')means put a null character on this character to have a null after the number
    value = atoi(&poly[j]);//Transform the string number to an integer starting at first digit's index j and ending at the index of null i
    poly[*i] = c;// this function is to return the character to its position(placement) in the string

    return value;
}

void IN (LT L, int co, int pow)// this function will insert the polynomial term in the right place
{

    PLACEMENT temp = (PLACEMENT) malloc( sizeof(struct N) );

    if (temp != NULL)//this function check if the temp is empty or not
    {
        temp -> COE = co;//temp point to the coefficient
        temp -> POW = pow;//temp point to the power
    }
    else
    {
        printf("SORRY :( ,But Out of Memory!\n");
        exit(0);//to exit from the program
    }

    PLACEMENT p,previous;

    p = L -> next;
    previous = L;// previous points at the node before p

    while (p != NULL)//while p is not empty then
    {
        if (p -> POW > temp -> POW)
        {
            p = p -> next;
            previous = previous -> next;
        }
        else
        {
            previous -> next = temp;
            temp -> next = p;
            break;
        }
    }

    if (p == NULL)//if the list is empty and it means that The power of the node we choose to add is lower than the other nodes.
    {
        previous -> next = temp;
        temp -> next = NULL;//let the temp equal null
    }
}

void EST (LT L)//this function is to ELIMINATE THE SIMILAR TERMS from the list L
{

    PLACEMENT p, q, previous;//positions

    p = L -> next;//new node

    while (p != NULL)//the condition is that it is not empty
    {
        q = p -> next;
        while (q != NULL)//the condition is that it is not empty
        {
            if (p -> POW == q -> POW )
            {
                p -> COE += q -> COE;
                previous = FP(L,q);
                previous -> next = q -> next;
                free(q);//free the memory
                q = previous -> next;
            }
            else
            {
                q = q -> next;
            }
        }
        p = p -> next;
    }

    // the following code deletes the zero from the polynomial
    previous = L;
    p = L -> next;

    if ((p !=NULL)&&(p -> next !=NULL))//The aim of p -> next!= NULL is to ensure that the node containing the zero is not the polynomial's only node.
    {

        while (p -> next != NULL)//the condition is about (p -> next!= NULL) and its aim is to ensure that the node containing the zero is not the polynomial's only node.
        {
            p = p -> next;
            previous = previous -> next;
        }

        if (p -> COE == 0)//point to the coefficient
        {
            free(p);//free the memory
            previous -> next = NULL; //let it equal null
        }
    }
}

PLACEMENT FP (LT L, PLACEMENT p)
{
    PLACEMENT previous = L;
    while ( (previous -> next != NULL) && (previous -> next != p) )
        previous = previous -> next;

    return previous;//return the first thing we initialized here
}

void PL (LT L) //this function will print the list
{

    PLACEMENT p = L -> next;

    if (L -> next != NULL)//if it is not empty then
    {
        while (p != NULL)//while p is not empty then do the following
        {
            if (p -> COE == 0)
            {
                if (L -> next -> next == NULL)// if this node is the only node, then print zero, otherwise dont do any thing
                    printf("0");//print zero
            }
//the following operations are on the power and the coefficient of the polynomial if it was zero or 1 or -1 or even bigger or smaller than 1
            else if (p -> POW == 0)//if the power was zero then
                printf("%d ",p -> COE);

            else if ( (p -> POW == 1) && ( (p -> COE != 1) && (p -> COE != -1) ) )//if the power was 1 or in other word not equal -1 then
                printf("%dx ",p -> COE);//print p->coefficient

            else if ( (p -> POW == 1) && (p -> COE == 1) )//if the power and the coefficient was 1 then
                printf("x ");//print x

            else if ( (p -> POW == 1) && (p -> COE == -1) )//if the power was 1 and the coefficient was -1 then
                printf("-x ");//print -x

            else if ( (p -> POW > 1) && (p -> COE == 1) )//if the power was bigger than 1 and coefficient was equal 1 then
                printf("x^%d ",p -> POW);//print p->power

            else if ( (p -> POW > 1) && (p -> COE == -1) )//if the power was bigger than 1 and the coefficient was equal -1 then
                printf("-x^%d ",p -> POW);//print p->power

            else//if there was some thing else then
                printf("%dx^%d ",p -> COE, p -> POW);

            if (p -> next != NULL)  //This function is means that don't put (+) after the last term
                printf("+ ");

            p = p -> next;
        }

        printf("\n");//new line
    }
    else//if no thing of the above operations happen then print ..
        printf("Nothing to print! List is Empty\n");
}

void DL (LT L) //this function will delete the list
{

    PLACEMENT p = L -> next;

    while (L -> next != NULL)//if it was not empty then do the following
    {
        L -> next = p -> next;
        free(p);//free the memory
        p = L -> next;
    }
}
//this function to add the polynomial
LT ADDITION (LT L1, LT L2)
{
// This function would create a new list of the two lists we choose to combine, and then call eliminate Similar Term(EST) to get the final answer.
    LT sum = (LT) malloc( sizeof(struct N) );

    if (sum != NULL)//if the sum is not empty then
    {
        sum -> next = NULL;//let it empty
//the following operations make the program comes with the value or in other word the equations L1 and L2
        while (L1 -> next != NULL)//the first equation is not empty
        {
            IN(sum,L1 -> next -> COE,L1 -> next -> POW);
            L1 = L1 -> next;
        }

        while (L2 -> next != NULL)//the second equation is not empty
        {
            IN(sum,L2 -> next -> COE,L2 -> next -> POW);
            L2 = L2 -> next;
        }

        EST (sum);//call the eliminate Similar Term to get the final answer
    }

    return sum;//return the sum to the screen
}
//this function to sub the polynomial
LT SUBTRACT (LT L1, LT L2)
{
//This function would create a new list of the two lists we choose to subtract, except with the second one's coefficients compounded by -1, and then call the function eliminateSimilarTerm to find the final answer.
    LT diff = (LT) malloc( sizeof(struct N) );

    if (diff != NULL)// if the difference not equal null then
    {
        diff -> next = NULL;
//the following operations make the program comes with the value or in other word the equations L1 and L2
        while (L1 -> next != NULL)//the first equation is not empty
        {
            IN(diff, L1 -> next -> COE, L1 -> next -> POW);
            L1 = L1 -> next;
        }

        while (L2 -> next != NULL)//the second equation is not empty
        {
            IN(diff, -(L2 -> next -> COE), L2 -> next -> POW);
            L2 = L2 -> next;
        }

        EST (diff);//call the eliminate Similar Term to get the final answer
    }

    return diff;//return the difference to the screen
}
//this function to mul the polynomial
LT MULTIPLY (LT L1, LT L2)
{
    // This function would make a new list, multiply each term in the first list by all the terms in the second list, save the answer, and then call the function eliminateSimilarTerm to find the final result.
    LT product = (LT) malloc( sizeof(struct N) );

    if (product != NULL)// if the product not equal null then
    {
        product -> next = NULL;//let it equal null

        PLACEMENT L2_firstNode = L2 -> next;

        L1 = L1 -> next;
        L2 = L2 -> next;

        while (L1 != NULL)//the first equation is not empty
        {
            while (L2 != NULL)//the second equation is not empty
            {
                IN (product, (L1 -> COE) * (L2 -> COE), (L1 -> POW) + (L2 -> POW));
                L2 = L2 -> next;
            }
            L2 = L2_firstNode;
            L1 = L1 -> next;//put the result in the new list
        }

        EST (product);//call the eliminate Similar Term to get the final answer
    }

    return product;//return the product to the screen
}

double SUB (LT L, double x)//This function would return the product of substituting a value in a polynomial.
{

    double result = 0;//initialise the result to zero value
    L = L -> next;

    while (L != NULL)//the condition here is that L does not equal null or it is not empty
    {
        result += (L -> COE) * pow(x, L -> POW);
        L = L -> next;
    }
    return result;//return the result to the screen
}

int SIGN (char *poly, short i)// this function will determine if the given character in the given equation is a sign
{

    if (!((poly[i]=='+')||(poly[i]=='-')))//this function will check if the character in the given equation is a sign or not
        return 0;

    char PREVIOUSCHAR = PC(poly, i);

    if (isdigit(PREVIOUSCHAR)||PREVIOUSCHAR == 'x')//if the digit either for the previous character or the next character was equal x then return 0 otherwise return 1
        return 0;
    else
        return 1;//means that its a succseful
}

char NC (char *ASD, short i)// Regardless of spaces, this function returns the next character in the string.
{
    i++;// increment i by 1 so that we find previousChar in next step
    while (ASD[i] == ' ')//if there was a space or just the ASD function equal a space
        i++;// increment i by 1 so that we find previousChar in next step
    return ASD[i];
}

char PC (char *ASD, short i)// If i = 1, this function returns the first character before the one at index i (excluding spaces), and if i = 0, it returns null.
{
    if (i == 0)
        return '\0';//it will return a null
    i--;//The -- operator works in a similar way to the ++ operator except -- decreases the value by 1 so that we find nextChar in next step
    while ( (i > -1) && (ASD[i] == ' ') )
        i--;//The -- operator works in a similar way to the ++ operator except -- decreases the value by 1 so that we find nextChar in next step
    if (i == -1)
        return ' ';//it will return a space
    else
        return ASD[i];//return the ASD function
}

short IOPC (char *ASD, short i)//This function returns the index of the previous character in the given string, independent of spaces, and if i reaches -1, it returns -1.
{
    i--;//The -- operator works in a similar way to the ++ operator except -- decreases the value by 1 so that we find nextChar in next step
    while ( (i > -1) && (ASD[i] == ' ') )
        i--;//The -- operator works in a similar way to the ++ operator except -- decreases the value by 1 so that we find nextChar in next step
    return i;
}

short IONC (char *ASD, short i)// This function will return the index of the first previous char in the given string, regardless of spaces, and the index of the null char will be returned if i enter it.
{
    i++;// increment i by 1 so that we find previousChar in next step
    while (ASD[i] == ' ')
        i++;// increment i by 1 so that we find previousChar in next step
    return i;//means its run successfully
}

int POWER (char *poly, short i)//this function check the value which at index i is a power or not
{
    while ( isdigit(poly[i]) )
        i--;//The -- operator works in a similar way to the ++ operator except -- decreases the value by 1 so that we find nextChar in next step
    i++;// increment i by 1 so that we find previousChar in next step

    if (PC(poly, i) == '^')//if it contain this sign (^)then its a successful and return 1 if not return 0
        return 1;//if it is true then return 1
    else
        return 0;//if it is not then return 0
}

int EOT (char *poly, short i)// this function check If the value at index i is the last thing in the expression (no 'x' or '*' after it), this function returns true.
{
    while ( isdigit(poly[i]) )
        i++;// increment i by 1 so that we find previousChar in next step

    i--;//The -- operator works in a similar way to the ++ operator except -- decreases the value by 1 so that we find nextChar in next step

    if ( (NC(poly, i) == 'x') || (NC(poly, i) == '*') )//this function check if the value reached the last thing in the term by check if it contain x or (*)
        return 0;//if it is not then return 0
    else
        return 1;//if it is true then return 1
}

int INTEGER (double num)//If the given double number can be replaced with an integer number, this function will return true.
{
    int n = (int) num;
    if (n == num)
        return 1;//if it is true then return 1
    else
        return 0;//if it is not then return 0
}

void PTF(FILE *output, LT l) // print the polynomial to the output file
{
    LT temp = l -> next;// starts from the node next of the list
    while( temp != NULL )
    {
        fprintf(output, "%dx^%d ", temp->COE, temp->POW);// prints each peace of the polynomial into the file
        if(temp -> next != NULL)// check if there is still peace's
            fprintf(output, "+ ");// if still . then print a + sign
        temp = temp -> next;//the last thing here is get the next node
    }
}
