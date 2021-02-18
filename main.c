/* TUGAS BERSAR DASAR-DASAR PEMROGRAMAN
	PERMAINAN TIC TAC TOE SEDERHANA
			oleh
		AZIs SUROHMAN
		EBEN EZER NAPITU
	D4 TEKNIK INFORMATIKA POLITEKNIK NEGERI BANDUNG
*/
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
int grid1();
void grid3();
int grid2();
void board2();
void rounde ();
void level ();
void resetGrid();
void resetGrid2();
int p, q, r, s,u,t;
int skor1, skor2;
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char bidak [26]= {'.','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y' };
int cekwin5();
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
			rounde();
			break;
	//		printf("*#*#=================================================*#*#\n\n\nPilih Berapa kali anda ingin bermain\n\n[1] 3	[2] 5	[3] 7\n\nPilihan Anda : ");
	//		scanf("%i",&t);
	//		switch(t){
    //          case 1: t = 3; break;
    //          case 2: t = 5; break;
    //          case 3: t = 7; break;
	//		}
	//		system("cls");
	//		break;

		case 2 :
			level();
	//		printf("*#*#=================================================*#*#\n\n\nPilih Level Permainan\n\n[1] Mudah	[2] Sedang	[3] Sulit\n\nPilihan Anda : ");
	//		system("cls");
			break;
	}

}
void rounde (){
printf("*#*#=================================================*#*#\n\n\nPilih Berapa kali anda ingin bermain\n\n[1] 3	[2] 5	[3] 7\n\nPilihan Anda : ");
			scanf("%i",&t);
			switch(t){
                case 1: t = 3; break;
                case 2: t = 5; break;
                case 3: t = 7; break;
			}
			system("cls");
			}
void level(){
	printf("*#*#=================================================*#*#\n\n\nPilih Level Permainan\n\n[1] Mudah	[2] Sedang	[3] Sulit\n\nPilihan Anda : ");
		system("cls");
}

//...
void board2 (){system("cls");
				    printf("\n\n\tTic Tac Toe\n\n");

				    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
				    printf("Skor Player 1 (X) : %d -  Skor Player 2 (O) : %d\n\n\n", skor1, skor2);
			printf("=======================   PAPAN PERMAINAN   =======================\n\n");
			printf("||===========||===========||===========||===========||===========||\n");
			printf("||           ||           ||           ||           ||           ||\n");
			printf("||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||\n",bidak[1],bidak[2],bidak[3],bidak[4],bidak[5]);
			printf("||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||\n");
			printf("||           ||           ||           ||           ||           ||\n");
			printf("||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||\n",bidak[6],bidak[7],bidak[8],bidak[9],bidak[10]);
			printf("||===========||===========||===========||===========||===========||\n");
			printf("||           ||           ||           ||           ||           ||\n");
			printf("||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||\n",bidak[11],bidak[12],bidak[13],bidak[14],bidak[15]);
			printf("||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||\n");
			printf("||           ||           ||           ||           ||           ||\n");
			printf("||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||\n",bidak[16],bidak[17],bidak[18],bidak[19],bidak[20]);
			printf("||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||\n");
			printf("||           ||           ||           ||           ||           ||\n");
			printf("||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||\n",bidak[21],bidak[22],bidak[23],bidak[24],bidak[25]);
			printf("||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||\n\n\n");



}
void grid3 (){
			printf("====================================   PAPAN PERMAINAN   ====================================\n\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||     -     ||\n");
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n\n\n");
			scanf("%i",&u);
}
void help(){
	char pilihan='N';
	do{
	system("cls");
	printf("Besar papan permainan berukuran 3x3  dengan deret kemenangan 3.Papan 5x5 dengan deret 4, papan 7x7 dengan deret 5 \n");
	printf("Pemain dalam permainan ini dibatasi untuk satu lawan satu, dilakukan bergiliran antara pemain pertama dan pemain kedua.\n");
	printf("Untuk memberikan langkah, setiap pemain harus mengisi bidak dengan simbol pemain masing-masing, biasanya X atau O.\n");
	printf("Setiap pemain hanya mempunyai satu kali kesempatan pada setiap giliran.\n");
	printf("Bidak yang sudah terisi tidak bisa ditimpa oleh langkah berikutnya.\n");
	printf("Langkah yang sudah diambil tidak dapat dibatalkan atau diganti dengan langkah yang lain.\n");
	printf("Setiap pemain diberikan waktu 10 detik, jika melewati batas, maka akan dilanjutkan oleh pemain lain.\n");
	printf("Tujuan dari game ini adalah untuk mendapatkan deret dengan tiga simbol atau lebih yang sama secara horizontal, vertikal atau  diagonal.\n");
	printf("Pemenang ditentukan oleh pemain yang pertama kali menyusun deret tersebut.\n");
	printf("\n Masukan Y untuk kembali : ");
		scanf("%c",&pilihan);
	}while(tolower(pilihan) != 'y');
}

void about(){
	char pilihan='N';

	do{
		system("cls");
		printf("||===========   About   ===========||\n\n\n ");
		printf(" Game ini dibuat oleh Azis Surohman dan Eben Ezer Napitu dari 1B-D4 Teknik Informatika Politeknik Negeri Bandung dalam rangka penugasan untuk nilai UAS. Game ini juga mengambik sumber dari internet yang dimodifikasi.");

		printf("\n\nMasukan Y untuk kembali : ");
		scanf("%c",&pilihan);
	}while(tolower(pilihan) != 'y');
}

int grid1 (){
    int player = 1, i, choice, ti;
    double waktuInput;
    skor1 = 0;
    skor2 = 0;

    char mark;
    do{
        do
        {
            board();
            player = (player % 2) ? 1 : 2;

            ti=StartTime();
            printf("Player %d, enter a number:  ", player);
            scanf("%d", &choice);
            ti=EndTime()-ti;
            waktuInput=((double)ti)/CLOCKS_PER_SEC;

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
                printf("Waktu Habis hehe :)");
                getch();
            }


            i = checkwin();

            player++;
        }while (i ==  - 1);

        board();
        player--;
        if (i == 1){
            printf("==>\aPlayer %d win ",player);
            getch();
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

    }while(skor1!=t && skor2!=t);

    return 0;
}

/*********************************************/
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


/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ********************************************************************/

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
void resetGrid2(){
	char c='a';
    int i;

    for(i=1; i<26; i++){
        bidak[i]=c;
        c++;
	
	
}}

/*******************************************************************
END OF PROJECT
 ********************************************************************/
int cekwin5(){
	if (bidak[1]==bidak[2]&&bidak[2]==bidak[3]&&bidak[3]==bidak[4])
		return 1;
	else if (bidak[2]==bidak[3]&&bidak[3]==bidak[4]&&bidak[4]==bidak[5])
		return 1;
	else if (bidak[6]==bidak[7]&&bidak[7]==bidak[8]&&bidak[8]==bidak[9])
		return 1;
	else if (bidak[7]==bidak[8]&&bidak[8]==bidak[9]&&bidak[9]==bidak[10])
		return 1;
	else if (bidak[11]==bidak[12]&&bidak[12]==bidak[13]&&bidak[13]==bidak[14])
		return 1;
	else if (bidak[12]==bidak[13]&&bidak[13]==bidak[14]&&bidak[14]==bidak[15])
		return 1;
	else if (bidak[16]==bidak[17]&&bidak[17]==bidak[18]&&bidak[18]==bidak[19])
		return 1;
	else if (bidak[17]==bidak[18]&&bidak[18]==bidak[19]&&bidak[19]==bidak[20])
		return 1;
	else if (bidak[21]==bidak[22]&&bidak[22]==bidak[23]&&bidak[23]==bidak[24])
		return 1;
	else if (bidak[22]==bidak[23]&&bidak[23]==bidak[24]&&bidak[24]==bidak[25])
		return 1;
	else if (bidak[4]==bidak[8]&&bidak[8]==bidak[12]&&bidak[12]==bidak[16])
		return 1;
	else if (bidak[21]==bidak[17]&&bidak[17]==bidak[13]&&bidak[13]==bidak[9])
		return 1;
	else if (bidak[17]==bidak[13]&&bidak[13]==bidak[9]&&bidak[9]==bidak[5])
		return 1;
	else if (bidak[22]==bidak[18]&&bidak[18]==bidak[14]&&bidak[14]==bidak[10])
		return 1;
	else if (bidak[1]==bidak[6]&&bidak[6]==bidak[11]&&bidak[11]==bidak[16])
		return 1;
	else if (bidak[6]==bidak[11]&&bidak[11]==bidak[16]&&bidak[16]==bidak[21])
		return 1;
	else if (bidak[2]==bidak[7]&&bidak[7]==bidak[12]&&bidak[12]==bidak[17])
		return 1;
	else if (bidak[7]==bidak[12]&&bidak[12]==bidak[17]&&bidak[17]==bidak[22])
		return 1;
	else if (bidak[3]==bidak[8]&&bidak[8]==bidak[13]&&bidak[13]==bidak[18])
		return 1;
	else if (bidak[8]==bidak[13]&&bidak[13]==bidak[18]&&bidak[18]==bidak[23])
		return 1;
	else if (bidak[4]==bidak[9]&&bidak[9]==bidak[14]&&bidak[14]==bidak[19])
		return 1;
	else if (bidak[9]==bidak[14]&&bidak[14]==bidak[19]&&bidak[19]==bidak[24])
		return 1;
	else if (bidak[5]==bidak[10]&&bidak[10]==bidak[15]&&bidak[15]==bidak[20])
		return 1;
	else if (bidak[10]==bidak[15]&&bidak[15]==bidak[19]&&bidak[20]==bidak[25])
		return 1;
	else if (bidak[6]==bidak[12]&&bidak[12]==bidak[18]&&bidak[18]==bidak[14])
		return 1;
	else if (bidak[1]==bidak[7]&&bidak[7]==bidak[13]&&bidak[15]==bidak[19])
		return 1;
	else if (bidak[7]==bidak[13]&&bidak[13]==bidak[19]&&bidak[19]==bidak[25])
		return 1;
	else if (bidak[2]==bidak[8]&&bidak[8]==bidak[14]&&bidak[14]==bidak[20])
		return 1;
	else if (bidak[1] != 'a' && bidak[2] != 'b' && bidak[3] != 'c'
		&& bidak[4] != 'd' && bidak[5] != 'e' && bidak[6] != 'f'
		&& bidak[7] != 'g' && bidak[8] != 'h' && bidak[9] != 'i' && bidak[10] != 'j'
		&& bidak[11] != 'k' && bidak[12] != 'l' && bidak[13] != 'm' && bidak[14] != 'n'
		&& bidak[15] != 'o' && bidak[16] != 'p' && bidak[17] != 'q' && bidak[18] != 'r'
		&& bidak[19] != 's' && bidak[20] != 't' && bidak[21] != 'u' && bidak[22] != 'v'
		&& bidak[23] != 'w' && bidak[24] != 'x' && bidak[25] != 'y')

        return 0;
    else
        return  - 1;

}

int grid2(){
	int player = 1, i, ti;
    double waktuInput;
    skor1 = 0;
    skor2 = 0;
    char choice;
    char mark;
    do{
        do
        {
            board2();
            player = (player % 2) ? 1 : 2;

            ti=StartTime();
            printf("Player %d, enter a character:  ", player);
            fflush(stdin);
            scanf("%c", &choice);
            ti=EndTime()-ti;
            waktuInput=((double)ti)/CLOCKS_PER_SEC;

            mark = (player == 1) ? 'X' : 'O';

            if(waktuInput<=10){
                if (choice == 'a' && bidak[1] == 'a')
                    bidak[1] = mark;

                else if (choice == 'b' && bidak[2] == 'b')
                    bidak[2] = mark;
				else if (choice == 'c' && bidak[3] == 'c')
                    bidak[3] = mark;
                else if (choice == 'd' && bidak[4] == 'd')
                    bidak[4] = mark;
                else if (choice == 'e' && bidak[5] == 'e')
                    bidak[5] = mark;
                else if (choice == 'f' && bidak[6] == 'f')
                    bidak[6] = mark;
                else if (choice == 'g' && bidak[7] == 'g')
                    bidak[7] = mark;
                else if (choice == 'h' && bidak[8] == 'h')
                    bidak[8] = mark;
                else if (choice == 'i' && bidak[9] == 'i')
                    bidak[9] = mark;
                else if (choice == 'j' && bidak[10] == 'j')
                    bidak[10] = mark;
                else if (choice == 'k' && bidak[11] == 'k')
                    bidak[11] = mark;
                else if (choice == 'l' && bidak[12] == 'l')
                    bidak[12] = mark;
                else if (choice == 'm' && bidak[13] == 'm')
                    bidak[13] = mark;
                else if (choice == 'n' && bidak[14] == 'n')
                    bidak[14] = mark;
                else if (choice == 'o' && bidak[15] == 'o')
                    bidak[15] = mark;
                else if (choice == 'p' && bidak[16] == 'p')
                    bidak[16] = mark;
                else if (choice == 'q' && bidak[17] == 'q')
                    bidak[17] = mark;
                else if (choice == 'r' && bidak[18] == 'r')
                    bidak[18] = mark;
                else if (choice == 's' && bidak[19] == 's')
                    bidak[19] = mark;
                else if (choice == 't' && bidak[20] == 't')
                    bidak[20] = mark;
                else if (choice == 'u' && bidak[21] == 'u')
                    bidak[21] = mark;
                else if (choice == 'v' && bidak[22] == 'v')
                    bidak[22] = mark;
                else if (choice == 'w' && bidak[23] == 'w')
                    bidak[23] = mark;
                else if (choice == 'x' && bidak[24] == 'x')
                    bidak[24] = mark;
                else if (choice == 'y' && bidak[25] == 'y')
                    bidak[25] = mark;

                else
                {
                    printf("Invalid move ");

                    player--;
                    getch();
                }
            } else {
                printf("Waktu Habis hehe :)");
                getch();
            }


            i = cekwin5();

            player++;
        }while (i ==  - 1);

        board2();
        player--;
        if (i == 1){
            printf("==>\aPlayer %d win ",player);
            getch();
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
        board2();
        resetGrid2();

    }while(skor1!=t && skor2!=t);

    return 0;
}
























