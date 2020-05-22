#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(void) {
    int NCC, NIC[99], X, Y, A, W, B;
    double Q[9801], VU[9801], PD, VMP, T1[99], T2, K, Z, S, P;
    char NC[99][26], DI[9801][16], UM[9801][4], UMO[9801][3], TP[2];

    char TP1[2] = "A";
    char TP2[2] = "P";
    T1[0] = 0;
    T2 = 0;
    B = 0;

    scanf("%d", &NCC);

    //Recebe X, Y, NCC, T1[0], T2, NIC[0], DI[0...NIC[0]-1], Q[0...NIC[0]-1], UM[0...NIC[0]-1], UM0[0...NIC[0]-1] E VU[0...NIC[0]-1].
    //Devolve Atribuições Para Tais Variáveis.
    for(X=0;X<1;X++) {
        //Atribuição Para As Variáveis NC[0], NIC[0] E T2.
        scanf("%s %d", NC[0], &NIC[0]);
        for(Y=0;Y<NIC[0];Y++) {
            //Atribuição De DI[0...NIC[0]-1], Q[0...NIC[0]-1], UM[0...NIC[0]-1], UMO[0...NIC[0]-1], VU[0...NIC[0]-1] E T1[0].
            scanf("%s %lf %s %s %lf", DI[Y], &Q[Y], UM[Y], UMO[Y], &VU[Y]);
            T1[0] += Q[Y]*VU[Y];
        }
        T2 += T1[0];
    }


    // Recebe X, Y, NCC, T2, T1[1...X-1], NC[1...X-1], NIC[1...X-1], DI[NIC[0]...A-1], Q[NIC[0]...A-1], UM[NIC[0]...A-1], UMO[NIC[0]...A-1], VU[NIC[0]...A-1].
    //Devolve Atribuições Para Tais Variáveis.
    A = NIC[0];
    for(X=1; X<NCC;X++) {
        //Atribuição Para As Variáveis NC[1...NCC-1], NIC[1...NCC-1] E T2.
        scanf("%s %d", NC[X], &NIC[X]);
        for(Y=0;Y<NIC[X];Y++) {
            //Atribuição De DI[NIC[0]...A-1], Q[NIC[0]...A-1], UM[NIC[0]...A-1], UMO[NIC[0]...A-1] E VU[NIC[0]...A-1], TI[1...X-1].
            scanf("%s %lf %s %s %lf", DI[A], &Q[A], UM[A], UMO[A], &VU[A]);
            T1[X] += Q[A]*VU[A];
            A += 1;
        }
        T2 += T1[X];
    }


    scanf("%lf %s", &PD, TP);


    //Recebe As Variáveis TP E TP1.
    //Devolve 0 Se Forem Iguais.
    if(strcmp(TP,TP1)==0) {
            printf("\n\nHenrique Jorge Barateli\nhenriquejb194@gmail.com\n\n");
            S = T2*PD/100;
            P = T2 - S;
            //Recebe As Variáveis X, Y, S, P, PD, T2, K, A, NC[0...X-1], NIC[0...X-1], T1[0...X], DI[0...B-1], Q[0...B-1], UM[0...B-1] E VU[0...B-1].
            //Devolve As Atribuições Feitas Para Tais Variáveis.
            for(X=0;X<NCC;X++) {
                printf("%s\n", NC[X]);
                for(Y=0;Y<NIC[X];Y++) {
                    K = Q[B]*VU[B];
                    printf("%s: R$ %.2lf (%.1lf %s)\n", DI[B], K, Q[B], UM[B]);
                    B += 1;
                }
                printf("Total %s: R$ %.2lf\n\n", NC[X], T1[X]);
            }
            printf("TOTAL DE ITENS: %d\n\n", A);
            printf("VALOR TOTAL: R$ %.2lf\n\n", T2);
            printf("DESCONTO: %.2lf%%\n\n", PD);
            printf("VALOR DO DESCONTO: R$ %.2lf\n\n", S);
            printf("VALOR A PAGAR: R$ %.2lf\n\n", P);
    }


    //Recebe TP E TP2.
    //Devolve 0 Se Forem Iguais.
    else if(strcmp(TP,TP2)==0) {
            scanf("%s %lf", UMO[A], &VMP);
            printf("\n\nHenrique Jorge Barateli\nhenriquejb194@gmail.com\n\n");
            S = T2*PD/100;
            P = T2 - S;
            W = P/VMP;
            Z = P/W;
            //Recebe As Variáveis X, Y, S, P, PD, T2, K, A, W, VMP, Z, NC[0...X-1], NIC[0...X-1], T1[0...X-1], DI[0...B-1], Q[0...B-1], UM[0...B-1] E VU[0...B-1].
            //Devolve As Atribuições Feitas Para Tais Variáveis, com exceção de VMP.
            for(X=0;X<NCC;X++) {
                printf("%s\n", NC[X]);
                for(Y=0;Y<NIC[X];Y++) {
                    K = Q[B]*VU[B];
                    printf("*%s: R$ %.2lf (%.1lf %s)\n", DI[B], K, Q[B], UM[B]);
                    B += 1;
                }
                printf("**Total %s: R$ %.2lf\n\n", NC[X], T1[X]);
            }
            printf("TOTAL DE ITENS: %d\n\n", A);
            printf("VALOR TOTAL: R$ %.2lf\n\n", T2);
            printf("DESCONTO: %.2lf%%\n\n", PD);
            printf("VALOR DO DESCONTO: R$ %.2lf\n\n", S);
            printf("VALOR A PAGAR: R$ %.2lf\n\n", P);
            printf("PARCELA: %d\n\n", W);
            printf("VALOR DA PARCELA: R$ %.2lf\n\n", Z);
    }


    else printf("FORMA DE PAGAMENTO INVALIDA.\n");


    return 0;
}
