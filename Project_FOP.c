//FOP-Project
// Mohammad Hossein Eslami 

#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h> 
#include <sys/types.h>
#include <math.h>
#include <dirent.h>
#define MAX_LINE_LENGTH 1000
char clipboard[10000];
int counterclipboard = 0;

void print_cwd()
{
    char cwd[1000];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
    }
}
void createfile(){ //bekhun--file <address>
    int counter = 0; //This counter is used to get out of dir in createfile
    FILE * fptr;
    char c;
    scanf(" ");
    scanf("%c", &c); //Next line is to seperate the different ways to receive a command
    if (c == '/'){
        char folder[100];
        char foldersaver[100];
        char foldersaver1[100];

        for (int i = 0; i < 100; i++){
            foldersaver[i] = '\0';
            foldersaver1[i] = '\0';
        }

        scanf("%s", folder);
        
        for (int i = 0; i < strlen(folder); i++){
            foldersaver[i] = folder[i];
            foldersaver1[i] = folder[i];
        }
        
        char *folder2 = (char*)malloc(50); 
        char *folder1 = strtok(folder, "/");
        while (folder1 != NULL){
            mkdir(folder1);
            chdir(folder1);
            counter++;
            folder2 = folder1;
            folder1 = strtok(NULL, "/");
        }

        fptr = fopen(folder2, "rb");
        if (fptr != 0){                //This part is made to see what is inside the file
            printf("File Already exists\n");
            for (int i = counter; i > 1; i--){
                chdir("..");
            }
            return;    
        }
        chdir(".."); //Goes back to delete the directory and make a file with the same name
        rmdir(folder2);
        
        fptr = fopen(folder2, "w");
        fclose(fptr);

        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        counter = 0;
        
        
        for (int i = 0; i < strlen(foldersaver1); i++){
            if (foldersaver1[i] == '/'){
                for (int j = strlen(foldersaver1); j >= i; j--){
                    foldersaver1[j+1] = foldersaver1[j];
                }
                foldersaver1[i] = '1';
                break;
            }
        }
        
        //foldersaver1[strlen(foldersaver1)-1] = '\0';
        char *folder4 = (char*)malloc(50); 
        char *folder3 = strtok(foldersaver1, "/");
        while (folder3 != NULL){
            mkdir(folder3);
            chdir(folder3);
            counter++;
            folder4 = folder3;
            folder3 = strtok(NULL, "/");
         }
        chdir(".."); //Goes back to delete the directory and make a file with the same name
        rmdir(folder2);
        fptr = fopen(folder2, "w");
        fclose(fptr);
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
       
        counter = 0;

    } else if ( c == '"'){
        char folder[100];
        char foldersaver[100];
        char foldersaver1[100];
        char a;
        gets(folder);
        for (int i=0;;i++){ //This for is made to ignore the '"' mark at the end of the string
            a=folder[i];
            if(a=='\0'){
                folder[i-1] = '\0';
                break;
            }
        }

        for (int i = 0; i < strlen(folder); i++){
            foldersaver[i] = folder[i];
            foldersaver1[i] = folder[i];
        }

        char *folder2 = (char*)malloc(50); 
        char *folder1 = strtok(folder, "/");
        while (folder1 != NULL){
            mkdir(folder1);
            chdir(folder1);
            counter++;
            folder2 = folder1;
            folder1 = strtok(NULL, "/");
        }
        fptr = fopen(folder2, "rb");
        if (fptr != 0){                //This part is made to see what is inside the file
            printf("File Already exists\n");
            for (int i = counter; i > 1; i--){
                chdir("..");
            }
            return;    
        }
        chdir("..");
        rmdir(folder2);
        fptr = fopen(folder2, "w");
        fclose(fptr);
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        counter = 0;
        

        for (int i = 0 ; i < strlen(foldersaver1); i++){
            foldersaver1[i] = foldersaver1[i+1];
        }

        for (int i = 0; i < strlen(foldersaver1); i++){
            if (foldersaver1[i] == '/'){
                for (int j = strlen(foldersaver1); j >= i; j--){
                    foldersaver1[j+1] = foldersaver1[j];
                }
                foldersaver1[i] = '1';
                break;
            }
        }
        


        char *folder4 = (char*)malloc(50); 
        char *folder3 = strtok(foldersaver1, "/");
        while (folder3 != NULL){
            mkdir(folder3);
            chdir(folder3);
            counter++;
            folder4 = folder3;
            folder3 = strtok(NULL, "/");
         }
        chdir(".."); //Goes back to delete the directory and make a file with the same name
        rmdir(folder4);
        fptr = fopen(folder2, "w");
        fclose(fptr);

        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        counter = 0;
        
    }
}

void firstundo(char * infoFile, char *backfolder, char *backfolder1, int length){
    FILE * fptr;
    int counter = 0;
    for (int i = 2; i < strlen(backfolder); i++){
        if (backfolder[i] == '/'){
            for (int j = strlen(backfolder)-1; j >= i; j--){
                backfolder[j+1] = backfolder[j];
            }
            backfolder[i] = '1';
            break;
        }
    }
    

    
    
    char *folder2 = (char*)malloc(50); 
    char *folder1 = strtok(backfolder, "/");
    while (folder1 != NULL){
        chdir(folder1);
        counter++;
        folder2 = folder1;
        folder1 = strtok(NULL, "/");
    }
    
    
    infoFile[strlen(infoFile)] = '\0';
    fptr = fopen(folder2, "wb");
    fputs(infoFile, fptr);
    fclose(fptr);

    
    for(int i = counter; i > 1; i--){
        chdir("..");
    }
    counter = 0;

    
    char *folder3 = strtok(backfolder1, "/");
    while (folder3 != NULL){
        chdir(folder3);
        folder3 = strtok(NULL, "/");
    }
}


void catfile(){  //bekhun--file <address>
    int counter1 = 0;
    FILE *fptr;
    char c;
    int flag = 0;
    scanf(" ");
    scanf("%c", &c); //Next line is to seperate the different ways to receive a command
    if (c == '/'){
        char folder[50];
        scanf("%s", folder);
        char *folder2 = (char*)malloc(50); 
        char *folder1 = strtok(folder, "/");
        while (folder1 != NULL){
            if (chdir(folder1) == -1){
                flag++;
                if (flag >= 2){
                    printf("Wrong Directory\n");
                    for (int i = counter1; i > 1; i--){
                        chdir("..");
                    }
                    print_cwd();
                    return;
                }
            }
            counter1++;
            folder2 = folder1;
            folder1 = strtok(NULL, "/");
        }
        fptr = fopen(folder2, "r");
        if (fptr == NULL){
            printf("File does not exist\n");
            for (int i = counter1; i > 1; i--){
                chdir("..");
            }
            counter1 = 0;
        } else {
            char ch;
            ch = fgetc(fptr);
            while( ch != EOF){
                printf("%c", ch);
                ch = fgetc(fptr);
            }
            printf("\n");
            for (int i = counter1; i > 1; i--){
                chdir("..");
            }
        }
        fclose(fptr);
        counter1 = 0;
    } else if (c == '"'){
        char folder[100];
        char a;
        gets(folder);
        for (int i=0;;i++){ //This for is made to ignore the '"' mark at the end of the string
            a=folder[i];
            if(a=='\0'){
                folder[i-1] = '\0';
                break;
            }
        }
        char *folder2 = (char*)malloc(50); 
        char *folder1 = strtok(folder, "/");
        while (folder1 != NULL){
            if (chdir(folder1) == -1){
                flag++;
                if (flag >= 2){
                    printf("Wrong Directory\n");
                    for (int i = counter1; i > 1; i--){
                        chdir("..");
                    }
                    print_cwd();
                    return;
                }
            }
            counter1++;
            folder2 = folder1;
            folder1 = strtok(NULL, "/");
        }
        fptr = fopen(folder2, "r");
        if (fptr == NULL){
            printf("File does not exist\n");
            for (int i = counter1; i > 1; i--){
                chdir("..");
            }
            counter1 = 0;
        } else {
            char ch;
            ch = fgetc(fptr);
            while( ch != EOF){
                printf("%c", ch);
                ch = fgetc(fptr);
            }
            printf("\n");
            for (int i = counter1; i > 1; i--){
                chdir("..");
            }
        }
        fclose(fptr);
        counter1 = 0;
    }
}  

void removestr(){ //hazfstr--file <address> --poax:y--sizenumb-b/or/f
    FILE *fptr;
    int counter = 0;
    char c;
    int flag = 0;
    scanf(" ");
    scanf("%c", &c); //Next line is to seperate the different ways to receive a command
    char folder[50];
    scanf("%s", folder);
    int length = strlen(folder);
    char backfolder [50];
    char backfolder1 [50];
    for (int i = 0; i < strlen(folder); i++){
        backfolder1[i] = '\0';
        backfolder[i] = '\0';
    }
    for (int i = 0; i < strlen(folder); i++){
        backfolder[i] = folder[i];
        backfolder1[i] = folder[i];
    }
    char *folder2 = (char*)malloc(50); 
    char *folder1 = strtok(folder, "/");
    while (folder1 != NULL){
        if (chdir(folder1) == -1){
            flag++;
            if (flag >= 2){
                printf("Wrong Directory\n");
                for (int i = counter; i > 1; i--){
                    chdir("..");
                }
                return;
            }
        }
        counter++;
        folder2 = folder1;
        folder1 = strtok(NULL, "/");
    }
    int temp = counter;
    scanf(" --pos");
    int line, pos;
    scanf("%d:%d", &line, &pos);
    scanf("--size");
    int size;
    char posi;
    scanf("%d-%c", &size, &posi);
    char *infoFile = (char *)malloc(10000*sizeof(char));
    if ((fptr = fopen(folder2, "rb")) == NULL){                //This part is made to see what is inside the file
        printf("File does not exist\n");
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        return;    
    } else {
        char ch2; //This copies the data inside the file
        int i = 0;
        ch2 = fgetc(fptr);
        infoFile[0] = ch2;
        while(ch2 != EOF){
            i++;
            ch2 = fgetc(fptr);
            infoFile[i] = ch2;
        }
        infoFile[i] = '\0';
    }
    fclose(fptr);
    for (int i = counter; i > 1; i--){
        chdir("..");
    }


    firstundo(infoFile, backfolder, backfolder1, length);



    int flag1 = 1; 
    int place;
    for (int i = 0; i < strlen(infoFile); i++){ //This is to find the position of the line we are trying to get to
        if (infoFile[i] == '\n'){
            flag1++;
        }
        if (flag1 == line){
            place = i;
            break;
        }
    }
    if (line == 1){ //This one is done to make sure that if the line is one, we don't add the \n which does not exist
        place -= 1;
    }
    if(posi == 'b'){
        for (int i = pos+place+1-size+1; i <= pos+place+1; i++){  //This is to check for \r
            if (infoFile[i] == '\r'){
                size += 1;
            }
        }
        for (int i = pos+place+1-size; i < strlen(infoFile); i++){
            infoFile[i] = infoFile[i+size];
        }
    } else if (posi == 'f'){
        for (int i = pos+place+1; i <= pos+place+1+size-1; i++){    //This is to check for \r
            if (infoFile[i] == '\r'){
                size += 1;
            }
        }

        for(int i = pos+place+1; i < strlen(infoFile); i++){
            infoFile[i] = infoFile[i+size];
        }
    }
    fptr = fopen(folder2, "wb"); //reopens the file but empties it and fills it again
    for(int i = 0; i < strlen(infoFile); i++){
        fprintf(fptr, "%c", infoFile[i]);
    }
    fclose(fptr);
    for(int i = counter; i > 1; i--){
        chdir("..");
    }
    return;
}

void copystr(){ // copystr--file <address> --posx:y--sizex-y
    FILE *fptr;
    int counter = 0;
    char c;
    int flag = 0;
    for (int i = 0; i < strlen(clipboard); i++){ //This is used to empty everything in our global clipboard
        clipboard[i] = '\0';
    }
    counterclipboard = 0;
    scanf(" ");
    scanf("%c", &c); //Next line is to seperate the different ways to receive a command
    char folder[50];
    scanf("%s", folder);
    char *folder2 = (char*)malloc(50); 
    char *folder1 = strtok(folder, "/");
    while (folder1 != NULL){
        if (chdir(folder1) == -1){
            flag++;
            if (flag >= 2){
                printf("Wrong Directory\n");
                for (int i = counter; i > 1; i--){
                    chdir("..");
                }
                return;
            }
        }
        counter++;
        folder2 = folder1;
        folder1 = strtok(NULL, "/");
    }
    scanf(" --pos");
    int line, pos;
    scanf("%d:%d", &line, &pos);
    scanf("--size");
    int size;
    char posi;
    scanf("%d-%c", &size, &posi);
    char *infoFile = (char *)malloc(10000*sizeof(char));
    if ((fptr = fopen(folder2, "rb")) == NULL){                //This part is made to see what is inside the file
        printf("File does not exist\n");
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        return;    
    } else {
        char ch2; //This copies the data inside the file
        int i = 0;
        ch2 = fgetc(fptr);
        infoFile[0] = ch2;
        while(ch2 != EOF){
            i++;
            ch2 = fgetc(fptr);
            infoFile[i] = ch2;
        }
        infoFile[i] = '\0';
    }
    fclose(fptr);
    int flag1 = 1; 
    int place;
    for (int i = 0; i < strlen(infoFile); i++){ //This is to find the position of the line we are trying to get to
        if (infoFile[i] == '\n'){
            flag1++;
        }
        if (flag1 == line){
            place = i;
            break;
        }
    }
    if (line == 1){ //This one is done to make sure that if the line is one, we don't add the \n which does not exist
        place -= 1;
    }
    if(posi == 'b'){
        for (int i = pos+place+1-size+1; i <= pos+place; i++){    //This is to check for \r
            if (infoFile[i] == '\r'){
                size += 1;
            }
        }
        for (int i = pos+place+1-size; i <= pos+place; i++){
            clipboard[counterclipboard] = infoFile[i];
            counterclipboard++;
        }
    } else if (posi == 'f'){
        for (int i = pos+place+1; i <= pos+place+1+size-1;i++){    //This is to check for \r
            if (infoFile[i] == '\r'){
                size += 1;
            }
        }
        for (int i = pos+place+1; i <= pos+place+1+size-1; i++){
            clipboard[counterclipboard] = infoFile[i];
            counterclipboard++;
        }
    }

    printf("%s\n", clipboard);
    for (int i  = counter; i > 1; i--){
        chdir("..");
    }
    counter = 0;
    return;
}

void cutstr(){ //beborstr--file <address> --posx:y--sizenum-b/or/f
    FILE *fptr;
    int counter = 0;
    char c;
    int flag = 0;
    for (int i = 0 ; i < strlen(clipboard); i++){
        clipboard[i] = '\0';
    }
    counterclipboard = 0;
    scanf(" ");
    scanf("%c", &c); //Next line is to seperate the different ways to receive a command
    char folder[50];
    scanf("%s", folder);
    int length = strlen(folder);
    char backfolder [50];
    char backfolder1 [50];
    for (int i = 0; i < 50; i++){
        backfolder[i] = '\0';
        backfolder1[i]  = '\0';
    }
    for (int i = 0; i < strlen(folder); i++){
        backfolder[i] = folder[i];
        backfolder1[i] = folder[i];
    }
    char *folder2 = (char*)malloc(50); 
    char *folder1 = strtok(folder, "/");
    while (folder1 != NULL){
        if (chdir(folder1) == -1){
            flag++;
            if (flag >= 2){
                printf("Wrong Directory\n");
                for (int i = counter; i > 1; i--){
                    chdir("..");
                }
                return;
            }
        }
        counter++;
        folder2 = folder1;
        folder1 = strtok(NULL, "/");
    }
    scanf(" --pos");
    int line, pos;
    scanf("%d:%d", &line, &pos);
    scanf("--size");
    int size;
    char posi;
    scanf("%d-%c", &size, &posi);
    char *infoFile = (char *)malloc(10000*sizeof(char));
    if ((fptr = fopen(folder2, "rb")) == NULL){                //This part is made to see what is inside the file
        printf("File does not exist\n");
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        return;    
    } else {
        char ch2; //This copies the data inside the file
        int i = 0;
        ch2 = fgetc(fptr);
        infoFile[0] = ch2;
        while(ch2 != EOF){
            i++;
            ch2 = fgetc(fptr);
            infoFile[i] = ch2;
        }
        infoFile[i] = '\0';
    }
    fclose(fptr);

    for (int i = counter; i > 1; i--){
        chdir("..");
    }

    firstundo(infoFile, backfolder, backfolder1, length);


    int flag1 = 1; 
    int place;
    for (int i = 0; i < strlen(infoFile); i++){ //This is to find the position of the line we are trying to get to
        if (infoFile[i] == '\n'){
            flag1++;
        }
        if (flag1 == line){
            place = i;
            break;
        }
    }
    if (line == 1){ //This one is done to make sure that if the line is one, we don't add the \n which does not exist
        place -= 1;
    }
    if(posi == 'b'){
        for (int i = pos+place+1-size+1; i <= pos+place; i++){    //This is to check for \r
            if (infoFile[i] == '\r'){
                size += 1;
            }
        }
        for (int i = pos+place+1-size; i < pos+place+1; i++){
            clipboard[counterclipboard] = infoFile[i];
            counterclipboard++;
        }
    } else if (posi == 'f'){
        for (int i = pos+place+1; i <= pos+place+1+size-1;i++){    //This is to check for \r
            if (infoFile[i] == '\r'){
                size += 1;
            }
        }
        for (int i = pos+place+1; i <= pos+place+1+size-1; i++){
            clipboard[counterclipboard] = infoFile[i];
            counterclipboard++;
        }
    }
    if(posi == 'b'){
        for (int i = pos+place+1-size; i < strlen(infoFile); i++){
            infoFile[i] = infoFile[i+size];
        }
    } else if (posi == 'f'){
        for(int i = pos+place+1; i < strlen(infoFile); i++){
            infoFile[i] = infoFile[i+size];
        }
    }
    fptr = fopen(folder2, "wb"); //reopens the file but empties it and fills it again
    for(int i = 0; i < strlen(infoFile); i++){
        fprintf(fptr, "%c", infoFile[i]);
    }
    fclose(fptr);
    //printf("%s\n", clipboard);
    for(int i = counter; i > 1; i--){
        chdir("..");
    }
    counter = 0;
    return;
}


void pastestr(){ //bechasbunstr--file <address> --posx:y
    int counter4 = 0;
    int couunter11 = 0;
    FILE *fptr;
    int counter = 0;
    char c;
    int flag = 0;
    scanf(" ");
    scanf("%c", &c); //Next line is to seperate the different ways to receive a command
    char folder[50];
    scanf("%s", folder);
    int length = strlen(folder);
    char backfolder [50];
    char backfolder1 [50];
    for (int i = 0; i < length; i++){
        backfolder1[i] = '\0';
        backfolder[i] = '\0';
    }
    for (int i = 0; i < strlen(folder); i++){
        backfolder[i] = folder[i];
        backfolder1[i] = folder[i];
    }
    char *folder2 = (char*)malloc(50); 
    char *folder1 = strtok(folder, "/");
    while (folder1 != NULL){
        if (chdir(folder1) == -1){
            flag++;
            if (flag >= 2){
                printf("Wrong Directory\n");
                for (int i = counter; i > 1; i--){
                    chdir("..");
                }
                return;
            }
        }
        counter++;
        folder2 = folder1;
        folder1 = strtok(NULL, "/");
    }
    scanf(" --pos");
    int line, pos;
    scanf("%d:%d", &line, &pos);
    char *infoFile = (char *)malloc(10000*sizeof(char));
    if ((fptr = fopen(folder2, "rb")) == NULL){                //This part is made to see what is inside the file
        printf("File does not exist\n");
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        fclose(fptr);
        return;    
    } else {
        char ch2; //This copies the data inside the file
        int i = 0;
        ch2 = fgetc(fptr);
        infoFile[0] = ch2;
        while(ch2 != EOF){
            i++;
            ch2 = fgetc(fptr);
            infoFile[i] = ch2;
        }
        infoFile[i+1] = '\0';
    }
    fclose(fptr);

    for (int i = counter; i > 1; i--){
        chdir("..");
    }

    printf("%s\n", backfolder1);
    printf("%s\n", backfolder);
    print_cwd();

    firstundo(infoFile, backfolder, backfolder1, length);

    fptr = fopen(folder2, "rb+");
    if (fptr == NULL){ //This checks if the file exists
        printf("File does not exist\n");
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        counter = 0;
        return;
    } else {  
    fseek(fptr, 0, SEEK_END);     
    int size;
    size = ftell(fptr);
    if ( size == 0){ //This is used to check if the file empty, then start the command
        printf("The position you are looking for does not exist in this file\n");
         } else {
            int flag = 1; //This is to see how many \n are in the file
            for (int i = 0; i < strlen(infoFile); i++){
                if (infoFile[i] == '\n'){
                    flag++;
                }
            }
            if (flag < line){ //This part checkes if the given position is below everything already in the file
                printf("The position you are looking for does not exit\n");
            } else {
                int flag1 = 1;
                int place = 0;
                for (int i = 0; i < strlen(infoFile); i++){ //This is to find the position of the line we are trying to get to
                    if (infoFile[i] == '\n'){
                    flag1++;
                }
                    if (flag1 == line){
                    place = i;
                    break;
                    }
                }
                if (line == 1){ //This one is done to make sure that if the line is one, it is not added up to the position
                    line = 0;
                }
                if (line+1 == 1){
                    fseek(fptr, place+pos, SEEK_SET);
                } else {
                    fseek(fptr, place+pos+1, SEEK_SET);
                }
                int counter6 = 0; //This coutner is used to check for \n and \\n
                for(int i = 0; i < strlen(clipboard); i++){ //Here we are checking for \n and \\n
                    if (clipboard[i] == '\\'){
                    counter6++;
                    if (clipboard[i+1] == 'n' && counter6 == 1){
                        fputs("\n", fptr);
                        i++;
                        counter6 = 0;
                    }
                        fprintf(fptr, "%c", clipboard[i+1]);
                        i++;
                    } else {
                        fprintf(fptr, "%c", clipboard[i]);
                    }
                }
                if (line+1 == 1){
                    for (int i = pos+place; i < strlen(infoFile)-1; i++){
                        fprintf(fptr, "%c", infoFile[i]);
                    }
                } else {
                    for (int i = pos+place+1; i < strlen(infoFile)-1; i++){
                        fprintf(fptr, "%c", infoFile[i]);
                    } 
                }             
            }
            }
            fclose(fptr);
            for (int i = counter; i > 1; i--){
                chdir("..");
            }
            counter = 0;
    }


}

void bywordstr(char message[100], char infoFile[10000]){
    char *pos = strstr(infoFile, message);
    int flag = 0;
    if (pos-infoFile == 0){
        printf("1\n");
        return;
    }
    for (int i = 0; i < (pos-infoFile); i++){
        if (infoFile[i] == ' ' || infoFile[i] == '\n'){
            flag++;
        }
    }
    if (flag == 0){
        printf("-1\n");
        return;
    }
    printf("%d\n", flag);
}


void countstr(char message[100], char infoFile[10000]){ // This site really helped, https://www.javatpoint.com/find-occurrence-of-substring-in-c-using-function
    int l1, l2, j;
    int count = 0;
    int count1 = 0;
    l1 = strlen(message);
    l2 = strlen(infoFile);
    for (int i = 0; i <= l2; i++){
        j = 0;
        while(infoFile[i] == message[j]){
            count++;
            i++;
            j++;
        }

        if (count == l1){
            count1++;
            count = 0;
        } else {
            count = 0;
        }
    }
    printf("%d\n", count1);
}

void allstr(char message[100], char infoFile[10000]){
    int l1, l2, j;
    int count = 0;
    int words = 1;
    int saver[100];
    int savercounter = 0;
    l1 = strlen(message);
    l2 = strlen(infoFile);
    for (int i = 0; i <= l2; i++){
        j = 0;
        while(infoFile[i] == message[j]){
            count++;
            i++;
            j++;
        }

        if (count == l1){
            for (int j = 0; j <= i-l1; j++){
                if (infoFile[j] == ' ' || infoFile[j] == '\n'){
                    words++;
                }
            }
            saver[savercounter] = words;
            savercounter++;
            words = 1;
            count = 0;
        } else {
            count = 0;
        }
    }
    if (savercounter == 0){
        printf("-1\n");
        return;
    }
    for (int i = 0; i < savercounter; i++){
        printf("%d, ", saver[i]);
    }
    printf("\n");
}

void atstr(char message[100], char infoFile[10000], int num){
    int l1, l2, j;
    int count = 0;
    int saver[100];
    int savercounter = 0;
    l1 = strlen(message);
    l2 = strlen(infoFile);
    for (int i = 0; i <= l2; i++){
        j = 0;
        while(infoFile[i] == message[j]){
            count++;
            i++;
            j++;
        }

        if (count == l1){
            saver[savercounter] = i-l1;
            savercounter++;
            count = 0;
        } else {
            count = 0;
        }
    }
    if (savercounter == 0){
        printf("-1\n");
        return;
    }
    if (num > savercounter){
        printf("-1\n");
        return;
    } else {
        printf("%d\n", saver[num-1]);
        return;
    }
}

void atbywordstr(char message[100], char infoFile[10000], int num){
    int l1, l2, j;
    int count = 0;
    int words = 1;
    int saver[100];
    int savercounter = 0;
    l1 = strlen(message);
    l2 = strlen(infoFile);
    for (int i = 0; i <= l2; i++){
        j = 0;
        while(infoFile[i] == message[j]){
            count++;
            i++;
            j++;
        }

        if (count == l1){
            saver[savercounter] = i-l1;
            savercounter++;
            count = 0;
        } else {
            count = 0;
        }
    }
    if (savercounter == 0){
        printf("-1\n");
        return;
    }
    if (num > savercounter){
        printf("-1\n");
        return;
    } else {
        for (int i = 0; i < saver[num-1]; i++){
            if (infoFile[i] == ' ' || infoFile[i] == '\n'){
                words++;
            }
        }
        printf("%d\n", words);
        return;
    }
}



bool match(char* first, char* second)     //https://www.geeksforgeeks.org/wildcard-character-matching/ 
{
    // If we reach at the end of both strings, we are done
    if (*first == '\0' && *second == '\0')
        return true;
 
    // Make sure to eliminate consecutive '*'
    if (*first == '*') {
        while (*(first + 1) == '*')
            first++;
    }
 
    // Make sure that the characters after '*' are present
    // in second string. This function assumes that the
    // first string will not contain two consecutive '*'
    if (*first == '*' && *(first + 1) != '\0'
        && *second == '\0')
        return false;
 
    // If the first string contains '?', or current
    // characters of both strings match
    if (*first == '?' || *first == *second)
        return match(first + 1, second + 1);
 
    // If there is *, then there are two possibilities
    // a) We consider current character of second string
    // b) We ignore current character of second string.
    if (*first == '*')
        return match(first + 1, second)
               || match(first, second + 1);
    return false;
}
 
// A function to run test cases
int test(char* first, char* second)
{
    if (match(first, second)){
        return 1;
    } else {
        return 0;
    }
}


void findwildcard(char *infoFile1, char *infoFile, char **wordsaver, int counter1, char *message){
    int javab;
    char c3 = getchar();
    if (c3 == '\n'){
        for (int j = 0; j <= counter1; j++){
            javab = test(message, wordsaver[j]);
            if (javab){
                char *pos = strstr(infoFile, wordsaver[j]);
                printf("%d\n", pos-infoFile);
                return;
            }
        }
        printf("-1\n");
    } else if(c3 == ' '){
        scanf("-");
        char options[50];
        gets(options);
        for (int i = 0; i < strlen(options); i++){
            if (options[i] == ' '){
                for (int j = i; j < strlen(options); j++){
                    options[j] = options[j+1];
                }
            }
        }
        if (!strcmp(options, "count")){
            int count = 0;
            for (int j = 0; j <= counter1; j++){
            javab = test(message, wordsaver[j]);
                if (javab){
                    char *pos = strstr(infoFile, wordsaver[j]);
                    if (pos){
                        count++;
                    }
                }
            }
            printf("%d\n", count);  
        } else if (!strcmp(options, "byword")){
            int word = 1;
            for (int j = 0; j <= counter1; j++){
            javab = test(message, wordsaver[j]);
                if (javab){
                    char *pos = strstr(infoFile, wordsaver[j]);
                    for (int i = 0; i <= pos-infoFile; i++){
                        if(infoFile[i] == ' '){
                            word++;
                        }
                    }
                    printf("%d\n", word);
                    word = 0;
                    return;
                } 
            }
            printf("-1\n");
        } else if(!strcmp(options, "all")){
            int counter = 0;
            for (int j = 0; j <= counter1; j++){
                javab = test(message, wordsaver[j]);
                if (javab){
                    char *pos = strstr(infoFile, wordsaver[j]);
                    printf("%d, ", pos-infoFile);
                    infoFile[pos-infoFile] = '$';
                    counter++;
                }
            }
            if (counter == 0){
                printf("-1");
            }
            printf("\n");
        } else if((!strcmp(options, "all-byword")) || (!strcmp(options, "byword-all"))){
            int word = 1;
            int counter = 0;
            for (int j = 0; j <= counter1; j++){
                javab = test(message, wordsaver[j]);
                if (javab){
                    char *pos = strstr(infoFile, wordsaver[j]);
                    for (int i = 0; i <= pos-infoFile; i++){
                        if(infoFile[i] == ' '){
                            word++;
                        }
                    }
                    printf("%d, ", word);
                    infoFile[pos-infoFile] = '$';  //This is check if the words we are looking for have been repeated before
                    word = 1; 
                    counter++;   
                } 
            }
            if(counter == 0){
                printf("-1");
            } 
            printf("\n");
        } else if (!strstr("at", options) && !(strstr("byword", options))){
            if (strstr(options, "-all")){
                printf("Invalid command\n");
                return;
            }
            int index;
            int index1;
            for (int i = 0; i < strlen(options); i++){ //All of this until next 'else' is used to extract the number from the at option
                if (options[i] == 'a' && options[i+1] == 't'){
                    index = i+2; 
                    break;         
                }
            }
            int flag = 0;
            for (int i = index; i < strlen(options); i++){
                if (options[i] >= 49 && options[i] <= 57){
                    flag++;
                }
            }
            int num = 0; 
            int power = flag-1;
            for (int i = index; i < index+flag; i++){
                num += (options[i]-48)*pow(10, power);
                power--;
            }
            
            int * saver = (int *)malloc(50);
            int poscounter = 0;
            int index2 =0;
            int negah = 0;
            char * pos;
            for (int j = 0; j <= counter1; j++){ //This is to save the index of the required pattern
                javab = test(message, wordsaver[j]);
                if (javab){
                    pos = strstr(infoFile, wordsaver[j]);
                    if (pos+1){
                        negah++;
                    }
                    poscounter++;
                    infoFile[pos-infoFile] = '&'; //This is check if the words we are looking for have been repeated before
                    if (poscounter == num){
                        index2 = pos-infoFile;
                        break;
                    }
                }
            }
            
            int word = 1;
            if (index2 != 0 && index2 < strlen(infoFile) && index2 > 0){
                for (int i = 0; i <= index2; i++){ //This is where indices are turned to words
                    if (infoFile[i] == ' '){
                        word++;
                    }
                }
                printf("%d", word);
                printf("\n");
                return;
            } else if (index2 == 0 && pos < infoFile+strlen(infoFile) && pos > infoFile){
                printf("1\n");
            }

            if(negah == 0){
                printf("-1\n");
                return;
            }
        } else {
            printf("Invalid options");
        }
    }            
}

void findcomplex(char *infoFile , char **wordsaver, char ** messagesaver, int counter4, int counter1, char * message, char * message1, int indextolook, int wordsbefore, int wordsafter){
    int javab;
    char c = getchar();
    int flag = 0;
    int flag1 = 1;
    int flag2 = 1;
    int cursor = 0;
    if (c == '\n'){
        for (int j = 0; j <= counter1; j++){
            javab = test(messagesaver[indextolook], wordsaver[j]);
            if (javab){             
                if (j - wordsbefore < 0){
                    goto h;
                }
                if (j + wordsafter > counter1){
                    goto h;
                }
                for (int p = wordsbefore; p > 0; p--){
                    if (!strcmp(messagesaver[p-1], wordsaver[j-flag1])){
                        flag1++;
                        flag++;   
                    } else {
                        goto h;
                    }
                }

                for (int q = indextolook+1; q <= counter4; q++){
                    if (!strcmp(messagesaver[q], wordsaver[j+flag2])){
                        flag2++;
                        flag++;
                    } else {
                        goto h;
                    }
                }
                h:
                if (flag == wordsbefore+wordsafter){
                    char * pos;
                    if (wordsbefore == 0){
                        pos = strstr(infoFile+cursor, wordsaver[j]);
                    } else {
                        pos = strstr(infoFile+cursor, messagesaver[0]);
                    }
                    printf("%d\n", pos-infoFile);
                    return;
                } 
                
                flag1 = 1;
                flag2 = 1;
                flag = 0;
            }
            if (j >= wordsbefore){
                cursor += strlen(wordsaver[j-wordsbefore])+1;    
            }
        }
        printf("-1\n");
        return;
    } else if (c == ' '){
        scanf("-");
        char options[50];
        gets(options);
        for (int i = 0; i < strlen(options); i++){
            if (options[i] == ' '){
                for (int j = i; j < strlen(options); j++){
                    options[j] = options[j+1];
                }
            }
        }
        if (!strcmp(options, "count")){
            int count = 0;
            for (int j = 0; j <= counter1; j++){
                javab = test(messagesaver[indextolook], wordsaver[j]);
                if (javab){      
                    if (j - wordsbefore < 0){
                        goto k;
                    }      
                    if (j + wordsafter > counter1){
                    goto k;
                    }       
                    for (int p = wordsbefore; p > 0; p--){
                        if (!strcmp(messagesaver[p-1], wordsaver[j-flag1])){
                            flag1++;
                            flag++;
                        } else {
                            goto k;
                        }
                    }
                    
                    for (int q = indextolook+1; q < counter4; q++){
                        if (!strcmp(messagesaver[q], wordsaver[j+flag2])){
                            flag2++;
                            flag++;
                        } else {
                            goto k;
                        }
                    }
                    k:
                
                    if (flag == wordsbefore+wordsafter){
                        count++; 
                    }

                    flag1 = 1;
                    flag2 = 1;
                    flag = 0;
                }   
            }
            printf("%d\n", count);
        } else if (!strcmp(options, "byword")){
            for (int j = 0; j <= counter1; j++){
            javab = test(messagesaver[indextolook], wordsaver[j]);
            if (javab){   
                if (j - wordsbefore < 0){
                    goto g;
                } 
                if (j + wordsafter > counter1){
                    goto g;
                }      
            
                for (int p = wordsbefore; p > 0; p--){
                    if (!strcmp(messagesaver[p-1], wordsaver[j-flag1])){
                        flag1++;
                        flag++;
                    } else {
                        goto g;
                    }
                }
                
                for (int q = indextolook+1; q <= counter4; q++){
                    if (!strcmp(messagesaver[q], wordsaver[j+flag2])){
                        flag2++;
                        flag++;
                        
                    } else {
                        goto g;
                    }
                }
                g:
                
                if (flag == wordsbefore+wordsafter){
                    int word = 1;
                    int checker = 0;
                    char * pos;
                    
                    if (wordsbefore == 0){
                        pos = strstr(infoFile+cursor, wordsaver[j]);
                    } else {
                        pos = strstr(infoFile+cursor, messagesaver[0]);
                    }
                    
                    for (int i = 0; i <= pos-infoFile; i++){
                        if (infoFile[i] == ' '){
                            word++;
                            
                        }
                    }    
                    
                    if (pos >= infoFile && pos < infoFile+strlen(infoFile)){
                        printf("%d\n", word);
                        word = 1;
                    } else {
                        printf("-1\n");
                    }
                    return;
                } 
                
                flag1 = 1;
                flag2 = 1;
                flag = 0;
            }
                if (j >= wordsbefore){
                    cursor += strlen(wordsaver[j-wordsbefore])+1;    
                }
            }
        } else if (!strcmp(options, "all")){
            int checker = 0;
            for (int j = 0; j <= counter1; j++){
            javab = test(messagesaver[indextolook], wordsaver[j]);
            if (javab){     
                if (j - wordsbefore < 0){
                    goto f;
                }     
                if (j + wordsafter > counter1){
                    goto f;
                }
                for (int p = wordsbefore; p > 0; p--){
                    if (!strcmp(messagesaver[p-1], wordsaver[j-flag1])){
                        flag1++;
                        flag++;
                        
                    } else {
                        goto f;
                    }
                }
                
                for (int q = indextolook+1; q <= counter4; q++){
                    if (!strcmp(messagesaver[q], wordsaver[j+flag2])){
                        flag2++;
                        flag++;
                    } else {
                        goto f;
                    }
                }
                f:
                if (flag == wordsbefore+wordsafter){
                    int word = 1;
                    char * pos;
                    if (wordsbefore == 0){
                        pos = strstr(infoFile+cursor, wordsaver[j]);
                    } else {
                        pos = strstr(infoFile+cursor, messagesaver[0]);
                    }
                    printf("%d\n", pos-infoFile);
                    checker++;
                } 
                
                flag1 = 1;
                flag2 = 1;
                flag = 0;
            }
                if (j >= wordsbefore){
                    cursor += strlen(wordsaver[j-wordsbefore])+1;    
                }
            }
            if (checker == 0){
                printf("-1\n");
            }
        } else if (!strcmp(options, "byword-all") || !strcmp(options, "all-byword")){
            int checker = 0;
            for (int j = 0; j <= counter1; j++){
            javab = test(messagesaver[indextolook], wordsaver[j]);
            if (javab){  
                if (j - wordsbefore < 0){
                    goto e;
                }  
                if (j + wordsafter > counter1){
                    goto e;
                }      
                for (int p = wordsbefore; p > 0; p--){
                    if (!strcmp(messagesaver[p-1], wordsaver[j-flag1])){
                        flag1++;
                        flag++;
                        
                    } else {
                        goto e;
                    }
                }
                
                for (int q = indextolook+1; q <= counter4; q++){
                    if (!strcmp(messagesaver[q], wordsaver[j+flag2])){
                        flag2++;
                        flag++;
                    } else {
                        goto e;
                    }
                }
                e:
                if (flag == wordsbefore+wordsafter){
                    int word = 1;
                    checker++;
                    char * pos;
                    if ( wordsbefore == 0){
                        pos = strstr(infoFile+cursor, wordsaver[j]);
                    } else {
                        pos = strstr(infoFile+cursor, messagesaver[0]);
                    }
                    for (int i = 0; i <= pos-infoFile; i++){
                        if (infoFile[i] == ' '){
                            word++;
                        }
                    }    
                    if (checker != 0){
                        printf("%d\n", word);
                        word = 1;
                    }
                }  
                flag1 = 1;
                flag2 = 1;
                flag = 0;
            }
                if (j >= wordsbefore){
                    cursor += strlen(wordsaver[j-wordsbefore])+1;    
                }
            }
            if (checker == 0){
                printf("-1\n");
            }
        } else if (!strstr("at", options) && !(strstr("byword", options))){
            if (strstr(options, "-all")){
                printf("Invalid command\n");
                return;
            }
            int index;
            int index1;
            for (int i = 0; i < strlen(options); i++){ //All of this until next 'else' is used to extract the number from the at option
                if (options[i] == 'a' && options[i+1] == 't'){
                    index = i+2; 
                    break;         
                }
            }
            int flag = 0;
            for (int i = index; i < strlen(options); i++){
                if (options[i] >= 49 && options[i] <= 57){
                    flag++;
                }
            }
            int num = 0; 
            int power = flag-1;
            for (int i = index; i < index+flag; i++){
                num += (options[i]-48)*pow(10, power);
                power--;
            }
            flag = 0;
            int checker = 0;
            for (int j = 0; j <= counter1; j++){
            javab = test(messagesaver[indextolook], wordsaver[j]);
            if (javab){          
                if (j - wordsbefore < 0){
                    goto t;
                }
                if (j + wordsafter > counter1){
                    goto t;
                }
                for (int p = wordsbefore; p > 0; p--){
                    if (!strcmp(messagesaver[p-1], wordsaver[j-flag1])){
                        flag1++;
                        flag++;
                        
                    } else {
                        goto t;
                    }
                }
                
                for (int q = indextolook+1; q <= counter4; q++){
                    if (!strcmp(messagesaver[q], wordsaver[j+flag2])){
                        flag2++;
                        flag++;
                    } else {
                        goto t;
                    }
                }
                t:
                if (flag == wordsbefore+wordsafter){
                    int word = 1;
                    checker++;
                    char * pos;
                    if ( wordsbefore == 0){
                        pos = strstr(infoFile+cursor, wordsaver[j]);
                    } else {
                        pos = strstr(infoFile+cursor, messagesaver[0]);
                    }

                    if (checker == num){
                        for (int i = 0; i <= pos-infoFile; i++){
                            if (infoFile[i] == ' '){
                                word++;
                            }
                        }    
                        printf("%d\n", word);
                        return;
                    } else {

                    }
                }  
                flag1 = 1;
                flag2 = 1;
                flag = 0;
            }
                if (j >= wordsbefore){
                    cursor += strlen(wordsaver[j-wordsbefore])+1;    
                }
            }
            if (checker < num){
                printf("-1\n");
            }
        } else {
            printf("Invalid options\n");
        }
    }
}

void findstr(){
    int counter = 0;
    FILE *fptr;
    char c;
    scanf(" ");
    char c1;
    char *message = (char*)malloc(100*sizeof(char));
    c1 = getchar();
    message[0] = c1; //This is to get the string that we want to insert
    int counter2 = 1; //This counter is used to get command
    if (c1 != '"'){
        while(1){
            c1 = 0;
            c1 = getchar();
            *(message+counter2) = c1;
            counter2++;
            if( c1 == ' '){
                break;
            }
        } 
        message[counter2-1] = '\0';
    } else {
        while(1){
            c1 = 0;
            c1 = getchar();
            *(message+counter2) = c1;
            counter2++;
            if( c1 == '"' && message[counter2-2] != '\\'){
                break;
            }
        }
    }
    message[counter2] = '\0';
    

    for (int i = 0; i < strlen(message); i++){
        if (message[i] == ' ' && message[0] != '"'){
            printf("Invalid Input\n");
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        counter = 0;
        return;
        }
    }
    int flag1 = 0;
    scanf(" --file ");
    char folder[50];
    scanf("%s", folder);
    char *folder2 = (char*)malloc(50); 
    char *folder1 = strtok(folder, "/");
    while (folder1 != NULL){
        if (chdir(folder1) == -1){
            flag1++;
            if (flag1 >= 2){
                printf("Wrong Directory\n");
                for (int i = counter; i > 1; i--){
                    chdir("..");
                }
                return;
            }
        }
        counter++;
        folder2 = folder1;
        folder1 = strtok(NULL, "/");
    }

    if (message[0] == '"'){ //This part is to shift all the characters back one place
        message[strlen(message)-1] = '\0';
        for (int i = 0; i < strlen(message); i++){
            message[i] = message[i+1];
        }
    }
    
    
    for (int i = 1; i < strlen(message); i++){
        if (message[i] == '\\'){
            if (message[i+1]  == '"'){
                message[i] = '"';
                for(int j = i; j < strlen(message); j++){
                    message[j] = message[j+1];
                }
            }
        }
    }
    

    char infoFile[10000];
    if ((fptr = fopen(folder2, "rb")) == NULL){                //This part is made to see what is inside the file
        printf("File does not exist\n");
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        counter = 0;
        return;    
    } else {
        char ch2; //This copies the data inside the file
        int i = 0;
        ch2 = fgetc(fptr);
        infoFile[0] = ch2;
        while(ch2 != EOF){
            i++;
            ch2 = fgetc(fptr);
            infoFile[i] = ch2;
        }
        infoFile[i+1] = '\0';
    }
    fclose(fptr);
    

    char *infoFile1 = (char*)malloc(1000*1000*sizeof(char));
    for (int i = 0; i < strlen(infoFile); i++){
        infoFile1[i] = infoFile[i];
    }

    char **wordsaver = (char **)malloc((1000)*(1000)*(sizeof(char*)));
    for (int i = 0; i < 1000; i++){
        *(wordsaver+i) = (char *)malloc(sizeof(char)*(1000));
    }

    char *word = (char*)malloc(50);
    word = strtok(infoFile1, " ");
    int counter1 = 0; //This is to check where to store the address;
    while (word != NULL){ //This is to save the addresses
        wordsaver[counter1] = word;
        counter1++;
        word = strtok(NULL, " ");
    }
   

    int javab;
    int flag = 0;
    for (int i = 0; i < strlen(message); i++){
        if (message[i] == '*' && message[i-1] != '\\'){
            for (int j = 0; j < strlen(message); j++){
                if (message[j] == ' '){ 
                    flag++;
                }
            }
            if (flag == 0){
                findwildcard(infoFile1, infoFile, wordsaver, counter1, message);
                for (int i = counter; i > 1; i--){
                chdir("..");
                }
                counter = 0;
                return;
            }
        }
    }
    
    char message1[1000];
    for (int i = 0 ; i < strlen(message); i++){
        message1[i] = message[i];
    }

    char **messagesaver = (char **)malloc((1000)*(1000)*(sizeof(char*)));
    for (int i = 0; i < 1000; i++){
        *(messagesaver+i) = (char *)malloc(sizeof(char)*(1000));
    }

    word = strtok(message1, " ");
    int counter4 = 0; //This is to check where to store the address;
    while (word != NULL){ //This is to save the addresses
        messagesaver[counter4] = word;
        counter4++;
        word = strtok(NULL, " ");
    }
    
    int indextolook;
    int wordsbefore ;
    int wordsafter;
    for (int i = 0; i <= counter4; i++){
        for (int j = 0; j < strlen(messagesaver[i]); j++){
            if (messagesaver[i][j] == '*'){
                indextolook = i;
                wordsbefore = i;
                wordsafter = counter4 - i -1;
                goto y;
            }
        }
    }
    y:
    
    for (int i = 0; i < strlen(message); i++){
        if (message[i] == '*' && message[i-1] != '\\'){
            for (int j = 0; j < strlen(message); j++){
                if (message[j] == ' '){
                    findcomplex(infoFile, wordsaver, messagesaver, counter4, counter1, message, message1, indextolook, wordsbefore, wordsafter);
                    for (int i = counter; i > 1; i--){
                        chdir("..");
                    }
                    counter = 0;
                    return;
                }
            }
        }
    }

    int counter3 = 0; //This is to check for *
    for (int i = 0; i < strlen(message); i++){
        if (message[i] == '\\'){
            counter3++;
            if (message[i+1] == '*' && counter3 == 1){
                for (int j = i; j < strlen(message); j++){
                    message[j] = message[j+1];
                }
                counter3 = 0;
            }
        }
    }

    char c3 = getchar();
    if (c3 == '\n'){ 
    char *pos = strstr(infoFile, message);
    int line = 1;
    if (pos){ //This is to check which line my position is located
        for (int i = 0; i < (pos-infoFile); i++){
            if (infoFile[i] == '\n'){
                line++;
            }
        }
        int flag1 = 1;
        int place = 0;
        for (int i = 0; i < (pos-infoFile); i++){ //This is to find the position of the line we are trying to get to
            if (infoFile[i] == '\n'){
                flag1++;
            }
            if (flag1 == line){
                place = i;
                break;
            }
        }
        if (line == 1){ //This is done to prevent the addition of an extra line because line one is an exception
            place -= 1;
        }
        int cursor = (pos-infoFile)-place-1; //This is where the absolute position is printed
        printf("%d:%d\n", line, cursor);
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        return;
    } else {
        printf("-1\n");
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        return;
    }
    } else if ( c3 == ' '){
        scanf("-");
        char options[50];
        gets(options);
        for (int i = 0; i < strlen(options); i++){
            if (options[i] == ' '){
                for (int j = i; j < strlen(options); j++){
                    options[j] = options[j+1];
                }
            }
        }
        if (!strcmp(options, "count")){
            countstr(message, infoFile);
            for (int i = counter; i > 1; i--){
                chdir("..");
            }
        } else if ((!strcmp(options, "all-byword")) || (!strcmp(options, "byword-all"))){
            allstr(message, infoFile);
            for (int i = counter; i > 1; i--){
                chdir("..");
            } 
            } else if (!strcmp(options, "byword")){
                bywordstr(message, infoFile);
                for (int i = counter; i > 1; i--){
                    chdir("..");
                } 
        } else if (!strcmp(options, "all-byword-count") || !strcmp(options, "byword-all-count") || !strcmp(options, "byword-count-all") || !strcmp(options, "all-count-byword") || !strcmp(options, "count-byword-all") || !strcmp(options, "count-all-byword")){
                countstr(message, infoFile);
                allstr(message, infoFile);
                for (int i = counter; i > 1; i--){
                    chdir("..");
                }
        }else if (!strcmp(options, "count-byword") || !strcmp(options, "byword-count")) {
            countstr(message, infoFile);
            bywordstr(message, infoFile);
            for (int i = counter; i > 1; i--){
                    chdir("..");
            }
        } else if (!strstr("at", options)){
            if (strstr(options, "-all")){
                printf("Invalid command\n");
                for (int i = counter; i > 1; i--){
                    chdir("..");
                }
                counter = 0;
                return;
            }
            if (strstr(options, "byword")){
                int index;
                int index1;
                for (int i = 0; i < strlen(options); i++){ //All of this until next 'else' is used to extract the number from the at option
                    if (options[i] == 'a' && options[i+1] == 't'){
                        index = i+2; 
                        break;         
                    }
                }
                int flag = 0;
                for (int i = index; i < strlen(options); i++){
                    if (options[i] >= 49 && options[i] <= 57){
                        flag++;
                    }
                }
                int num = 0; 
                int power = flag-1;
                for (int i = index; i < index+flag; i++){
                    num += (options[i]-48)*pow(10, power);
                    power--;
                }
                if (strstr(options, "count")){
                    countstr(message, infoFile);
                }
                atbywordstr(message, infoFile, num);
                for (int i = counter; i > 1; i--){
                    chdir("..");
                }
            } else {
                int index;
                int index1;
                for (int i = 0; i < strlen(options); i++){ //All of this until next 'else' is used to extract the number from the at option
                    if (options[i] == 'a' && options[i+1] == 't'){
                        index = i+2; 
                        break;         
                    }
                }
                int flag = 0;
                for (int i = index; i < strlen(options); i++){
                    if (options[i] >= 49 && options[i] <= 57){
                        flag++;
                    }
                }
                int num = 0; 
                int power = flag-1;
                for (int i = index; i < index+flag; i++){
                    num += (options[i]-48)*pow(10, power);
                    power--;
                }
                if (strstr(options, "count")){
                    countstr(message, infoFile);
                }
                atstr(message, infoFile, num);
                for (int i = counter; i > 1; i--){
                    chdir("..");
                }
            }
            counter = 0;
        } else {
            char c; //All of this is made in order to print only one "invalid command"
            scanf("%c", &c);
            if (c == '\n'){
                goto x;
            }
            while(c!='\n')
                scanf("%c", &c);
            x:
            printf("Invalid command\n");
            c=0;
        }
    }
}

int occurence(char pattern[100], char infoFile[10000]){ // This site really helped, https://www.javatpoint.com/find-occurrence-of-substring-in-c-using-function
    int l1, l2, j;
    int count = 0;
    int count1 = 0;
    l1 = strlen(pattern);
    l2 = strlen(infoFile);
    for (int i = 0; i <= l2; i++){
        j = 0;
        while(infoFile[i] == pattern[j]){
            count++;
            i++;
            j++;
        }

        if (count == l1){
            count1++;
            count = 0;
        } else {
            count = 0;
        }
    }
    return count1;
}

int shomare(char pattern[100], char infoFile[10000], int num){ //This is to get the index of each occerence
    int l1, l2, j;
    int count = 0;
    int saver[100];
    int savercounter = 0;
    l1 = strlen(pattern);
    l2 = strlen(infoFile);
    for (int i = 0; i <= l2; i++){
        j = 0;
        while(infoFile[i] == pattern[j]){
            count++;
            i++;
            j++;
        }

        if (count == l1){
            saver[savercounter] = i-l1;
            savercounter++;
            count = 0;
        } else {
            count = 0;
        }
    }
    return saver[num-1];
}

void grepstr(){ //grep [options] --str <string> --files <addresses>
    int counter = 0; //This is for going inside files
    int counter2 = 1;
    FILE *fptr;
    char c1;
    char c;
    scanf(" -");
    char options[2] = {0};
    scanf("%c", &c);
    char * pattern = (char*)malloc(100*sizeof(char));
    if (c == '-'){
        scanf("str ");
        c1 = getchar();
        pattern[0] = c1; //This is to get the string that we want to insert
        int counter2 = 1; //This counter is used to get command
        if (c1 != '"'){
            while(1){
                c1 = 0;
                c1 = getchar();
                *(pattern+counter2) = c1;
                counter2++;
                if( c1 == ' '){
                    break;
                }
            } 
            pattern[counter2-1] = '\0';
        } else {
            while(1){
                c1 = 0;
                c1 = getchar();
                *(pattern+counter2) = c1;
                counter2++;
                if( c1 == '"' && pattern[counter2-2] != '\\'){
                    break;
                }
            }
        }
        pattern[counter2] = '\0';
    } else {
        char c2;
        options[0] = c;
        scanf(" -");
        c2 = getchar();
        if (c2 == '-'){
            scanf("str ");
            c1 = getchar();
            pattern[0] = c1; //This is to get the string that we want to insert
            int counter2 = 1; //This counter is used to get command
            if (c1 != '"'){
            while(1){
                c1 = 0;
                c1 = getchar();
                *(pattern+counter2) = c1;
                counter2++;
                if( c1 == ' '){
                    break;
                }
            } 
            pattern[counter2-1] = '\0';
            } else {
                while(1){
                    c1 = 0;
                    c1 = getchar();
                    *(pattern+counter2) = c1;
                    counter2++;
                    if( c1 == '"' && pattern[counter2-2] != '\\'){
                        break;
                    }
                }
            }
            pattern[counter2] = '\0';
        } else { 
            options[1] = c2;
            scanf(" --str ");
            c1 = getchar();
            pattern[0] = c1; //This is to get the string that we want to insert
            int counter2 = 1; //This counter is used to get command
            if (c1 != '"'){
            while(1){
                c1 = 0;
                c1 = getchar();
                *(pattern+counter2) = c1;
                counter2++;
                if( c1 == ' '){
                    break;
                }
            } 
            pattern[counter2-1] = '\0';
            } else {
                while(1){
                    c1 = 0;
                    c1 = getchar();
                    *(pattern+counter2) = c1;
                    counter2++;
                    if( c1 == '"' && pattern[counter2-2] != '\\'){
                        break;
                    }
                }
            }
            pattern[counter2] = '\0';
        }
    }


    for (int i = 0; i < strlen(pattern); i++){
        if (pattern[i] == ' ' && pattern[0] != '"'){
            printf("Invalid Input\n");
            return;
        }
    }


    for (int i = 1; i < strlen(pattern); i++){
        if (pattern[i] == '\\'){
            if (pattern[i+1]  == '"'){
                pattern[i] = '"';
                for(int j = i; j < strlen(pattern); j++){
                    pattern[j] = pattern[j+1];
                }
            }
        }
    }
    scanf(" --files");
    scanf(" ");
    char folders[1000];
    gets(folders);
    char **filesaver = (char **)malloc((1000)*(1000)*(sizeof(char*)));
    for (int i = 0; i < 1000; i++){
        *(filesaver+i) = (char *)malloc(sizeof(char)*(1000));
    }


    
    char *folder1 = strtok(folders, " ");
    int counter1 = 0; //This is to check where to store the address;

    while (folder1 != NULL){ //This is to save the addresses
        filesaver[counter1] = folder1;
        counter1++;
        folder1 = strtok(NULL, " ");
    }

    int coption = 0;
    int howmanyloption = 0;
    int flag4 = 0;
    for (int i = 0; i < counter1; i++){  
        char *folder2 = (char*)malloc(50); 
        char *folder3 = strtok(filesaver[i], "/");
        while (folder3 != NULL){
            if (chdir(folder3) == -1){
                flag4++;
                if (flag4 >= 2){
                    printf("Wrong Directory\n");
                    for (int i = counter; i > 1; i--){
                        chdir("..");
                    }
                    return;
                }
            }
            counter++;
            folder2 = folder3;
            folder3 = strtok(NULL, "/");
        }
    flag4 = 0;

    char *infoFile = (char *)malloc(10000*sizeof(char));
    if ((fptr = fopen(folder2, "rb")) == NULL){                //This part is made to see what is inside the file
        printf("File does not exist\n");
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        fclose(fptr);
        continue;    
    } else {
        char ch2; //This copies the data inside the file
        int f = 0;
        ch2 = fgetc(fptr);
        infoFile[0] = ch2;
        while(ch2 != EOF){
            f++;
            ch2 = fgetc(fptr);
            infoFile[f] = ch2;
        }
        fclose(fptr);
    }
    int howmany = occurence(pattern, infoFile);
    coption += howmany;
    if (howmany != 0){
        howmanyloption = 1;
    }
    int fback, lback;
    for (int j = 1; j <= howmany; j++){
        int place = shomare(pattern, infoFile, j);
        for (int k = place; k <= strlen(infoFile); k++){
            if (infoFile[k] == '\n' || infoFile[k] == '\0'){
                lback = k-1;
                break;
            }
        }

        for (int d = lback; d >= 0; d--){
            if (infoFile[d] == '\n'){
                fback = d+1;
                break;
            } else if (d == 0){
                fback = d;
                break;
            }
        }
        if (options[0] == 0){
            printf("%s: ", folder2);
            for(int h = fback; h <= lback; h++){
                printf("%c", infoFile[h]);
            }
            printf("\n");
        }
        

        if (options[0] == 'l' || options[1] == 'l'){
            for (int i = 0; i < howmanyloption; i++){
                printf("%s ", folder2);
                printf("\n");
                howmanyloption = 0;
            }
        }
    }
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        counter = 0;
    }
    if (options[0] == 'c' || options[1] == 'c'){
        printf("%d\n", coption);
        coption = 0;
    }
}


void comparatorfile(){ //moghayese --files <addresses>
    FILE * fptr;
    int counter = 0;
    char folders[1000];
    gets(folders);
    char **filesaver = (char **)malloc((1000)*(1000)*(sizeof(char*)));
    for (int i = 0; i < 1000; i++){
        *(filesaver+i) = (char *)malloc(sizeof(char)*(1000));
    }


    
    char *folder1 = strtok(folders, " ");
    int counter1 = 0; //This is to check where to store the address;

    while (folder1 != NULL){ //This is to save the addresses
        filesaver[counter1] = folder1;
        counter1++;
        folder1 = strtok(NULL, " ");
    }

    char **infoFile = (char **)malloc((10000)*(10000)*(sizeof(char*)));
    for (int i = 0; i < 1000; i++){
        *(infoFile+i) = (char *)malloc(sizeof(char)*(10000));
    }

    char **filesaver1= (char **)malloc((100)*(2)*(sizeof(char*)));
    for (int i = 0; i < 2; i++){
        *(infoFile+i) = (char *)malloc(sizeof(char)*(100));
    }


    for (int k = 0; k < 2; k++){  
        int flag4 = 0;
        char *folder2 = (char*)malloc(50); 
        char *folder3 = strtok(filesaver[k], "/");
        while (folder3 != NULL){
            if (chdir(folder3) == -1){
                flag4++;
                if (flag4 >= 2){
                    printf("Wrong Directory\n");
                    for (int i = counter; i > 1; i--){
                        chdir("..");
                    }
                    return;
                }
            }
            counter++;
            folder2 = folder3;
            folder3 = strtok(NULL, "/");
        }
    filesaver1[k] = folder2;
    if ((fptr = fopen(folder2, "rb")) == NULL){                //This part is made to see what is inside the file
        printf("File does not exist\n");
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        fclose(fptr);
        counter = 0;
        continue;    
    } else {
        char ch2; //This copies the data inside the file
        int f = 0;
        ch2 = fgetc(fptr);
        infoFile[k][0] = ch2;
        while(ch2 != EOF){
            f++;
            ch2 = fgetc(fptr);
            infoFile[k][f] = ch2;
        }
        
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        counter = 0;
        fclose(fptr);
    }
}  

    int line1 = 1;
    int line2 = 1;
    for (int j  = 0; j < strlen(infoFile[0]); j++){
        if (infoFile[0][j] == '\n'){
            line1++;
        }
    }

    for (int j  = 0; j < strlen(infoFile[0]); j++){
        if (infoFile[1][j] == '\n'){
            line2++;
        }
    }

    char **linesaver1 = (char **)malloc((10000)*(10000)*(sizeof(char*)));
    for (int i = 0; i < 1000; i++){
        *(linesaver1+i) = (char *)malloc(sizeof(char)*(10000));
    }

    char **linesaver2 = (char **)malloc((10000)*(10000)*(sizeof(char*)));
    for (int i = 0; i < 1000; i++){
        *(linesaver2+i) = (char *)malloc(sizeof(char)*(10000));
    }

    int shomar1 = 0; //This is to seperate the lines in the first file
    linesaver1[shomar1] = strtok(infoFile[0], "\n");
    while ( linesaver1[shomar1]!= NULL){
        shomar1++;
        linesaver1[shomar1] = strtok(NULL, "\n");
    }
    

    int shomar2 = 0; // This is to seperate the liens in the second line
    linesaver2[shomar2] = strtok(infoFile[1], "\n");
    while ( linesaver2[shomar2]!= NULL){
        shomar2++;
        linesaver2[shomar2] = strtok(NULL, "\n");
    }

    
    int khat;
    int khat1;
    if (shomar1 <= shomar2){
        khat = shomar1;
        khat1 = shomar2;
    } else {
        khat = shomar2;
        khat1 = shomar1;
    }


    for (int i = 0; i < khat; i++){
        if (strcmp(linesaver1[i], linesaver2[i])){
            printf("    compare %s %s\n", filesaver1[0], filesaver1[1]);
            printf("    ==========#%d===========\n", i+1);
            printf("%s\n", linesaver1[i]);
            printf("%s\n", linesaver2[i]);
        }
    }

    if (khat1 != khat){
        printf(">>>>>>>>>>>>> #%d - #%d >>>>>>>>>>>>>", khat+1, khat1);
        if (line1 > line2){
            printf(" %s\n", filesaver1[0]);
        } else {
            printf(" %s\n", filesaver1[1]);
        }
    }

    for (int i = khat; i < khat1; i++){
        if (line1 > line2){
            printf("%s\n", linesaver1[i]);
        } else {
            printf("%s\n", linesaver2[i]);
        }
    }

}

int slashshomarglobal = 0;
void treedepthcounter(char *basePath, const int root){ //https://codeforwin.org/c-programming/c-program-to-list-all-files-in-a-directory-recursively This website was used to make the tree
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            int slashshomar = -1;
            for (int i = 0 ; i < strlen(path); i++){
                if (path[i] == '/'){
                    slashshomar++;
                }
            }
            if (slashshomar > slashshomarglobal){
                slashshomarglobal  = slashshomar;
            }
            treedepthcounter(path, root + 2);
        }
    }
    closedir(dir);
}

void treedepth1(char *basePath, const int root, int depth){
    if (depth > slashshomarglobal || depth < -1 || depth == 0){
        printf("The entered depth does not exist\n");
        return;
        slashshomarglobal = 0;
    } else if (depth == -1) {
        int i;
        char path[1000];
        struct dirent *dp;
        DIR *dir = opendir(basePath);

        if (!dir)
            return;

        while ((dp = readdir(dir)) != NULL)
        {
            if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
            {
                for (i=0; i<root; i++) 
                {
                    if (i%2 == 0 || i == 0)
                        printf("%c", 179);
                    else
                        printf(" ");

               }

                printf("%c%c%s\n", 195, 196, dp->d_name);

                strcpy(path, basePath);
                strcat(path, "/");
                strcat(path, dp->d_name);
                treedepth1(path, root + 2, depth);
            
        }
    }
    closedir(dir);
    slashshomarglobal = 0;
    } 
}

void treedepth2(char *basePath, const int root, int depth){
    int i;
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            for (i=0; i<root; i++) 
            {
                if (i%2 == 0 || i == 0)
                    printf("%c", 179);
                else
                    printf(" ");

            }

            printf("%c%c%s\n", 195, 196, dp->d_name);

            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            int slashshomar = -1;
            for (int i = 0 ; i < strlen(path); i++){
                if (path[i] == '/'){
                    slashshomar++;
                }
            }
            if (slashshomar < depth){
                treedepth2(path, root + 2, depth);
            }
        }
    }
    slashshomarglobal = 0;
    closedir(dir);
}

int countreplace(char *message, char *infoFile, char *message1){
    char *infoFile1 = (char *)malloc(1000000);
    int l1, l2, j;
    int count = 0;
    int count1 = 0;
    l1 = strlen(message);
    l2 = strlen(infoFile);
    for (int i = 0; i <= l2; i++){
        j = 0;
        while(infoFile[i] == message[j]){
            count++;
            i++;
            j++;
        }

        if (count == l1){
            count1++;
            count = 0;
        } else {
            count = 0;
        }
    }
    return count1;
}

int atreplace(char*message, char *infoFile, int num){
    int l1, l2, j;
    int count = 0;
    int saver[100];
    int savercounter = 0;
    l1 = strlen(message);
    l2 = strlen(infoFile);
    for (int i = 0; i <= l2; i++){
        j = 0;
        while(infoFile[i] == message[j]){
            count++;
            i++;
            j++;
        }

        if (count == l1){
            saver[savercounter] = i-l1;
            savercounter++;
            count = 0;
        } else {
            count = 0;
        }
    }
    return saver[num-1];
}



void replacewildcard(char * infoFile, char * message, char * message1, int counter1, char * folder2, char **wordsaver){
    FILE *fptr;
    char * infoFile1 = (char *)malloc(1000000);
    char c3 = getchar();
    if (c3 == '\n'){
        char * pos;
        int index;
        for (int j = 0; j <= counter1; j++){
            int javab;
            javab = test(message, wordsaver[j]);
            if (javab){
                pos = strstr(infoFile, wordsaver[j]);
                j = index;
                break;
            }
        }
        
        int length;
        for (int i = pos-infoFile; i < strlen(infoFile); i++){
            if (infoFile[i] == ' '){
                length = i-(pos-infoFile);
                break;
            }
        }
        
        if (pos != NULL){
            for (int j = 0; j < pos-infoFile; j++){
                infoFile1[j] = infoFile[j];
            }
            
            for (int j = pos-infoFile; j <= pos-infoFile+strlen(message1); j++){
                infoFile1[j] = message1[j-(pos-infoFile)];
            }
            
            for (int j = pos-infoFile+strlen(message1); j < strlen(infoFile)+strlen(infoFile1); j++){
                infoFile1[j] = infoFile[j-strlen(message1)+length];
            }
            
            infoFile1[strlen(infoFile1)-1] = '\0';
            fptr = fopen(folder2, "wb");
            fputs(infoFile1, fptr);
            fclose(fptr);
            printf("Completed successfully\n");
        } else {
            printf("Did not find the pattern you were looking for\n");
        }
    } else if (c3 == ' '){
        scanf("-");
        char options[50];
        gets(options);
        for (int i = 0; i < strlen(options); i++){
            if (options[i] == ' '){
                for (int j = i; j < strlen(options); j++){
                    options[j] = options[j+1];
                }
            }
        }
        if (!strcmp(options, "all")){
            int index;
            char * pos;
            for (int j = 0; j <= counter1; j++){
                int javab;
                javab = test(message, wordsaver[j]);
                if (javab){
                    pos = strstr(infoFile, wordsaver[j]);
                    
                    int length;
                    for (int i = pos-infoFile; i < strlen(infoFile); i++){
                        if (infoFile[i] == ' '){
                            length = i-(pos-infoFile);
                            break;
                        }
                    }

                    for (int j = 0; j <= pos-infoFile; j++){
                    infoFile1[j] = infoFile[j];
                    }
            
                    for (int j = pos-infoFile; j <= pos-infoFile+strlen(message1); j++){
                        infoFile1[j] = message1[j-(pos-infoFile)];
                    }
            
                    for (int j = pos-infoFile+strlen(message1); j < strlen(infoFile)+strlen(infoFile1); j++){
                        infoFile1[j] = infoFile[j-strlen(message1)+length];
                    }
                    
                    infoFile[strlen(infoFile1)] = '\0';
                    for (int j = 0; j < strlen(infoFile1); j++){
                        infoFile[j] = infoFile1[j];
                    }
                }
            }
            infoFile1[strlen(infoFile1)-1] = '\0';
            fptr = fopen(folder2, "wb");
            fputs(infoFile1, fptr);
            fclose(fptr);
            printf("Completed successfully\n");
        } else if (!strstr("at", options)){
            if (strstr(options, "-all")){
                printf("Invalid command\n");
                return;
            } else {
                int index;
                int index1;
                for (int i = 0; i < strlen(options); i++){ //All of this until next 'else' is used to extract the number from the at option
                    if (options[i] == 'a' && options[i+1] == 't'){
                        index = i+2; 
                        break;         
                    }
                }
                int flag = 0;
                for (int i = index; i < strlen(options); i++){
                    if (options[i] >= 49 && options[i] <= 57){
                        flag++;
                    }
                }
                int num = 0; 
                int power = flag-1;
                for (int i = index; i < index+flag; i++){
                    num += (options[i]-48)*pow(10, power);
                    power--;
                }
                int **saver = (int **)malloc((sizeof(int*)));
                for (int i = 0; i < 50; i++){
                    *(saver+i) = (int *)malloc(sizeof(int));
                }
                
                int poscounter = 0;
                int index2 = 0;
                int negah = 0;
                char * pos;
                int javab;
                int cursor = 0;
                for (int j = 0; j <= counter1; j++){ //This is to save the index of the required pattern
                    javab = test(message, wordsaver[j]);
                    if (javab){
                        pos = strstr(infoFile+cursor, wordsaver[j]);
                        poscounter++;
                        cursor = 0;
                        for (int i = 0; i <= j; i++){
                            cursor += strlen(wordsaver[j])+1;
                        }
                        if (poscounter == num){
                            index2 = pos-infoFile;
                            break;
                        }
                    }
                }
                int length;
                for (int i = index2; i < strlen(infoFile); i++){
                    if (infoFile[i] == ' '){
                        length = i-(index2);
                        break;
                    }
                }

                for (int j = 0; j <= index2; j++){
                    infoFile1[j] = infoFile[j];
                }
            
                for (int j = index2; j <= index2+strlen(message1); j++){
                    infoFile1[j] = message1[j-(index2)];
                }
            
                for (int j = index2+strlen(message1); j < strlen(infoFile)+strlen(infoFile1); j++){
                    infoFile1[j] = infoFile[j-strlen(message1)+length];
                }
                
                infoFile1[strlen(infoFile1)-1] = '\0';
                fptr = fopen(folder2, "wb");
                fputs(infoFile1, fptr);
                fclose(fptr);
                printf("Completed successfully\n");
            }      
        } else {
            printf("Invalid option\n");
            return;
        }
    }
} 
  



void replacestr(){
    int counter = 0;
    FILE *fptr;
    char c;
    scanf(" ");
    char c1;
    char *message = (char*)malloc(100*sizeof(char));
    char *message1 = (char*)malloc(100*sizeof(char));
    c1 = getchar();
    message[0] = c1; //This is to get the string that we want to insert
    int counter2 = 1; //This counter is used to get command
    if (c1 != '"'){
        while(1){
            c1 = 0;
            c1 = getchar();
            *(message+counter2) = c1;
            counter2++;
            if( c1 == ' '){
                break;
            }
        } 
        message[counter2-1] = '\0';
    } else {
        while(1){
            c1 = 0;
            c1 = getchar();
            *(message+counter2) = c1;
            counter2++;
            if( c1 == '"' && message[counter2-2] != '\\'){
                break;
            }
        }
    }
    message[counter2] = '\0';

    for (int i = 0; i < strlen(message); i++){
        if (message[i] == ' ' && message[0] != '"'){
            printf("Invalid Input\n");
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        counter = 0;
        return;
        }
    }

    if (message[0] == '"'){ //This is to get rid of '"' and get the real message
        message[strlen(message)-1] = '\0';
        for (int i = 0; i < strlen(message); i++){
            message[i] = message[i+1];
        }   
    }


    scanf(" --str2 ");
    c1 = getchar();
    message1[0] = c1; //This is to get the string that we want to insert
    counter2 = 1; //This counter is used to get command
    if (c1 != '"'){
        while(1){
            c1 = 0;
            c1 = getchar();
            *(message1+counter2) = c1;
            counter2++;
            if( c1 == ' '){
                break;
            }
        } 
        message1[counter2-1] = '\0';
    } else {
        while(1){
            c1 = 0;
            c1 = getchar();
            *(message1+counter2) = c1;
            counter2++;
            if( c1 == '"' && message1[counter2-2] != '\\'){
                break;
            }
        }
    }
    message1[counter2] = '\0';
    
    for (int i = 0; i < strlen(message1); i++){
        if (message1[i] == ' ' && message1[0] != '"'){
            printf("Invalid Input\n");
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        counter = 0;
        return;
        }
    }

    if (message1[0] == '"'){ //This is to get rid of '"' and get the real message
        message1[strlen(message1)-1] = '\0';
        for (int i = 0; i < strlen(message1); i++){
            message1[i] = message1[i+1];
        }   
    }
    
    scanf(" --file");
    char folder[50];
    scanf("%s", folder);
    int length = strlen(folder);
    char backfolder [50];
    char backfolder1 [50];
    for (int i = 0; i < strlen(folder); i++){
        backfolder1[i] = '\0';
        backfolder[i] = '\0';
    }
    for (int i = 0; i < strlen(folder); i++){
        backfolder[i] = folder[i];
        backfolder1[i] = folder[i];
    }
    int flag = 0;
    char *folder2 = (char*)malloc(50); 
    char *folder1 = strtok(folder, "/");
    while (folder1 != NULL){
        if (chdir(folder1) == -1){
            flag++;
            if (flag == 2){
                printf("Wrong Directory\n");
                for (int i = counter; i > 1; i--){
                    chdir("..");
                }
                return;
            }
        }
        counter++;
        folder2 = folder1;
        folder1 = strtok(NULL, "/");
    }
    
    
    char * infoFile = (char *)malloc(10000000);
    char * infoFile1 = (char *)malloc(10000000);
    char * infoFile2 = (char *)malloc(10000000);
    if ((fptr = fopen(folder2, "rb")) == NULL){                //This part is made to see what is inside the file
        printf("File does not exist\n");
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        counter = 0;
        return;    
    } else {
        char ch2; //This copies the data inside the file
        int i = 0;
        ch2 = fgetc(fptr);
        infoFile[0] = ch2;
        while(ch2 != EOF){
            i++;
            ch2 = fgetc(fptr);
            infoFile[i] = ch2;
        }
        infoFile[i+1] = '\0';
    }
    fclose(fptr);

    for (int i = counter; i > 1; i--){
        chdir("..");
    }


    firstundo(infoFile, backfolder, backfolder1, length);



    for (int i = 1; i < strlen(message); i++){
        if (message[i] == '\\'){
            if (message[i+1]  == '"'){
                message[i] = '"';
                for(int j = i; j < strlen(message); j++){
                    message[j] = message[j+1];
                }
            }
        }
    }

    for (int i = 1; i < strlen(message1); i++){
        if (message1[i] == '\\'){
            if (message1[i+1]  == '"'){
                message1[i] = '"';
                for(int j = i; j < strlen(message1); j++){
                    message1[j] = message1[j+1];
                }
            }
        }
    }

    


    for (int i = 0; i < strlen(infoFile); i++){
        infoFile2[i] = infoFile[i];
    }

    char **wordsaver = (char **)malloc((1000)*(1000)*(sizeof(char*)));
    for (int i = 0; i < 1000; i++){
        *(wordsaver+i) = (char *)malloc(sizeof(char)*(1000));
    }

    char * word = (char *)malloc(50);
    word = strtok(infoFile2, " ");
    int counter1 = 0; //This is to check where to store the address;
    while (word != NULL){ //This is to save the addresses
        wordsaver[counter1] = word;
        counter1++;
        word =  strtok(NULL, " ");
    }
   

    int javab;

    for (int i = 0; i < strlen(message); i++){
        if (message[i] == '*' && message[i-1] != '\\'){
            replacewildcard(infoFile, message, message1, counter1, folder2, wordsaver);
            for (int i = counter; i > 1; i--){
                chdir("..");
            }
            counter = 0;
            return;
        }
    }


    int counter3 = 0; //This is to check for *
    for (int i = 0; i < strlen(message); i++){
        if (message[i] == '\\'){
            counter3++;
            if (message[i+1] == '*' && counter3 == 1){
                for (int j = i; j < strlen(message); j++){
                    message[j] = message[j+1];
                }
                counter3 = 0;
            }
        }
    }
    
    char c3 = getchar();
    if (c3 == '\n'){
        char *pos = strstr(infoFile, message);
        if (pos != NULL){
            for (int i = 0; i < pos-infoFile; i++){
                infoFile1[i] = infoFile[i];
            }
            
            for (int i = pos-infoFile; i <= pos-infoFile+strlen(message1); i++){
                infoFile1[i] = message1[i-(pos-infoFile)];
            }
            
            for (int i = pos-infoFile+strlen(message1); i < strlen(infoFile)+strlen(infoFile1); i++){
                infoFile1[i] = infoFile[i-strlen(message1)+strlen(message)];
            }
            infoFile1[strlen(infoFile1)-1] = '\0';
            fptr = fopen(folder2, "wb");
            fputs(infoFile1, fptr);
            fclose(fptr);
            printf("Completed successfully\n");
            for (int i = counter; i > 1; i--){
                chdir("..");
            }
            counter = 0;

        } else {
            printf("Did not find the pattern you are looking for\n");
            for (int i = counter; i > 1; i--){
                chdir("..");
            }
            counter = 0;
        }
    } else if (c3 == ' '){
        scanf("-");
        char options[50];
        gets(options);
        for (int i = 0; i < strlen(options); i++){
            if (options[i] == ' '){
                for (int j = i; j < strlen(options); j++){
                    options[j] = options[j+1];
                }
            }
        }
        if(!strcmp(options, "all")){
            int count;
            count  = countreplace(message, infoFile, message1);
                if (count != 0){
                    for (int i = 0; i < count; i++){
                    char *pos = strstr(infoFile, message);
                    for (int j = 0; j < pos-infoFile; j++){
                    infoFile1[j] = infoFile[j];
                    }
            
                    for (int j = pos-infoFile; j <= pos-infoFile+strlen(message1); j++){
                        infoFile1[j] = message1[j-(pos-infoFile)];
                    }
            
                    for (int j = pos-infoFile+strlen(message1); j < strlen(infoFile)+strlen(infoFile1); j++){
                        infoFile1[j] = infoFile[j-strlen(message1)+strlen(message)];
                    }
                
                    for (int j = 0; j < strlen(infoFile1); j++){
                        infoFile[j] = infoFile1[j];
                    }
                }
                infoFile1[strlen(infoFile1)-1] = '\0';
                fptr = fopen(folder2, "wb");
                fputs(infoFile1, fptr);
                fclose(fptr);
                printf("Completed succesfully\n");
                for (int i = counter; i > 1; i--){
                chdir("..");
                }
                counter = 0;
            } else {
                printf("Did not find any match\n");
                for (int i = counter; i > 1; i--){
                chdir("..");
                }
                counter = 0;
            }
        } else if (!strstr("at", options)){
            if (strstr(options, "-all")){
                printf("Invalid command\n");
                for (int i = counter; i > 1; i--){
                    chdir("..");
                }
                counter = 0;
                return;
            } else {
                int index;
                int index1;
                for (int i = 0; i < strlen(options); i++){ //All of this until next 'else' is used to extract the number from the at option
                    if (options[i] == 'a' && options[i+1] == 't'){
                        index = i+2; 
                        break;         
                    }
                }
                int flag = 0;
                for (int i = index; i < strlen(options); i++){
                    if (options[i] >= 49 && options[i] <= 57){
                        flag++;
                    }
                }
                int num = 0; 
                int power = flag-1;
                for (int i = index; i < index+flag; i++){
                    num += (options[i]-48)*pow(10, power);
                    power--;
                }
                int place = atreplace(message, infoFile, num);

                if (place >= 0 && place <strlen(infoFile)){
                    for (int j = 0; j < place; j++){
                        infoFile1[j] = infoFile[j];
                        }
            
                    for (int j = place; j <= place+strlen(message1); j++){
                        infoFile1[j] = message1[j-(place)];
                    }
            
                    for (int j = place+strlen(message1); j < strlen(infoFile)+strlen(infoFile1); j++){
                        infoFile1[j] = infoFile[j-strlen(message1)+strlen(message)];
                    }
                    infoFile1[strlen(infoFile1)-1] = '\0';
                    fptr = fopen(folder2, "wb");
                    fputs(infoFile1, fptr);
                    fclose(fptr);
                    printf("Completed succesfully\n");
                } else {
                    printf("Did not find what you were looking for\n");
                }
                for (int i = counter; i > 1; i--){
                chdir("..");
                }
                counter = 0;
            }
        } else {
            printf("Invalid options");
            for (int i = counter; i > 1; i--){
                chdir("..");
            }
            counter = 0;
        }
    }
}



void autoindent(){
    FILE * fptr;
    int counter = 0;
    int flag = 0;
    scanf(" ");
    char folder[50];
    scanf("%s", folder);
    char *folder2 = (char*)malloc(50); 
    char *folder1 = strtok(folder, "/");
    while (folder1 != NULL){
        if (chdir(folder1) == -1){
            flag++;
            if (flag == 2){
                printf("Wrong Directory\n");
                for (int i = counter; i > 1; i--){
                    chdir("..");
                }
                return;
            }
        }
        counter++;
        folder2 = folder1;
        folder1 = strtok(NULL, "/");
    }
    char * infoFile = (char *)malloc(10000000);
   
    if ((fptr = fopen(folder2, "rb")) == NULL){                //This part is made to see what is inside the file
        printf("File does not exist\n");
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        counter = 0;
        return;    
    } else {
        char ch2; //This copies the data inside the file
        int i = 0;
        ch2 = fgetc(fptr);
        infoFile[0] = ch2;
        while(ch2 != EOF){
            i++;
            ch2 = fgetc(fptr);
            infoFile[i] = ch2;
        }
        infoFile[i+1] = '\0';
    }
    fclose(fptr);
    
    int indexharf;
    int indexharf1;

    for (int i = 0; i < strlen(infoFile); i++){ //This is to make a space between the '{' and non-whitespace character if there is non
        if (infoFile[i] == '{' && infoFile[i-1] != ' ' && i != 0){
            for (int j = strlen(infoFile)-1; j > i-1; j--){
                infoFile[j+1] = infoFile[j];
            }
            infoFile[i] = ' ';
            i += 2;
        }
    }

    for (int i = 0 ; i < strlen(infoFile); i++){ //This is to get rid of the spaces between '{' and what comes after them
        if (infoFile[i] == '{'){
            for (int j = i+1; j < strlen(infoFile); j++){
                if (infoFile[j] != ' '){
                    indexharf = j;
                    break;
                }
            }
            
            for (int k = i+1; k < strlen(infoFile); k++){
                infoFile[k] = infoFile[k+indexharf-i-1]; 
            }
        }
    }


    for (int i = 0; i < strlen(infoFile); i++){ //This is to see if '{' is one space more to the right of a non-whitespace
        if (infoFile[i] == '{'){
            for (int k = i-1; i >= 0 ; k--){
                if (infoFile[k] != ' '){
                    indexharf1 = k;
                    break;
                }
            }
            if ((i - indexharf1) > 2){
                for (int j = indexharf1+2; j < strlen(infoFile); j++){
                    infoFile[j] = infoFile[j+i-indexharf1-2];
                }
            }
        }
    }

    
    int akolad = 0;

    for (int i = 0 ; i < strlen(infoFile); i++){ //This is to get rid of the spaces between '}' and what comes after them
        if (infoFile[i] == '}'){
            for (int j = i+1; j < strlen(infoFile); j++){
                if (infoFile[j] != ' '){
                    indexharf1 = j;
                    break;
                }
            }
            
            for (int k = i+1; k < strlen(infoFile); k++){
                infoFile[k] = infoFile[k+indexharf1-i-1]; 
            }
        }
    }

    int indexghabl;

    for (int i = 0 ; i < strlen(infoFile); i++){ //This is to get rid of the spaces between  the first'}' and what came before it
        if (infoFile[i] == '}'){
            for (int j = i-1; j >= 0; j--){
                if (infoFile[j] != ' '){
                    indexghabl = j;
                    break;
                }
            }
            for (int k = indexghabl+1; k < strlen(infoFile); k++){
                infoFile[k] = infoFile[k+i-indexghabl-1]; 
            }
        }
    }
    
    
    for (int i = 0 ; i < strlen(infoFile); i++){
        if (infoFile[i] == '{'){
            akolad++;
            for (int j = strlen(infoFile)-1; j > i; j--){
                infoFile[j+(akolad*4+1)] = infoFile[j];
            }
            infoFile[i+1] = '\n';
            for (int r = 2; r < akolad*4+2; r++){
                infoFile[r+i] = ' ';
            }
        } else if (infoFile[i] == '}'){
            akolad--;
            for (int j = i-1; j >= 0; j--){
                if (infoFile[j] != ' ' && infoFile[j] != '\n'){
                    indexghabl = j;
                    break;
                }
            }
            
            for (int a = strlen(infoFile)-1; a > indexghabl; a--){
                infoFile[a+(akolad*4+1)] = infoFile[a]; 
            }
            infoFile[indexghabl+1] = '\n';
            for (int r = 2; r < akolad*4+2; r++){
                infoFile[r+indexghabl] = ' ';
            }
            i += akolad*4+1;
        }
    }

    int akolad1 = 0;
    
    for (int i = 0; i < strlen(infoFile); i++){ //This is to check if there are any datas between '}'s
        if (infoFile[i] == '}' && infoFile[i+1] != '\n' && infoFile[i+1] != '}'){
            for (int k = i; k >= 0; k--){
                if (infoFile[k] == '{'){
                    akolad1++;
                } else if(infoFile[k] == '}'){
                    akolad1--;
                }
            }
            for (int j = strlen(infoFile)-1; j > i; j--){
                infoFile[j+(akolad1*4+1)] = infoFile[j];
            }
            infoFile[i+1] = '\n';
            for (int r = 2; r < akolad1*4+2; r++){
                infoFile[r+i] = ' ';
            }
            i += akolad1*4+1;
            akolad1 = 0;
        }
    }

    int indexhazfi = 0;
    for (int i = 0; i < strlen(infoFile); i++){ //This is to send back any '}' which has popped in front because there was a '{' before it
        if (infoFile[i] == '}'){
            for (int k = i-1; k >= 0; k--){
                if (infoFile[k] != ' ' && infoFile[k] != '\n'){
                    if (infoFile[k] == '{'){
                        for (int j = i-4; j < strlen(infoFile); j++){
                            infoFile[j] = infoFile[j+4];
                        }
                    } else {
                        break;
                    }
                    break;
                }
            }
        }
    }

    infoFile[strlen(infoFile)-1] = '\0';
    fptr = fopen(folder2, "wb");
    fputs(infoFile, fptr);
    fclose(fptr);


    for (int i = counter; i > 1; i--){
        chdir("..");
    }
    counter = 0;
}

void undostr(){
    FILE *fptr;
    int counter = 0;
    char c;
    scanf(" ");
    scanf("%c", &c); //Next line is to seperate the different ways to receive a command
    char folder[50];
    scanf("%s", folder);
    int length = strlen(folder);
    char backfolder [50];
    char backfolder1 [50];
    for (int i = 0; i < 50; i++){
        backfolder[i] = '\0';
        backfolder1[i] = '\0';
    }

    for (int i = 0; i < strlen(folder); i++){
        backfolder[i] = folder[i];
        backfolder1[i] = folder[i];
    }
    int flag = 0;
    char *folder2 = (char*)malloc(50); 
    char *folder1 = strtok(folder, "/");
    while (folder1 != NULL){
        if (chdir(folder1) == -1){
            flag++;
            if (flag == 2){
                printf("Wrong Directory\n");
                for (int i = counter; i > 1; i--){
                    chdir("..");
                }
                return;
            }
        }
        counter++;
        folder2 = folder1;
        folder1 = strtok(NULL, "/");
    }
    

    char * infoFile = (char *)malloc(1000000);
    char * infoFile1 = (char *)malloc(1000000);

    if ((fptr = fopen(folder2, "rb")) == NULL){                //This part is made to see what is inside the file
        printf("File does not exist\n");
        for (int i = counter; i > 1; i--){
            chdir("..");
        }
        return;    
    } else {
        char ch2; //This copies the data inside the file
        int i = 0;
        ch2 = fgetc(fptr);
        infoFile[0] = ch2;
        while(ch2 != EOF){
            i++;
            ch2 = fgetc(fptr);
            infoFile[i] = ch2;
        }
        infoFile[i] = '\0';
    }
    fclose(fptr);

    for (int i = counter; i > 1; i--){
        chdir("..");
    }

    for (int i = 2; i < strlen(backfolder); i++){
        if (backfolder[i] == '/'){
            for (int j = strlen(backfolder)-1; j >= i; j--){
                backfolder[j+1] = backfolder[j];
            }
            backfolder[i] = '1';
            break;
        }
    }
    backfolder[length+1] = '\0';

    char *folder3 = strtok(backfolder, "/");
    while (folder3 != NULL){
        chdir(folder3);
        folder3 = strtok(NULL, "/");
    }

    fptr = fopen(folder2, "rb");
    char ch1; //This copies the data inside the file
    int index = 0;
    ch1 = fgetc(fptr);
    infoFile1[0] = ch1;
    while(ch1 != EOF){
        index++;
        ch1 = fgetc(fptr);
        infoFile1[index] = ch1;
    }
        infoFile1[index] = '\0';
    fclose(fptr);

    fptr = fopen(folder2, "wb");
    fputs(infoFile, fptr);
    fclose(fptr);

    for(int i = counter; i > 1; i--){
        chdir("..");
    }

    char *folder4 = strtok(backfolder1, "/");
    while (folder4 != NULL){
        chdir(folder4);
        folder4 = strtok(NULL, "/");
    }

    fptr = fopen(folder2, "wb");
    fputs(infoFile1, fptr);
    fclose(fptr);

    for(int i = counter; i > 1; i--){
        chdir("..");
    }
    
}


int main(){
    char dastor [30];
    char file[] = "besaz--file";
    char cat[] = "bekhun--file";
    char exit[] = "exit";
    char insert[] = "berizstr--file";
    char remove[] = "hazfstr--file";
    char copy[] = "copystr--file";
    char cut[] = "beborstr--file";
    char paste[] = "bechasbunstr--file";
    char find[] = "begard--str";
    char grep[] = "grep";
    char comparator[] = "moghayese--files";
    char tree[] = "tree";
    char replace[] = "avazkon--str1";
    char closingpair []= "auto-indent--file";
    char undo [] = "undo--file";
    int counter1 = 0; //This counter is used to get out of dir in cat
    FILE * fptr;
    while(1){
    z:
    scanf("%s", dastor);   
    if(!strcmp(dastor, file)){
            createfile();
        } else if (!strcmp(dastor, exit)){
            break;
        } else if (!strcmp(dastor, cat)){
            catfile();   
        } else if (!strcmp(dastor, insert)){ //berizstr--file <address> --str <message> --posx:y
                scanf(" ");
                int counter11 = 0;
                int counter3 = 0; //This counter is used to get out of dir in insert
                char folder[50];
                scanf("%s", folder);
                char backfolder [50];
                char backfolder1 [50];
                for (int i = 0; i < strlen(folder); i++){
                    backfolder1[i] = '\0';
                    backfolder[i] = '\0';
                }
                for (int i = 0; i < strlen(folder); i++){
                backfolder[i] = folder[i];
                backfolder1[i] = folder[i];
                }
                int flag4 = 0;
                int length = strlen(folder);
                char *folder2 = (char*)malloc(50); 
                char *folder1 = strtok(folder, "/");
                while (folder1 != NULL){
                    if (chdir(folder1) == -1){
                        flag4++;
                        if (flag4 >= 2){
                            printf("Wrong Directory\n");
                            for (int i = counter3; i > 1; i--){
                                chdir("..");
                            }
                            goto z;
                        }
                    }
                    counter3++;
                    counter11++;
                    folder2 = folder1;
                    folder1 = strtok(NULL, "/");
                }
                scanf(" --str ");
                char c1;
                char *message = (char*)malloc(100*sizeof(char));
                c1 = getchar();
                message[0] = c1; //This is to get the string that we want to insert
                int counter2 = 1; //This counter is used to get command
                if (c1 != '"'){
                while(1){
                    c1 = 0;
                    c1 = getchar();
                    *(message+counter2) = c1;
                    counter2++;
                    if( c1 == ' '){
                        break;
                    }
                } 
                message[counter2-1] = '\0';
                } else {
                    while(1){
                        c1 = 0;
                        c1 = getchar();
                        *(message+counter2) = c1;
                        counter2++;
                        if( c1 == '"' && message[counter2-2] != '\\'){
                            break;
                        }
                    }
                }
                message[counter2] = '\0';
                
                scanf(" --pos");
                int line;
                int pos;
                scanf("%d:%d", &line, &pos);
                
                for (int i = 0; i < strlen(message); i++){
                    if (message[i] == ' ' && message[0] != '"'){
                        printf("Invalid Input\n");
                        goto z;
                    }
                }

                for (int i = 1; i < strlen(message); i++){
                    if (message[i] == '\\'){
                        if (message[i+1]  == '"'){
                            message[i] = '"';
                            for(int j = i; j < strlen(message); j++){
                                message[j] = message[j+1];
                            }
                        }
                    }
                }

                if (message[0] == '"'){ //This part is to shift all the characters back one place
                    message[strlen(message)-1] = '\0';
                    for (int i = 0; i < strlen(message); i++){
                        message[i] = message[i+1];
                    }
                }
    
                char c2;
                int counter4 = 0; //This counter is used to check for \n
                fptr = fopen(folder2, "r"); //This part is made to see what is inside the file
                char ch2;
                char *infoFile = (char *)malloc(10000*sizeof(char));
                int i = 0;
                ch2 = fgetc(fptr);
                infoFile[0] = ch2;
                while(ch2 != EOF){
                    i++;
                    ch2 = fgetc(fptr);
                    infoFile[i] = ch2;
                }
                infoFile[i+1] = '\0';
                fclose(fptr);
                
                for (int i = counter11; i > 1; i--){
                    chdir("..");
                }

                
                
                firstundo(infoFile, backfolder, backfolder1, length);

                fptr = fopen(folder2, "r+");
                if (fptr == NULL){ //This checks if the file exists
                        printf("File does not exist\n");
                        for (int i = counter3; i > 1; i--){
                            chdir("..");
                        }
                        counter3 = 0;
                        goto z;
                } else {  
                    fseek(fptr, 0, SEEK_END);     
                    int size;
                    size = ftell(fptr);
                    if ( size == 0){ //This is used to check if the file empty, then start the command
                        printf("This is an empty file and nothing can be inserted\n");
                        goto z;
                    } else {
                        int flag = 1; //This is to see how many \n are in the file
                        for (int i = 0; i < strlen(infoFile); i++){
                            if (infoFile[i] == '\n'){
                                flag++;
                            }
                        }
                        if (flag < line){ //This part checkes if the given position is below everything already in the file
                            printf("Your given position is more than the existing lines\n");
                            goto z;
                        } else {
                            int flag1 = 1;
                            int place = 0;
                            for (int i = 0; i < strlen(infoFile); i++){ //This is to find the position of the line we are trying to get to
                                if (infoFile[i] == '\n'){
                                    flag1++;
                                }
                                if (flag1 == line){
                                    place = i;
                                    break;
                                }
                            }
                            if (line == 1){ //This one is done to make sure that if the line is one, it is not added up to the position
                                line = 0;
                            }
                            fseek(fptr, place+pos+line, SEEK_SET);
                            int counter6 = 0; //This coutner is used to check for \n and \\n
                            for(int i = 0; i < strlen(message); i++){ //Here we are checking for \n and \\n
                            if (message[i] == '\\'){
                                counter6++;
                                if (message[i+1] == 'n' && counter6 == 1){
                                    fputs("\n", fptr);
                                    i++;
                                    counter6 = 0;
                                }
                                fprintf(fptr, "%c", message[i+1]);
                                i++;
                            } else {
                                fprintf(fptr, "%c", message[i]);
                            }
                            }
                            if (line+1 == 1){
                                for (int i = pos+place; i < strlen(infoFile)-1; i++){ //This part continues from where the message was started
                                    fprintf(fptr, "%c", infoFile[i]);
                                }
                            } else {
                                for (int i = pos+place+1; i < strlen(infoFile)-1; i++){
                                fprintf(fptr, "%c", infoFile[i]);
                            } 
                            }             
                        }
                    }
                    fclose(fptr);
                    for (int i = counter3; i > 1; i--){
                        chdir("..");
                    }
                    counter3 = 0;
                }  
        } else if (!strcmp(dastor, remove)){
            removestr();
        } else if (!strcmp(dastor, copy)){
            copystr();
        } else if (!strcmp(dastor, cut)){
            cutstr();
        } else if (!strcmp(dastor, paste)){
            pastestr();
        } else if (!strcmp(dastor, find)){
            findstr();
        } else  if (!strcmp(dastor, grep)){
            grepstr();
        } else if (!strcmp(dastor, comparator)){
            comparatorfile();
        } else if (!strcmp(dastor, tree)){
            scanf(" ");
            int depth;
            scanf("%d", &depth);
            char *basePath = (char *)malloc(100);
            
            printf("Please enter your path: ");
            scanf("%s", basePath);
            treedepthcounter(basePath, 0);
            if (depth > 0 && depth <= slashshomarglobal){
                treedepth2(basePath, 0, depth);
            } else {
                treedepth1(basePath, 0, depth);
            }
        } else if(!strcmp(dastor, replace)){
            replacestr();
        } else if (!strcmp(dastor, closingpair)){
            autoindent();
        } else if (!strcmp(dastor, undo)){
            undostr();
        } else {
            char c; //All of this is made in order to print only one "invalid command"
            scanf("%c", &c);
            if (c == '\n'){
                goto x;
            }
            while(c!='\n')
                scanf("%c", &c);
            x:
            printf("Invalid command\n");
            c=0;
        }
    }
}