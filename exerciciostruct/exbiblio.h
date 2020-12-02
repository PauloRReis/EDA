typedef struct Dados Dados;

void menu();
void le_funcionario(Dados *x);
void mostra_funcionario(Dados x);
int maior_salario(Dados *x, int n);
int menor_salario(Dados *x, int n);
int media_salarios(Dados *x, int n);
void remover_funcionario(Dados *x, int p, int n);