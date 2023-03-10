#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int biaya_kamar;
int totalharga;


void reg()
{
	//Simpan Data
	FILE *inputfile = NULL;
	FILE *outputfile = NULL;
	FILE *currentfile = NULL;

	FILE *inputfile2 = NULL;
	FILE *outputfile2 = NULL;
	FILE *currentfile2 = NULL;

	char user[100],pass[100];
	char jawab='y';


	inputfile= fopen ("DATABASE.txt","r");
	inputfile2= fopen ("DATABASE PW.txt","r");
	outputfile= fopen ("DATABASE.txt","w");
	outputfile2= fopen ("DATABASE PW.txt","w");
ULANG:

	system ("cls");
	gotoxy(40,1);
	printf ("==========PENDAFTARAN==========\n");
	gotoxy(40,3);
	printf (" NAMA AKUN\t:");
	//gotoxy(40,4);
	scanf (" %[^\n]s",user);
	gotoxy(40,5);
	printf (" Password\t:");
	scanf (" %[^\n]s",pass);

	if(strlen(user)<8||strlen(pass)<8)
	{
		system("cls");
		gotoxy(30,1);
		printf("\t+++++ERROR! KESALAHAN INPUT!+++++");
		gotoxy(46,2);
		printf("\n\n\t\t\tNAMA AKUN/PASSWORD HARUS LEBIH DARI 8 KARAKTER!!!");
		gotoxy(40,3);
		printf("\n\nTekan apa saja untuk memasukkan ulang...");
		getch();
		goto ULANG;
	}
	else
	{
		BALIK:
        gotoxy(40,7);
		printf ("Apakah Anda Yakin?(Y/T): ");
		scanf (" %c",&jawab);
		if (jawab=='y' || jawab=='Y')
		{
			goto LANJUT;
		}
		else if (jawab=='t' || jawab=='T')
		{
			goto ULANG;
		}
		else
		{
			system ("cls");
			printf ("++INVALID INPUT!++\n");
			goto BALIK;
		}

	}

	LANJUT:
	system("cls");
	fprintf (outputfile,"%s",user);
	fclose(outputfile);
	fprintf (outputfile2,"%s",pass);
	fclose(outputfile2);
    gotoxy(40,1);
	printf("======================================\n");
	gotoxy(40,3);
	printf("          BERHASIL MENDAFTAR          \n");
	gotoxy(40,5);
	printf("======================================");
	gotoxy(40,6);
	printf("\n\n Tekan apa saja untuk kembali....");
	getch();
	login();


}

void login(){
		char User[100],Pass[100];
		char cek_user[100],cek_pass[100];

	FILE *outputfile=fopen("DATABASE.txt","r");
	fscanf(outputfile," %[^\n]s",cek_user);
	fclose(outputfile);
	FILE *outputfile2=fopen("DATABASE PW.txt","r");
	fscanf(outputfile2," %[^\n]s",cek_pass);
	fclose(outputfile2);

	INPUT:
	system("cls");
	gotoxy(40,1);
	printf("==================================\n");
	gotoxy(40,2);
	printf("            MENU LOGIN          \n");
	gotoxy(40,3);
	printf("==================================");
	gotoxy(40,4);
	printf ("Nama Akun\t: ");
	scanf (" %[^\n]s",User);
	gotoxy(40,5);
	printf ("Password\t: ");
	scanf (" %[^\n]s",Pass);


	if(strcmp(cek_user, User)==0&&strcmp(cek_pass, Pass)==0)
	{

	}
	else if(strcmp(cek_user, User)==1&&strcmp(cek_pass, Pass)==0)
	{
	char jwb='y';
	gotoxy(40,3);
	printf("\n     !!!!Nama Invalid!!!!");
	SINI2:
    gotoxy(40,4);
	printf ("\n\n\nLupa Nama Akun Anda? (Y/T): ");
	scanf (" %c",&jwb);
		if(jwb=='y' || jwb=='Y')
		{
			system ("cls");
			main();
		}
		else if(jwb=='t' || jwb=='T')
		{
			goto INPUT;
		}

		else
		{
			system ("cls");
			gotoxy(40,3);
			printf("\t++++KESALAHAN INPUT++++");
			goto SINI2;
		}
	}

	else if(strcmp(cek_user, User)==0&&strcmp(cek_pass, Pass)==1)
	{
	char jwb='y';
	gotoxy(40,3);
	printf("\n     !!!!Password Invalid!!!!");
	SINI:
    gotoxy(40,4);
	printf ("\n\n\nLupa Password? (Y/T): ");
	scanf (" %c",&jwb);
		if(jwb=='y' || jwb=='Y')
		{
			system ("cls");
			main();
		}
		else if(jwb=='t' || jwb=='T')
		{
			goto INPUT;
		}

		else
		{
			system ("cls");
			gotoxy(40,3);
			printf("\t++++KESALAHAN INPUT++++");
			goto SINI;
		}
	}
	else
	{
	char jwb='y';
	gotoxy(40,3);
	printf ("  !!!!Akun tidak ditemukan!!!!");
	SINI3:
    gotoxy(40,4);
	printf ("\n\nIngin Buat Akun? (Y/T): ");
	scanf (" %c",&jwb);
		if(jwb=='y' || jwb=='Y')
		{
			system ("cls");
			main();
		}
		else if(jwb=='t' || jwb=='T')
		{
			goto INPUT;
		}

		else
		{
			system ("cls");
			gotoxy(40,3);
			printf("\t++++KESALAHAN INPUT++++");
			goto SINI3;
		}
	}
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menu()
{
    system("cls");
    int pil;
    gotoxy(40,1);
    printf("=============================\n");
    gotoxy(53,3);
    printf("MENU\n");
    gotoxy(40,5);
    printf("=============================\n");
    gotoxy(41,7);
    printf("1. Tambah Pasien\n");
    gotoxy(41,8);
    printf("2. Harga Kamar\n");
    gotoxy(41,9);
    printf("3. Harga Obat\n");
    gotoxy(41,10);
    printf("4. Exit\n");
    gotoxy(40,12);
    printf("=============================\n");
    printf("\t\t\t\t\t pilihan: ");
    scanf("%d",&pil);
    switch(pil)
    {

        case 1:
            system("cls");
            input_nama();
            break;

        case 2:
            system("cls");
            harga_kamar();
            break;

        case 3:
            system("cls");
            harga_obat();
            break;

        case 4:
            system("cls");
            exit1();
            break;

        default:
            fflush(stdin);
            menu();
    }
}

void rawat()
{
    system("cls");
    int pil;
    gotoxy(40,1);
    printf("=============================\n");
    gotoxy(48,3);
    printf("Jenis Rawat\n");
    gotoxy(40,5);
    printf("=============================\n");
    gotoxy(41,7);
    printf("1. Rawat Inap \n");
    gotoxy(41,8);
    printf("2. Rawat Jalan\n");
    gotoxy(40,10);
    printf("=============================\n");
    printf("\t\t\t\t\t pilihan: ");
    scanf("%d",&pil);
    fflush(stdin);
    switch(pil)
    {
        case 1:
            system("cls");
            harga_kamar();
            break;

        case 2:
            system("cls");
            harga_obat();
            break;

        default:
            fflush(stdin);
            rawat();

    }
}

struct pasien{
char nama[50];
char penyakit[50];
} psn[10];
idx_pasien = 0;
void input_nama()
{
    char input;
    system("cls");
    gotoxy(40,1);
    printf("=============================\n");
    gotoxy(40,3);
    printf("     TAMBAH INPUT\n");
    gotoxy(40,5);
    printf("=============================\n");
    gotoxy(41,7);
    printf("Data Pasien ke-%d\n",idx_pasien+1);
    gotoxy(41,8);
    printf("masukan nama pasien : ");
    scanf(" %[^\n]s", &psn[idx_pasien].nama);
    gotoxy(41,9);
    printf("masukkan penyakit pasien = ");
    scanf(" %[^\n]s", &psn[idx_pasien].penyakit);
    syarat:
    printf("\t\t\t\t\t pilihan: (y/n) ");
    scanf("%s", &input);
    if(input == 'y'){
        idx_pasien++;
        rawat();
    }
    else if(input == 'n'){
        menu();
    }
    else{
        fflush(stdin);
        goto syarat;
    }

}


void harga_kamar()
{
    int pil;
    gotoxy(40,1);
    printf("==================================\n");
    gotoxy(53,3);
    printf("HARGA KAMAR\n");
    gotoxy(40,5);
    printf("==================================\n");
    gotoxy(41,7);
    printf("1. Kelas 3      = Rp 350.000/hari\n");
    gotoxy(41,8);
    printf("2. Kelas 2      = Rp 600.000/hari\n");
    gotoxy(41,9);
    printf("3. Kelas 1      = Rp 900.000/hari\n");
    gotoxy(41,10);
    printf("4. VIP          = Rp 1.200.000/hari\n");
    gotoxy(41,11);
    printf("5. Executive    = Rp 1.800.000/hari\n");
    gotoxy(41,12);
    printf("6. Kembali \n");
    gotoxy(40,14);
    printf("==================================\n");
    printf("\t\t\t\t\t pilihan: ");
    scanf("%d",&pil);
    switch(pil)
    {
        case 1:
            system("cls");
            kelas_3();
            break;

        case 2:
            system("cls");
            kelas_2();
            break;

        case 3:
            system("cls");
            kelas_1();
            break;

        case 4:
            system("cls");
            vip();
            break;

        case 5:
            system("cls");
            Ex();
            break;

        case 6:
            system("cls");
            menu();
            break;

        default:
            fflush(stdin);
            harga_kamar();

    }

}
struct kelas_3
{
    char status[10];
    int prmtr;

}kls3[4] ;

void kelas_3()
{
    int pilih;
    int hari;

    char a[10];
    char b[10];
    chc:
    strcpy(a,"isi");
    strcpy(b,"kosong");

    if(kls3[0].prmtr==0){strcpy(kls3[0].status,b);}
    else if(kls3[0].prmtr==-1){strcpy(kls3[0].status,a);}

    if(kls3[1].prmtr==0){strcpy(kls3[1].status,b);}
    else if(kls3[1].prmtr==-1){strcpy(kls3[1].status,a);}

    if(kls3[2].prmtr==0){strcpy(kls3[2].status,b);}
    else if(kls3[2].prmtr==-1){strcpy(kls3[2].status,a);}

    if(kls3[3].prmtr==0){strcpy(kls3[3].status,b);}
    else if(kls3[3].prmtr==-1){strcpy(kls3[3].status,a);}

    if(kls3[4].prmtr==0){strcpy(kls3[4].status,b);}
    else if(kls3[4].prmtr==-1){strcpy(kls3[4].status,a);}

    gotoxy(40,1);
    printf("===============================\n");
    gotoxy(50,3);
    printf("KELAS 3\n");
    gotoxy(40,5);
    printf("===============================\n");
    gotoxy(41,7);
    printf("Kamar 1\tstatus: %s \n",kls3[0].status);
    gotoxy(41,8);
    printf("Kamar 2\tstatus: %s \n",kls3[1].status);
    gotoxy(41,9);
    printf("Kamar 3\tstatus: %s \n",kls3[2].status);
    gotoxy(41,10);
    printf("Kamar 4\tstatus: %s \n",kls3[3].status);
    gotoxy(41,11);
    printf("Kamar 5\tstatus: %s \n",kls3[4].status);
    gotoxy(40,13);
    printf("===============================\n");
    printf("\t\t\t\t\t pilihan: ");
    scanf("%d",&pilih);
    fflush(stdin);
    if (pilih==1||pilih==2||pilih==3||pilih==4||pilih==5)

    {
        kls3[pilih-1].prmtr--;
        if(kls3[pilih-1].prmtr<-1){kls3[pilih-1].prmtr=3;}
        system("cls");
        }

    else
    {
        fflush(stdin);
        system("cls");
        kelas_3();
    }
    if(kls3[pilih-1].prmtr==1||kls3[pilih-1].prmtr==2||kls3[pilih-1].prmtr==3){goto chc;}
    gotoxy(40,1);
    printf("===============================\n");
    gotoxy(50,3);
    printf("KELAS 3\n");
    gotoxy(40,5);
    printf("===============================\n");
    gotoxy(41,7);
    printf("berapa hari? ");
    scanf("%d",&hari);
    fflush(stdin);
    biaya_kamar=hari*350000;
    gotoxy(41,8);
    printf("biaya kamar: %d",biaya_kamar);
    fflush(stdin);
    getch();
    harga_obat();

}


struct kelas_2
{
    char status[10];
    int prmtr;

}kls2[4] ;

void kelas_2()
{
    int pilih;
    int hari;

    char a[10];
    char b[10];
    chc:
    strcpy(a,"isi");
    strcpy(b,"kosong");

    if(kls2[0].prmtr==0){strcpy(kls2[0].status,b);}
    else if(kls2[0].prmtr==-1){strcpy(kls2[0].status,a);}

    if(kls2[1].prmtr==0){strcpy(kls2[1].status,b);}
    else if(kls2[1].prmtr==-1){strcpy(kls2[1].status,a);}

    if(kls2[2].prmtr==0){strcpy(kls2[2].status,b);}
    else if(kls2[2].prmtr==-1){strcpy(kls2[2].status,a);}

    if(kls2[3].prmtr==0){strcpy(kls2[3].status,b);}
    else if(kls2[3].prmtr==-1){strcpy(kls2[3].status,a);}

    if(kls2[4].prmtr==0){strcpy(kls2[4].status,b);}
    else if(kls2[4].prmtr==-1){strcpy(kls2[4].status,a);}

    gotoxy(40,1);
    printf("===============================\n");
    gotoxy(50,3);
    printf("KELAS 2\n");
    gotoxy(40,5);
    printf("===============================\n");
    gotoxy(41,7);
    printf("Kamar 1\tstatus: %s \n",kls2[0].status);
    gotoxy(41,8);
    printf("Kamar 2\tstatus: %s \n",kls2[1].status);
    gotoxy(41,9);
    printf("Kamar 3\tstatus: %s \n",kls2[2].status);
    gotoxy(41,10);
    printf("Kamar 4\tstatus: %s \n",kls2[3].status);
    gotoxy(41,11);
    printf("Kamar 5\tstatus: %s \n",kls2[4].status);
    gotoxy(40,13);
    printf("===============================\n");
    printf("\t\t\t\t\t pilihan: ");
    scanf("%d",&pilih);
    fflush(stdin);
    if (pilih==1||pilih==2||pilih==3||pilih==4||pilih==5)

    {
        kls2[pilih-1].prmtr--;
        if(kls2[pilih-1].prmtr<-1){kls2[pilih-1].prmtr=3;}
        system("cls");
        }

    else
    {
        fflush(stdin);
        system("cls");
        kelas_2();
    }
    if(kls2[pilih-1].prmtr==1||kls2[pilih-1].prmtr==2||kls2[pilih-1].prmtr==3){goto chc;}
    gotoxy(40,1);
    printf("===============================\n");
    gotoxy(50,3);
    printf("KELAS 2\n");
    gotoxy(40,5);
    printf("===============================\n");
    gotoxy(41,7);
    printf("berapa hari? ");
    scanf("%d",&hari);
    fflush(stdin);
    biaya_kamar=hari*600000;
    gotoxy(41,8);
    printf("biaya kamar: %d",biaya_kamar);
    fflush(stdin);
    getch();
    harga_obat();

}


struct kelas_1
{
    char status[10];
    int prmtr;

}kls1[4] ;

void kelas_1()
{
    int pilih;
    int hari;

    char a[10];
    char b[10];
    chc:
    strcpy(a,"isi");
    strcpy(b,"kosong");

    if(kls1[0].prmtr==0){strcpy(kls1[0].status,b);}
    else if(kls1[0].prmtr==-1){strcpy(kls1[0].status,a);}

    if(kls1[1].prmtr==0){strcpy(kls1[1].status,b);}
    else if(kls1[1].prmtr==-1){strcpy(kls1[1].status,a);}

    if(kls1[2].prmtr==0){strcpy(kls1[2].status,b);}
    else if(kls1[2].prmtr==-1){strcpy(kls1[2].status,a);}

    if(kls1[3].prmtr==0){strcpy(kls1[3].status,b);}
    else if(kls1[3].prmtr==-1){strcpy(kls1[3].status,a);}

    if(kls1[4].prmtr==0){strcpy(kls1[4].status,b);}
    else if(kls1[4].prmtr==-1){strcpy(kls1[4].status,a);}

    gotoxy(40,1);
    printf("===============================\n");
    gotoxy(50,3);
    printf("KELAS 1\n");
    gotoxy(40,5);
    printf("===============================\n");
    gotoxy(41,7);
    printf("Kamar 1\tstatus: %s \n",kls1[0].status);
    gotoxy(41,8);
    printf("Kamar 2\tstatus: %s \n",kls1[1].status);
    gotoxy(41,9);
    printf("Kamar 3\tstatus: %s \n",kls1[2].status);
    gotoxy(41,10);
    printf("Kamar 4\tstatus: %s \n",kls1[3].status);
    gotoxy(41,11);
    printf("Kamar 5\tstatus: %s \n",kls1[4].status);
    gotoxy(40,13);
    printf("===============================\n");
    printf("\t\t\t\t\t pilihan: ");
    scanf("%d",&pilih);
    fflush(stdin);
    if (pilih==1||pilih==2||pilih==3||pilih==4||pilih==5)

    {
        kls1[pilih-1].prmtr--;
        if(kls1[pilih-1].prmtr<-1){kls1[pilih-1].prmtr=3;}
        system("cls");
        }

    else
    {
        fflush(stdin);
        system("cls");
        kelas_1();
    }
    if(kls1[pilih-1].prmtr==1||kls1[pilih-1].prmtr==2||kls1[pilih-1].prmtr==3){goto chc;}
    gotoxy(40,1);
    printf("===============================\n");
    gotoxy(50,3);
    printf("KELAS 1\n");
    gotoxy(40,5);
    printf("===============================\n");
    gotoxy(41,7);
    printf("berapa hari? ");
    scanf("%d",&hari);
    fflush(stdin);
    biaya_kamar=hari*900000;
    gotoxy(41,8);
    printf("biaya kamar: %d",biaya_kamar);
    fflush(stdin);
    getch();
    harga_obat();

}


struct kelas_VIP
{
    char status[10];
    int prmtr;

}VIP[4] ;

void vip()
{
    int pilih;
    int hari;
    char a[10];
    char b[10];
    chc:
    strcpy(a,"isi");
    strcpy(b,"kosong");

    if(VIP[0].prmtr==0){strcpy(VIP[0].status,b);}
    else if(kls3[0].prmtr==-1){strcpy(kls3[0].status,a);}

    if(VIP[1].prmtr==0){strcpy(VIP[1].status,b);}
    else if(VIP[1].prmtr==-1){strcpy(VIP[1].status,a);}

    if(VIP[2].prmtr==0){strcpy(VIP[2].status,b);}
    else if(VIP[2].prmtr==-1){strcpy(VIP[2].status,a);}

    if(VIP[3].prmtr==0){strcpy(VIP[3].status,b);}
    else if(VIP[3].prmtr==-1){strcpy(VIP[3].status,a);}

    if(VIP[4].prmtr==0){strcpy(VIP[4].status,b);}
    else if(VIP[4].prmtr==-1){strcpy(VIP[4].status,a);}

    gotoxy(40,1);
    printf("===============================\n");
    gotoxy(55,3);
    printf("VIP\n");
    gotoxy(40,5);
    printf("===============================\n");
    gotoxy(41,7);
    printf("Kamar 1\tstatus: %s \n",VIP[0].status);
    gotoxy(41,8);
    printf("Kamar 2\tstatus: %s \n",VIP[1].status);
    gotoxy(41,9);
    printf("Kamar 3\tstatus: %s \n",VIP[2].status);
    gotoxy(41,10);
    printf("Kamar 4\tstatus: %s \n",VIP[3].status);
    gotoxy(41,11);
    printf("Kamar 5\tstatus: %s \n",VIP[4].status);
    gotoxy(40,13);
    printf("===============================\n");
    printf("\t\t\t\t\t pilihan: ");
    scanf("%d",&pilih);
    fflush(stdin);
    if (pilih==1||pilih==2||pilih==3||pilih==4||pilih==5)

    {
        VIP[pilih-1].prmtr--;
        if(VIP[pilih-1].prmtr<-1){VIP[pilih-1].prmtr=3;}
        system("cls");
        }

    else
    {
        fflush(stdin);
        system("cls");
        vip();
    }
    if(VIP[pilih-1].prmtr==1||VIP[pilih-1].prmtr==2||VIP[pilih-1].prmtr==3){goto chc;}
    gotoxy(40,1);
    printf("===============================\n");
    gotoxy(50,3);
    printf("VIP\n");
    gotoxy(40,5);
    printf("===============================\n");
    gotoxy(41,7);
    printf("berapa hari? ");
    scanf("%d",&hari);
    fflush(stdin);
    biaya_kamar=hari*1200000;
    gotoxy(41,8);
    printf("biaya kamar: %d",biaya_kamar);
    fflush(stdin);
    getch();
    harga_obat();

}


struct kelas_EX
{
    char status[10];
    int prmtr;

}EX[2] ;

void Ex()
{
    int pilih;
    int hari;

    char a[10];
    char b[10];
    chc:
    strcpy(a,"isi");
    strcpy(b,"kosong");

    if(EX[0].prmtr==0){strcpy(EX[0].status,b);}
    else if(EX[0].prmtr==-1){strcpy(EX[0].status,a);}

    if(EX[1].prmtr==0){strcpy(EX[1].status,b);}
    else if(EX[1].prmtr==-1){strcpy(EX[1].status,a);}

    if(EX[2].prmtr==0){strcpy(EX[2].status,b);}
    else if(EX[2].prmtr==-1){strcpy(EX[2].status,a);}

    gotoxy(40,1);
    printf("===============================\n");
    gotoxy(50,3);
    printf("Executive\n");
    gotoxy(40,5);
    printf("===============================\n");
    gotoxy(41,7);
    printf("Kamar 1\tstatus: %s \n",EX[0].status);
    gotoxy(41,8);
    printf("Kamar 2\tstatus: %s \n",EX[1].status);
    gotoxy(41,9);
    printf("Kamar 3\tstatus: %s \n",EX[2].status);
    gotoxy(40,11);
    printf("===============================\n");
    printf("\t\t\t\t\t pilihan: ");
    scanf("%d",&pilih);
    fflush(stdin);
    if (pilih==1||pilih==2||pilih==3||pilih==4||pilih==5)

    {
        EX[pilih-1].prmtr--;
        if(EX[pilih-1].prmtr<-1){EX[pilih-1].prmtr=3;}
        system("cls");
        }

    else
    {
        fflush(stdin);
        system("cls");
        Ex();
    }
    if(EX[pilih-1].prmtr==1||EX[pilih-1].prmtr==2||EX[pilih-1].prmtr==3){goto chc;}
    gotoxy(40,1);
    printf("===============================\n");
    gotoxy(50,3);
    printf("Executive\n");
    gotoxy(40,5);
    printf("===============================\n");
    gotoxy(41,7);
    printf("berapa hari? ");
    scanf("%d",&hari);
    fflush(stdin);
    biaya_kamar=hari*1800000;
    gotoxy(41,8);
    printf("biaya kamar: %d",biaya_kamar);
    fflush(stdin);
    getch();
    harga_obat();

}


void harga_obat()
{
    int jenis,khusus,i,x,w,y,z,hitung,pilihan;
int cont;

    getch();
    system("cls");
    ulang1:
    printf ("        Jenis obat yang tersedia \n");
    printf("=========================================\n");
    printf("|[1] obat penyakit ringan  Rp.20.000    |\n");
    printf("|[2] obat penyakit berat   Rp.300.000   |\n");
    printf("|[3] obat khusus           Rp.1.000.000 |\n");
    printf("=========================================\n\n");
    printf("Pilihlah angka yang diinginkan : ");
    scanf("%d",&jenis);

    switch(jenis){
    case 1 :
        //memilih president suite
        printf("    obat penyakit ringan    \n");
        printf("Harga : 20.000       \n");
        i=20000;
        printf("Jumlah pemesanan : ");
        scanf("%d",&x);
        totalharga=x*i;
        printf("Total pemesanan obat = Rp.%d\n", totalharga);
        getchar();
        cont=getchar();
        printf("harga obat anda = Rp.%d.\n\n",totalharga);
        system("pause");
        system("cls");
        total_biaya();
        break;

    case 2 :

        printf("    obat penyakit berat     \n");
        printf("Harga : 300.000      \n");
        y=300000;
        printf("Jumlah pemesanan : ");
        scanf("%d",&x);
        totalharga=x*y;
        printf("Total pemesanan obat = Rp.%d\n", totalharga);
        getchar();
        cont=getchar();
        printf("harga obat anda = Rp.%d.\n\n",totalharga);
        system("pause");
        system("cls");
        total_biaya();
        break;

    case 3 :
        printf("    obat khusus    \n");
        printf("Harga : 1.000.000       \n");
        z=1000000;
        printf("Jumlah pemesanan : ");
        scanf("%d",&x);
        totalharga=x*z;
        printf("Total pemesanan obat = Rp.%d\n", totalharga);\
        getchar();
        cont=getchar();
        system("pause");
        system("cls");
        total_biaya();
        break;




    default:
        fflush(stdin);
        harga_obat();
    }

}


void total_biaya()
{
    system("cls");
    int total=biaya_kamar+totalharga;
    gotoxy(40,1);
    printf("===============================\n");
    gotoxy(50,3);
    printf("Total Biaya:\n");
    gotoxy(40,5);
    printf("===============================\n");
    gotoxy(41,7);
    printf("Nama: %s\n",psn->nama);
    gotoxy(41,8);
    printf("Penyakit: %s\n",psn->penyakit);
    gotoxy(41,9);
    printf("Total biaya: \n");
    gotoxy(41,10);
    printf("kamar: %d\n",biaya_kamar);
    gotoxy(41,11);
    printf("obat: %d\n", totalharga);
    gotoxy(40,13);
    printf("===============================\n");
    printf("\t\t\t\t\t Total: %d",total);
    getch();
    menu();

}

void exit1()
{
    system("cls");
    gotoxy(40,1);
    printf("================================================\n");
    gotoxy(40,2);
    printf("|                                              |\n");
    gotoxy(40,3);
    printf("|                TERIIMA KASIH                 |\n");
    gotoxy(40,4);
    printf("|                                              |\n");
    gotoxy(40,5);
    printf("================================================\n");
    gotoxy(40,6);
    printf("| Author :                                     |\n");
    gotoxy(40,7);
    printf("|                                              |\n");
    gotoxy(40,8);
    printf("| Christopher Arvin Tungady 672022279          |\n");
    gotoxy(40,9);
    printf("| Eugene Tanuwijaya 672022275                  |\n");
    gotoxy(40,10);
    printf("| Emanuell Devtavalandra Rahmanto 672022091    |\n");
    gotoxy(40,11);
    printf("================================================\n");
    getch();
    exit(0);
}
int main()
{
    reg();
    menu();
    return 0;
}
