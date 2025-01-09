#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Số lượng sinh viên tối đa


int n = 5; // Số lượng sinh viên thực tế

// Cấu trúc sinh viên
struct Student
{
    int ID_Student;
    char Name_Student[30];
    int Age_Student;
    char Phone_Student[11];
};

// Hàm hiển thị danh sách sinh viên
void display_Students(struct Student struc[], int n)
{
    printf("\n");
    printf("                   DANH SÁCH SINH VIÊN                  \n");
    printf("\n");
    printf("--------------------------------------------------------\n");
    printf("| ID | Tên Sinh Viên           | Tuổi | Số Điện Thoại  |\n");
    printf("|----|-------------------------|------|----------------|\n");
    for (int i = 0; i < n; i++)
    {
        printf("| %2d | %-23s | %4d | %-14s |\n", struc[i].ID_Student, struc[i].Name_Student, struc[i].Age_Student, struc[i].Phone_Student);
        if (i == n - 1)
        {
            printf("--------------------------------------------------------\n");
        }
        else
        {
            printf("|----|-------------------------|------|----------------|\n");
        }
    }
}

// Hàm thêm sinh viên
void add_Students(struct Student struc[])
{
    if (n >= MAX)
    {
        printf("Danh sách sinh viên đầy, không thể thêm mới!\n");
        return;
    }

    int pos;
    printf("\nNhập vị trí cần thêm mới sinh viên ( từ 1 đến %d ): ", n + 1);
    scanf("%d", &pos);
    printf("\n");

    if (pos < 1 || pos > n + 1)
    {
        printf("Vị trí không hợp lệ!\n");
        return;
    }

    for (int i = n; i >= pos; i--)
    {
        struc[i] = struc[i - 1];
    }

    // Nhập thông tin sinh viên mới
    struc[pos - 1].ID_Student = pos;
    printf("Nhập vào tên sinh viên: ");
    scanf("%s", struc[pos - 1].Name_Student);
    printf("\n");
    fflush(stdin);
    printf("Nhập vào tuổi sinh viên: ");
    scanf("%d", &struc[pos - 1].Age_Student);
    printf("\n");
    printf("Nhập vào số điện thoại sinh viên: ");
    scanf("%s", struc[pos - 1].Phone_Student);
    printf("\n");

    // Tăng id các các sinh viên sau pos thêm 1
    for (int i = pos; i < n + 1; i++)
    {
        struc[i].ID_Student = i + 1;
    }

    n++; // Tăng số lượng sinh viên
    printf("Đã thêm sinh viên thành công!\n");
}

// Hàm sửa sinh viên
void edit_Students(struct Student struc[])
{
    int id;
    printf("\nNhập ID sinh viên cần sửa: ");
    scanf("%d", &id);
    printf("\n");

    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (struc[i].ID_Student == id)
        {
            printf("Nhập tên sinh viên mới: ");
            scanf("%s", struc[i].Name_Student);
            printf("\n");
            fflush(stdin);
            printf("Nhập tuổi sinh viên mới: ");
            scanf("%d", &struc[i].Age_Student);
            printf("\n");
            printf("Nhập số điện thoại sinh viên mới: ");
            scanf("%s", struc[i].Phone_Student);
            printf("\n");
            found = 1;
            printf("Đã sửa sinh viên thành công!\n");
            break;
        }
    }

    if (!found)
    {
        printf("Không tìm thấy sinh viên có ID %d!\n", id);
    }
}

// Hàm xóa sinh viên
void delete_Students(struct Student struc[], int *n)
{
    int id;
    printf("\nNhập ID sinh viên cần xóa: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < *n; i++)
    {
        if (struc[i].ID_Student == id)
        {
            for (int j = i; j < *n - 1; j++)
            {
                struc[j] = struc[j + 1];
            }
            
            (*n)--;

            found = 1;
            printf("\n");
            printf("Đã xóa sinh viên thành công!\n");
            break;
        }
    }

    if (!found)
    {
        printf("Không tìm thấy sinh viên có ID %d!\n", id);
    }
}

// Hàm tìm kiếm sinh viên
void search_Students(struct Student struc[])
{
    char name[30];
    fflush(stdin);
    printf("\nNhập tên sinh viên cần tìm: ");
    gets(name);
    printf("\n");

    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(struc[i].Name_Student, name) == 0)
        {
            printf("| %2d | %-23s | %4d | %-14s |\n", struc[i].ID_Student, struc[i].Name_Student, struc[i].Age_Student, struc[i].Phone_Student);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Không tìm thấy sinh viên có tên %s!\n", name);
    }
}

// Hàm sắp xếp sinh viên theo tên
void sort_StudentsByName(struct Student struc[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(struc[i].Name_Student, struc[j].Name_Student) > 0)
            {
                struct Student temp = struc[i];
                struc[i] = struc[j];
                struc[j] = temp;
            }
        }
    }
    printf("\n");
    printf("Đã sắp xếp sinh viên thành công!\n");
}

// Hàm main
int main()
{
    int choice;
    struct Student struc[MAX] = {
        {1, "Phan Trung Kien", 18, "0814780306"},
        {2, "Le Thi Hong Anh", 19, "0901234567"},
        {3, "Truong Doan Anh Thu", 18, "0987654321"},
        {4, "Tran Vo Huu Tai", 18, "0153428419"},
        {5, "Do Hoang Son", 18, "0113456312"},
    };
    while (1) // Vòng lặp vô hạn hiển thị MENU
    {
        printf("\n                MENU                 \n");
        printf("-------------------------------------\n");
        printf("| 1. Hiển thị danh sách sinh viên   |\n");
        printf("|-----------------------------------|\n");
        printf("| 2. Thêm một sinh viên             |\n");
        printf("|-----------------------------------|\n");
        printf("| 3. Sửa một sinh viên              |\n");
        printf("|-----------------------------------|\n");
        printf("| 4. Xóa một sinh viên              |\n");
        printf("|-----------------------------------|\n");
        printf("| 5. Tìm kiếm sinh viên theo tên    |\n");
        printf("|-----------------------------------|\n");
        printf("| 6. Sắp xếp sinh viên theo tên     |\n");
        printf("|-----------------------------------|\n");
        printf("| 7. Thoát                          |\n");
        printf("-------------------------------------\n");
        printf("\n");
        printf("Chọn chức năng: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display_Students(struc, n);
            break;

        case 2:
            add_Students(struc);
            break;

        case 3:
            edit_Students(struc);
            break;

        case 4:
            delete_Students(struc, &n);
            break;

        case 5:
            search_Students(struc);
            break;

        case 6:
            sort_StudentsByName(struc, n);
            break;

        case 7:
            printf("Thoát chương trình. Tạm biệt!\n");
            exit(0);

        default:
            printf("Lựa chọn không hợp lệ! Vui lòng chọn lại.\n");
            break;
        }
    }
}
