#include <stdio.h>
#include <string.h>

struct vehicle
{
    char plaka[20];
    char sahibi[50];
    char girisZamani;
};

#define CAPACITY 10

struct vehicle parkingLot[CAPACITY];
int count = 0;

void parkVehicle(){
    if(count >= CAPACITY){  // <= yerine >=
        printf("Otopark Dolu!\n\n");
        return;
    }

    struct vehicle v;

    printf("Plakanizi giriniz: ");
    scanf("%s", v.plaka);
    getchar(); // sadece burası yeterli, enter tuşunu yakalamak için

    printf("Arac Sahibi: ");
    fgets(v.sahibi, 50, stdin);
    v.sahibi[strcspn(v.sahibi, "\n")] = 0; // newline temizleme

    printf("Giris Zamanini giriniz (HHMM): ");
    scanf("%c", &v.girisZamani);
    getchar(); // scanf sonrası enter’ı temizle

    parkingLot[count++] = v;

    printf("Araciniz park edildi!\n\n");
}

void removeVehicle(){
    char plaka[20];
    printf("Cikartmak istediginiz aracin plakasini giriniz: ");
    scanf("%s", plaka);
    for(int i = 0; i < count; i++){
        if(strcmp(parkingLot[i].plaka, plaka) == 0) {
            for(int j = i; j < count - 1; j++){
                parkingLot[j] = parkingLot[j + 1];
            }
            count--;
            printf("Araciniz cikartildi!\n");
            return;
        }
    }
}

void checkAvailability(){
    printf("Bos park yeri sayisi: %d\n", CAPACITY - count);
}

void searchVehicle(){
    char plaka[20];
    printf("Aramak istediginiz aracin plakasini giriniz: ");
    scanf("%s", plaka);
    for(int i = 0; i < count; i++){
        if(strcmp(parkingLot[i].plaka, plaka) == 0) {
            printf("Arac Sahibi: %s\n", parkingLot[i].sahibi);
            printf("Giris Zamani: %c\n", parkingLot[i].girisZamani);
            return;
        }
    }
    printf("Arac bulunmadi!\n");
}






int main(){
    printf("Otoparka Hos Geldiniz!\n");
    int choice;

    while(1){
        printf("1. Arac Park Et\n");
        printf("2. Arac Cikart\n");
        printf("3. Bos Park Yeri Kontrolu\n");
        printf("4. Arac Ara\n");
        printf("5. Cikis\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                parkVehicle();
                break;
            case 2:
                removeVehicle();
                break;
            case 3:
                checkAvailability();
                break;
            case 4:
                searchVehicle();
                break;
            case 5:
                printf("Otoparktan cikiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim, tekrar deneyiniz.\n");
        }
    }
    return 0;
}