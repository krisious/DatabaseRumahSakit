#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct dokter{
    char id[5];
    char nama[30];
    char jenkel[10];
    char spesialis[100];
}dokter;

typedef struct pasien{
    char id[5];
    char dokter[5];
    char obat[5];
    char nama[30];
    int umur;
    char jenkel[10];
    char ruangan[4];
    char penyakit[20];
}pasien;

typedef struct obat{
    char id[5];
    char nama[30];
    char jenis[6];
    int stok;
}obat;

//Fungsi Menu
void PilihMenuUtama();
int MenuUtama();
int MenuDokter();
int SubmenuDokter();
int MenuPasien();
int SubmenuPasien();
int MenuObat();
int SubmenuObat();

//Fungsi Dokter
void TambahDataDokter();
void TampilkanDataDokter();
void CariDataDokter();
void UbahDataDokter();
void HapusDataDokter();
void UrutkanDataDokter();
int SubmenuUrutkanDataDokter();
void UrutkanNamaDokter();
void UrutkanSpesialisDokter();

//Fungsi Pasien
void TambahDataPasien();
void TampilkanDataPasien();
void CariDataPasien();
void UbahDataPasien();
void HapusDataPasien();
void UrutkanDataPasien();
int SubmenuUrutkanDataPasien();
void UrutkanNamaPasien();
void UrutkanRuanganPasien();
void UrutkanPenyakitPasien();

//Fungsi Obat
void TambahDataObat();
void TampilkanDataObat();
void CariDataObat();
void UbahDataObat();
void HapusDataObat();
void UrutkanDataObat();
int SubmenuUrutkanDataObat();
void UrutkanNamaObat();
void UrutkanJenisObat();

//Fungsi Database
void CheckDatabase();
void SortDatabaseRecordDokter();
void SortDatabaseRecordPasien();
void SortDatabaseRecordPasien();

void main(){
    printf("\n\n\n\n");
    printf("\t\t\t\t      ========================================================================================\n");
    printf("\t\t\t\t      ||                                                                                    ||\n");
    printf("\t\t\t\t      ||__________________________TUGAS UAS ALGORITMA DAN PEMROGRAMAN_______________________||\n");
    printf("\t\t\t\t      ||________________________________FAKULTAS ILMU KOMPUTER______________________________||\n");
    printf("\t\t\t\t      ||__________________________________S1 SISTEM INFORMASI_______________________________||\n");
    printf("\t\t\t\t      ||________________________________________KELAS A_____________________________________||\n");
    printf("\t\t\t\t      ||                                                                                    ||\n");
    printf("\t\t\t\t      ========================================================================================\n\n\n");

    printf("\t\t\t\t      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t      ||                                    KELOMPOK NINDdev                                ||\n");
    printf("\t\t\t\t      ||                              Dwi Krisdiyanto   (2110512018)                        ||\n");
    printf("\t\t\t\t      ||                              Khaliza Fania     (2110512020)                        ||\n");
    printf("\t\t\t\t      ||                              Isabel Rose       (2110512012)                        ||\n");
    printf("\t\t\t\t      ||                              Muhammad Naufal T (2110512023)                        ||\n");
    printf("\t\t\t\t      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    getch();

    CheckDatabase();
    getch();

    PilihMenuUtama();
    getch();
}

void CheckDatabase(){
    FILE *Dokter;
    FILE *Pasien;
    FILE *Obat;
    system("cls");

    printf("Pengecekan Database\n");
    if(Dokter=fopen("Dokter.bin","rb+")){
            printf("Database Dokter ditemukan . . .\n");
    }else{
        printf("Database Dokter tidak ditemukan, buat database Dokter baru . . .\n");
        fclose(Dokter);
        fopen("Dokter.bin","wb+");
        }

    if(Pasien=fopen("Pasien.bin","rb+")){
            printf("Database Pasien ditemukan . . .\n");
    }else{
        printf("Database Pasien tidak ditemukan, buat database Pasien baru . . .\n");
        fclose(Pasien);
        fopen("Pasien.bin","wb+");
        }

    if(Obat=fopen("Obat.bin","rb+")){
            printf("Database Obat ditemukan . . .\n");
    }else{
        printf("Database Obat tidak ditemukan, buat database Obat baru . . .\n");
        fclose(Obat);
        fopen("Obat.bin","wb+");
        }
}

void SortDatabaseRecordDokter(){
    dokter *sort, unsort;
    FILE *Dokter;

    Dokter = fopen("Dokter.bin","rb");
    fseek(Dokter,0,SEEK_END);
    int n = ftell(Dokter)/sizeof(dokter);
    sort = (dokter*)calloc(n,sizeof(dokter));

    rewind(Dokter);
    for(int i=0;i<n;i++)
        fread(&sort[i],sizeof(dokter),1,Dokter);
    fclose(Dokter);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp (sort[i].id,sort[j].id)>0){
                unsort = sort[i];
                sort[i] = sort[j];
                sort[j] = unsort;
            }
        }
    }
    Dokter = fopen("Dokter.bin","wb");

    for(int i=0;i<n;i++){
        fwrite(&sort[i],sizeof(dokter),1,Dokter);
    }

    fclose(Dokter);
}

void SortDatabaseRecordPasien(){
    pasien *sort, unsort;
    FILE *Pasien;

    Pasien = fopen("Pasien.bin","rb");
    fseek(Pasien,0,SEEK_END);
    int n = ftell(Pasien)/sizeof(pasien);
    sort = (pasien*)calloc(n,sizeof(pasien));

    rewind(Pasien);
    for(int i=0;i<n;i++)
        fread(&sort[i],sizeof(pasien),1,Pasien);
    fclose(Pasien);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp (sort[i].id,sort[j].id)>0){
                unsort = sort[i];
                sort[i] = sort[j];
                sort[j] = unsort;
            }
        }
    }
    Pasien = fopen("Pasien.bin","wb");

    for(int i=0;i<n;i++){
        fwrite(&sort[i],sizeof(pasien),1,Pasien);
    }

    fclose(Pasien);
}

void SortDatabaseRecordObat(){
    obat *sort, unsort;
    FILE *Obat;

    Obat = fopen("Obat.bin","rb");
    fseek(Obat,0,SEEK_END);
    int n = ftell(Obat)/sizeof(obat);
    sort = (obat*)calloc(n,sizeof(obat));

    rewind(Obat);
    for(int i=0;i<n;i++)
        fread(&sort[i],sizeof(obat),1,Obat);
    fclose(Obat);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp (sort[i].id,sort[j].id)>0){
                unsort = sort[i];
                sort[i] = sort[j];
                sort[j] = unsort;
            }
        }
    }
    Obat = fopen("Obat.bin","wb");

    for(int i=0;i<n;i++){
        fwrite(&sort[i],sizeof(obat),1,Obat);
    }

    fclose(Obat);
}

void PilihMenuUtama(){
    int pilihan=0;

    enum pilihan{Dokter=1,Pasien,Obat,Selesai};
    do{
        pilihan=MenuUtama();
        switch(pilihan){
        case Dokter:
            MenuDokter();
            break;
        case Pasien:
            MenuPasien();
            break;
        case Obat:
            MenuObat();
            break;
        case Selesai:
            printf("\n\n\n\n");
            printf("\t\t\t                                      Terima kasih sudah menggunakan program ini,\n\n");
            printf("\t\t\t             ######  ######  ###  ### #######  ######  ####     ####### ##  ## ###  ### #######  ######    ######\n");
            printf("\t\t\t             ##     ##    ## ## ## ## ##   ## ##    ##  ##         ##   ##  ## ## ## ## ##   ## ##    ##    ####\n");
            printf("\t\t\t             ###### ######## ##    ## ####### ########  ##         ##   ##  ## ##    ## ####### ########     ##\n");
            printf("\t\t\t                 ## ##    ## ##    ## ##      ##    ##  ##         ##   ##  ## ##    ## ##      ##    ##\n");
            printf("\t\t\t             ###### ##    ## ##    ## ##      ##    ## ####     #####   ###### ##    ## ##      ##    ##     ##\n");

            break;
            }
     }
     while(pilihan!=Selesai);
     getch();
}

int MenuUtama(){
    int input;
    time_t currentTime;
    time(&currentTime);

    MenuUtama:
    system("cls");

    do{
        printf("\n\n\n");
        printf("\t\t\t     ###### ###### ##      ######  ###   ###  ######   #######     #####    ###### #######   ######  ###   ## #######\n");
        printf("\t\t\t     ##     ##     ##     ##    ## ## ##  ## ##    ##    ##        ##   ## ##    ##   ##    ##    ## ## ## ## ##     \n");
        printf("\t\t\t     ###### ###### ##     ######## ##     ## ########    ##        ##   ## ########   ##    ######## ## ## ## #######\n");
        printf("\t\t\t         ## ##     ##     ##    ## ##     ## ##    ##    ##        ##   ## ##    ##   ##    ##    ## ##   ### ##   ##\n");
        printf("\t\t\t     ###### ###### ###### ##    ## ##     ## ##    ##    ##        #####   ##    ##   ##    ##    ## ##    ## #######\n\n\n");



        printf("\t\t\t==========================================================================================================================\n");
        printf("\t\t\t||                                                                                                                      ||\n");
        printf("\t\t\t||                                                     DI APLIKASI DATABASE                                             ||\n");
        printf("\t\t\t||                                                   RUMAH SAKIT PEDULI KASIH                                           ||\n");
        printf("\t\t\t||                                                                                                                      ||\n");
        printf("\t\t\t==========================================================================================================================\n\n");
        printf("\t\t\t                                                    %s\n",ctime(&currentTime));
        printf("\t\t\t                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t                         ||                                Menu Utama                               ||\n");
        printf("\t\t\t                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t                         || 1. Database Dokter                                                      ||\n");
        printf("\t\t\t                         || 2. Database Pasien                                                      ||\n");
        printf("\t\t\t                         || 3. Database Obat                                                        ||\n");
        printf("\t\t\t                         || 4. Keluar                                                               ||\n");
        printf("\t\t\t                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t                         Pilih database yang digunakan [1-4] : ");
        scanf("%d",&input);

        if ((input < 1)||(input > 4)){
            printf("Pilihan anda tidak ada dalam menu\n\n");
            getch();
            goto MenuUtama;
        }
    }
    while ((input < 1)||(input > 4));
    return input;
}

int MenuDokter(){
    int pilihan;

    enum pilihan{Tambah=1,Tampilkan,Cari,Ubah,Hapus,Urutkan,Kembali};
    do{
        pilihan=SubmenuDokter();
        switch(pilihan){
        case Tambah:
            printf("Tambahkan data dokter\n");
            getch();
            TambahDataDokter();
            break;
        case Tampilkan:
            printf("Tampilkan data dokter\n");
            getch();
            TampilkanDataDokter();
            break;
        case Cari:
            printf("Cari data dokter\n");
            getch();
            CariDataDokter();
            break;
        case Ubah:
            printf("Ubah data dokter\n");
            getch();
            UbahDataDokter();
            break;
        case Hapus:
            printf("Hapus data dokter\n");
            getch();
            HapusDataDokter();
            break;
        case Urutkan:
            printf("Urutkan data dokter\n");
            getch();
            UrutkanDataDokter();
            break;
        case Kembali:
            printf ("Kembali ke menu utama\n\n");
            break;
    }
    }
    while(pilihan!=Kembali);
    getch();
    return pilihan;
}

int SubmenuDokter(){
    int input;

    SubmenuDokter:
    system("cls");

    do{
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("||\t\t\t       Menu Dokter                                 ||\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("|| 1. Tambahkan data dokter                                                ||\n");
        printf("|| 2. Tampilkan data dokter                                                ||\n");
        printf("|| 3. Cari data dokter                                                     ||\n");
        printf("|| 4. Ubah data dokter                                                     ||\n");
        printf("|| 5. Hapus data dokter                                                    ||\n");
        printf("|| 6. Urutkan data dokter                                                  ||\n");
        printf("|| 7. Kembali                                                              ||\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Pilih layanan yang ingin digunakan [1-7] : ");
        scanf("%d",&input);
        fflush(stdin);
        printf("\n");

        if ((input < 1)||(input > 7)){
            printf("Pilihan anda tidak ada dalam menu\n\n");
            getch();
            goto SubmenuDokter;
        }
    }
    while ((input < 1)||(input > 7));
    return input;
}

void TambahDataDokter(){
    dokter *add;
    FILE *Dokter;
    int n;
    printf("Banyak data yang ingin dimasukkan : ");
    scanf("%d",&n);
    fflush(stdin);

    add = (dokter*)calloc(n, sizeof(dokter));
    Dokter = fopen("Dokter.bin","ab");

    for(int i=0;i<n;i++){
        printf("\nID Dokter (D000-D999)   : ");
        gets(add[i].id);
        printf("Nama Dokter             : ");
        gets(add[i].nama);
        printf("Jenis kelamin           : ");
        gets(add[i].jenkel);
        printf("Spesialis               : ");
        gets(add[i].spesialis);
        fwrite(&add[i],sizeof(dokter),1,Dokter);
    }
    fclose(Dokter);
    SortDatabaseRecordDokter();
}


void TampilkanDataDokter(){
    dokter read;
    FILE *Dokter;

    Dokter = fopen("Dokter.bin","rb");

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||                            Data Dokter                               ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||  ID  ||       Nama       ||    Jenis Kelamin    ||      Spesialis    ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while(fread(&read,sizeof(dokter),1,Dokter))
    {
        printf("||%4s  ||%16s  ||%9s            ||%19s||\n",read.id,read.nama,read.jenkel,read.spesialis);
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    fclose(Dokter);
    getch();
}

void CariDataDokter(){
    dokter search;
    FILE *Dokter;
    char id[5];
    int found=0;

    Dokter = fopen("Dokter.bin","rb");
    printf("Masukkan ID dokter (D000-D999) yang ingin dicari : ");
    gets(id);


    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||                            Data Dokter                              ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||  ID  ||       Nama      ||    Jenis Kelamin    ||      Spesialis    ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while(fread(&search,sizeof(dokter),1,Dokter))
    {
        if(strcmp(search.id,id)==0){
            found=1;
            printf("||%4s  ||%15s  ||%9s            ||%19s||\n",search.id,search.nama,search.jenkel,search.spesialis);
        }
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    if(!found)
        printf("\nData tidak ditemukan");
    fclose(Dokter);
    getch();
}

void UbahDataDokter(){
    dokter update;
    FILE *Dokter,*temp;
    char id[5];
    int found=0;

    TampilkanDataDokter();
    Dokter = fopen("Dokter.bin","rb");
    temp = fopen("temp.bin","wb");
    printf("Masukkan ID dokter (D000-D999) yang ingin diubah : ");
    gets(id);

    while(fread(&update,sizeof(dokter),1,Dokter))
    {
        if(strcmp(update.id,id)==0){
            found=1;
            printf("\nUpdate ID (D000-D999)    : ");
            gets(update.id);
            printf("Update nama              : ");
            gets(update.nama);
            printf("Update jenis kelamin     : ");
            gets(update.jenkel);
            printf("update spesialis         : ");
            gets(update.spesialis);
        }
        fwrite(&update,sizeof(dokter),1,temp);
    }
    fclose(Dokter);
    fclose(temp);


    if(found){
        temp = fopen("temp.bin","rb");
        Dokter = fopen("Dokter.bin","wb");

        while(fread(&update,sizeof(dokter),1,temp)){
            fwrite(&update,sizeof(dokter),1,Dokter);
        }
        fclose(Dokter);
        fclose(temp);
        printf ("\nData telah diubah");

    }else{
        printf("\nData tidak ditemukan\n");
    }
    SortDatabaseRecordDokter();
    getch();
}

void HapusDataDokter(){
    dokter del;
    FILE *Dokter,*temp;
    char id[5];
    int found=0;

    TampilkanDataDokter();
    Dokter = fopen("Dokter.bin","rb");
    temp = fopen("temp.bin","wb");
    printf("Masukkan ID dokter (D000-D999) yang ingin dihapus : ");
    gets(id);

    while(fread(&del,sizeof(dokter),1,Dokter))
    {
        if(strcmp(del.id,id)==0){
            found=1;
        }else
        fwrite(&del,sizeof(dokter),1,temp);
    }
    fclose(Dokter);
    fclose(temp);

    if(found){
        temp = fopen("temp.bin","rb");
        Dokter = fopen("Dokter.bin","wb");

        while(fread(&del,sizeof(dokter),1,temp)){
            fwrite(&del,sizeof(dokter),1,Dokter);
        }

        fclose(Dokter);
        fclose(temp);
        printf ("\nData telah dihapus");

    }else{
        printf("\nData tidak ditemukan\n");
    }
    getch();
}

void UrutkanDataDokter(){
    int pilihan;

    enum pilihan{Nama=1,Spesialis,Batal};
    do{
        pilihan=SubmenuUrutkanDataDokter();
        switch(pilihan){
        case Nama:
            printf("Urutkan berdasarkan nama\n");
            getch();
            UrutkanNamaDokter();
            break;
        case Spesialis:
            printf("Urutkan berdasarkan spesialis\n");
            getch();
            UrutkanSpesialisDokter();
            break;
        case Batal:
            printf ("Kembali ke menu dokter\n\n");
            break;
    }
    }
    while(pilihan!=Batal);
    getch();
    return pilihan;
}

int SubmenuUrutkanDataDokter(){
    int input;

    SubmenuUrutkanDataDokter:
    system("cls");
    do{
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("||                        Pengurutan Data Dokter                           ||\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("|| 1. Urutkan berdasarkan nama                                             ||\n");
        printf("|| 2. Urutkan berdasarkan spesialis                                        ||\n");
        printf("|| 3. Batal                                                                ||\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Pilih metode pengurutan [1-3] : ");
        scanf("%d",&input);
        fflush(stdin);
        printf("\n");

        if ((input < 1)||(input > 3)){
            printf("Pilihan anda tidak ada dalam menu\n\n");
            getch();
            goto SubmenuUrutkanDataDokter;
        }
    }
    while ((input < 1)||(input > 3));
    return input;
}

void UrutkanNamaDokter(){
    dokter *sort, unsort;
    FILE *Dokter;

    Dokter = fopen("Dokter.bin","rb");
    fseek(Dokter,0,SEEK_END);
    int n = ftell(Dokter)/sizeof(dokter);
    sort = (dokter*)calloc(n,sizeof(dokter));

    rewind(Dokter);
    for(int i=0;i<n;i++)
        fread(&sort[i],sizeof(dokter),1,Dokter);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp (sort[i].nama,sort[j].nama)>0){
                unsort = sort[i];
                sort[i] = sort[j];
                sort[j] = unsort;
            }
        }
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||                            Data Dokter                              ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||  ID  ||       Nama      ||    Jenis Kelamin    ||      Spesialis    ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for(int i=0;i<n;i++){
        printf("||%4s  ||%15s  ||%9s            ||%19s||\n",sort[i].id,sort[i].nama,sort[i].jenkel,sort[i].spesialis);
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


    fclose(Dokter);
    getch();
}

void UrutkanSpesialisDokter(){
    dokter *sort, unsort;
    FILE *Dokter;

    Dokter = fopen("Dokter.bin","rb");
    fseek(Dokter,0,SEEK_END);
    int n = ftell(Dokter)/sizeof(dokter);
    sort = (dokter*)calloc(n,sizeof(dokter));

    rewind(Dokter);
    for(int i=0;i<n;i++)
        fread(&sort[i],sizeof(dokter),1,Dokter);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp (sort[i].spesialis,sort[j].spesialis)>0){
                unsort = sort[i];
                sort[i] = sort[j];
                sort[j] = unsort;
            }
        }
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||                            Data Dokter                              ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||  ID  ||       Nama      ||    Jenis Kelamin    ||      Spesialis    ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for(int i=0;i<n;i++){
        printf("||%4s  ||%15s  ||%9s            ||%19s||\n",sort[i].id,sort[i].nama,sort[i].jenkel,sort[i].spesialis);
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    fclose(Dokter);
    getch();
}

int MenuPasien(){
    int pilihan;

    enum pilihan{Tambah=1,Tampilkan,Cari,Ubah,Hapus,Urutkan,Kembali};
    do{
        pilihan=SubmenuPasien();
        switch(pilihan){
        case Tambah:
            printf("Tambahkan data pasien\n");
            getch();
            TambahDataPasien();
            break;
        case Tampilkan:
            printf("Tampilkan data pasien\n");
            getch();
            TampilkanDataPasien();
            break;
        case Cari:
            printf("Cari data pasien\n");
            getch();
            CariDataPasien();
            break;
        case Ubah:
            printf("Ubah data pasien\n");
            getch();
            UbahDataPasien();
            break;
        case Hapus:
            printf("Hapus data pasien\n");
            getch();
            HapusDataPasien();
            break;
        case Urutkan:
            printf("Urutkan data pasien\n");
            getch();
            UrutkanDataPasien();
            break;
        case Kembali:
            printf ("Kembali ke menu utama\n\n");
            break;
    }
    }
    while(pilihan!=Kembali);
    getch();
    return pilihan;
}

int SubmenuPasien(){
    int input;

    SubmenuPasien:
    system("cls");

    do{
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("||\t\t\t       Menu Pasien                                 ||\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("|| 1. Tambahkan data pasien                                                 ||\n");
        printf("|| 2. Tampilkan data pasien                                                ||\n");
        printf("|| 3. Cari data pasien                                                     ||\n");
        printf("|| 4. Ubah data pasien                                                     ||\n");
        printf("|| 5. Hapus data pasien                                                    ||\n");
        printf("|| 6. Urutkan data pasien                                                  ||\n");
        printf("|| 7. Kembali                                                              ||\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Pilih layanan yang ingin digunakan [1-7] : ");
        scanf("%d",&input);
        fflush(stdin);
        printf("\n");

        if ((input < 1)||(input > 7)){
            printf("Pilihan anda tidak ada dalam menu\n\n");
            getch();
            goto SubmenuPasien;
        }
    }
    while ((input < 1)||(input > 7));
    return input;
}

void TambahDataPasien(){
    pasien *add;
    FILE *Pasien;
    int n;
    printf("Banyak data yang ingin dimasukkan : ");
    scanf("%d",&n);
    fflush(stdin);

    add = (pasien*)calloc(n, sizeof(pasien));
    Pasien = fopen("Pasien.bin","ab");

    for(int i=0;i<n;i++){
        printf("\nID  Pasien (P000-P999)  : ");
        gets(add[i].id);
        printf("ID Dokter (D000-D999)   : ");
        gets(add[i].dokter);
        printf("ID Obat (B000-B999)     : ");
        gets(add[i].obat);
        printf("Nama Pasien             : ");
        gets(add[i].nama);
        printf("Umur                    : ");
        scanf ("%d", &add[i].umur);
        fflush(stdin);
        printf("Jenis Kelamin           : ");
        gets(add[i].jenkel);
        printf("No Ruangan              : ");
        gets(add[i].ruangan);
        printf("Penyakit                : ");
        gets(add[i].penyakit);
        fwrite(&add[i],sizeof(pasien),1,Pasien);
    }
    fclose(Pasien);
    SortDatabaseRecordPasien();
}


void TampilkanDataPasien(){
    pasien read;
    FILE *Pasien;

    Pasien = fopen("Pasien.bin","rb");

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||                                                  Data Pasien                                                      ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("|| ID Pasien || ID Dokter || ID Obat ||   Nama Pasien  || Umur || Jenis Kelamin || No Ruangan ||       Penyakit      ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    while(fread(&read,sizeof(pasien),1,Pasien))
    {
        printf("||%11s||%11s||%9s||%16s||%6d||%15s||%12s||%21s||\n",read.id,read.dokter,read.obat,read.nama,read.umur,read.jenkel,read.ruangan,read.penyakit);
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    fclose(Pasien);
    getch();
}

void CariDataPasien(){
    pasien search;
    FILE *Pasien;
    char id[5];
    int found=0;

    Pasien = fopen("Pasien.bin","rb");
    printf("Masukkan ID pasien (P000-P999) yang ingin dicari : ");
    gets(id);


    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||                                                  Data Pasien                                                  ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("|| ID Pasien || ID Dokter || ID Obat ||   Nama Pasien  || Umur || Jenis Kelamin || No Ruangan ||     Penyakit    ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while(fread(&search,sizeof(pasien),1,Pasien))
    {
        if(strcmp(search.id,id)==0){
            found=1;
            printf("||%11s||%11s||%9s||%16s||%6d||%15s||%12s||%17s||\n",search.id,search.dokter,search.obat,search.nama,search.umur,search.jenkel,search.ruangan,search.penyakit);
    }
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    if(!found)
        printf("\nData tidak ditemukan");
    fclose(Pasien);
    getch();
}

void UbahDataPasien(){
    pasien update;
    FILE *Pasien,*temp;
    char id[5];
    int found=0;

    TampilkanDataPasien();
    Pasien = fopen("Pasien.bin","rb");
    temp = fopen("temp.bin","wb");
    printf("Masukkan ID pasien (P000-P999) yang ingin diubah : ");
    gets(id);

    while(fread(&update,sizeof(pasien),1,Pasien))
    {
        if(strcmp(update.id,id)==0){
            found=1;
            printf("\nID  Pasien (P000-P999)  : ");
            gets(update.id);
            printf("ID Dokter (P000-P999)   : ");
            gets(update.dokter);
            printf("ID Obat (P000-P999)     : ");
            gets(update.obat);
            printf("Nama Pasien             : ");
            gets(update.nama);
            printf("Umur                    : ");
            scanf ("%d", &update.umur);
            fflush(stdin);
            printf("Jenis Kelamin           : ");
            gets(update.jenkel);
            printf("No Ruangan              : ");
            gets(update.ruangan);
            printf("Penyakit                : ");
            gets(update.penyakit);
        }
        fwrite(&update,sizeof(pasien),1,temp);
    }
    fclose(Pasien);
    fclose(temp);


    if(found){
        temp = fopen("temp.bin","rb");
        Pasien = fopen("Pasien.bin","wb");

        while(fread(&update,sizeof(pasien),1,temp)){
            fwrite(&update,sizeof(pasien),1,Pasien);
        }
        fclose(Pasien);
        fclose(temp);
        printf ("\nData telah diubah");
    }else{
        printf("\nData tidak ditemukan\n");
    }
    SortDatabaseRecordPasien();
    getch();
}

void HapusDataPasien(){
    pasien del;
    FILE *Pasien,*temp;
    char id[5];
    int found=0;

    TampilkanDataPasien();
    Pasien = fopen("Pasien.bin","rb");
    temp = fopen("temp.bin","wb");
    printf("Masukkan ID pasien (P000-P999) yang ingin dihapus : ");
    gets(id);

    while(fread(&del,sizeof(pasien),1,Pasien))
    {
        if(strcmp(del.id,id)==0){
            found=1;
        }else
        fwrite(&del,sizeof(pasien),1,temp);
    }
    fclose(Pasien);
    fclose(temp);

    if(found){
        temp = fopen("temp.bin","rb");
        Pasien = fopen("Pasien.bin","wb");

        while(fread(&del,sizeof(pasien),1,temp)){
            fwrite(&del,sizeof(pasien),1,Pasien);
        }

        fclose(Pasien);
        fclose(temp);
        printf ("\nData telah dihapus");

    }else{
        printf("\nData tidak ditemukan\n");
    }
    getch();
}

void UrutkanDataPasien(){
    int pilihan;

    enum pilihan{Nama=1,Ruangan,Penyakit,Batal};
    do{
        pilihan=SubmenuUrutkanDataPasien();
        switch(pilihan){
        case Nama:
            printf("Urutkan berdasarkan nama\n");
            getch();
            UrutkanNamaPasien();
            break;
        case Ruangan:
            printf("Urutkan berdasarkan ruangan\n");
            getch();
            UrutkanRuanganPasien();
            break;
        case Penyakit:
            printf("Urutkan berdasarkan penyakit\n");
            getch();
            UrutkanPenyakitPasien();
            break;
        case Batal:
            printf ("Kembali ke menu pasien\n\n");
            break;
    }
    }
    while(pilihan!=Batal);
    getch();
    return pilihan;
}

int SubmenuUrutkanDataPasien(){
    int input;

    SubmenuUrutkanDataPasien:
    system("cls");
    do{
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("||                        Pengurutan Data Pasien                           ||\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("|| 1. Urutkan berdasarkan nama                                             ||\n");
        printf("|| 2. Urutkan berdasarkan ruangan                                          ||\n");
        printf("|| 3. Urutkan berdasarkan penyakit                                         ||\n");
        printf("|| 4. Batal                                                                ||\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Pilih metode pengurutan [1-4] : ");
        scanf("%d",&input);
        fflush(stdin);
        printf("\n");

        if ((input < 1)||(input > 4)){
            printf("Pilihan anda tidak ada dalam menu\n\n");
            getch();
            goto SubmenuUrutkanDataPasien;
        }
    }
    while ((input < 1)||(input > 4));
    return input;
}

void UrutkanNamaPasien(){
    pasien *sort, unsort;
    FILE *Pasien;

    Pasien = fopen("Pasien.bin","rb");
    fseek(Pasien,0,SEEK_END);
    int n = ftell(Pasien)/sizeof(pasien);
    sort = (pasien*)calloc(n,sizeof(pasien));

    rewind(Pasien);
    for(int i=0;i<n;i++)
        fread(&sort[i],sizeof(pasien),1,Pasien);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp (sort[i].nama,sort[j].nama)>0){
                unsort = sort[i];
                sort[i] = sort[j];
                sort[j] = unsort;
            }
        }
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||                                                  Data Pasien                                                      ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("|| ID Pasien || ID Dokter || ID Obat ||   Nama Pasien  || Umur || Jenis Kelamin || No Ruangan ||       Penyakit      ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for(int i=0;i<n;i++){
        printf("||%11s||%11s||%9s||%16s||%6d||%15s||%12s||%21s||\n",sort[i].id,sort[i].dokter,sort[i].obat,sort[i].nama,sort[i].umur,sort[i].jenkel,sort[i].ruangan,sort[i].penyakit);
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


    fclose(Pasien);
    getch();
}

void UrutkanRuanganPasien(){
    pasien *sort, unsort;
    FILE *Pasien;

    Pasien = fopen("Pasien.bin","rb");
    fseek(Pasien,0,SEEK_END);
    int n = ftell(Pasien)/sizeof(pasien);
    sort = (pasien*)calloc(n,sizeof(pasien));

    rewind(Pasien);
    for(int i=0;i<n;i++)
        fread(&sort[i],sizeof(pasien),1,Pasien);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp (sort[i].ruangan,sort[j].ruangan)>0){
                unsort = sort[i];
                sort[i] = sort[j];
                sort[j] = unsort;
            }
        }
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||                                                  Data Pasien                                                      ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("|| ID Pasien || ID Dokter || ID Obat ||   Nama Pasien  || Umur || Jenis Kelamin || No Ruangan ||       Penyakit      ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for(int i=0;i<n;i++){
        printf("||%11s||%11s||%9s||%16s||%6d||%15s||%12s||%21s||\n",sort[i].id,sort[i].dokter,sort[i].obat,sort[i].nama,sort[i].umur,sort[i].jenkel,sort[i].ruangan,sort[i].penyakit);
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    fclose(Pasien);
    getch();
}

void UrutkanPenyakitPasien(){
    pasien *sort, unsort;
    FILE *Pasien;

    Pasien = fopen("Pasien.bin","rb");
    fseek(Pasien,0,SEEK_END);
    int n = ftell(Pasien)/sizeof(pasien);
    sort = (pasien*)calloc(n,sizeof(pasien));

    rewind(Pasien);
    for(int i=0;i<n;i++)
        fread(&sort[i],sizeof(pasien),1,Pasien);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp (sort[i].penyakit,sort[j].penyakit)>0){
                unsort = sort[i];
                sort[i] = sort[j];
                sort[j] = unsort;
            }
        }
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||                                                  Data Pasien                                                      ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~\n");
    printf("|| ID Pasien || ID Dokter || ID Obat ||   Nama Pasien  || Umur || Jenis Kelamin || No Ruangan ||       Penyakit      ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for(int i=0;i<n;i++){
        printf("||%11s||%11s||%9s||%16s||%6d||%15s||%12s||%21s||\n",sort[i].id,sort[i].dokter,sort[i].obat,sort[i].nama,sort[i].umur,sort[i].jenkel,sort[i].ruangan,sort[i].penyakit);
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    fclose(Pasien);
    getch();
}

int MenuObat(){
    int pilihan;

    enum pilihan{Tambah=1,Tampilkan,Cari,Ubah,Hapus,Urutkan,Kembali};
    do{
        pilihan=SubmenuObat();
        switch(pilihan){
        case Tambah:
            printf("Tambahkan data obat\n");
            getch();
            TambahDataObat();
            break;
        case Tampilkan:
            printf("Tampilkan data obat\n");
            getch();
            TampilkanDataObat();
            break;
        case Cari:
            printf("Tampilkan cari obat\n");
            getch();
            CariDataObat();
            break;
        case Ubah:
            printf("Ubah data obat\n");
            getch();
            UbahDataObat();
            break;
        case Hapus:
            printf("Hapus data obat\n");
            getch();
            HapusDataObat();
            break;
        case Urutkan:
            printf("Urutkan data obat\n");
            getch();
            UrutkanDataObat();
            break;
        case Kembali:
            printf ("Kembali ke menu utama\n\n");
            break;
    }
    }
    while(pilihan!=Kembali);
    getch();
    return pilihan;
}

int SubmenuObat(){
    int input;

    SubmenuObat:
    system("cls");

    do{
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("||\t\t\t       Menu Obat                                   ||\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("|| 1. Tambahkan data obat                                                  ||\n");
        printf("|| 2. Tampilkan data obat                                                  ||\n");
        printf("|| 3. Cari data obat                                                       ||\n");
        printf("|| 4. Ubah data obat                                                       ||\n");
        printf("|| 5. Hapus data obat                                                      ||\n");
        printf("|| 6. Urutkan data obat                                                    ||\n");
        printf("|| 7. Kembali                                                              ||\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Pilih layanan yang ingin digunakan [1-7] : ");
        scanf("%d",&input);
        fflush(stdin);
        printf("\n");


        if ((input < 1)||(input > 7)){
            printf("Pilihan anda tidak ada dalam menu\n\n");
            getch();
            goto SubmenuObat;
        }
    }
    while ((input < 1)||(input > 7));
    return input;
}

void TambahDataObat(){
    obat *add;
    FILE *Obat;
    int n;
    printf("Banyak data yang ingin dimasukkan : ");
    scanf("%d",&n);
    fflush(stdin);

    add = (obat*)calloc(n, sizeof(obat));
    Obat = fopen("Obat.bin","ab");

    for(int i=0;i<n;i++){
        printf("\nID Obat (B000-B999)    : ");
        gets(add[i].id);
        printf("Nama obat              : ");
        gets(add[i].nama);
        printf("Jenis obat             : ");
        gets(add[i].jenis);
        printf("Stok                   : ");
        scanf("%d",&add[i].stok);
        fflush(stdin);
        fwrite(&add[i],sizeof(obat),1,Obat);
    }
    fclose(Obat);
    SortDatabaseRecordObat();
}


void TampilkanDataObat(){
    obat read;
    FILE *Obat;

    Obat = fopen("Obat.bin","rb");

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||                       Data Obat                            ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||   ID Obat   ||     Nama Obat    ||    Jenis    ||   Stok   ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    while(fread(&read,sizeof(obat),1,Obat))
    {
        printf("||%13s||%18s||%13s||%10d||\n",read.id,read.nama,read.jenis,read.stok);
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    fclose(Obat);
    getch();
}

void CariDataObat(){
    obat search;
    FILE *Obat;
    char id[5];
    int found=0;

    Obat = fopen("Obat.bin","rb");
    printf("Masukkan ID (B000-B999) obat untuk dicari : ");
    gets(id);


    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||                       Data Obat                            ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||   ID Obat   ||     Nama Obat    ||    Jenis    ||   Stok   ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    while(fread(&search,sizeof(obat),1,Obat))
    {
        if(strcmp(search.id,id)==0){
            found=1;
            printf("||%13s||%18s||%13s||%10d||\n",search.id,search.nama,search.jenis,search.stok);;
        }
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    if(!found)
        printf("\nData tidak ditemukan");
    fclose(Obat);
    getch();
}

void UbahDataObat(){
    obat update;
    FILE *Obat,*temp;
    char id[5];
    int found=0;

    TampilkanDataObat();
    Obat = fopen("Obat.bin","rb");
    temp = fopen("temp.bin","wb");
    printf("Masukkan ID obat yang ingin diubah : ");
    gets(id);

    while(fread(&update,sizeof(obat),1,Obat))
    {
        if(strcmp(update.id,id)==0){
            found=1;
            printf("\nID Obat (B000-B999)    : ");
            gets(update.id);
            printf("Nama obat              : ");
            gets(update.nama);
            printf("Jenis obat             : ");
            gets(update.jenis);
            printf("Stok                   : ");
            scanf("%d",&update.stok);
            fflush(stdin);
        }
        fwrite(&update,sizeof(obat),1,temp);
    }
    fclose(Obat);
    fclose(temp);

    if(found){
        temp = fopen("temp.bin","rb");
        Obat = fopen("Obat.bin","wb");

        while(fread(&update,sizeof(obat),1,temp)){
            fwrite(&update,sizeof(obat),1,Obat);
        }
        fclose(Obat);
        fclose(temp);
        printf ("\nData telah diubah");

    }else{
        printf("\nData tidak ditemukan\n");
    }
    SortDatabaseRecordObat();
    getch();
}

void HapusDataObat(){
    obat del;
    FILE *Obat,*temp;
    char id[5];
    int found=0;

    TampilkanDataObat();
    Obat = fopen("Obat.bin","rb");
    temp = fopen("temp.bin","wb");
    printf("Masukkan ID obat (B000-B999) yang ingin dihapus : ");
    gets(id);

    while(fread(&del,sizeof(obat),1,Obat))
    {
        if(strcmp(del.id,id)==0){
            found=1;
        }else
        fwrite(&del,sizeof(obat),1,temp);
    }
    fclose(Obat);
    fclose(temp);

    if(found){
        temp = fopen("temp.bin","rb");
        Obat = fopen("Obat.bin","wb");

        while(fread(&del,sizeof(obat),1,temp)){
            fwrite(&del,sizeof(obat),1,Obat);
        }

        fclose(Obat);
        fclose(temp);
        printf ("\nData telah dihapus");

    }else{
        printf("\nData tidak ditemukan\n");
    }
    getch();
}

void UrutkanDataObat(){
    int pilihan;

    enum pilihan{Nama=1,Jenis,Batal};
    do{
        pilihan=SubmenuUrutkanDataObat();
        switch(pilihan){
        case Nama:
            printf("Urutkan berdasarkan nama\n");
            getch();
            UrutkanNamaObat();
            break;
        case Jenis:
            printf("Urutkan berdasarkan jenis\n");
            getch();
            UrutkanJenisObat();
            break;
        case Batal:
            printf ("Kembali ke menu obat\n\n");
            break;
    }
    }
    while(pilihan!=Batal);
    getch();
    return pilihan;
}

int SubmenuUrutkanDataObat(){
    int input;

    SubmenuUrutkanDataObat:
    system("cls");
    do{
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("||                        Pengurutan Data Obat                             ||\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("|| 1. Urutkan berdasarkan nama                                             ||\n");
        printf("|| 2. Urutkan berdasarkan jenis                                            ||\n");
        printf("|| 3. Batal                                                                ||\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Pilih metode pengurutan [1-3] : ");
        scanf("%d",&input);
        fflush(stdin);
        printf("\n");

        if ((input < 1)||(input > 3)){
            printf("Pilihan anda tidak ada dalam menu\n\n");
            getch();
            goto SubmenuUrutkanDataObat;
        }
    }
    while ((input < 1)||(input > 3));
    return input;
}

void UrutkanNamaObat(){
    obat *sort, unsort;
    FILE *Obat;

    Obat = fopen("Obat.bin","rb");
    fseek(Obat,0,SEEK_END);
    int n = ftell(Obat)/sizeof(obat);
    sort = (obat*)calloc(n,sizeof(obat));

    rewind(Obat);
    for(int i=0;i<n;i++)
        fread(&sort[i],sizeof(obat),1,Obat);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp (sort[i].nama,sort[j].nama)>0){
                unsort = sort[i];
                sort[i] = sort[j];
                sort[j] = unsort;
            }
        }
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||                       Data Obat                            ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||   ID Obat   ||     Nama Obat    ||    Jenis    ||   Stok   ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for(int i=0;i<n;i++){
        printf("||%13s||%18s||%13s||%10d||\n",sort[i].id,sort[i].nama,sort[i].jenis,sort[i].stok);
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


    fclose(Obat);
    getch();
}

void UrutkanJenisObat(){
    obat *sort, unsort;
    FILE *Obat;

    Obat = fopen("Obat.bin","rb");
    fseek(Obat,0,SEEK_END);
    int n = ftell(Obat)/sizeof(obat);
    sort = (obat*)calloc(n,sizeof(obat));

    rewind(Obat);
    for(int i=0;i<n;i++)
        fread(&sort[i],sizeof(obat),1,Obat);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp (sort[i].jenis,sort[j].jenis)>0){
                unsort = sort[i];
                sort[i] = sort[j];
                sort[j] = unsort;
            }
        }
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||                       Data Obat                            ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("||   ID Obat   ||     Nama Obat    ||    Jenis    ||   Stok   ||\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for(int i=0;i<n;i++){
        printf("||%13s||%18s||%13s||%10d||\n",sort[i].id,sort[i].nama,sort[i].jenis,sort[i].stok);
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    fclose(Obat);
    getch();
}
