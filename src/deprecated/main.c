//
//  main.c
//  BellhamFord
//
//  Created by ZhuZiyi on 3/31/16.
//  Copyright © 2016 ZhuZiyi. All rights reserved.
//

//
//  main.c
//  HFT
//
//  Created by Shang Liu on 3/30/16.
//  Copyright © 2016 Shang Liu. All rights reserved.
//

#include <stdio.h>

#define inf 1000
#define currencyNumber 5


int main(int argc, const char * argv[]) {
    // insert code here...
    
    double rate[currencyNumber][currencyNumber]={
        0,  1, -2,  3, -5,
        -1,  0, -1,  2, -3,
        2,  1,  0,  1,  4,
        -3, -2, -1,  0,  2,
        5,  3, -4, -2,  0};
    
    /*
     double rate[currencyNumber][currencyNumber]={
     0,  10,   24,  23,  15,
     1,  0,  18,  2,  10,
     2,  1,  0,   1,   4,
     3,  8,  1,  0,  2,
     5,  3,  6, 2,  0};
     */
    double weight[currencyNumber]={0,inf,inf,inf,inf};
    double record[currencyNumber]={0};
    int PNrecord[currencyNumber]={0};
    
    int previousNode[currencyNumber]={-1};
    
    int i = 0,j,k,m,a, flag = 0;
    for(k=0;k<currencyNumber+1;k++){
        for(i=0; i<currencyNumber; i++){
            for(j=1; j<currencyNumber;j++){
                if((j!=i)&&(weight[j]>weight[i]+rate[i][j])){
                    weight[j]=weight[i]+rate[i][j];
                    previousNode[j]=i;
                }
            }
        }
        
        for(i=1;i<currencyNumber;i++){
            printf("Node: %d, mininal weight: %f,previous node:%d\n", i, weight[i],previousNode[i]);
        }
        printf("\n");
        if (k == currencyNumber-1){
            for(m=0;m<currencyNumber;m++){
                record[m] = weight[m];
            }
        }
    }
    // Find one negative cycle
    for(m=0;m<currencyNumber;m++){
        if (record[m] != weight[m]){
            PNrecord[0] = m;
            a = m;
            for(i = 1;i<currencyNumber;i++){
                PNrecord[i] = previousNode[a];
                a = PNrecord[i];
                for(j=0; j < i; j++){
                    if(a == PNrecord[j]){
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1) break;
            }
        }
        if (flag == 1) break;
    }
    for (k=0;k <= i;k++){
    printf("%d ",PNrecord[k]);
    }
    
    
    
    return 0;
}

