#include "zesendertigen.h"

void throwDice(int no_dice, int *thrown_dice){
    for (int i=0; i < no_dice; i++){
        thrown_dice[i] = rand() % 6 + 1;
    }
}

void odds36(double tries){
    double odds = 0;
    int total;
    int no_dice;

    int sixes;
    for (int try = 0; try < tries; try++){
        bool running = true;
        no_dice = 6;
        total = 0;
        while (running==true){
            sixes = 0;
            int thrown_dice[no_dice];
            throwDice(no_dice, thrown_dice);
            int loop_dice = no_dice;
            for (int i=0; i < loop_dice; i++){
                if (thrown_dice[i] == 6){
                    sixes++;
                    no_dice--;
                    total += 6;    
                }
            }
            if (sixes == 0){
                running = false;
            }
        
        }
    if (total == 36){
        odds++;
    }
    }
    printf("The odds are:%lf\n",odds/tries);
}

void averageThrow(int min_number, double tries){
    int no_dice;
    int total;
    double average_throw = 0;

    for (int try = 0; try < tries; try++){
        bool running = true;
        no_dice = 6;
        total = 0;
        while (running==true){
            int thrown_dice[no_dice];
            throwDice(no_dice, thrown_dice);
            int loop_dice = no_dice;
            bool die_taken = false;
            int max_die = 0;
            for (int i=0; i < loop_dice; i++){
                if (thrown_dice[i] >= min_number){
                    no_dice--;
                    total += thrown_dice[i];
                    die_taken = true;
                }
                if (thrown_dice[i] > max_die){
                    max_die = thrown_dice[i];
                }
            }
            if (die_taken==false){
                total += max_die;
                no_dice--;
            }
            if (no_dice == 0){
                running = false;
            }
        }
        average_throw += total;
    }
    printf("When taking out the minimum number of %i\n",min_number);
    printf("The average total is: %lf\n", average_throw/tries);
}

int main(){
    srand(time(0));
    double tries = 1000000;
    odds36(tries);
    averageThrow(6,tries);
    averageThrow(5,tries);
    averageThrow(4,tries);
    averageThrow(3,tries);
    averageThrow(2,tries);
    averageThrow(1,tries);
    
}