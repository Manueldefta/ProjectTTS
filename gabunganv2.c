#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int biaya_kamar;
int totalharga;


char username[20];
char passlog[20];

void login()
{
    char user[20];
    char pass[20];

    int i;

    while (1) {
    system("cls");
    system("cls");
    gotoxy(40,1);
    printf("==============================\n");
    gotoxy(48,3);
    printf("TUGAS RUMAH SAKIT");
    gotoxy(40,5);
    printf("==============================\n");
    gotoxy(40,8);
    printf("Masukan Username: ");
    scanf("%[^\n]s",&username);
    fflush(stdin);
    gotoxy(40,9);
    printf("Masukan Password: ");
    i = 0;
    while (1) {
        char c = getch();
        if (c == '\r') {
            pass[i] = '\0';
            break;
        } else if (c == '\b') {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            pass[i] = c;
            i++;
            printf("*");
        }
    }
    printf("\n");
    system("cls");
    fflush(stdin);
    gotoxy(40,1);
    printf("==============================\n");
    gotoxy(48,3);
    printf("TUGAS RUMAH SAKIT");
    gotoxy(40,5);
    printf("==============================\n");
    gotoxy(40,8);
    printf("Masukan Username: ");
    scanf("%s",&user);
    fflush(stdin);
    gotoxy(40,9);
    printf("Masukan Password: ");
    i = 0;
    while (1) {
        char c = getch();
        if (c == '\r') {
            passlog[i] = '\0';
            break;
        } else if (c == '\b') {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            passlog[i] = c;
            i++;
            printf("*");
        }
    }
    printf("\n");


    if (strcmp(username, user) == 0 && strcmp(pass, passlog) == 0)
        {
            system("cls");
            gotoxy(40,1);
            printf("==============================\n");
            gotoxy(48,3);
            printf("TUGAS RUMAH SAKIT");
            gotoxy(40,5);
            printf("==============================\n");
            gotoxy(40,8);
            printf("Selamat Login telah berhasil\n");
            system("pause");
            menu();
        }
    else {
    gotoxy(40,10);
    printf("Username dan Password salah\n");
    system("pause");
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
    char pil;
    do{
        gotoxy(40,1);
        printf("=============================\n");
        gotoxy(48,2);
        printf("MENU RUMAH SAKIT\n");
        gotoxy(40,3);
        printf("=============================\n");
        gotoxy(45,5);
        printf("1. Tambah Data\n");
        gotoxy(45,6);
        printf("2. Lihat Data\n");
        gotoxy(45,7);
        printf("3. Pilih Data\n");
        gotoxy(45,8);
        printf("4. Edit Data\n");
        gotoxy(45,9);
        printf("5. Hapus Data\n");
        gotoxy(45,10);
        printf("6. Keluar\n");
        gotoxy(40,12);
        printf("=============================\n");
        gotoxy(41,13);
        printf("Pilihan : ");
        scanf(" %[^\n]s", &pil);
        switch(pil){
            case '1' : TambahData();break;
            case '2' : LihatData();break;
            case '3' : PilihData();break;
            case '4' : editData();break;
            case '5' : deleteData();break;
            case '6' : exit(0);break;
            default : printf("Inputan Salah\n\n");break;
        }
        getch();
        system("cls");
    }while(pil != '6');
}
struct pasien{
    char nama [30], alamat[100], penyakit[30];
    int umur;
    struct pasien *next;
}*head, *tail, *current;

void LihatData(){
    if(head == NULL){
        printf("Belum ada Data, silahkan input dulu!\n");
    }else{
        // Menghitung jumlah elemen pada linked list
        current = head;
        int count = 0;
        while(current != NULL){
            count++;
            current = current->next;
        }
        // Menyimpan data dari linked list ke array
        struct pasien arr[count];
        current = head;
        int i = 0;
        while(current != NULL){
            strcpy(arr[i].nama, current->nama);
            strcpy(arr[i].alamat, current->alamat);
            strcpy(arr[i].penyakit, current->penyakit);
            arr[i].umur = current->umur;
            i++;
            current = current->next;
        }
        // Sorting data pada array
        for (int i = 0; i < count-1; i++){
            for (int j = i+1; j < count; j++){
                if (strcmp(arr[i].nama, arr[j].nama) > 0){
                    struct pasien temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        // Menampilkan data yang sudah diurutkan
        i = 1;
        gotoxy(41,14);
        printf("Data yang sudah diurutkan:\n\n");
        for (int j = 0; j < count; j++){

            printf("\t\t\t\t\t Data ke - %i\n", i);

            printf("\t\t\t\t\t Nama     : %s\n", arr[j].nama);

            printf("\t\t\t\t\t Alamat   : %s\n", arr[j].alamat);

            printf("\t\t\t\t\t Penyakit : %s\n", arr[j].penyakit);

            printf("\t\t\t\t\t Umur     : %i\n", arr[j].umur);
            printf("\n");
            i++;
        }
    }
    printf("\n");
}

void TambahData(){
    char nama [30], alamat[100], penyakit[30];
    int umur;
    current = (struct pasien*)malloc(sizeof(struct pasien));

    gotoxy(41,14);
    printf("Nama     : ");fflush(stdin);gets(nama);
    gotoxy(41,15);
    printf("Alamat   : ");scanf("%s", &alamat);
    gotoxy(41,16);
    printf("Penyakit : ");fflush(stdin);gets(penyakit);
    gotoxy(41,17);
    printf("Umur     : ");scanf("%i", &umur);

    strcpy(current->nama, nama);
    strcpy(current->alamat, alamat);
    strcpy(current->penyakit, penyakit);
    current->umur = umur;

    if(head == NULL){
        head = tail = current;
    }
    else{
        tail->next = current;
        tail = current;
    }
    tail->next = NULL;

    gotoxy(41,18);
    printf("Data berhasil diinput");
}

void PilihData(){
    if(head==NULL){
        printf("Belum ada Data, silahkan input dulu!\n");
    }else{
        current = head;

        char nama [30];
        printf("Cari nama yang mau dipilih : ");scanf("%s", &nama);

        while (current != NULL) {
            if (strcmp(current->nama, nama)==0){
            gotoxy(41,14);
            printf("Nama     : %s\n", current->nama);
            gotoxy(41,15);
            printf("Alamat   : %s\n", current->alamat);
            gotoxy(41,16);
            printf("Penyakit : %s\n", current->penyakit);
            gotoxy(41,17);
            printf("Umur     : %i\n", current->umur);
            getch();
            rawat();
            break;
            }else if(current == NULL || current->next==NULL){
                gotoxy(41,14);printf("\nData tidak ada");
            }
            current = current->next;
        }
    }
}

void editData(){
    if(head==NULL){
        gotoxy(41,14);
        printf("Belum ada Data, silahkan input dulu!\n");
    }else{
        current = head;

        char nama [30];
        gotoxy(41,14);
        printf("Cari nama yang mau diedit : ");scanf("%s", &nama);

        while (current != NULL) {
            if (strcmp(current->nama, nama)==0){
            gotoxy(41,15);
            printf("Nama     : %s\n", current->nama);
            gotoxy(41,16);
            printf("Alamat   : %s\n", current->alamat);
            gotoxy(41,17);
            printf("Penyakit : %s\n", current->penyakit);
            gotoxy(41,18);
            printf("Umur     : %i\n", current->umur);
            gotoxy(41,19);
                printf("EDIT DATA\n");
                char penyakitBaru[30];
                gotoxy(41,20);
                printf("Penyakit baru : ");fflush(stdin);gets(penyakitBaru);
                strcpy(current->penyakit, penyakitBaru);

                gotoxy(41,21);printf("Data berhasil diedit");
                break;
            }else if(current == NULL || current->next==NULL){
                gotoxy(41,15);printf("Data tidak ada");
            }
            current = current->next;
        }
    }
}

void deleteData(){
    if (head == NULL){
        gotoxy(41,14);
        printf("Belum ada Data, silahkan input dulu!");
    }else{
        struct pasien *temp = head;
        current = head;

        char nama [30];
        gotoxy(41,14);
        printf("Cari nama yang mau dihapus : ");scanf("%s", &nama);

        int index = 0;
        while (current != NULL) {
            if (strcmp(current->nama, nama)==0){
                break;
            }
            index++;
            current = current->next;
        }
        if (index == 0){
            head = temp->next;
            free(temp);
            gotoxy(41,15);
            printf("Data berhasil dihapus");
        }else{
            for (int i=0; temp!=NULL && i<index-1; i++){
                temp = temp->next;
            }
            if (temp == NULL || temp->next == NULL){
                gotoxy(41,15);printf("Data tidak ada");

            }else{
                struct pasien *next = temp->next->next;
                free(temp->next);
                temp->next = next;
                gotoxy(41,15);
                printf("Data berhasil dihapus");
            }
        }
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


here:

hotel:
    system("cls");
    ulang1:
    gotoxy(41,1);
    printf ("        Jenis obat yang tersedia \n");
    //Jenis Kamar
    gotoxy(41,2);
    printf("=========================================\n");
    gotoxy(41,3);
    printf("|[1] obat penyakit ringan  Rp.20.000    |\n");
    gotoxy(41,4);
    printf("|[2] obat penyakit berat   Rp.300.000   |\n");
    gotoxy(41,5);
    printf("|[3] obat khusus           Rp.1.000.000 |\n");
    gotoxy(41,6);
    printf("=========================================\n\n");
    gotoxy(41,8);
    printf("Pilihlah angka yang diinginkan : ");
    scanf("%d",&jenis);

    switch(jenis){
    case 1 :
        //memilih president suite
        gotoxy(41,10);
        printf("    obat penyakit ringan    \n");
        gotoxy(41,11);
        printf("Harga : 20.000       \n");
        i=20000;
        gotoxy(41,12);
        printf("Jumlah pemesanan : ");
        scanf("%d",&x);
        totalharga=x*i;
        gotoxy(41,13);
        printf("Total pemesanan obat = Rp.%d\n", totalharga);
        getchar();//Membaca input y/n
        cont=getchar();//variabel untul menyimpan y/n
        gotoxy(41,14);
        printf("harga obat anda = Rp.%d.\n\n",totalharga);
        system("pause");
        system("cls");
        total_biaya();
        break;

    case 2 :

        gotoxy(41,10);
        printf("    obat penyakit berat     \n");
        gotoxy(41,11);
        printf("Harga : 300.000      \n");
        y=300000;
        gotoxy(41,12);
        printf("Jumlah pemesanan : ");
        scanf("%d",&x);
        totalharga=x*y;
        gotoxy(41,13);
        printf("Total pemesanan obat = Rp.%d\n", totalharga);
        getchar();//Membaca input y/n
        cont=getchar();//variabel untul menyimpan y/n
        gotoxy(41,14);
        printf("harga obat anda = Rp.%d.\n\n",totalharga);
        system("pause");
        system("cls");
        total_biaya();
        break;

    case 3 :
        gotoxy(41,10);
        printf("    obat khusus    \n");
        gotoxy(41,11);
        printf("Harga : 1.000.000       \n");
        z=1000000;
        gotoxy(41,12);
        printf("Jumlah pemesanan : ");
        scanf("%d",&x);
        totalharga=x*z;
        gotoxy(41,13);
        printf("Total pemesanan obat = Rp.%d\n", totalharga);\
        getchar();//Membaca input y/n
        cont=getchar();//variabel untul menyimpan y/n
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
    printf("Nama: %s\n",current->nama);
    gotoxy(41,8);
    printf("Penyakit: %s\n",current->penyakit);
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
    system("color 70");
    login();
    menu();
    return 0;
}
