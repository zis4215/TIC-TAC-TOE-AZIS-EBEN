/* TUGAS BERSAR DASAR-DASAR PEMROGRAMAN
	PERMAINAN TIC TAC TOE SEDERHANA
			oleh
		AZIS SUROHMAN
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

//Modul Halaman Depan
void mode();
void papanChoice();
void menu();
void about();
void help();


int grid1();
int grid3();
int grid2();

void board();
void board2();
void board3();
void rounde();
void level();
void resetGrid();
void resetGrid2();

int p, q, r, s,u,t;
int skor1, skor2;
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char bidak [26]= {'.','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y' };
int cekwin5();

char papan[50];
void resetGrid3();
void isi3();
int cekwin3();
int checkwin();

//Begin
int main()
{
	do {
		printf("	======================================================================\n\n\n 			SELAMAT DATANG DI GAME TIC TAC TOE AE\n\n\n[1] Mulai	[2] Keluar	[3] Cara Bermain	 [4] Tentang\n\n\nPilihan Anda : ");

		scanf("%i",&p);

		system("cls"); // untuk membersihkan layar
		switch(p){
			case 1 :
				mode (); //menampilkan ke modul mode
				papanChoice (); // menampilkan ke modul papanChoice
				break;
			case 2 :
				printf("Terima Kasih");
				break;
			case 3 :
				help(); // menampilkan help 
				break;
			case 4 :
				about (); // menampilkan about
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

//Modul Menampilkan Help
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
	
	scanf("%c",&pilihan);}
	while(tolower(pilihan) != 'y');
}

//Modul Menampilkan Halaman About
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




//Modul Pemilihan Mode
void mode(){
printf("*#*#=================================================*#*#\n\n\n Pilih Mode Permainan\n\n[1] VS P	[2] VS AI (Belum tersedia)\n\nPilihan Anda : ");
	scanf("%i",&r);
	system("cls");
	switch (r)
	{
		case 1 :
			rounde();
			break;
		case 2 :
			level();
			printf("*#*#=================================================*#*#\n\n\nPilih Level Permainan\n\n[1] Mudah	[2] Sedang	[3] Sulit\n\nPilihan Anda : ");
			system("cls");
			break;
	}

}

//Modul Rounde untuk menentukan berapa skor yang ingin dicapai
void rounde(){
printf("*#*#=================================================*#*#\n\n\nPilih skor yang ingin anda capai\n\n[1] 3	[2] 5	[3] 7\n\nPilihan Anda : ");
			scanf("%i",&t);
			switch(t){
                case 1: t = 3; break;
                case 2: t = 5; break;
                case 3: t = 7; break;
			}
			system("cls");
			}
			
//Modul Level AI
void level(){
	printf("*#*#=================================================*#*#\n\n\nPilih Level Permainan\n\n[1] Mudah	[2] Sedang	[3] Sulit\n\nPilihan Anda : ");
	system("cls");
}

//Modul Pemilihan Grid 
void papanChoice()
{printf("*#*#=================================================*#*#\n\n\nPilih Ukuran Papan\n\n[1] 3x3	[2] 5x5	[3] 7x7\n\nPilihan Anda : ");
	scanf("%i",&q);
	system("cls");
	switch (q){
		case 1 :
			grid1 (); // menampilkan permainan 3x3
			break;
		case 2 :
			grid2();// menampilkan permainan 5x5
			break;
		case 3 :
			grid3();// menampilkan permainan 7x7
			break;
		default:
			break;
	}
}


// Modul StartTime()
// Referensi dari kelompok Arsal & Naufal
// Modul untuk mencatat waktu pertama dihitung
int StartTime() {
    clock_t startInput;
    startInput = clock();

    return startInput;
}

// Modul EndTime()
// Referensi dari kelompok Arsal & Naufal
// Modul untuk mencatat waktu terakhir dihitung
int EndTime() {
    clock_t endInput;
    endInput = clock();

    return endInput;
}








void board2() {
	system("cls");			// untuk membersihkan layar
	printf("\n\n\tTic Tac Toe\n\n");  
	printf("Player 1 (X)  -  Player 2 (O)\n\n\n"); // sebagai penanda player mana yang X atau O
	printf("Skor Player 1 (X) : %d -  Skor Player 2 (O) : %d\n\n\n", skor1, skor2);    // menampilkan skor pemain
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





int grid1 (){
    int player = 1, i, choice, ti;
    double waktuInput;
    skor1 = 0;    // skor awal pemain 1
    skor2 = 0;		// skor awal pemain 2

    char mark;       // tanda X atau O
    do{
        do
        {
            board();
            player = (player % 2) ? 1 : 2; 		// menentukan giliran

            ti=StartTime();         // memulai perrhitungan waktu
            printf("Player %d, enter a number:  ", player);   
            scanf("%d", &choice);
            ti=EndTime()-ti;		// waktu habis
            waktuInput=((double)ti)/CLOCKS_PER_SEC;

            mark = (player == 1) ? 'X' : 'O';

            if(waktuInput<=10){				// untuk memberi tanda X atau O pada kotak yang belum terisi
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

                    player--;    // giliran tidak berubah
                    getch();
                }
            } else {
                printf("Waktu Habis hehe :)");
                getch();
            }


            i = checkwin(); // untuk mengecek kemenangan setiap game

            player++; 		// untuk mengganti giliran
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
int grid3(){    				// untuk memainkan game 7x7

	int player = 1, i, ti;
    double waktuInput; 			
    skor1 = 0;    //skor awal player 1
    skor2 = 0;    // skor awal player 2
    int choice;	// untuk mengenal inputan
    char mark;		// untuk menandakan X atau O
    isi3(); // untuk mengisi karakter papan 7x7
    do{
        do
        {
           
            board3();  // memanggil modul papan
            player = (player % 2) ? 1 : 2;      // 

            ti=StartTime();
            printf("Player %d, enter a number:  ", player);
            fflush(stdin);
            scanf("%d", &choice);
            ti=EndTime()-ti;
            waktuInput=((double)ti)/CLOCKS_PER_SEC;

            mark = (player == 1) ? 'X' : 'O';
			
            if(waktuInput<=10){
                if (choice == 1 && papan[1] == '_')
                    papan[1] = mark;
                else if (choice == 2 && papan[2] == '_')
                    papan[2] = mark;
                else if (choice == 3 && papan[3] == '_')
                    papan[3] = mark;
                else if (choice == 4 && papan[4] == '_')
                    papan[4] = mark;
                else if (choice == 5 && papan[5] == '_')
                    papan[5] = mark;
                else if (choice == 6 && papan[6] == '_')
                    papan[6] = mark;
                else if (choice == 7 && papan[7] == '_')
                    papan[7] = mark;
                else if (choice == 9 && papan[9] == '_')
                    {papan[9] = mark;}
                else if (choice == 10 && papan[10] == '_')
                    papan[10] = mark;
                else if (choice == 11 && papan[11] == '_')
                    papan[11] = mark;
                else if (choice == 12 && papan[12] == '_')
                    papan[12] = mark;
                else if (choice == 13 && papan[13] == '_')
                    papan[13] = mark;
                else if (choice == 14 && papan[14] == '_')
                    papan[14] = mark;
                else if (choice == 15 && papan[15] == '_')
                    papan[15] = mark;
                else if (choice == 16 && papan[16] == '_')
                    papan[16] = mark;
                else if (choice == 17 && papan[17] == '_')
                    papan[17] = mark;
                else if (choice == 18 && papan[18] == '_')
                    papan[18] = mark;
                else if (choice == 19 && papan[19] == '_')
                    papan[19] = mark;
                else if (choice == 20 && papan[20] == '_')
                    papan[20] = mark;
                else if (choice == 21 && papan[21] == '_')
                    papan[21] = mark;
                else if (choice == 22 && papan[22] == '_')
                    papan[22] = mark;
                else if (choice == 23 && papan[23] == '_')
                    papan[23] = mark;
                else if (choice == 24 && papan[24] == '_')
                    papan[24] = mark;
                else if (choice == 25 && papan[25] == '_')
                    papan[25] = mark;
                else if (choice == 26 && papan[26] == '_')
                    papan[26] = mark;
                else if (choice == 27 && papan[27] == '_')
                    papan[27] = mark;
                else if (choice == 28 && papan[28] == '_')
                    papan[28] = mark;
                else if (choice == 29 && papan[29] == '_')
                    papan[29] = mark;
                else if (choice == 30 && papan[30] == '_')
                    papan[30] = mark;
                else if (choice == 31 && papan[31] == '_')
                    papan[31] = mark;
                 else if (choice == 32 && papan[32] == '_')
                    papan[32] = mark;
                 else if (choice == 33 && papan[33] == '_')
                    papan[33] = mark;
                 else if (choice == 34 && papan[34] == '_')
                    papan[34] = mark;
                 else if (choice == 35 && papan[35] == '_')
                    papan[35] = mark;
                 else if (choice == 36 && papan[36] == '_')
                    papan[36] = mark;
                 else if (choice == 37 && papan[37] == '_')
                    papan[37] = mark;
                 else if (choice == 38 && papan[38] == '_')
                    papan[38] = mark;
                 else if (choice == 39 && papan[39] == '_')
                    papan[39] = mark;
                 else if (choice == 40 && papan[40] == '_')
                    papan[40] = mark;
                 else if (choice == 41 && papan[41] == '_')
                    papan[41] = mark;
                 else if (choice == 42 && papan[42] == '_')
                    papan[42] = mark;
                 else if (choice == 43 && papan[43] == '_')
                    papan[43] = mark;
                 else if (choice == 44 && papan[44] == '_')
                    papan[44]= mark;
                 else if (choice == 45 && papan[45] == '_')
                    papan[45] = mark;
                 else if (choice == 46 && papan[46] == '_')
                    papan[46] = mark;
                 else if (choice == 47 && papan[47] == '_')
                    papan[47] = mark;
                 else if (choice == 48 && papan[48] == '_')
                    papan[48] = mark;
                 else if (choice == 49 && papan[49] == '_')
                    papan[49] = mark;
                 else if (choice == 8 && papan [8]== '_')
            		{papan[8]= mark;}

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


            i = cekwin3();

            player++;
        }while (i ==  - 1);

        board3();
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
        board3();
        resetGrid3();

    }while(skor1!=t && skor2!=t);

    return 0;
}

void board3(){
	
	system("cls");
					    printf("\n\n\tTic Tac Toe\n\n");

   					 printf("Player 1 (X)  -  Player 2 (O)\n\n\n");  									// sebagai penanda player mana yang X atau O
   					 printf("Skor Player 1 (X) : %d -  Skor Player 2 (O) : %d\n\n\n", skor1, skor2);		// untuk menampilkan skor palyer
   					 
			printf("====================================   PAPAN PERMAINAN   ====================================\n\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||1          ||2          ||3          ||4          ||5          ||6          ||7          ||\n");
			printf("||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||\n"		// untuk menyimpan tanda X atau O
			,papan[1],papan[2],papan[3],papan[4],papan[5],papan[6],papan[7]); 													
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||8          ||9          ||10         ||11         ||12         ||13         ||14         ||\n");
			printf("||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||\n"
			,papan[8],papan[8],papan[10],papan[11],papan[12],papan[13],papan[14]);
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||15         ||16         ||17         ||18         ||19         ||29         ||21         ||\n");
			printf("||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||\n"
			,papan[15],papan[16],papan[17],papan[18],papan[19],papan[20],papan[21]);
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||22         ||23         ||24         ||25         ||26         ||27         ||28         ||\n");
			printf("||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||\n"
			,papan[22],papan[23],papan[24],papan[25],papan[26],papan[27],papan[28]);
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||29         ||30         ||31         ||32         ||33         ||34         ||35         ||\n");
			printf("||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||\n"
			,papan[29],papan[30],papan[31],papan[32],papan[33],papan[34],papan[35]);
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||36         ||37         ||38         ||39         ||40         ||41         ||42         ||\n");
			printf("||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||\n"
			,papan[36],papan[37],papan[38],papan[39],papan[40],papan[41],papan[42]);
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n");
			printf("||43         ||44         ||45         ||46         ||47         ||48         ||49         ||\n");
			printf("||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||     %c     ||\n"
			,papan[43],papan[44],papan[45],papan[46],papan[47],papan[48],papan[49]);
			printf("||           ||           ||           ||           ||           ||           ||           ||\n");
			printf("||===========||===========||===========||===========||===========||===========||===========||\n\n\n");

		}
void resetGrid3(){   //untuk mereset grid jika game pertama selesai
    char c='_';
    int i;

    for(i=0; i<50; i++){
        square[i]=c;
    }
}
int cekwin3(){  // untuk mengecek kemenangan papan 7x7 secara horizontal, vertikal, atau diagonal
	// b1
			if((papan[1]=='X'&&papan[2]=='X'&&papan[3]=='X'&&papan[4]=='X'&&papan[5]=='X') || 
			(papan[1]=='O'&&papan[2]=='O'&&papan[3]=='O'&&papan[4]=='O'&&papan[5]=='O'))
		return 1;
			else if((papan[6]=='X'&&papan[2]=='X'&&papan[3]=='X'&&papan[4]=='X'&&papan[5]=='X') || 
			(papan[6]=='O'&&papan[2]=='O'&&papan[3]=='O'&&papan[4]=='O'&&papan[5]=='O'))
		return 1;
			else if((papan[7]=='X'&&papan[6]=='X'&&papan[3]=='X'&&papan[4]=='X'&&papan[5]=='X') || 
			(papan[7]=='O'&&papan[6]=='O'&&papan[3]=='O'&&papan[4]=='O'&&papan[5]=='O'))
		return 1;
	//b2
			else if((papan[8]=='X'&&papan[9]=='X'&&papan[10]=='X'&&papan[11]=='X'&&papan[12]=='X') || 
			(papan[8]=='O'&&papan[9]=='O'&&papan[10]=='O'&&papan[11]=='O'&&papan[12]=='O'))
		return 1;
			else if((papan[13]=='X'&&papan[9]=='X'&&papan[10]=='X'&&papan[11]=='X'&&papan[12]=='X') || 
			(papan[13]=='O'&&papan[9]=='O'&&papan[10]=='O'&&papan[11]=='O'&&papan[12]=='O'))
		return 1;
			else if((papan[13]=='X'&&papan[14]=='X'&&papan[10]=='X'&&papan[11]=='X'&&papan[12]=='X') || 
			(papan[13]=='O'&&papan[14]=='O'&&papan[10]=='O'&&papan[11]=='O'&&papan[12]=='O'))
		return 1;
	//b3
			else if((papan[15]=='X'&&papan[16]=='X'&&papan[17]=='X'&&papan[18]=='X'&&papan[19]=='X') || 
			(papan[15]=='O'&&papan[16]=='O'&&papan[17]=='O'&&papan[18]=='O'&&papan[19]=='O'))
		return 1;
			else if((papan[20]=='X'&&papan[16]=='X'&&papan[17]=='X'&&papan[18]=='X'&&papan[19]=='X') || 
			(papan[20]=='O'&&papan[16]=='O'&&papan[17]=='O'&&papan[18]=='O'&&papan[19]=='O'))
		return 1;
			else if((papan[20]=='X'&&papan[21]=='X'&&papan[17]=='X'&&papan[18]=='X'&&papan[19]=='X') || 
			(papan[20]=='O'&&papan[21]=='O'&&papan[17]=='O'&&papan[18]=='O'&&papan[19]=='O'))
		return 1;
	//b4
			else if((papan[22]=='X'&&papan[23]=='X'&&papan[24]=='X'&&papan[25]=='X'&&papan[26]=='X') || 
			(papan[22]=='O'&&papan[23]=='O'&&papan[24]=='O'&&papan[25]=='O'&&papan[26]=='O'))
		return 1;
			else if((papan[27]=='X'&&papan[23]=='X'&&papan[24]=='X'&&papan[25]=='X'&&papan[26]=='X') || 
			(papan[27]=='O'&&papan[23]=='O'&&papan[24]=='O'&&papan[25]=='O'&&papan[26]=='O'))
		return 1;
			else if((papan[27]=='X'&&papan[28]=='X'&&papan[24]=='X'&&papan[25]=='X'&&papan[26]=='X') || 
			(papan[27]=='O'&&papan[28]=='O'&&papan[24]=='O'&&papan[25]=='O'&&papan[26]=='O'))
		return 1;
	//b5
			else if((papan[29]=='X'&&papan[30]=='X'&&papan[31]=='X'&&papan[32]=='X'&&papan[33]=='X') || 
			(papan[29]=='O'&&papan[30]=='O'&&papan[31]=='O'&&papan[32]=='O'&&papan[33]=='O'))
		return 1;
			else if((papan[34]=='X'&&papan[30]=='X'&&papan[31]=='X'&&papan[32]=='X'&&papan[33]=='X') || 
			(papan[34]=='O'&&papan[30]=='O'&&papan[31]=='O'&&papan[32]=='O'&&papan[33]=='O'))
		return 1;
			else if((papan[34]=='X'&&papan[35]=='X'&&papan[31]=='X'&&papan[32]=='X'&&papan[33]=='X') || 
			(papan[34]=='O'&&papan[35]=='O'&&papan[31]=='O'&&papan[32]=='O'&&papan[33]=='O'))
		return 1;
	//b6
		else if((papan[36]=='X'&&papan[37]=='X'&&papan[38]=='X'&&papan[39]=='X'&&papan[40]=='X') || 
			(papan[36]=='O'&&papan[37]=='O'&&papan[38]=='O'&&papan[39]=='O'&&papan[40]=='O'))
		return 1;
			else if((papan[41]=='X'&&papan[37]=='X'&&papan[38]=='X'&&papan[39]=='X'&&papan[40]=='X') || 
			(papan[41]=='O'&&papan[37]=='O'&&papan[38]=='O'&&papan[39]=='O'&&papan[40]=='O'))
		return 1;
			else if((papan[41]=='X'&&papan[42]=='X'&&papan[38]=='X'&&papan[39]=='X'&&papan[40]=='X') || 
			(papan[41]=='O'&&papan[42]=='O'&&papan[38]=='O'&&papan[39]=='O'&&papan[40]=='O'))
		return 1;
	//b7
			else if((papan[43]=='X'&&papan[44]=='X'&&papan[45]=='X'&&papan[46]=='X'&&papan[47]=='X') || 
			(papan[43]=='O'&&papan[44]=='O'&&papan[45]=='O'&&papan[46]=='O'&&papan[47]=='O'))
		return 1;
			else if((papan[48]=='X'&&papan[44]=='X'&&papan[45]=='X'&&papan[46]=='X'&&papan[47]=='X') || 
			(papan[48]=='O'&&papan[44]=='O'&&papan[45]=='O'&&papan[46]=='O'&&papan[47]=='O'))
		return 1;
			else if((papan[48]=='X'&&papan[49]=='X'&&papan[45]=='X'&&papan[46]=='X'&&papan[47]=='X') || 
			(papan[48]=='O'&&papan[49]=='O'&&papan[45]=='O'&&papan[46]=='O'&&papan[47]=='O'))
		return 1;
	//d1
	else if((papan[5]=='X'&&papan[11]=='X'&&papan[17]=='X'&&papan[23]=='X'&&papan[27]=='X') || 
			(papan[5]=='O'&&papan[11]=='O'&&papan[17]=='O'&&papan[23]=='O'&&papan[27]=='O'))
		return 1;
	else if((papan[6]=='X'&&papan[12]=='X'&&papan[18]=='X'&&papan[24]=='X'&&papan[30]=='X') || 
			(papan[6]=='O'&&papan[12]=='O'&&papan[18]=='O'&&papan[24]=='O'&&papan[30]=='O'))
		return 1;
		else if((papan[36]=='X'&&papan[12]=='X'&&papan[18]=='X'&&papan[24]=='X'&&papan[30]=='X') || 
			(papan[36]=='O'&&papan[12]=='O'&&papan[18]=='O'&&papan[24]=='O'&&papan[30]=='O'))
		return 1;
		else if((papan[7]=='X'&&papan[13]=='X'&&papan[19]=='X'&&papan[25]=='X'&&papan[31]=='X') || 
			(papan[7]=='O'&&papan[13]=='O'&&papan[19]=='O'&&papan[25]=='O'&&papan[31]=='O'))
		return 1;
		else if((papan[37]=='X'&&papan[13]=='X'&&papan[19]=='X'&&papan[25]=='X'&&papan[31]=='X') || 
			(papan[37]=='O'&&papan[13]=='O'&&papan[19]=='O'&&papan[25]=='O'&&papan[31]=='O'))
		return 1;
			else if((papan[37]=='X'&&papan[43]=='X'&&papan[19]=='X'&&papan[25]=='X'&&papan[31]=='X') || 
			(papan[37]=='O'&&papan[43]=='O'&&papan[19]=='O'&&papan[25]=='O'&&papan[31]=='O'))
		return 1;
		
		//DIAGONAL		
	//
	else if((papan[3]=='X'&&papan[11]=='X'&&papan[19]=='X'&&papan[27]=='X'&&papan[35]=='X') || 
			(papan[3]=='O'&&papan[11]=='O'&&papan[19]=='O'&&papan[27]=='O'&&papan[35]=='O'))
		return 1;
	//	
	else if((papan[2]=='X'&&papan[10]=='X'&&papan[18]=='X'&&papan[26]=='X'&&papan[34]=='X') || 
			(papan[2]=='O'&&papan[10]=='O'&&papan[18]=='O'&&papan[26]=='O'&&papan[34]=='O'))
		return 1;
	else if((papan[10]=='X'&&papan[18]=='X'&&papan[26]=='X'&&papan[34]=='X'&&papan[42]=='X') || 
			(papan[10]=='O'&&papan[18]=='O'&&papan[26]=='O'&&papan[34]=='O'&&papan[42]=='O'))
		return 1;		
	//	
	else if((papan[1]=='X'&&papan[9]=='X'&&papan[17]=='X'&&papan[25]=='X'&&papan[33]=='X') || 
			(papan[1]=='O'&&papan[9]=='O'&&papan[17]=='O'&&papan[25]=='O'&&papan[33]=='O'))
		return 1;
	else if((papan[9]=='X'&&papan[17]=='X'&&papan[25]=='X'&&papan[33]=='X'&&papan[41]=='X') || 
			(papan[9]=='O'&&papan[17]=='O'&&papan[25]=='O'&&papan[33]=='O'&&papan[41]=='O'))
		return 1;
	else if((papan[17]=='X'&&papan[25]=='X'&&papan[33]=='X'&&papan[41]=='X'&&papan[49]=='X') || 
			(papan[17]=='O'&&papan[25]=='O'&&papan[33]=='O'&&papan[41]=='O'&&papan[49]=='O'))
		return 1;		
	//
	else if((papan[8]=='X'&&papan[16]=='X'&&papan[24]=='X'&&papan[32]=='X'&&papan[40]=='X') || 
			(papan[8]=='O'&&papan[16]=='O'&&papan[24]=='O'&&papan[32]=='O'&&papan[40]=='O'))
		return 1;
	else if((papan[16]=='X'&&papan[24]=='X'&&papan[32]=='X'&&papan[40]=='X'&&papan[48]=='X') || 
			(papan[16]=='O'&&papan[24]=='O'&&papan[32]=='O'&&papan[40]=='O'&&papan[48]=='O'))
		return 1;		
	//	
	else if((papan[15]=='X'&&papan[23]=='X'&&papan[31]=='X'&&papan[39]=='X'&&papan[47]=='X') || 
			(papan[15]=='O'&&papan[23]=='O'&&papan[31]=='O'&&papan[39]=='O'&&papan[47]=='O'))
		return 1;
		
	//DiagonL kanan atas ke kiri bawah
else if((papan[14]=='X'&&papan[20]=='X'&&papan[26]=='X'&&papan[32]=='X'&&papan[38]=='X') || 
			(papan[14]=='O'&&papan[20]=='O'&&papan[26]=='O'&&papan[32]=='O'&&papan[38]=='O'))
		return 1;
else if((papan[20]=='X'&&papan[26]=='X'&&papan[32]=='X'&&papan[38]=='X'&&papan[44]=='X') || 
			(papan[20]=='O'&&papan[26]=='O'&&papan[32]=='O'&&papan[38]=='O'&&papan[44]=='O'))
		return 1;
//		
else if((papan[21]=='X'&&papan[27]=='X'&&papan[33]=='X'&&papan[39]=='X'&&papan[45]=='X') || 
			(papan[21]=='O'&&papan[27]=='O'&&papan[33]=='O'&&papan[39]=='O'&&papan[45]=='O'))
		return 1;
		
		
		
		
		//draw			
		else if (papan[1] != '_' && papan[2] != '_' && papan[3] != '_'                //kondisi draw papan 7x7
			&& papan[4] != '_' && papan[5] != '_' && papan[6] != '_'
			&& papan[7] != '_' && papan[8] != '_' && papan[9] != '_' && papan[10] != '_'
			&& papan[11] != '_' && papan[12] != '_' && papan[13] != '_' && papan[14] != '_'
			&& papan[15] != '_' && papan[16] != '_' && papan[17] != '_' && papan[18] != '_'
			&& papan[19] != '_' && papan[20] != '_' && papan[21] != '_' && papan[22] != '_'
			&& papan[23] != '_' && papan[24] != '_' && papan[25] != '_' && papan[26] != '_'
			&& papan[27] != '_' && papan[28] != '_' && papan[29] != '_' && papan[30] != '_'
			&& papan[31] != '_' && papan[32] != '_' && papan[33] != '_' && papan[34] != '_'
			&& papan[35] != '_' && papan[36] != '_' && papan[37] != '_' && papan[38] != '_'
			&& papan[39] != '_' && papan[40] != '_' && papan[41] != '_' && papan[43] != '_'
			&& papan[44] != '_' && papan[45] != '_' && papan[47] != '_' && papan[49] != '_'
			)
			return 0;
    	else
         return -1;
		
		
		
		
		
		
		
		
		
		
		
		
	//draw
//		else if (papan[1] != '1' && papan[2] != '2' && papan[3] != '3'
//			&& papan[4] != '4' && papan[5] != '5' && papan[6] != '6'
//			&& papan[7] != '7' && papan[8] != '8' && papan[9] != '9' && papan[10] != '10'
//			&& papan[11] != '11' && papan[12] != '12' && papan[13] != '13' && papan[14] != '14'
//			&& papan[15] != '15' && papan[16] != '16' && papan[17] != '17' && papan[18] != '18'
//			&& papan[19] != '19' && papan[20] != '20' && papan[21] != '21' && papan[22] != '22'
//			&& papan[23] != '23' && papan[24] != '24' && papan[25] != '25' && papan[26] != '26'
//			&& papan[27] != '27' && papan[28] != '28' && papan[29] != '29' && papan[30] != '30'
//			&& papan[31] != '31' && papan[32] != '32' && papan[33] != '33' && papan[34] != '34'
//			&& papan[35] != '35' && papan[36] != '36' && papan[37] != '37' && papan[38] != '38'
//			&& papan[39] != '39' && papan[40] != '40' && papan[41] != '42' && papan[43] != '44'
//			&& papan[44] != '44' && papan[45] != '46' && papan[47] != '48' && papan[49] != '49'
//			)
//			return 0;
    	}

void isi3(){              // untuk mengisi karakter pada papan 7x7
    char c='_';
    int i;

    for(i=0; i<50; i++){
        papan[i]=c;
    }
}





















