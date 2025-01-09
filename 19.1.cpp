#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Hàm xóa sinh viên
void delete_Student(struct Student struc[], int *n)
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

// Hàm main
int main()
{
    int n = 5;
    struct Student struc[5] = {
        {1, "tran quoc bao", 21, "0862235178"},
        {2, "nguyen cong tru", 22, "012345678"},
        {3, "do dinh long", 19, "012345678"},
        {4, "nguyen quang thien", 19, "012345678"},
        {5, "pham nhat huy", 19, "012345678"},
    };
    display_Students(struc, n);
    delete_Student(struc, &n);
    display_Students(struc, n);
    system("pause");
}
