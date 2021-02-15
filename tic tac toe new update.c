#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<mmsystem.h>

void mode();
void papan();
void menu();
void about();
void help();
void grid1();
void grid2();
void grid3();
void resetGrid();
int p, q, r, s,u,t;
int skor1, skor2;
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int StartTime() {
    clock_t startInput;
    startInput = clock();

    return startInput;
}

int EndTime() {
    clock_t endInput;
    endInput = clock();

    return endInput;
}
int checkwin();
void board();


int main()
{
	do {
		printf("	======================================================================\n\n\n 			SELAMAT DATANG DI GAME TIC TAC TOE AE\n\n\n[1] Mulai	[2] Keluar	[3] Cara Bermain	 [4] Tentang\n\n\nPilihan Anda : ");
		scanf("%i",&p);

		system("cls");
		switch(p){
			case 1 :
				mode ();
				papan ();
				break;
			case 2 :
				printf("Terima Kasih");
				break;
			case 3 :
				help();
				break;
			case 4 :
				about ();
				break;
			default:
		        printf("Salah Input.\n");
		        system("cls");
		        menu;
		        break;
	    }
	}while(p!=2 || p<2);
	return 0;
}

void papan()
{printf("*#*#=================================================*#*#\n\n\nPilih Ukuran Papan\n\n[1] 3x3	[2] 5x5	[3] 7x7\n\nPilihan Anda : ");
	scanf("%i",&q);
	system("cls");
	switch (q){
		case 1 :
			grid1 ();
			break;
		case 2 :
			grid2();
			break;
		case 3 :
			grid3();
			break;
		default:
			break;
	}
}

void mode(){
	printf("*#*#=================================================*#*#\n\n\n Pilih Mode Permainan\n\n[1] VS P	[2] VS AI\n\nPilihan Anda : ");
	scanf("%i",&r);
	system("cls");
	switch (r)
	{
		case 1 :
			printf("*#*#=================================================*#*#\n\n\nPilih Skor Maks\n\n[1] 3	[2] 5	[3] 7\n\nPilihan Anda : ");
			scanf("%i",&t);
			switch(t){
                case 1: t = 3; break;
                case 2: t = 5; break;
                case 3: t = 7; break;
			}
			system("cls");
			break;

		case 2 :
			printf("*#*#=================================================*#*#\n\n\nPilih Level Permainan\n\n[1] VS P	[2] VS AI\n\nPilihan Anda : ");
			scanf("%i",&t);
			system("cls");
			break;
	}

}
//void grid1 (){
//			printf("||===========||===========||===========||\n");
//			printf("||1          ||2          ||3          ||\n");
//			printf("||     -     ||     -     ||     -     ||\n");
//			printf("||           ||           ||           ||\n");
//			printf("||===========||===========||===========||\n");
//			printf("||4          ||5          ||6          ||\n");
//			printf("||     -     ||     -     ||     -     ||\n");
//			printf("||           ||           ||           ||\n");
//			printf("||===========||===========||===========||\n");
//			printf("||7          ||8          ||9          ||\n");
//			printf("||     -     ||     -     ||     -     ||\n");
//			printf("||           ||           ||           ||\n");
//			printf("||===========||===========||===========||\n\n\n");
//			scanf("%i",&s);
//
//}
//}

void grid2 (){
			printf("=======================   PAPAN PERMAINAN   =======================\n\n");
			printf("||===========||===========||===========||===========||===========||\n");
			printf("||1          ||2          ||3          ||4          ||5          ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||\n");
			printf("||6          ||7          ||8          ||9          ||10         ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||===========||===========||===========||===========||===========||\n");
			printf("||11         ||12         ||13         ||14         ||15         ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||\n");
			printf("||16         ||17         ||18         ||19         ||20         ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||\n");
			printf("||21         ||22         ||23         ||24         ||25         ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||\n\n\n");\
			scanf("%i",&t);


}
void grid3 (){
			printf("====================================   PAPAN PERMAINAN   ====================================\n\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||1          ||2          ||3          ||4          ||5          ||6          ||7          ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||8          ||9          ||10         ||11         ||12         ||13         ||14         ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||15         ||16         ||17         ||18         ||19         ||20         ||21         ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||22         ||23         ||24         ||25         ||26         ||27         ||28         ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||29         ||30         ||31         ||32         ||33         ||34         ||35         ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||36         ||37         ||38         ||39         ||40         ||41         ||42         ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||43         ||44         ||45         ||46         ||47         ||48         ||49         ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n\n\n");
			scanf("%i",&u);
}
void help(){
	char pilihan='N';
	do{
	system("cls");
	printf (" Mainkan aja \n\n\n");
		printf("Masukan Y untuk kembali : ");
		scanf("%c",&pilihan);
	}while(tolower(pilihan) != 'y');
}

void about(){
	char pilihan='N';

	do{
		system("cls");
		printf("||===========   About   ===========||\n");
		printf("||                                 ||\n");
		printf("||                                 ||\n");
		printf("||                                 ||\n");
		printf("||                                 ||\n");
		printf("||=================================||\n\n\n");
		printf("Masukan Y untuk kembali : ");
		scanf("%c",&pilihan);
	}while(tolower(pilihan) != 'y');
}

void grid1 (){
    int player = 1, i, choice, t;
    double waktuInput;
    skor1 = 0;
    skor2 = 0;

    char mark;
    do{
        do
        {
            board();
            player = (player % 2) ? 1 : 2;

            t=StartTime();
            printf("Player %d, enter a number:  ", player);
            scanf("%d", &choice);
            t=EndTime()-t;
            waktuInput=((double)t)/CLOCKS_PER_SEC;

            mark = (player == 1) ? 'X' : 'O';

            if(waktuInput<=10){
                if (choice == 1 && square[1] == '1')
                    square[1] = mark;

                else if (choice == 2 && square[2] == '2')
                    square[2] = mark;

                else if (choice == 3 && square[3] == '3')
                    square[3] = mark;

                else if (choice == 4 && square[4] == '4')
                    square[4] = mark;

                else if (choice == 5 && square[5] == '5')
                    square[5] = mark;

                else if (choice == 6 && square[6] == '6')
                    square[6] = mark;

                else if (choice == 7 && square[7] == '7')
                    square[7] = mark;

                else if (choice == 8 && square[8] == '8')
                    square[8] = mark;

                else if (choice == 9 && square[9] == '9')
                    square[9] = mark;

                else
                {
                    printf("Invalid move ");

                    player--;
                    getch();
                }
            } else {
                printf("Waktu Habis BEN !!!");
                getch();
            }


            i = checkwin();

            player++;
        }while (i ==  - 1);

        board();
        player--;
        if (i == 1){
            printf("==>\aPlayer %d win ",player);
            if(player==1){
                 skor1++;
            }

            else{
                skor2++;
            }
        }
        else{
            printf("==>\aGame draw");
        }
        board();
        resetGrid();
        getch();

    }while(skor1!=t && skor2!=t);

    return 0;
}

/***************/
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}


/***********************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ************************/

void board()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    printf("Skor Player 1 (X) : %d -  Skor Player 2 (O) : %d\n\n\n", skor1, skor2);


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}

void resetGrid(){
    char c='0';
    int i;

    for(i=0; i<10; i++){
        square[i]=c;
        c++;
    }

}

/***********************
END OF PROJECT
 ************************/ 
