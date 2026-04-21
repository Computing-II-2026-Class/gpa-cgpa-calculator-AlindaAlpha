/*
Name: ALINDA ATUNGA ALPHA
Registration Number: 25/U/BIE/01354/PE
*/

#include <stdio.h>
#include <stdlib.h>
int main() {
    //Semester one data and credit units
    int cu1[8] = {4,3,3,3,3,3,2,3};
    char *sem1_codes[8] ={"TEMB 1101","TEMB 1102","TEMB 1103","TEMB 1104","TEMB 1105", "TEMB 1106", "TEMB 1107","TEMB 1108"};

    //Course credit units semester two
    int cu2[8] = {4,3,3,3,3,3,3,3};
    char *sem2_codes[] = {"TEMB 1201","TEMB 1202","TEMB 1203","TEMB 1204","TEMB 1205","TEMB 1206","TEMB 1207","TEMB 1208"};

    float scores1[8] , scores2[8];
    float gp1[8] , gp2[8];
    char grades1[8], grades2[8];
    float sem1_weighted_sum = 0, sem2_weighted_sum = 0;
    int sem1_total_cu = 24, sem2_total_cu = 25;

    // input for semester One
    printf("Semester I\n");
    for (int i = 0; i < 8; i++){
        // printf("Enter score for %s:", sem1_codes[i]);
        scanf("%f", &scores1[i]);
        //the invalid input rule  
        if(scores1[i] < 0 || scores1[i] >100) {
            printf("Invalid score entered\n");
            return 0;
        }
        if (scores1[i] >=80) {gp1[i]= 5; grades1[i] ='A';}
        else if (scores1[i] >=70) {gp1[i]=4; grades1[i] ='B';}
        else if (scores1[i] >=60) {gp1[i]=3; grades1[i] ='C';}
        else if (scores1[i] >=50) {gp1[i]=2; grades1[i] ='D';}
        else {gp1[i]= 0; grades1[i] ='F';}

        sem1_weighted_sum += (gp1[i] * cu1[i]);
    }
    // input for semester Two
    // printf("Semester II\n");
    for ( int i = 0; i < 8; i++) {
        /// printf("Enter score for %s:",sem2_codes[i]);
        scanf("%f",&scores2[i]);
        //the invalid input rule
        if (scores2[i] < 0 || scores2[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }
        if (scores2[i] >= 80) {gp2[i] = 5; grades2[i] ='A';}
        else if (scores2[i] >=70) {gp2[i] =4; grades2[i] ='B';}
        else if (scores2[i] >=60) {gp2[i] =3; grades2[i] ='C';}
        else if (scores2[i] >=50) {gp2[i] =2; grades2[i] ='D';}
        else {gp2[i] =0; grades2[i] = 'F';}

        sem2_weighted_sum += (gp2[i] * cu2[i]);
    }
    // calculation for gpa1, gpa2 & cgpa
    float gpa1 = sem1_weighted_sum / sem1_total_cu;
    float gpa2 = sem2_weighted_sum / sem2_total_cu;
    float cgpa = (sem1_weighted_sum + sem2_weighted_sum) / ( sem1_total_cu + sem2_total_cu);
    // the logic classification
    char *class;
    if (cgpa >=4.40) class = "First class";
    else if (cgpa >=3.60) class = "Second class upper";
    else if (cgpa >=2.80) class = "Second class lower";
    else if (cgpa >=2.00) class = "Pass";
    else class = "Fail";

    printf("Semester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n",gpa2);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", class);
    
    //output report
    printf("\n---FULL ACADEMIC REPORT---\n");
    printf("\n%-12s | %-6s | %-5s | %-3s| %-3s| %-8s\n","CourseCode","Score","Grade","GP","Cu","Weighted");
    for (int i = 0; i<8; i++) printf("%s\t%.1f\t%c\t%.0f\t%d\t%.1f\n",sem1_codes[i], scores1[i],grades1[i], gp1[i], cu1[i],gp1[i]*cu1[i]);
    for (int i = 0; i<8; i++) printf("%s\t%.1f\t%c\t%.0f\t%d\t%.1f\n",sem2_codes[i], scores2[i],grades2[i], gp2[i], cu2[i],gp2[i]*cu2[i]);

    
   
    return 0;
}
