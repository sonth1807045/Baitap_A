#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char MaSinhVien[10];
    char TenSinhVien[50];
    char SoDienThoai[50];

} SinhVien;

void themSV(int i, SinhVien sinhVien[]) {
    char a[10];
    SinhVien *pointer = sinhVien;
    i = 0;
    for (int count = 0; count < 10; ++count) {
        while (1) {
            printf("Nhập mã sinh viên thứ %d:", i + 1);
            scanf("%s", sinhVien[i].MaSinhVien);
            if (strlen(sinhVien[i].MaSinhVien) != 5) {
                printf("Nhập lại %d:", i + 1);
            } else break;
        }
        printf("Nhập tên SV %d:", i + 1);
        fgetc(stdin);
        scanf("%s", sinhVien[i].TenSinhVien);
        printf("Nhập sdt SV %d:", i + 1);
        scanf("%s", sinhVien[i].SoDienThoai);
        i++;
        printf("Nhập exit để chuyển về menu ban đầu hoặc ấn Enter để tiếp tục nhập.");
        fgetc(stdin);
        fgets(a, 10, stdin);
        if (strcmp(a, "exit\n") == 0)break;

    }
}

void HienthidanhsachSV(int i, SinhVien sinhVien[]) {
    i = 0;
    printf("-%-25s|%-25s|%s", "Mã sinh viên", "Tên sinh viên", "Điện thoại\n");
    for (int count = 0; count < 10; ++count) {
        printf("-%-23s|%-23s|%s\n", sinhVien[i].MaSinhVien, sinhVien[i].TenSinhVien, sinhVien[i].SoDienThoai);
        i++;
    }
}

void Luuanhsachvaofile(int i, SinhVien sinhVien[]) {
    FILE *fp;
    i=0;
    fp = fopen("danhsach.txt", "w+");
    fprintf(fp, "-%-20s|%-20s|%s", "Mã sinh viên ", "Tên sinh viên", "Điện thoại");
    for (int count = 0; count < 10; ++count) {
        fprintf(fp, "\n-%-18s|%-18s|%s", sinhVien[i].MaSinhVien, sinhVien[i].TenSinhVien, sinhVien[i].SoDienThoai);
        i++;
    }
    fclose(fp);
}

void Docdanhsachtufile() {
    FILE *fp;
    char buff[255];
    fp = fopen("danhsach.txt", "r");
    printf("read file data\n");
    while (fgets(buff, 255, fp) != NULL) {
        printf("%s\n", buff);
        fclose(fp);
    }
}

int main() {
    int choice;
    int i = 0;
    SinhVien sinhVien[10] = {};
    FILE *fp;
    printf("-------------Menu---------------\n");
    printf("1. Nhập thông tin sinh viên mới. \n");
    printf("2. Hiển thị danh sách sinh viên.\n");
    printf("3. Lưu danh sách sinh viên ra file.\n");
    printf("4. Đọc danh sách sinh viên từ file.\n");
    printf("5. Thoát chương trình.\n");

    while (1) {
        printf("Lựa chọn của bạn là :");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                themSV(10, sinhVien);
                break;
            case 2:
                HienthidanhsachSV(10, sinhVien);
                break;
            case 3:
                Luuanhsachvaofile(10, sinhVien);
                break;
            case 4:
                Docdanhsachtufile();
        }
        if (choice == 5){
            printf("Cám ơn bạn !!!!");
            break;
        }
    }
    return 0;
}
