#include <stdio.h>


struct mahasiswa{
char nama[50];
char penyakit[50];
} mhs[10];

idx_pasien = 0;

void input_nama()
{
    char input;
    system("cls");
    printf("=============================\n");
    printf("     TAMBAH INPUT\n");
    printf("=============================\n");
    printf("Data Pasien ke-%d\n",idx_pasien+1);
    printf("masukan nama pasien : ");
    scanf(" %[^\n]s", &mhs[idx_pasien].nama);
    printf("masukkan penyakit pasien = ");
    scanf(" %[^\n]s", &mhs[idx_pasien].penyakit);
    syarat:
    printf("masukkan input = ");
    scanf("%s", &input);
    if(input == 'y'){
        idx_pasien++;
        input_nama();
    }
    else if(input == 'n'){
        exit(0);
    }
    else{
        printf("input salah\n");
        goto syarat;
    }

}

int main(){
input_nama();
}
