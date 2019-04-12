#include<stdio.h>
#include<string.h>
struct process_Str {
    char process_name[15];
    int A_T, B_T, C_T, remain_
}temp_Str;
void faculty_Queue(int number_of_process) {
    int c, A_T, B_T,Q_T;
    struct process_Str faculty_Process[number_of_process];
    for(c = 0; c < number_of_process; c++) {
        printf("Enter the required details of the Process P[%d]", c+1);
        puts("");
        printf("Name of the Process : ");
        scanf("%s", faculty_Process[c].process_name);
        printf("Arrival Time of the process : ");
        scanf("%d", &faculty_Process[c].A_T);
        printf("Burst Time of the process : ");
        scanf("%d", &faculty_Process[c].B_T);
        puts("");
    }
    printf("Enter the quantum time for FACULTY queue you required : ");
    scanf("%d", &A_T);
    for(c = 0; c< number_of_process; c++) {
        for(int i= c +1; i < c; i++){
            if(faculty_Process[c].A_T > faculty_Process[i].A_T) {
                temp_Str = faculty_Process[c];
                faculty_Process[c] = faculty_Process[i];
                faculty_Process[i] = temp_Str;
            }
        }
}
    for(c=0;c< number_of_process; c++) {
        faculty_Process[c].remain_Time = faculty_Process[c].B_T;
        faculty_Process[c].C_T = 0;
    }
    int Total_T, queue, round_robin[15];
    Total_T = 0;
    queue = 0;
    round_robin[queue] = 0;
    int flag, i, n, z, W_T = 0;
    do {
        for(c = 0; c < number_of_process; c++){
            if(Total_T >= faculty_Process[c].A_T){
                z = 0;
                for(i = 0; i <= queue; i++) {
                    if(round_robin[i] == c) {
                        z++;
                    }
                }
                if(z == 0) {
                    queue++; 
                    round_robin[queue] == c;
                }
            }
        }
        if(queue == 0) {
            n = 0;
        }
        if(faculty_Process[n].remain_Time == 0) {
            n++ ;
        }
        if(n > queue) {
            n = (n - 1) % queue;
        }
        if(n <= queue) {
            if(faculty_Process[n].remain_Time > 0) {
                if(faculty_Process[n].remain_Time < Q_T){
                    Total_T += faculty_Process[n].remain_Time;
                    faculty_Process[n].remain_Time = 0;
                }else {
                    Total_T += Q_T;
                    faculty_Process[n].remain_Time -= Q_T;
                }
                faculty_Process[n].C_T = Total_T;
            }
            n++;
        }
        flag = 0;
        for(c = 0; c < number_of_process; c++) {
            if(faculty_Process[c].remain_Time > 0) {
                flag++;
            }
        }
    }while(flag != 0);
    puts("\t\t\t      OUTPUT OF THE ROUND ROBIN ALGORITHM       ");
    printf("\nName of the Process  Arrival Time   Burst Time Completion Time of the process  \n");
    for(c = 0; c < number_of_process; c++){
      W_T = faculty_Process[c].C_T - faculty_Process[c].B_T - faculty_Process[c].A_T;
        printf("\n         %s                %d             %d                %d   \n", faculty_Process[c].process_name, faculty_Process[c].A_T, faculty_Process[c].B_T, faculty_Process[c].C_T);
    }
}
void student_Queue(int number_of_process) {
    int c, A_T, B_T, Q_T;
    struct process_Str student_Process[number_of_process];
    for(c = 0; c < number_of_process; c++) {
        printf("Enter the required details of Process[%d]", c+1);
        puts("");
        printf(" Name of the process  : ");
        scanf("%s", student_Process[c].process_name);\
        printf("Arrival Time of the process : ");
        scanf("%d", &student_Process[c].A_T);
        printf("Burst Time of the process : ");
        scanf("%d", &student_Process[c].B_T);
    }
    printf(" Enter the required quantum time for STUDENT queue : ");
    scanf("%d", &Q_T);
    for(c = 0; c < number_of_process; c++) {
        for(int i = c +1; i < c; i++){
            if(student_Process[c].A_T > student_Process[i].A_T) {
                temp_Str = student_Process[c];
                student_Process[c] = student_Process[i];
                student_Process[i] = temp_Str;
            }
        }
    }
    for(c = 0; c < number_of_process; c++) {
        student_Process[c].remain_Time = student_Process[c].B_T;
        student_Process[c].C_T = 0;
    }
    int Total_T, queue, round_robin[20];
    Total_T = 0;
    queue = 0;
    round_robin[queue] = 0;
}
int main(int argc, char const *argv[]) {
    int select_queue, number_of_process;
    puts("Please choose a type to post your query : ");
    puts("1. FACULTY queue.");
    puts("2. STUDENT queue.");
    printf("> ");
    scanf("%d", &select_queue);
    switch(select_queue) {
        case 1 :
                printf("Enter required number of process for FACULTY queue : ");
                scanf("%d", &number_of_process);
                faculty_Queue(number_of_process);
                break;
        case 2 :
                printf("Enter requied number of process for STUDENT queue : ");
                scanf("%d", &number_of_process);
                student_Queue(number_of_process);
                break;
        default : 
                printf("Please choose the correct option by running the program again.");
    }
    return 0;
}
