#include <iostream>

using namespace std;

struct fracao{
    int num;
	int den;
};

int mdc(int , int);

struct fracao leitura();

int mmc(int, int);

void irredutivel(struct fracao);

void menu1();

void menu2();

void menu3();

void escolha(int,struct fracao,struct fracao);

void operacoes(struct fracao, struct fracao);

void soma(struct fracao, struct fracao);

void subtracao(struct fracao, struct fracao);

void multipl(struct fracao, struct fracao);

void mensagem1();

void mensagem2();

void mensagem3();

void menscomum();

void divi(struct fracao, struct fracao);

void soma_ou_sub(int, struct fracao, struct fracao);

void saida(struct fracao);

void inverte(struct fracao);

void decimal(struct fracao);

int nova_leitura();

void comparacao(struct fracao, struct fracao);

int main(){
    menu1();
	return 0;
}
// ---------- MENU1 ---------------
void menu1(){
   int op=0;
   do{ 
    mensagem1();
		do{
			cin >> op;
			if (op > 2 || op < 0){
				cout << "Valor invalido, digite novamente" << endl;
			}
		}while (op > 2 || op < 0);
	    if (op != 0){
			if (op == 2){
				menu3();
			}
			else if (op == 1) {
				menu2();
			}
		}
	} while( op != 0);
	cout << "---------------------           FIM          -------------------" << endl;
}
// -----------FIM DO MENU1 ------------------

// --------- MENU3 ---------------
void menu3(){
	int op=0;
	struct fracao fra1,fra2;
	cout << "---------- Insira as fracoes ----------" << endl;
	cout << "Primeira Fracao:" << endl;
	fra1= leitura();
	cout << "Segunda Fracao:" << endl;
	fra2 = leitura();
   do{ 
	mensagem3();
    operacoes(fra1,fra2);
	menscomum();
	cin >> op;
	if (op == 1){
		if (nova_leitura() == 1){
			fra1= leitura();
			fra2 = leitura();
		}
	}
   } while( op == 1);
}
// -------- FIM DO MENU3 -----------


// --------- MENU2 -------------
void menu2(){
	int op=0;
	struct fracao fra;
	cout << "Digite a fracao:" << endl;
	fra = leitura();
   do{ 
	mensagem2();
		do{
			cin >> op;
			switch (op){
				case 2:
				    cout << "A inversao de  " << fra.num << "/" << fra.den << " eh -> ";
					inverte(fra);
					break;
				case 3:
					cout << "Fracao simplificada:" << endl;
					cout << fra.num << "/" << fra.den;
					irredutivel(fra);
					break;
				case 4:
					cout << "Versao decimal da fracao:" << endl;
					cout << fra.num << "/" << fra.den;
					decimal(fra);
					break;
				default:
					cout << "Valor invalido, digite novamente" << endl;
			}
		} while (op < 2 || op > 4);
	menscomum();
	cin >> op;
	if (op == 1) {
		if (nova_leitura() == 1)
				fra = leitura();
	}
   } while( op == 1);
}

// ---------- NOVA LEITURA ------------

int nova_leitura(){
		int esc;
		cout << "Deseja mudar o(s) valor(es) ?" << endl;
		cout << "Sim - Digite 1" << endl;
		cout << "Nao - Digite 2" << endl;
		cin >> esc;
		return esc;
}


// ------------MENSAGEM 3--------------
void mensagem3( ){
    cout << "---------- Operacoes com fracoes -----------" << endl;
    cout << "---------- Para Somar       - Digite 1 -----" << endl;
    cout << "---------- Para Subtrair    - Digite 2 -----" << endl;
	cout << "---------- Para Multiplicar - Digite 3 -----" << endl;
	cout << "---------- Para Dividir     - Digite 4 -----" << endl;
	cout << "---------- Para Comparar    - Digite 5 -----" << endl;
}
// ----------FIM DO MENSAGEM 3---------

// ---------- MENSAGEM 1 ------------
void mensagem1(){
	cout << "--------------------- PROGRAMA SOBRE FRACOES -------------------" << endl;
	cout << "----------- Operacoes com uma UNICA fracao   - Digite 1" << endl;
	cout << "----------- Operacoes com DUAS fracoes       - Digite 2" << endl;
	cout << "----------- Para finalizar o programa        - Digite 0" << endl;
}
// ------------ FIM DA MENSAGEM 1 ----------


// ------------ MENSAGEM 2 -----------
void mensagem2(){
	cout << "Para inverter a fracao          - Digite 2 " << endl;
	cout << "Para simplica-la                - Digite 3" << endl;
	cout << "Para torna-la um numero decimal - Digite 4 " << endl;
	
}
// -------- FIM MENSAGEM 2 ----------

// ---------- MENSAGEM COMUM ----------
void menscomum(){
	cout << "Para voltar ao menu principal - Digite 0" << endl;
	cout << "Para continuar nesse menu     - Digite 1" << endl;
}
// -------- FIM DA MENSAGEM COMUM -----


// -----------OPERAÇÕES-----------
void operacoes(struct fracao fra1, struct fracao fra2){
    int op;
    do {
	cin >> op;
	if (op > 5 || op < 1){
        cout << "Valor invalido, digite novamente" << endl;
    }
    } while (op > 5 || op < 1);
    escolha(op, fra1, fra2);
	
}
// ---------FIM DAS OPERAÇÕES-----------


// -------ESCOLHA---------
void escolha(int op,struct fracao fra1, struct fracao fra2){
    switch (op){
        case 1:
			soma_ou_sub(op,fra1,fra2);
            break;
        case 2:
            soma_ou_sub(op,fra1,fra2);
            break;
		case 3:
			multipl(fra1,fra2);
			break;
		case 4:
			divi(fra1,fra2);
			break;
		case 5:
			comparacao(fra1,fra2);
			break;
    }
}
// ------FIM ESCOLHA---------

// ------- CALCULA O MMC ---------
int mmc(int a,int b){
    return (a*b)/mdc(a,b);
}
//------- FIM MMC ---------


// CALCULA O MDC
int mdc(int num, int den){
	if (num % den == 0)
	 return den;
	else
		return mdc(den, num % den);
}
// ----- FIM MDC ----------


// --------- FAZ A LEITURA DAS INFORMAÇÕES -----------
struct fracao leitura(){
    struct fracao teste;
	cout << "Digite o numerador" << endl;
	cin >> teste.num;
	do {
	cout << "Digite o denominador" << endl;
	cin >> teste.den;
	   if (teste.den == 0) {
		   cout << "O denominador nao pode ser 0" << endl;
		   cout << "Digite qualquer valor diferente de 0" << endl;
	   }
	} while (teste.den == 0);
	return teste;
}
// ------- FIM DA LEITURA -------

// SOMA OU SUBTRAÇÃO DE FRAÇÕES
void soma_ou_sub(int op,struct fracao fra1, struct fracao fra2){
	struct fracao result;
	if (op == 1)
		soma(fra1,fra2);
	else if ( op == 2)
		subtracao(fra1,fra2);
    result.den = mmc(fra1.den,fra2.den);
    int prod1 = result.den / fra1.den;
    fra1.num *= prod1;
    int prod2 = result.den / fra2.den;
    fra2.num *= prod2;
    if (op == 1){
		result.num = fra1.num + fra2.num;
        saida(result);
    }
    else if (op == 2){
		if (fra1.num > fra2.num)
			result.num = fra1.num - fra2.num;
		else
			result.num = fra2.num - fra1.num;
		saida(result);
    }
}
// ------- IMPRIME A FRACAO ------------
void saida(struct fracao result){
	cout << " = " << result.num << "/" << result.den;
	int div = mdc(result.num,result.den);
	if ( div == 1){ // SIMPLIFICA SE FOR DIFERENTE DE 1
		cout << endl;
	}
	else {
		 result.num /= div;
		 result.den /= div;
		 cout << " = " <<result.num << "/" << result.den << endl;
	}
}

void soma(struct fracao fra1,struct fracao fra2){
	cout << "A soma de " << fra1.num << "/" << fra1.den << "+" << fra2.num << "/" << fra2.den;
}

void subtracao(struct fracao fra1,struct fracao fra2){
	cout << "A subtracao de" << fra1.num << "/" << fra1.den << "-" << fra2.num << "/" << fra2.den;
}

// ----------- MULTIPLICA AS FRACÕES -----------
void multipl(struct fracao fra1, struct fracao fra2){
	struct fracao result;
	cout << "O produto de " << fra1.num << "/" << fra1.den << " * " << fra2.num << "/" << fra2.den;
	result.num = fra1.num * fra2.num;
	result.den = fra1.den * fra2.den;
	saida(result);
}
// -------- FIM ----------------------

// ------------- DIVIDE AS FRACÕES -----------
void divi(struct fracao fra1, struct fracao fra2){
	struct fracao result;;
	cout << "O divisao de " << fra1.num << "/" << fra1.den << " / " << fra2.num << "/" << fra2.den;
	result.num = fra1.num * fra2.den;
	result.den = fra1.den * fra2.num;
	saida(result);
}


// TORNA A FRAÇÃO IRREDUTÍVEL
void irredutivel(struct fracao teste){
    int div = mdc(teste.den,teste.num);
	if (div == 1){
		cout << endl;
		cout << "A fracao ja esta simplificada" << endl;
	}
	else{
		teste.num /= div;
		teste.den /= div;
		cout << "= " << teste.num << "/" << teste.den << endl;
    }
}
// -------

// INVERTE AS FRAÇÕES
void inverte(struct fracao fra){
	int temp;
	temp = fra.num;
	fra.num = fra.den;
	fra.den = temp;
	cout << fra.num << "/" << fra.den << endl;
}

// TRANSFORMA A FRAÇÃO EM DECIMAL
void decimal(struct fracao fra1){
		float dec;
		dec =  float (fra1.num) / fra1.den;
		cout << " = " << dec << endl;
}
// COMPARA AS FRACÕES
void comparacao(struct fracao fra1, struct fracao fra2){
	int fator1 = fra1.num * fra2.den;
	int fator2 = fra2.num * fra1.den;
	if (fator1 > fator2){
		cout << fra1.num << "/" << fra1.den << " > " << fra2.num << "/" << fra2.den << endl; 
	}
	else if (fator1 < fator2){
		cout << fra1.num << "/" << fra1.den << " < " << fra2.num << "/" << fra2.den << endl; 
	}
	else{
		cout << fra1.num << "/" << fra1.den << " = " << fra2.num << "/" << fra2.den << endl; 
	}
}