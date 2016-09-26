#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    Mariah Schon
    2240
    Program 3
    March 14
   Honor Pledge:   On my honor as a student of the University
                    of Nebraska at Omaha, I have neither given nor received
                    unauthorized help on this homework assignment.
    Mariah Schon
    mschon@unomaha.edu
    Help from tutors
   */
/*
Function name
Arguments
Return
Description*/


#define DEFAULT_FILE "prog3"

 /*
    Function Name       : canPrint
    Parameters          : char to see if it is a valid char
    Return value(s)     : 0 or 1
    Partners            : NONE
    Description         : It checks the char
    */
int canPrint(char c){
    if(c != '\n' || c!= 0){
        if(c < 91 && c > 65) return 1;
        return 0;
        printf("Unknown Character");
    }
    return 1;
}

/*
    Function Name       : compare
   Parameters           : 2 cahr arrays to compare the words
   Return value(s)      : 0 or 1
    Partners            : NONE
    Description         : It checks the word
    */
int compare(char a[], char b[])
{
   int c = 0;

   while (a[c] == b[c]) {

      if (c>2)
         break;
      c++;
   }

   if (a[c] == b[c])
      return 0;
   else
      return 1;
}


/*
    Function Name       : main
   Parameters           : the file
   Return value(s)      : 0
    Partners            : NONE
    Description         : It dose all the stuff
    */

int main(int argc, char* argv[]){
    char toprint='0';
    int comchars1 = 0;
    int comchars2 = 0;

    int adrchars1 = 0;
    int adrchars2 = 0;

    char b4comchars[2] = "00";
    char b4adrchars[2] = "00";
    int halted = 0;
    int com1 = 0;
    int com2 = 0;

    int adr1 = 0;
    int adr2 = 0;

    char b4com[2] = "00";
    char b4adr[2] = "00";
    int the = 0;

        int com = 0;
        int adr = 0;
        char mem[4];
        int accumulator = 0;
        int instructionCounter = 0;
        int instructionReister = 0;
        int operationCode = 0;
        int operand = 0;

    /*comp vars*/
    int q = 0;
    FILE *fPtr = NULL;
    int line = 0;
    int halt = 0;
    char code[13];

    int vm[100] =   {0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0};

    if (argc == 1){
        fPtr = fopen(DEFAULT_FILE, "r");
    }else{
        fPtr = fopen(argv[1], "r");
    }

    if (fPtr == NULL){
        printf("File could not be opened.\n");
        return 0;
    }

    while (fgets(code, sizeof code, fPtr) != NULL){

        char temp[4] = "0000";
        int p1_1 = 0;
        int p1_2 = 0;
        int memadr = 0;
        char p2[4] = "0000";
        int command;
        char rawcom[4] = "xxxx";
int comstar = 3;
        int x = 0;
        int y = 0;


       line++;

       p1_1 = code[0] - '0';
       p1_2 = code[1] - '0';
       memadr = (p1_1*10)+p1_2;

       while(code[comstar] != ' '){
           rawcom[y] = code[comstar];
           comstar++;
           y++;
       }
          comstar++;
       while(code[comstar] != '\n'){
           p2[x] = code[comstar];
           x++;
           if(x>4){
                printf("Word overflow on line: %d",line);
                return 0;
           }
           comstar++;
       }

       if(compare(rawcom,"READ") == 0)command = 10;
       else if(compare(rawcom,"WRIT") == 0)command = 11;
       else if(compare(rawcom,"PRNT") == 0)command = 12;
       else if(compare(rawcom,"LOAD") == 0)command = 20;
       else if(compare(rawcom,"STOR") == 0)command = 21;
       else if(compare(rawcom,"SETx") == 0)command = 22;
       else if(compare(rawcom,"ADDx") == 0)command = 30;
       else if(compare(rawcom,"SUBx") == 0)command = 31;
       else if(compare(rawcom,"DIVx") == 0)command = 32;
       else if(compare(rawcom,"MULT") == 0)command = 33;
       else if(compare(rawcom,"MODx") == 0)command = 34;
       else if(compare(rawcom,"BRAN") == 0)command = 40;
       else if(compare(rawcom,"BRZR") == 0)command = 42;
       else if(compare(rawcom,"BRNG") == 0)command = 41;
       else if(compare(rawcom,"HALT") == 0){
           halt = 1;
           command = 99;
       }else{
           printf("Unknown command on line: %d\n",line);
           return 0;
       }

 if(command == 22){
            if(x == 1){
                   p2[3] = p2[0];
               p2[2] = '0';
               p2[1] = '0';
               p2[0] = '0';
            }else if(x == 2){
                   p2[3] = p2[1];
               p2[2] = p2[0];
               p2[1] = '0';
               p2[0] = '0';
            }else if(x == 3){
                   p2[3] = p2[2];
               p2[2] = p2[1];
               p2[1] = p2[0];
               p2[0] = '0';
            }
            sprintf(temp, "%c%c%c%c", p2[0],p2[1],p2[2],p2[3]);
        }
        else{
            if(x>1)sprintf(temp, "%d%c%c", command,p2[0],p2[1]);
            else sprintf(temp, "%d%c%c", command,'0',p2[0]);
        }

        vm[memadr] = atoi(temp);
    }
    fclose(fPtr);
   if(halt < 1){
        printf("No HALT");
        return 0;
    }

    while(q < (100)){
            if(vm[q] > 9999){
                printf("Segmentation Fault");
                return 0;
            }
            sprintf(mem,"%04d",vm[q]);

            com1 = (int) (long) mem[0]-'0';
            com2 = (int) (long) mem[1]-'0';

            adr1 = (int) (long) mem[2]-'0';
            adr2 = (int) (long) mem[3]-'0';
 sprintf(b4com, "%d%d", com1,com2);
            sprintf(b4adr, "%d%d", adr1,adr2);

            com = atoi(b4com);
            adr = atoi(b4adr);

            if(halted != 1)switch(com)
            {
                char memchars[4];
                int comchars = -1;
                int adrchars = -1;
                int a = 0;
                case 10:
                    scanf("%d", &a);
                    vm[adr] = a;
                    break;
                case 11:
                    printf("%04d\n",vm[adr]);
                    break;
                case 12:
                    comchars = 1;
                    while(comchars != 0){
                                sprintf(memchars,"%04d",vm[adr]);

                                comchars1 = (int) (long) memchars[0]-'0';
                                comchars2 = (int) (long) memchars[1]-'0';

                                adrchars1 = (int) (long) memchars[2]-'0';
                                adrchars2 = (int) (long) memchars[3]-'0';

                                sprintf(b4comchars, "%d%d", comchars1,comchars2);
                                sprintf(b4adrchars, "%d%d", adrchars1,adrchars2);

                                comchars = atoi(b4comchars);
                                adrchars = atoi(b4adrchars);

                                if(comchars == 0) break;
                                    toprint = comchars;
                                if(canPrint(toprint)<1) return 0;
                                    printf("%c",toprint);

                                    if(adrchars == 0) break;
                                    toprint = adrchars;
                                   if(canPrint(toprint)<1) return 0;
                                    printf("%c",toprint);
                                   adr++;
                    }

                     fflush( stdout );
                    printf("\n");
                    break;
 case 20:
                    accumulator=vm[adr];
                    break;
                case 21:
                    vm[adr] = accumulator;
                    break;
                case 30:
                    accumulator+=vm[adr];
                    break;
                case 31:
                    accumulator = accumulator - vm[adr];
                    break;
                case 32:
                    if(vm[adr]!=0) accumulator=accumulator/vm[adr];
                    else{
                        printf("Division by 0 was attempted");
                        return 0;
                    }
                    break;
                case 33:
                    accumulator*=vm[adr];
                    break;
                case 34:
                    accumulator = accumulator % vm[adr];
                    break;
                case 40:
                    q = adr-1;
                    break;
                case 41:
                    if(accumulator<0)q = adr-1;
                    break;
                case 42:
                    if(accumulator < 1 && accumulator>-1){
                        q = adr-1;
                    }
                    break;
                case 99:
                    halted = 1;
                    break;
                default :
                    printf("Unknown command %d",com);
                    return 0;
                    break;
            }



            if(accumulator >9999 || accumulator<-9999){
                printf("Word overflow");
                return 0;
            }

  q++;
    }
   q=0;
   printf("REGISTERS:\n");
   printf("accumulator:                  +%04d\n",accumulator);
   printf("instructionCounter:              %02d\n",instructionCounter);
   printf("instructionReigster:          +%04d\n",instructionReister);
   printf("operationCode:                   %02d\n",operationCode);
   printf("operand:                         %02d\n",operand);
   printf("MEMORY:\n");
   printf("       0     1     2     3     4     5     6     7     8     9");
   the =0;
   while(the < (10)){
       int end = 0;
       printf("\n%d0 ",the);
       while(end < (10)){
           printf("+%04d ",vm[(end+(the*10))]);
           end++;
       }
       the++;
   }
    return 0;
}

