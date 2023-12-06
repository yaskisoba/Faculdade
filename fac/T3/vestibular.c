#include <stdio.h>

int main(){
    int nQuestoes, acertos = 0;
    scanf("%d", &nQuestoes);

    char questoes[nQuestoes];
    char gabaritoQuestoes[nQuestoes];

    scanf("%s", questoes);
    scanf("%s", gabaritoQuestoes);


    for(int q = 0; q < nQuestoes; q++){
        if(questoes[q] == gabaritoQuestoes[q]){
            acertos++;
        }
    }

    printf("%d\n", acertos);

    return 0;
}