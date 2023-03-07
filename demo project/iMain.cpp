# include "iGraphics.h"
#include <time.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>

int x = 300, y = 300, r = 20;
int isCalled=1;
int strIdx = -1;
char str[1000] = {0};
int user_guideline = 0;
int strIdx2 = -1;
char str1[1000] = {0};
int p=0;
int File_open = 1;
int music_call = 0;
int add_reminder=0;
int back_on =0;
int event_name_done=0;
int show_reminder = 0;
int hour,minute,day,month,year;
int time_on =0;
int time_count_down = 0;
int hours,minutes,days,months,years;
int dark_mood = 0;
int dark_mood_on=0;



void diff_hr_min() {

    char *token = strtok(str, "&/");
    token = strtok(NULL, "&/");
    day = atoi(token);
    token = strtok(NULL, "&/");
    month = atoi(token);
    token = strtok(NULL, "&/");
    year = atoi(token);
    token = strtok(NULL, "&:");
    hour = atoi(token);
    token = strtok(NULL, "&:");
    minute = atoi(token);

}

void music_func() {
    PlaySound("C:\\Users\\ASUS\\Downloads\\To Do Reminer Music.wav", NULL , SND_SYNC);
    time_on = 1;
}




void add_task(void) {
    FILE* fp;

    char filename[] = "Todos Reminder.txt";
    fp = fopen(filename, "a");
    fprintf(fp, str);
    fprintf(fp, "\n");
    fclose(fp);

}



void iDraw() {


	iClear();

	if(dark_mood_on == 1) {
        iSetColor(0,0,0);
	}

	if(dark_mood_on == 0) {

    iSetColor(5, 36, 37);

	}

    iFilledRectangle(0,0,500, 650);


	iSetColor(21, 57, 57);
	iFilledRectangle(50 , 550 , 160, 35);
	iSetColor(255,255,255);
	iText(58, 559, "Add Reminder", GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(21, 57, 57);
	iFilledRectangle(50 , 470 , 175, 35);
	iSetColor(255,255,255);
	iText(60, 478, "Show Reminder", GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(21, 57, 57);
	iFilledRectangle(50 , 400 , 160, 35);
	iSetColor(255,255,255);
	iText(55, 410, "User Guideline", GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(21, 57, 57);
	iFilledRectangle(50 , 330 , 150, 35);
	iSetColor(255,255,255);
	iText(68, 340, "Dark Mode", GLUT_BITMAP_TIMES_ROMAN_24);


	if(isCalled) {
        iText(20, 220, "Don't forget to set reminder for productivity!!",  GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if(dark_mood == 1) {
        iClear();

        if(dark_mood_on == 1) {
            iSetColor(0,0,0);
        }

        if(dark_mood_on == 0) {

        iSetColor(5, 36, 37);

        }

        iFilledRectangle(0,0,500, 650);

        iSetColor(0, 0 , 0);
        iFilledRectangle(193, 340, 90, 35);

        iSetColor(255, 255, 255);
        iText(225, 350, "On",  GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(21, 57 , 57);
        iFilledRectangle(193, 290, 90, 35);

        iSetColor(255, 255, 255);
        iText(213, 295, "OFF",  GLUT_BITMAP_TIMES_ROMAN_24);


         iSetColor(21, 57 , 57);
        iFilledRectangle(193, 140, 90, 35);

        iSetColor(255, 255, 255);
        iText(213, 148, "Back",  GLUT_BITMAP_TIMES_ROMAN_24);

        if(back_on) {
                iClear();
                dark_mood = 0;

                if(dark_mood_on == 1) {
                    iSetColor(0,0,0);
                }

                if(dark_mood_on == 0) {

                iSetColor(5, 36, 37);

                }

                iFilledRectangle(0,0,500, 650);


                iSetColor(21, 57, 57);
                iFilledRectangle(50 , 550 , 160, 35);
                iSetColor(255,255,255);
                iText(58, 559, "Add Reminder", GLUT_BITMAP_TIMES_ROMAN_24);

                iSetColor(21, 57, 57);
                iFilledRectangle(50 , 470 , 175, 35);
                iSetColor(255,255,255);
                iText(60, 478, "Show Reminder", GLUT_BITMAP_TIMES_ROMAN_24);

                iSetColor(21, 57, 57);
                iFilledRectangle(50 , 400 , 160, 35);
                iSetColor(255,255,255);
                iText(55, 410, "User Guideline", GLUT_BITMAP_TIMES_ROMAN_24);

                iSetColor(21, 57, 57);
                iFilledRectangle(50 , 330 , 150, 35);
                iSetColor(255,255,255);
                iText(68, 340, "Dark Mode", GLUT_BITMAP_TIMES_ROMAN_24);



                back_on=0;


            }


	}




	   struct tm* ptr;
       time_t t;
       t = time(NULL);
       ptr = localtime(&t);

       hours = ptr->tm_hour;
       minutes = ptr->tm_min;
       days = ptr->tm_mday;
       months = ptr->tm_mon;
       years = ptr->tm_year;


       if((hours == hour) && (minutes == minute) && (days == day) && ( (months+1)==month) && ( (years+1900) == year) ) {



        iText(100, 300, "Hurry Up! Your Event is now!", GLUT_BITMAP_TIMES_ROMAN_24);


        music_call++;


        if(music_call == 1) {
            music_func();

        }

    }


	if(show_reminder) {
        FILE* fp3;
        char filename[100] = "Todos Reminder.txt";
        fp3 = fopen(filename , "r" );

        char line[100];
        int y=0;

        if(dark_mood_on == 1) {
            iSetColor(0,0,0);
        }

        if(dark_mood_on == 0) {

            iSetColor(5, 36, 37);

        }

        iFilledRectangle(0,0,500, 650);

        iSetColor(255, 255,255);
        iText(50, 550, "Event Name", GLUT_BITMAP_TIMES_ROMAN_24 );
        iText(230, 550, "Date", GLUT_BITMAP_TIMES_ROMAN_24 );
        iText(370, 550, "Time", GLUT_BITMAP_TIMES_ROMAN_24);

        int i=1;
        int y_axis = 500;
        char *token;



        while(fgets(line , 100, fp3)) {

            char st_r[10];
            sprintf(st_r , "%d", i);
            iSetColor(255, 255,255);
            iText(43,y_axis, st_r, GLUT_BITMAP_TIMES_ROMAN_24 );
            iText(54, y_axis , "." , GLUT_BITMAP_TIMES_ROMAN_24) ;


            token = strtok(line, "&");
            iText(68, y_axis, token, GLUT_BITMAP_TIMES_ROMAN_24 );


            token = strtok(NULL , "&");
            iText(200, y_axis, token, GLUT_BITMAP_TIMES_ROMAN_24 );

            token = strtok(NULL , "&");
            iText(360, y_axis, token, GLUT_BITMAP_TIMES_ROMAN_24 );


            i++;
            y_axis-=40;


        }

        fclose(fp3);

        iSetColor(21, 57 , 57);
        iFilledRectangle(193, 140, 90, 35);

        iSetColor(255, 255, 255);
        iText(213, 148, "Back",  GLUT_BITMAP_TIMES_ROMAN_24);



            if(back_on) {
                iClear();
                show_reminder = 0;

                if(dark_mood_on == 1) {
                    iSetColor(0,0,0);
                }

                if(dark_mood_on == 0) {

                iSetColor(5, 36, 37);

                }
                iFilledRectangle(0,0,500, 650);


                iSetColor(21, 57, 57);
                iFilledRectangle(50 , 550 , 160, 35);
                iSetColor(255,255,255);
                iText(58, 559, "Add Reminder", GLUT_BITMAP_TIMES_ROMAN_24);

                iSetColor(21, 57, 57);
                iFilledRectangle(50 , 470 , 175, 35);
                iSetColor(255,255,255);
                iText(60, 478, "Show Reminder", GLUT_BITMAP_TIMES_ROMAN_24);

                iSetColor(21, 57, 57);
                iFilledRectangle(50 , 400 , 160, 35);
                iSetColor(255,255,255);
                iText(55, 410, "User Guideline", GLUT_BITMAP_TIMES_ROMAN_24);

                iSetColor(21, 57, 57);
                iFilledRectangle(50 , 330 , 150, 35);
                iSetColor(255,255,255);
                iText(68, 340, "Dark Mode", GLUT_BITMAP_TIMES_ROMAN_24);


                back_on=0;


            }


	}




	if(add_reminder) {

        iClear();


        if(dark_mood_on == 1) {
            iSetColor(0,0,0);
        }

        if(dark_mood_on == 0) {

        iSetColor(5, 36, 37);

        }

        iFilledRectangle(0,0,500, 650);

        iSetColor(255, 255, 255);
        iText(100, 410, "Enter your Event Name & Time", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(70, 380, "(i.e.First Ramadan&25/3/2023&5:30)" , GLUT_BITMAP_TIMES_ROMAN_24);


        if(dark_mood_on == 1) {
        iSetColor(0,0,0);
            }

        if(dark_mood_on == 0) {

            iSetColor(5, 36, 37);

        }


        iSetColor(21,57,57);
        iFilledRectangle(50,320, 405, 43);

        iSetColor(255, 255, 255);
        iText(50, 333, str,  GLUT_BITMAP_TIMES_ROMAN_24);


        iSetColor(21,57,57);
        iFilledRectangle(193, 140, 90, 35);
        iSetColor(255, 255, 255);
        iText(213, 148, "Back",  GLUT_BITMAP_TIMES_ROMAN_24);



            if(back_on) {
                iClear();
                add_reminder = 0;

                if(dark_mood_on == 1) {
                    iSetColor(0,0,0);
                }

                if(dark_mood_on == 0) {

                iSetColor(5, 36, 37);

                }
                iFilledRectangle(0,0,500, 650);


                iSetColor(21, 57, 57);
                iFilledRectangle(50 , 550 , 160, 35);
                iSetColor(255,255,255);
                iText(58, 559, "Add Reminder", GLUT_BITMAP_TIMES_ROMAN_24);

                iSetColor(21, 57, 57);
                iFilledRectangle(50 , 470 , 175, 35);
                iSetColor(255,255,255);
                iText(60, 478, "Show Reminder", GLUT_BITMAP_TIMES_ROMAN_24);

                iSetColor(21, 57, 57);
                iFilledRectangle(50 , 400 , 160, 35);
                iSetColor(255,255,255);
                iText(55, 410, "User Guideline", GLUT_BITMAP_TIMES_ROMAN_24);

                iSetColor(21, 57, 57);
                iFilledRectangle(50 , 330 , 150, 35);
                iSetColor(255,255,255);
                iText(68, 340, "Dark Mode", GLUT_BITMAP_TIMES_ROMAN_24);


                back_on=0;


            }



	}


	if(user_guideline ) {
        iClear();

        if(dark_mood_on == 1) {
                iSetColor(0,0,0);
            }

        if(dark_mood_on == 0) {

            iSetColor(5, 36, 37);

        }

        iFilledRectangle(0,0,500, 650);

        iSetColor(21,57,57);
        iFilledRectangle(170 , 470 , 150, 35);
        iSetColor(255, 255, 255);
        iText(177, 478, "Input Format", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(55, 400, "(Event Name)&(dd/mm/yr)&(hr:min)",  GLUT_BITMAP_TIMES_ROMAN_24);
        iText(65,370, "i.e.First Ramadan&25/3/2023&5:30", GLUT_BITMAP_TIMES_ROMAN_24 );

        iText(60, 340, "Time must be in international format.",  GLUT_BITMAP_TIMES_ROMAN_24 );

        iText(200, 310, "Remind!!!" , GLUT_BITMAP_TIMES_ROMAN_24 );
        iText(110, 280, "You can set multiple events." , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(20, 250, "But alarm will ring based on your last reminder." , GLUT_BITMAP_TIMES_ROMAN_24) ;

        iSetColor(21, 57, 57);
        iFilledRectangle(193, 140, 90, 35);
        iSetColor(255, 255, 255);
        iText(213, 148, "Back",  GLUT_BITMAP_TIMES_ROMAN_24);



        if(back_on) {
                iClear();
                user_guideline = 0;

                if(dark_mood_on == 1) {
                    iSetColor(0,0,0);
                }

                if(dark_mood_on == 0) {

                iSetColor(5, 36, 37);

                }

                iFilledRectangle(0,0,500, 650);


                iSetColor(21, 57, 57);
                iFilledRectangle(50 , 550 , 160, 35);
                iSetColor(255,255,255);
                iText(58, 559, "Add Reminder", GLUT_BITMAP_TIMES_ROMAN_24);

                iSetColor(21, 57, 57);
                iFilledRectangle(50 , 470 , 175, 35);
                iSetColor(255,255,255);
                iText(60, 478, "Show Reminder", GLUT_BITMAP_TIMES_ROMAN_24);

                iSetColor(21, 57, 57);
                iFilledRectangle(50 , 400 , 160, 35);
                iSetColor(255,255,255);
                iText(55, 410, "User Guideline", GLUT_BITMAP_TIMES_ROMAN_24);

                iSetColor(21, 57, 57);
                iFilledRectangle(50 , 330 , 150, 35);
                iSetColor(255,255,255);
                iText(68, 340, "Dark Mode", GLUT_BITMAP_TIMES_ROMAN_24);


                back_on=0;

            }

	}

}


void func() {
    if(isCalled) {
        isCalled = 0;
    }

    else {
        isCalled = 1;
    }
}


void iMouseMove(int mx, int my) {

}


void iMouse(int button, int state, int mx, int my) {

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (mx >= 50 ) && (mx<=210) && (my >= 550) && (my<= 585) ) {
		add_reminder = 1;
		p=1;


	}

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (mx >= 193 ) && (mx<=283) && (my >= 140) && (my<= 175) ) {
        back_on = 1;
	}

	if( (button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (mx>= 50) && (mx<=225) && (my>=470) && (my<=505) ) {
        show_reminder = 1;
	}

	if( (button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (mx>= 50) && (mx<=210) && (my>=400) && (my<=435) ) {
        user_guideline = 1;
	}

	if( (button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (mx>= 50) && (mx<=200) && (my>=330) && (my<=365) ) {
        dark_mood = 1;
	}

	if(( (button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (dark_mood == 1) && (mx>= 193) && (mx<=283) && (my>=340) && (my<=375) )) {
        dark_mood_on = 1;
	}

	if(( (button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (dark_mood == 1) && (mx>= 193) && (mx<=283) && (my>=290) && (my<=325) )) {
        dark_mood_on = 0;
	}




}

    void input(unsigned char key) {

    if(key == '\b'){
        if(strIdx >= 0){
            str[strIdx] = '\0';
            strIdx--;
        }

	}
	else{
        strIdx++;
        str[strIdx] = key;
	}

    }



void iKeyboard(unsigned char key) {


	if(p){

       input(key);
	}

	if(p) {
        if(key == '\r') {
            add_task();
            diff_hr_min();

            time_count_down = 1;
            memset(str, 0, sizeof(str));
            strIdx = -1;

        }
	}


}


void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}

}




int main() {

    iSetTimer(3000 , func);
	iInitialize(500, 650, "To Do Reminder");
	return 0;

}

