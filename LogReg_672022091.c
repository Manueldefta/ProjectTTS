#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>


void main()
{
	//Simpan Data
	FILE *inputfile = NULL;
	FILE *outputfile = NULL;
	FILE *currentfile = NULL;

	FILE *inputfile2 = NULL;
	FILE *outputfile2 = NULL;
	FILE *currentfile2 = NULL;

	char user[100],pass[100];
	char jawab='Y';


	inputfile= fopen ("DATABASE.txt","r");
	inputfile2= fopen ("DATABASE PW.txt","r");
	outputfile= fopen ("DATABASE.txt","w");
	outputfile2= fopen ("DATABASE PW.txt","w");
ULANG:

	system ("cls");
	printf ("==========PENDAFTARAN==========\n");
	printf (" NAMA AKUN\t:");
	scanf (" %[^\n]s",user);
	printf (" Password\t:");
	scanf (" %[^\n]s",pass);

	if(strlen(user)<8||strlen(pass)<8)
	{
		system("cls");
		printf("\t\t+++++ERROR! KESALAHAN INPUT!+++++");
		printf("\n\n\tNAMA AKUN/PASSWORD HARUS LEBIH DARI 8 KARAKTER!!!");
		printf("\n\nTekan apa saja untuk memasukkan ulang...");
		getch();
		goto ULANG;
	}
	else
	{
		BALIK:
		printf ("\n\nApakah Anda Yakin?(Y/T): ");
		scanf (" %c",&jawab);
		if (jawab=='Y')
		{
			goto LANJUT;
		}
		else if (jawab=='T')
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

	printf("======================================\n");
	printf("          BERHASIL MENDAFTAR          \n");
	printf("======================================");
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
	printf("==================================\n");
	printf("            MENU LOGIN          \n");
	printf("==================================");
	printf ("\nNama Akun\t: ");
	scanf (" %[^\n]s",User);
	printf ("Password\t: ");
	scanf (" %[^\n]s",Pass);


	if(strcmp(cek_user, User)==0&&strcmp(cek_pass, Pass)==0)
	{

	}
	else if(strcmp(cek_user, User)==1&&strcmp(cek_pass, Pass)==0)
	{
	char jwb='Y';
	printf("\n     !!!!Nama Invalid!!!!");
	SINI2:
	printf ("\n\n\nLupa Nama Akun Anda? (Y/T): ");
	scanf (" %c",&jwb);
		if(jwb=='Y')
		{
			system ("cls");
			main();
		}
		else if(jwb=='T')
		{
			goto INPUT;
		}

		else
		{
			system ("cls");
			printf("\t++++KESALAHAN INPUT++++");
			goto SINI2;
		}
	}

	else if(strcmp(cek_user, User)==0&&strcmp(cek_pass, Pass)==1)
	{
	char jwb='Y';
	printf("\n     !!!!Password Invalid!!!!");
	SINI:
	printf ("\n\n\nLupa Password? (Y/T): ");
	scanf (" %c",&jwb);
		if(jwb=='Y')
		{
			system ("cls");
			main();
		}
		else if(jwb=='T')
		{
			goto INPUT;
		}

		else
		{
			system ("cls");
			printf("\t++++KESALAHAN INPUT++++");
			goto SINI;
		}
	}
	else
	{
	char jwb='Y';
	printf ("  !!!!Akun tidak ditemukan!!!!");
	SINI3:
	printf ("\n\nIngin Buat Akun? (Y/T): ");
	scanf (" %c",&jwb);
		if(jwb=='Y')
		{
			system ("cls");
			main();
		}
		else if(jwb=='T')
		{
			goto INPUT;
		}

		else
		{
			system ("cls");
			printf("\t++++KESALAHAN INPUT++++");
			goto SINI3;
		}
	}
}

