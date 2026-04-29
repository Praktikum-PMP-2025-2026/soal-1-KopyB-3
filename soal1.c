/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 03 - Structures and Dynamic Array
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : Luis Matthew Sembiring (13224053)
 *   Nama File           : soal1.c
 *   Deskripsi           : Mengurutkan data artefak menggunakan struct
 * 
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct {
    char nama[100];
    char kategori[100];
    int tahun;
    int nilai;
} Artefak;

int stralphcmp ();

int main(){
    int n;
    scanf("%d", &n);

    Artefak *data = (Artefak*)malloc(n*sizeof(Artefak));
    if (data == NULL) {
        return 1;
    }

    for (int i=0; i<n; i++){
        scanf("%s %s %d %d", data[i].nama, data[i].kategori, &data[i].tahun, &data[i].nilai);
    }
    
    //bubble sort
    for (int i = 0; i < n - 1 ; i++) {
        for (int j = 0; j < n - i - 1 ; j++) {
            int swapyes = 0;

            if (strcmp(data[j].kategori, data[j+1].kategori) > 0){
                Artefak temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            } 
            else if (strcmp(data[j].kategori, data[j+1].kategori) == 0){
                if (data[j].tahun > data[j+1].tahun){
                    Artefak temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                } 
                else if (data[j].tahun == data[j+1].tahun){
                    if (data[j].nilai < data[j+1].nilai){
                        Artefak temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;
                    } 
                    else if (data[j].nilai == data[j+1].nilai){
                        if (strcmp(data[j].nama, data[j+1].nama) > 0){
                            Artefak temp = data[j];
                            data[j] = data[j+1];
                            data[j+1] = temp;
                        }    
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s %s %d %d\n", data[i].nama, data[i].kategori, data[i].tahun, data[i].nilai);
    }

    free(data);

return 0;
}