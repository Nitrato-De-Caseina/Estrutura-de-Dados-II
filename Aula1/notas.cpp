#include <locale.h>
#include <stdio.h>


struct Aluno{
    char Nome[30];
    char Sexo;
    int Idade;
    float Notas[10];
    bool Aprovacao;
};

int main()
{
	setlocale(LC_ALL, "Portuguese");
    float media, m_calculo;
    int QtdAlunos, QtdProvas, cont_alunosA=0, somaIdades = 0;
    float soma = 0;
    struct Aluno Alunos[100];
    
    printf("informe a quantidade de alunos na turma: ");
    scanf("%i",&QtdAlunos);
    
    //define a  quantidde de provas
    printf("informe a quantidade de provas na turma: ");
    scanf("%i",&QtdProvas);
    
    //define a media de aprovaco
     printf("informe a media de aprovacao: ");
    scanf("%f",&media);
    
    for(int i=1; i<=QtdAlunos; i++){
        printf("informe o nome do %i aluno: ", i);
        scanf("%s",&Alunos[i].Nome);
        
        printf("informe a idade de %s: ", Alunos[i].Nome);
        scanf("%i",&Alunos[i].Idade);
        somaIdades = somaIdades + Alunos[i].Idade;
        
        printf("informe o sexo de %s [m/f]: ", Alunos[i].Nome);
        scanf("%s",&Alunos[i].Sexo);
        
        for(int n=1; n<=QtdProvas; n++){
            printf("informe a %i nota: ", n);
            scanf("%f",&Alunos[i].Notas[n]);
            soma= soma+Alunos[i].Notas[n];
        }
    	m_calculo= soma / QtdProvas;
        Alunos[i].Aprovacao=(m_calculo >= media);
        if(m_calculo>=media)
        cont_alunosA++; //contalunosa+= e contalunosa = contalunosa +1
        soma = 0;
        m_calculo= 0;
        
    }
    //printf("Aprovado: %s\n\n", Alunos[1].Aprovacao ? "Sim" : "Nao");
    printf("/n quantidade de alunos aprovados: %i", cont_alunosA);
    printf("/n quantidade de alunos aprovados: %i", QtdAlunos);
    float mediadIdades = somaIdades / QtdAlunos;
    printf("/n A media de idades dos alunos da turma:%0.2f ", mediadIdades);
    printf("/n A quantidade de alunos reprovados é &d", QtdAlunos - cont_alunosA);
    
    return 0;
}
