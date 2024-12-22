#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void sortSinhVien(struct SinhVien sv[], int currentLength);
void showSinhVien(struct SinhVien sv[], int currentLength);

int main() {
    struct SinhVien sv[5] = {
        {1, "Nguyen Van A", 18, "0123456789"},
        {2, "Le Van B", 19, "0123456788"},
        {3, "Phan C", 18, "0123456777"},
        {4, "Tran Thi D", 20, "0123456666"},
        {5, "Pham E", 21, "0123455555"}
    };

    int currentLength = 5;

    printf("Danh sach sinh vien truoc khi sap xep:\n");
    showSinhVien(sv, currentLength);

    sortSinhVien(sv, currentLength);

    printf("\nDanh sach sinh vien sau khi sap xep:\n");
    showSinhVien(sv, currentLength);

    return 0;
}

void sortSinhVien(struct SinhVien sv[], int currentLength) {
    for (int i = 0; i < currentLength - 1; i++) {
        for (int j = i + 1; j < currentLength; j++) {
            if (strcmp(sv[i].name, sv[j].name) > 0) {
                struct SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

void showSinhVien(struct SinhVien sv[], int currentLength) {
    for (int i = 0; i < currentLength; i++) {
        printf("%d\t%s\t%d\t%s\n", sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
    }
}
