#include <stdio.h>

int main(){
	FILE *inp = fopen("grades.txt", "r");

	float tab[10][6];
	float avg[6] = { 0 };
	float temp;	
	
	
	
	if (inp == NULL)printf("File is Cannot Opened\n");
	
	else{
	
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 6; j++){
				fscanf(inp, "%f ", &temp);
				tab[i][j] = temp;
			}
		}
	fclose(inp);
	
	for (int i = 1; i < 6; i++){
		for (int j = 0; j < 10; j++){
			avg[i] += tab[j][i];
		}
	}
	printf("Quiz Number\tAverage\n");
		for (int i = 1; i < 6; i++){
			printf("%d\t\t %.2f\n", i, avg[i]/10.0);
		}
	float avg2[10] = { 0 };
		for (int j = 0; j < 10; j++){
			for (int i = 1; i < 6; i++){
				avg2[j] += tab[j][i];
			}
		}

	FILE *out = fopen("average.txt", "w");

	for (int i = 0; i < 10; i++){
		fprintf(out,"%.0f\t%.1f\n", tab[i][0], avg2[i]/5 );
	}
		
	fclose(out);
	}
	return 0;
}


