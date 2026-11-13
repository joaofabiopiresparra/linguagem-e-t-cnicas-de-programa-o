#include <stdio.h>
#include <string.h>

#define MAX 100

struct Acao {
    int codigo;
    char escola[50];
    char tema[50];
    char data[15];
    char publico[50];
    char responsavel[50];
    int qtd_prevista;
    int qtd_efetiva;
    int situacao; // 1 = Planejada, 2 = Realizada, 3 = Cancelada
};

int main(void) {
    struct Acao acoes[MAX];
    int total = 0;
    int opcao = 0;

    do {
        // menu principal
        printf("\n=== SISTEMA PSE ===\n");
        printf("1. Cadastrar acao\n");
        printf("2. Listar todas as acoes\n");
        printf("3. Pesquisar acao\n");
        printf("4. Atualizar situacao\n");
        printf("5. Gerar resumo geral\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Opcao invalida!\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n'); // limpa o enter para não bugar

        // 1. CADASTRAR AÇÃO 
        if (opcao == 1) {
            if (total >= MAX) {
                printf("Limite de cadastro atingido!\n");
                continue;
            }

            printf("\n--- CADASTRAR ACAO ---\n");
            printf("Codigo (numero): ");
            scanf("%d", &acoes[total].codigo);
            while (getchar() != '\n');

            // verifica se o código já existe
            int codigo_existe = 0;
            int i;
            for (i = 0; i < total; i++) {
                if (acoes[i].codigo == acoes[total].codigo) {
                    codigo_existe = 1;
                }
            }

            if (codigo_existe) {
                printf("Erro: Ja existe uma acao com este codigo!\n");
                continue;
            }

            printf("Escola: ");
            fgets(acoes[total].escola, 50, stdin);
            acoes[total].escola[strcspn(acoes[total].escola, "\n")] = '\0'; //usei ia para fazer essa parte pois acontecia um erro que desalinhava e bugava na hora de pesquisar por uma ação e nao sabia como resolver

            printf("Tema: ");
            fgets(acoes[total].tema, 50, stdin);
            acoes[total].tema[strcspn(acoes[total].tema, "\n")] = '\0';

            printf("Data prevista (ex: 20/10/2026): ");
            fgets(acoes[total].data, 15, stdin);
            acoes[total].data[strcspn(acoes[total].data, "\n")] = '\0';

            printf("Publico-alvo: ");
            fgets(acoes[total].publico, 50, stdin);
            acoes[total].publico[strcspn(acoes[total].publico, "\n")] = '\0';

            printf("Responsavel: ");
            fgets(acoes[total].responsavel, 50, stdin);
            acoes[total].responsavel[strcspn(acoes[total].responsavel, "\n")] = '\0';

            printf("Quantidade prevista de participantes: ");
            scanf("%d", &acoes[total].qtd_prevista);
            while (getchar() != '\n');

            acoes[total].situacao = 1; // para começa sempre como Planejada
            acoes[total].qtd_efetiva = 0;

            total++;
            printf("Acao cadastrada com sucesso como 'Planejada'!\n");
        }

        // 2. LISTAR AÇÕES 
        else if (opcao == 2) {
            if (total == 0) {
                printf("\nNenhuma acao cadastrada.\n");
            } else {
                int i;
                printf("\n=== LISTA DE ACOES ===\n");
                for (i = 0; i < total; i++) {
                    printf("Codigo: %d | Escola: %s | Tema: %s | Previstos: %d | Situacao: ", 
                           acoes[i].codigo, acoes[i].escola, acoes[i].tema, acoes[i].qtd_prevista);
                    
                    if (acoes[i].situacao == 1) printf("Planejada\n");
                    else if (acoes[i].situacao == 2) printf("Realizada (Participantes: %d)\n", acoes[i].qtd_efetiva);
                    else if (acoes[i].situacao == 3) printf("Cancelada\n");
                }
            }
        }

        // 3. PESQUISAR AÇÕES 
        else if (opcao == 3) {
            if (total == 0) {
                printf("\nNenhuma acao cadastrada para pesquisar.\n");
            } else {
                int busca_cod;
                int i;
                int achou = 0;
                printf("\nDigite o codigo da acao que deseja buscar: ");
                scanf("%d", &busca_cod);
                while (getchar() != '\n');

                for (i = 0; i < total; i++) {
                    if (acoes[i].codigo == busca_cod) {
                        printf("\nAcao encontrada!\n");
                        printf("Escola: %s\n", acoes[i].escola);
                        printf("Tema: %s\n", acoes[i].tema);
                        printf("Data: %s\n", acoes[i].data);
                        printf("Responsavel: %s\n", acoes[i].responsavel);
                        achou = 1;
                        break;
                    }
                }
                if (!achou) {
                    printf("Nenhuma acao encontrada com este codigo.\n");
                }
            }
        }

        // 4. ATUALIZAR SITUAÇÃO 
        else if (opcao == 4) {
            if (total == 0) {
                printf("\nNenhuma acao cadastrada.\n");
            } else {
                int codigo_busca;
                int i;
                int encontrado = -1;

                printf("\nDigite o codigo da acao para atualizar: ");
                scanf("%d", &codigo_busca);
                while (getchar() != '\n');

                for (i = 0; i < total; i++) {
                    if (acoes[i].codigo == codigo_busca) {
                        encontrado = i;
                        break;
                    }
                }

                if (encontrado == -1) {
                    printf("Acao nao encontrada!\n");
                } else {
                    printf("Nova situacao (1- Planejada, 2- Realizada, 3- Cancelada): ");
                    scanf("%d", &acoes[encontrado].situacao);
                    while (getchar() != '\n');

                    if (acoes[encontrado].situacao == 2) {
                        printf("Informe a quantidade REAL de participantes: ");
                        scanf("%d", &acoes[encontrado].qtd_efetiva);
                        while (getchar() != '\n');
                    } else {
                        acoes[encontrado].qtd_efetiva = 0;
                    }
                    printf("Situacao atualizada com sucesso!\n");
                }
            }
        }

        // 5. GERAR RESUMO GERAL 
        else if (opcao == 5) {
            if (total == 0) {
                printf("\nNenhuma acao cadastrada para gerar resumo.\n");
            } else {
                int p = 0, r = 0, c = 0;
                int total_previsto_realizadas = 0;
                int total_efetivo = 0;
                int i;

                for (i = 0; i < total; i++) {
                    if (acoes[i].situacao == 1) p++;
                    else if (acoes[i].situacao == 2) {
                        r++;
                        total_previsto_realizadas += acoes[i].qtd_prevista;
                        total_efetivo += acoes[i].qtd_efetiva;
                    }
                    else if (acoes[i].situacao == 3) c++;
                }

                double percentual = 0;
                if (total_previsto_realizadas > 0) {
                    percentual = ((double)total_efetivo / total_previsto_realizadas) * 100.0;
                }

                printf("\n=== RESUMO GERAL ===\n");
                printf("Acoes Planejadas: %d\n", p);
                printf("Acoes Realizadas: %d\n", r);
                printf("Acoes Canceladas: %d\n", c);
                printf("Total de participantes reais: %d\n", total_efetivo);
                printf("Percentual de participacao (real vs previsto nas realizadas): %.2f%%\n", percentual);
            }
        }

        // 6. SAIR 
        else if (opcao == 6) {
            printf("\nSaindo do sistema. Ate mais!\n");
        } else {
            printf("\nOpcao invalida! Escolha de 1 a 6.\n");
        }

    } while (opcao != 6);

    return 0;
}
