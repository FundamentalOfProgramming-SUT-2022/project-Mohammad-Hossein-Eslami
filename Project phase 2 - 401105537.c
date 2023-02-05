//Mohammad Hossein Eslami ID:401105537
#include <stdio.h> 
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <form.h>
#define MAX 10000

int line = 0;
int col = 2;
int main(){
	
        char saver [1000][1000];
	int saverline = 0;
	int savercol = 0;
	int x = 0;
	int y = 0;
	int xv = 0;
	int yv = 0;
	initscr();
	mvprintw(0, 0, "%d", line+1);
	keypad(stdscr, TRUE);
	start_color();
        noecho();	
	cbreak();


	int c;


	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_WHITE);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
	init_pair(4, COLOR_RED, COLOR_WHITE);
	init_pair(5, COLOR_CYAN, COLOR_MAGENTA);
	refresh();
	char * mode = (char*)malloc(20);
	mode = "normal";
	char * commandline = (char *)malloc(1000);


	while (!strstr(commandline, "q")){
		attron(COLOR_PAIR(1));
                mvprintw(LINES-3, 0, "%s", mode);
                attroff(COLOR_PAIR(1));
		for (int i = LINES-line-1; i > 3; i--){
               	    mvprintw(LINES-i, 0, "~");
       		}
		

		if (c == 'i'){
		    for (int i = 0; i < strlen(mode); i++){
		    	mvprintw(LINES-3, i, " ");
		    }
		    mode = "insert";
		    attron(COLOR_PAIR(1));
		    mvprintw(LINES-3, 0, "%s", mode);
		    attroff(COLOR_PAIR(1));

		    int c1 = getch();
		    while (c1 != 27){
		    	if (c1 != '\n' && c1 != KEY_UP && c1 != KEY_DOWN && c1 != KEY_RIGHT && c1 != KEY_LEFT){
		            move(line, col);
			    printw("%c", c1);
                            saver[saverline][savercol] = c1;
			    savercol++;  
			    refresh();
			    col++;
			    c1 = getch();
			} else if ( c1 == '\n' && c1 != KEY_UP && c1 != KEY_DOWN && c1 != KEY_RIGHT && c1 != KEY_LEFT){
			    saver[saverline][savercol] = '\n';
			    col = 2;
			    savercol = 0;
			    line++;
			    saverline++;
			    move(line, col);
			    mvprintw(line, 0, "%d ", line+1);
			    move(line, col);
			    c1 = getch();
		            printw("%c", c1);
			    saver[saverline][savercol] = c1;
			    refresh();
		            col++;
			    savercol++;
		            c1 = getch();	    
			} else if (c1 == KEY_UP){

				move(line-1, col);
				c1 = getch();
				line -= 1;

			} else if (c1 == KEY_DOWN){

			   	 move(line+1, col);
			    	 c1 = getch();
				 line += 1;

			} else if (c1 == KEY_RIGHT){
			  
				move(line, col+1);
			    	c1 = getch();
				col += 1;

			} else if (c1 == KEY_LEFT){

			  	 move(line, col-1);
			  	 c1 = getch();
				 col -= 1;

			} 
 		    
		    }
		    refresh();
		    goto x;

		}

		if (c == 'v'){
		    for (int i = 0; i < strlen(mode); i++){
                        mvprintw(LINES-3, i, " ");
                    }

                    mode = "visual";
                    attron(COLOR_PAIR(1));
                    mvprintw(LINES-3, 0, "%s", mode);
                    attroff(COLOR_PAIR(1));
                    refresh();
		    int nav;
		    move(0, 0);
		    nav = getch();
		    while(nav != 27){
		    if (nav == KEY_UP){

                          move(yv-1, xv);
                                yv -= 1;

                        } else if (nav == KEY_DOWN){

                                 move(yv+1, xv);
                                 yv += 1;

                        } else if (nav == KEY_RIGHT){

                                move(yv, xv+1);
                                xv += 1;

                        } else if (nav == KEY_LEFT){

                                 move(yv, xv-1);
                                 xv -= 1;

                        }
		    nav = getch();

                }
			
		}
                 if (c == 27){
                    x:
                    for (int i = 0; i < strlen(mode); i++){
                        mvprintw(LINES-3, i, " ");
                    }
		    
                    mode = "normal"; 
		    
		    

                    attron(COLOR_PAIR(1));
                    mvprintw(LINES-3, 0, "%s", mode);
                    attroff(COLOR_PAIR(1));
                    refresh();
                }
		

		if (c == KEY_UP){
			if (y == 0){
				move(y, x);
			}
			move(--y,x);
		} 

		if (c == KEY_DOWN){
			if ( y == LINES - 4){
				move(y, x);
			}
			move(++y,x);
		}

		if (c == KEY_RIGHT){
			if (x == COLS){
				move(y, x);
			}
			move(y, ++x);
		}

		if (c == KEY_LEFT){
			if (x == 0){
				move(y, x);
			}
			move(y, --x);
		}
		

		
			
		if (c == ':'){
	            
		    move(LINES-2, 0);
		    for (int i = 0; i < strlen(commandline); i++){
		    	printw(" ");
		    
		    }
		    move(LINES-2, 0);
		    mvprintw(LINES-2, 0, ":");
		    char c2 = getch();
		    int counter1 = 1;
		    commandline[0] = c2;
		    printw("%c", c2);
		    while(c2 != '\n'){
	   		c2 = getch();			
			commandline[counter1] = c2;
			counter1++;
			if (c2 != 127){
			    printw("%c", c2);
			}
			
		    }
		    char folder [50];
		    for (int i = 0; i < strlen(folder); i++){
		    	folder[i] = '\0';
		    	
		    }
		    FILE * fptr;
		    int index;
		    if (strstr(commandline, "open--file:") != NULL){
			for (int i = 0; i < strlen(commandline); i++){
				if (commandline[i] == '/'){
					index = i;
				}
			}
			
			for (int  j = index+1; j < strlen(commandline); j++){
				folder[j-index-1] = commandline[j];
			}
			folder[strlen(folder)] = '\0';
			mvprintw(LINES-3, strlen(mode)+1, "%s", folder);
			char chsaver  = 1;
			int x = 2;
			int y = 0;
			int temp = 0;
			if (fptr = fopen(folder, "rb") != NULL){
			while(chsaver != EOF){
				if (temp == 0){
					mvprintw(x, 0, "%d", x+1);
					mvprintw(x, 1, "%s", " ");
				}

				chsaver = fgetc(fptr);
				mvprintw(x, y, "%c", chsaver);
				y++;
				temp = 1;
				if (chsaver== '\n'){
					temp = 0;
					x++;
					y = 2;
				}
			}
			fclose(fptr);
			} else {
				fptr = fopen(folder, "w");
				fclose(fptr);
			}
		    }
		    
		 } 
		y:
		c = getch();
	
	}
	refresh();
	endwin();
	return 0;
}
