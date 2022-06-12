#include<stdio.h>

void kanpsack(int num,float weight[],float profits[],float capacity){
    float x[num], total_profit=0;
    int i,j,u;
    u = capacity;
    for(i=0;i<num;i++){
        x[i] = 0.0;
    }

    for(i = 0;i<num;i++){
        if(weight[i] > u)
        break;
        else{
            x[i] = 1.0;
            total_profit = total_profit + profits[i];
            u = u - weight[i];
        }
    }

    if(i<num){
        x[i] = u/weight[i];
    }
    total_profit = total_profit + (x[i] * profits[i]) ;
    printf("The final vector is : ");
    for ( i = 0; i < num; i++)
    {
        printf("%f ", x[i]);
    }
    printf("\nMaximum Profit is : %f", total_profit);
    
}

void main(){
    int num, i,j, capacity, temp;
    printf("Enter the length of the array:\t ");
    scanf("%d", &num);

    float weight[num], profits[num], ratio[num];

    printf("Enter the weights and prifits:\n");
    for(i=0;i<num;i++){
        scanf("%f %f", &weight[i], &profits[i]);
    }

    for(i=0;i<num;i++){
        ratio[i] = profits[i]/weight[i];
    }

    printf("Enter the capacity of kanpsack :\t");
    scanf("%d", &capacity);
    
    for(i =0;i<num;i++){
        for(j=i+1;j<num;j++){
            if(ratio[i]<ratio[j]){
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profits[j];
                profits[j] = profits[i];
                profits[i] = temp;
            }
        }
    }
    kanpsack(num, weight, profits, capacity);
}