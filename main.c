#include <stdio.h>
#include <windows.h>

#define L 12  // листов
#define M 34 // занятий
#define N 28 // учеников

// Функция для заполнения журнала
void fillJournal(int journal[L][M][N]) {
    for (int l = 0; l < L; l++) {
        printf("Страница номер %d\n", l+1);
        for (int i = 0; i < M; i++) {
            printf("Урок номер %d\n", i+1);
            for (int j = 0; j < N; j++) {
                printf("Посетил ли ученик номер %d ?\n", j+1);
                scanf("%d",&journal[l][i][j]);
            }
        }
    }
}

// Функция для подсчета студентов, всегда соответствующих условию
int countStudents(int journal[L][M][N], int condition){
    int counter = 0;
    for(int n = 0; n<N; n++){
        int alwaysFollowsCondition = 1; //преполагаем, что всегда соответствует
        for(int l = 0; l<L; l++){
            for(int m = 0; m<M; m++){
                if(journal[l][m][n]!=condition){
                    alwaysFollowsCondition = 0;
                    break;
                }
            }
            if(!alwaysFollowsCondition)
                break;
        }
        if(alwaysFollowsCondition)
            counter++;
    }
    return counter;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int journal[L][M][N];

    // Заполнение журнала
    fillJournal(journal);

    // Подсчет студентов, которые никогда не пропускали занятия
    int neverAbsent = countStudents(journal, 1);

    // Подсчет студентов, которые ни разу не появлялись на занятиях
    int neverAttended = countStudents(journal, 0);

    // Вывод результатов
    printf("Студентов, которые никогда не пропускали занятия: %d\n", neverAbsent);
    printf("Студентов, которые ни разу не появлялись на занятиях: %d\n", neverAttended);
    return 0;
}
