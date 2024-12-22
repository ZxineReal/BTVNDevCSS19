#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void showSinhVien(struct SinhVien sv[], int currentLength);
void addSinhVien(struct SinhVien sv[], int *currentLength);
void editSinhVien(struct SinhVien sv[], int currentLength);
void delSinhVien(struct SinhVien sv[], int *currentLength, int id);
void findSinhVien(struct SinhVien sv[], int currentLength);
void sortSinhVien(struct SinhVien sv[], int currentLength);

int main() {
    struct SinhVien sv[50] = {
        {1, "Nguyen Van A", 18, "0123456789"},
        {2, "Le Van B", 19, "0123456788"},
        {3, "Phan C", 18, "0123456777"},
        {4, "Tran Thi D", 20, "0123456666"},
        {5, "Pham E", 21, "0123455555"}
    };

    int currentLength = 5;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showSinhVien(sv, currentLength);
                break;
            case 2:
                addSinhVien(sv, &currentLength);
                break;
            case 3:
                editSinhVien(sv, currentLength);
                break;
            case 4: {
                int id;
                printf("Nhap ID sinh vien can xoa: ");
                scanf("%d", &id);
                delSinhVien(sv, &currentLength, id);
                break;
            }
            case 5:
                findSinhVien(sv, currentLength);
                break;
            case 6:
                sortSinhVien(sv, currentLength);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 7);

    return 0;
}

void showSinhVien(struct SinhVien sv[], int currentLength) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d\t%s\t%d\t%s\n", sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
    }
}

void addSinhVien(struct SinhVien sv[], int *currentLength) {
    if (*currentLength >= 50) {
        printf("Khong the them sinh vien moi. Danh sach da day.\n");
        return;
    }

    struct SinhVien newSv;
    printf("Nhap ID: ");
    scanf("%d", &newSv.id);
    getchar();
    printf("Nhap ten: ");
    fgets(newSv.name, sizeof(newSv.name), stdin);
    newSv.name[strcspn(newSv.name, "\n")] = '\0';
    printf("Nhap tuoi: ");
    scanf("%d", &newSv.age);
    printf("Nhap so dien thoai: ");
    scanf("%s", newSv.phoneNumber);

    sv[*currentLength] = newSv;
    (*currentLength)++;
    printf("Them sinh vien thanh cong!\n");
}

void editSinhVien(struct SinhVien sv[], int currentLength) {
    int id;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &id);

    for (int i = 0; i < currentLength; i++) {
        if (sv[i].id == id) {
            getchar();
            printf("Nhap ten moi: ");
            fgets(sv[i].name, sizeof(sv[i].name), stdin);
            sv[i].name[strcspn(sv[i].name, "\n")] = '\0';
            printf("Nhap tuoi moi: ");
            scanf("%d", &sv[i].age);
            printf("Nhap so dien thoai moi: ");
            scanf("%s", sv[i].phoneNumber);
            printf("Sua thong tin thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien co ID = %d\n", id);
}

void delSinhVien(struct SinhVien sv[], int *currentLength, int id) {
    int found = 0;
    for (int i = 0; i < *currentLength; i++) {
        if (sv[i].id == id) {
            found = 1;
            for (int j = i; j < *currentLength - 1; j++) {
                sv[j] = sv[j + 1];
            }
            (*currentLength)--;
            printf("Xoa thanh cong!\n");
            return;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ID = %d\n", id);
    }
}

void findSinhVien(struct SinhVien sv[], int currentLength) {
    char name[50];
    getchar();
    printf("Nhap ten sinh vien can tim: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("\nKet qua tim kiem:\n");
    for (int i = 0; i < currentLength; i++) {
        if (strstr(sv[i].name, name) != NULL) {
            printf("%d\t%s\t%d\t%s\n", sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
        }
    }
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
    printf("Sap xep thanh cong!\n");
}
