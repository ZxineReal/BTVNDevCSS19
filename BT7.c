#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void xoaSinhVien(struct SinhVien sv[], int *currentLength, int id) {
    int found = 0;
    for (int i = 0; i < *currentLength; i++) {
        if (sv[i].id == id) {
            found = 1;
            for (int j = i; j < *currentLength - 1; j++) {
                sv[j] = sv[j + 1];
            }
            (*currentLength)--;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ID = %d\n", id);
    }
}

int main() {
    struct SinhVien sv[50] = {
        {1, "Nguyen Van A", 18, "0123456789"},
        {2, "Le Van B", 19, "0123456788"},
        {3, "Phan C", 18, "0123456777"},
        {4, "Tran Thi D", 20, "0123456666"},
        {5, "Pham E", 21, "0123455555"}
    };

    int currentLength = 5;
    int idToDelete;

    printf("Nhap ID cua sinh vien can xoa: ");
    scanf("%d", &idToDelete);

    xoaSinhVien(sv, &currentLength, idToDelete);

    printf("Danh sach sinh vien sau khi xoa:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d\t%s\t%d\t%s\n", sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
    }

    return 0;
}
