#include <stdio.h>
#include <stdlib.h>

#define ROW 8

int main(){
	char original[ROW][ROW];
	int new[2*ROW][2*ROW];
	original[0][0] = 0;
	original[0][1] = 1;
	original[0][2] = 1;
	original[0][3] = 1;
	original[0][4] = 0;

	original[1][0] = 1;
	original[1][1] = 0;
	original[1][2] = 0;
	original[1][3] = 0;
	original[1][4] = 1;

	original[2][0] = 1;
	original[2][1] = 0;
	original[2][2] = 0;
	original[2][3] = 0;
	original[2][4] = 1;

	original[3][0] = 1;
	original[3][1] = 0;
	original[3][2] = 0;
	original[3][3] = 0;
	original[3][4] = 1;

	original[4][0] = 1;
	original[4][1] = 1;
	original[4][2] = 1;
	original[4][3] = 1;
	original[4][4] = 1;

	original[5][0] = 1;
	original[5][1] = 0;
	original[5][2] = 0;
	original[5][3] = 0;
	original[5][4] = 1;

	original[6][0] = 1;
	original[6][1] = 0;
	original[6][2] = 0;
	original[6][3] = 0;
	original[6][4] = 1;

	int i, j, k, l;

	for (i = 0; i < ROW; i++){
		for (j = 0; j < ROW; j++){
			if (original[i][j]){
				new[(2*i)][(2*j)] = 0xff0000;
				new[(2*i)][(2*j)+1] = 0xff0000;
				new[(2*i)+1][(2*j)] = 0xff0000;
				new[(2*i)+1][(2*j)+1] = 0xff0000;
			}
			else {	
				new[(2*i)][(2*j)] = 0x000000;
				new[(2*i)][(2*j)+1] = 0x000000;
				new[(2*i)+1][(2*j)] = 0x000000;
				new[(2*i)+1][(2*j)+1] = 0x000000;
			}
		}
	}

	printf("WIDTH = 24;\nDEPTH = 256;\nADDRESS_RADIX = HEX;\nDATA_RADIX = HEX;\nCONTENT BEGIN\n\n");

	for (k = 0; k < (2*ROW); k++){
		for (l = 0; l < (2*ROW); l++){
			if (k == 0)
				printf("%x  : %06x;\n", l, new[k][l]);
			else
				printf("%x%x  : %06x;\n", k, l, new[k][l]);
		}
	}
	printf("END;");

	return 0;
}
